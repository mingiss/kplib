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

#ifdef __cplusplus

class KpCommonApp
{
public:
    UCHAR m_lpszProdName[KP_MAX_FNAME_LEN + 1];
    int m_iProdVer;
    UCHAR m_lpszProdDate[KP_MAX_FNAME_LEN + 1];

    const void *m_pStackTop;

    UCHAR m_lpszAppName[KP_MAX_FNAME_LEN + 1]; // full path to the executable
#ifdef WIN32
    static HINSTANCE m_hInstance;   // nustatomas KpInitWindows(), po to Init()
#endif
    UCHAR m_lpszCmdLine[KP_MAX_FNAME_LEN + 1]; // command line

    static KpLang m_iMsgLangOff; // member, set by KpInitWindows() // nupjautas iki KpNumOfLangs, galima naudoti masyvų indeksams

// --------------   
    KpCommonApp(const UCHAR *lpszProdName, int iProdVer);
    virtual ~KpCommonApp(void);

    virtual void Init(HINSTANCE hInstance, const UCHAR *lpszCmdLine, const void *pStackTop);  // pStackTop – caller stack top pointer,
    virtual void Close(void){}                                  // usually pointer to some local variable of the main() function
                                                                // could be NULL
#ifdef WIN32
    static void KpInitWindows(void); // iškviečiamas konstruktoriaus
#endif
   
    void GetAppName(UCHAR *lpszNameBuf);
                     // gets filename of application currently running
                     // lpszNameBuf[KP_MAX_FNAME_LEN + 1]
};

extern KpCommonApp *KpApp;

#endif // #ifdef __cplusplus
#endif // #ifndef kpcapp_included
