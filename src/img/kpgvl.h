/*
 * kpgvl.h
 *  
 *    VlFeat kp addons
 *
 *  2013-09-20  mp  Initial creation
 *   
 */   

#ifndef kpgvl_included
#define kpgvl_included

// -------------------------- VlFeat papildymai
#define KP_VL_KEYPOINT_TIMEOUT 5000 // keypoint skaičiavimo taimoutas, jeigu per jį nepabaigia – laužiam lauk
#define KP_VL_MAX_NUM_OF_KEYPNT_ORIENTS 4 // keypoint gali turėti iki 4 krypčių deskriptorius
#define KP_VL_KEYPNT_DESCR_SIZE (8 * 4 * 4) // keypoint descriptorius – 4x4 matrica iš gradiento elementų – 8 krypčių reikšmių

class KpVlSiftKeypoint: public VlSiftKeypoint
{
vl_sift_pix m_faDescr[KP_VL_MAX_NUM_OF_KEYPNT_ORIENTS][KP_VL_KEYPNT_DESCR_SIZE]; // deskriptoriai
double m_daOrients[KP_VL_MAX_NUM_OF_KEYPNT_ORIENTS]; // orientacijos
int m_iNumOfOrients; // krypčių skaičius masyve m_faDescr[] ir mfaOrients[]

public:
KpVlSiftKeypoint *m_pPairPnt; // suporuoto taško adresas lyginamame paveikslo keipointų sąraše; nesuporuotiems NULL
double m_dPairDiff; // mažiausias atstumas iki suporuoto taško deskriptorių; nesuporuotiems MAX_FLT
double m_dAngle; // kampų skirtumas tarp suporuoto ir „this“ artimiausių deskriptorių orientacijų; nesuporuotiems 0.0 

    KpVlSiftKeypoint(void); 

    void ClearPairPnt(void);
    
    void CalcDescrs(VlSiftFilt *p_pSiftFilt); // užpildo m_faDescr[], m_daOrients[] ir m_iNumOfOrients
    
    // skaičiuoja mažiausią atstumą tarp deskriptorių  
    // į *p_dAngle grąžina artimiausių deskriptorių orientacijų skirtumą (transformacijos iš p_pKeyPt1 į p_pKeyPt2 kampą)
    // jei p_bUseAngle == True, tada į atstumo skaičiavimą įtraukiamas skirtumas tarp transformacijos kampo ir
    //      suvidurkinto visų taškų transformacijos kampo, perduodamo parametru *p_pdAngle
    static double CalcKeyPtDiff(const KpVlSiftKeypoint *p_pKeyPt1, const KpVlSiftKeypoint *p_pKeyPt2, 
        double *p_pdAngle, bool p_bUseAngle);
    // skaičiuoja atstumą tarp deskriptorių, tik susumuoja skirtumų kvadratus, šaknies netraukia 
    static double CalcKeyPtDescDiff(const vl_sift_pix *p_pDesc1, const vl_sift_pix *p_pDesc2);
};

// vietoj vl_get_last_error_message() -- jeigu ją naudojam, iš vl.lib neprisilinkuoja _vl_state
extern const uchar *KpVlGetErrorMsg(int p_iVlErrCode);

#endif // #ifndef kpgvl_included
