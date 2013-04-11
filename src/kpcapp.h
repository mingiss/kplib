/* -----------------------------------------------
 *
 * kpcapp.cpp
 *
 *    common application
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef kpcapp_included
#define kpcapp_included

class KpCommonApp
{
public:
    UCHAR m_lpszProdName[KP_MAX_FNAME_LEN + 1];
    int m_iProdVer;
    UCHAR m_lpszProdDate[KP_MAX_FNAME_LEN + 1];

    UCHAR m_lpszAppName[KP_MAX_FNAME_LEN + 1]; // full path to the executable
#ifdef WIN32
    static HINSTANCE m_hInstance;   // nustatomas KpInitWindows(), po to Init()
#endif

    static KpLang m_iMsgLangOff; // member, set by KpInitWindows() // nupjautas iki KpNumOfLangs, galima naudoti masyvų indeksams

// --------------   
    KpCommonApp(const UCHAR *lpszProdName, int iProdVer);

    virtual void Init(HINSTANCE hInstance, const UCHAR *lpszCmdLine);
    virtual void Close(void){}

#ifdef WIN32
    static void KpInitWindows(void); // iškviečiamas konstruktoriaus
#endif
   
    void GetAppName(UCHAR *lpszNameBuf);
                     // gets filename of application currently running
                     // lpszNameBuf[KP_MAX_FNAME_LEN+1]
};

extern KpCommonApp *KpApp;

#endif // #ifndef kpcapp_included
