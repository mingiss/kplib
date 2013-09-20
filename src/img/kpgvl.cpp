/*
 * kpgvl.cpp
 *  
 *    VlFeat kp addons
 *
 *  2013-09-20  mp  Initial creation
 *   
 */   

#include "envir.h"

#include <stdio.h>
#include <iostream>
#include <math.h>
#ifdef __WIN32__
#include <windows.h>
#endif

// VlFeat
#include "generic.h"
#include "sift.h"
 
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kperrno.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kpimg.h"
#include "kpgvl.h"


// -------------------------- VlFeat papildymai
const uchar *KpVlGetErrorMsg(int p_iVlErrCode)
{
const uchar *rets = null; 
    
    switch (p_iVlErrCode)
    {
    case VL_ERR_OK:         rets = (const uchar *)"VlFeat: No error"; break;
    case VL_ERR_OVERFLOW:   rets = (const uchar *)"VlFeat: Buffer overflow"; break;
    case VL_ERR_ALLOC:      rets = (const uchar *)"VlFeat: Resource allocation error"; break;
    case VL_ERR_BAD_ARG:    rets = (const uchar *)"VlFeat: Bad argument or illegal data"; break;
    case VL_ERR_IO:         rets = (const uchar *)"VlFeat: Input/output error"; break;
    case VL_ERR_EOF:        rets = (const uchar *)"VlFeat: End-of-file or end-of-sequence"; break;
//  @deprecated    case VL_ERR_NO_MORE: rets = (const uchar *)"End-of-sequence"; break;
    default:                rets = (const uchar *)"VlFeat: Unknown error"; break;
    }
    
return(rets);
}


// ----------------------
KpVlSiftKeypoint::KpVlSiftKeypoint(void): VlSiftKeypoint()
{
    m_iNumOfOrients = 0;
    for (int ii = 0; ii < KP_VL_MAX_NUM_OF_KEYPNT_ORIENTS; ii++)
    {
        m_daOrients[ii] = 0.0;
        for (int jj = 0; jj < KP_VL_KEYPNT_DESCR_SIZE; jj++)
            m_faDescr[ii][jj] = 0.0;
    }

    ClearPairPnt();
}


void KpVlSiftKeypoint::ClearPairPnt(void)
{
    m_pPairPnt = NULL;
    m_dPairDiff = MAX_FLT;
    m_dAngle = 0.0;
}


// ---------------------
void KpVlSiftKeypoint::CalcDescrs(VlSiftFilt *p_pSiftFilt)
{
    KP_ASSERT(p_pSiftFilt, E_INVALIDARG, null);
    KP_ASSERT(vl_sift_get_octave_index(p_pSiftFilt) == o, KP_E_SYSTEM_ERROR, null);

    m_iNumOfOrients = vl_sift_calc_keypoint_orientations(p_pSiftFilt, m_daOrients, this);
    KP_ASSERT(m_iNumOfOrients < KP_VL_MAX_NUM_OF_KEYPNT_ORIENTS, KP_E_BUFFER_OVERFLOW, null);
    KP_ASSERT(m_iNumOfOrients > 0, KP_E_SYSTEM_ERROR, null);
// printf("%d ", m_iNumOfOrients); 

// vl_sift_pix descr[1000];
    for (int ii = 0; ii < m_iNumOfOrients; ii++)
    {
// for (int jj = 0; jj < 1000; jj++) descr[jj] = 0.0;         
        vl_sift_calc_keypoint_descriptor(p_pSiftFilt, m_faDescr[ii] /* descr */, this, m_daOrients[ii]);
// for (int jj = KP_VL_KEYPNT_DESCR_SIZE; jj < 1000; jj++) KP_ASSERT(descr[jj] == 0.0, KP_E_SYSTEM_ERROR, null);        
//      memcpy(m_faDescr[ii], descr, KP_VL_KEYPNT_DESCR_SIZE);
	} 
}


// -----------------------
double KpVlSiftKeypoint::CalcKpntDescDiff(const vl_sift_pix *p_pDesc1, const vl_sift_pix *p_pDesc2)
{
    KP_ASSERT(p_pDesc1, E_INVALIDARG, null);
    KP_ASSERT(p_pDesc2, E_INVALIDARG, null);

double diff = 0.0;

    for (int ii = 0; ii < KP_VL_KEYPNT_DESCR_SIZE; ii++)
    {
    double ldiff = p_pDesc2[ii] - p_pDesc1[ii];
        diff += ldiff * ldiff;
    } 

return (diff);
}


double KpVlSiftKeypoint::CalcKpntDiff(const KpVlSiftKeypoint *p_pKpnt1, const KpVlSiftKeypoint *p_pKpnt2, 
    double *p_pdAngle, bool p_bUseAngle)
{
    KP_ASSERT(p_pKpnt1, E_INVALIDARG, null);
    KP_ASSERT(p_pKpnt2, E_INVALIDARG, null);
    KP_ASSERT(p_pdAngle || (!p_bUseAngle), E_INVALIDARG, null);
    
double min_diff = MAX_FLT;
double min_angle = 0.0;

    for (int ii = 0; ii < p_pKpnt1->m_iNumOfOrients; ii++)
        for (int jj = 0; jj < p_pKpnt2->m_iNumOfOrients; jj++)
        {
        double diff = CalcKpntDescDiff(p_pKpnt1->m_faDescr[ii], p_pKpnt2->m_faDescr[jj]);
        
        double angle = p_pKpnt2->m_daOrients[jj] - p_pKpnt1->m_daOrients[ii];
        double angle_dif = NormAngle(angle - *p_pdAngle) * 10.0 /* / ( 2.0 * M_PI) */;
            diff += angle_dif * angle_dif;

            angle = NormAngle(angle);
            
            if (diff < min_diff)
            {
                min_diff = diff;
                min_angle = angle;
            } 
        }
        
if (p_pdAngle) *p_pdAngle = min_angle;
return(min_diff);
}
