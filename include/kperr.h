/* ----------------------------------------------
 *
 * kperr.h
 *
 *    error handling
 *
 * 2013-02-22  mp  initial creation
 *
 */

#ifndef kperr_included
#define kperr_included

// ---------------------------------------- assertions
// KP_ASSERT[W[0]](bool bCond, HRESULT lhErrCode, uchar *Msg);
//    assertion, whether bCond is kept
//    Msg could be null
//
// severe error – throws an exception if bCond not kept
#ifdef KP_CPP
#define KP_ASSERT(bCond, lhErrCode, Msg) {{ if (!(bCond)){ KP_THROW(lhErrCode, Msg); } }}
#else
#define KP_ASSERT(bCond, lhErrCode, Msg) {{ if (!(bCond)){ KP_ERROR(lhErrCode, Msg); exit(lhErrCode); } }}
#endif

// local fault – puts warning to the log file and sets local variable retc (HRESULT retc)
#define KP_ASSERTW(bCond, lhErrCode, Msg) {{ if (SUCCEEDED(retc)) if (!(bCond)){ KP_WARNING(lhErrCode, Msg); retc = lhErrCode; } }}
// the same as KP_ASSERTW, but does not bother with retc
#define KP_ASSERTW0(bCond, lhErrCode, Msg) {{ if (!(bCond)){ KP_WARNING(lhErrCode, Msg); } }}


#ifdef __cplusplus
// ---------------------------------------- exceptions
#define KP_THROW(lhErrCode, Msg) {{ throw(new KpException(lhErrCode, Msg, (const uchar *)__FILE__, __LINE__)); }}

// KP_CATCH(const std::exception &e);
// KP_CATCH(KpException &e);
#define KP_CATCH(e) {{ KpError.Catch(e); }}
#endif
#define KP_CATCH_ALL \
    catch(const KpException *exc) \
    { \
        KP_CATCH(*exc); \
    } \
    catch(const std::exception &exc) \
    { \
        KP_CATCH(exc); \
    } \
    catch(...) \
    { \
        KP_ERROR(KP_E_UNHANDLED_EXCEPTION, null); \
    }


// ---------------------------------------- error messages
#ifdef __cplusplus
#define KP_ERROR(lhErrCode, Msg) {{ KpError.OutputErrorMessage(lhErrCode, Msg, True, (const uchar *)__FILE__, __LINE__); }}
#define KP_WARNING(lhErrCode, Msg) {{ KpError.OutputErrorMessage(lhErrCode, Msg, False, (const uchar *)__FILE__, __LINE__); }}
// #define KP_TRACE(...) {{ char *trc_buf_ptr = new char[10000]; if(trc_buf_ptr != NULL){ sprintf(trc_buf_ptr, (const char *)__VA_ARGS__); KpError.PutLogMessage(trc_buf_ptr); delete [] trc_buf_ptr; } }}
#define KP_TRACE(...) {{ KpError.PutLogMessage((const char *)__VA_ARGS__); }}
#else
#define KP_ERROR(lhErrCode, Msg) {{ KpOutputErrorMessage(lhErrCode, Msg, True, (const uchar *)__FILE__, __LINE__); }}
#define KP_WARNING(lhErrCode, Msg) {{ KpOutputErrorMessage(lhErrCode, Msg, False, (const uchar *)__FILE__, __LINE__); }}
// #define KP_TRACE(...) {{ char *trc_buf_ptr = new char[10000]; if(trc_buf_ptr != NULL){ sprintf(trc_buf_ptr, (const char *)__VA_ARGS__); KpPutLogMessage(trc_buf_ptr); delete [] trc_buf_ptr; } }}
#define KP_TRACE(...) {{ KpPutLogMessage((const char *)__VA_ARGS__); }}
#endif



#ifdef __cplusplus
class KpException : public std::exception
{
public:
   // KpErrorClass::OutputErrorMessage() parametrai
   HRESULT m_lhErrCode;
   uchar m_lpszMsg[KP_MAX_FILE_LIN_LEN + 1];
   LONG m_lWindowsErrorCode;
   uchar m_lpszSourceFile[KP_MAX_FNAME_LEN + 1];
   int m_iSourceLine;

   KpException
   (
      HRESULT lhRetc,
      const uchar *lpszMessageText,
      const uchar *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, lpszMessageText, 0L, lpszSourceFile, iSourceLine); }

   KpException
   (
      HRESULT lhRetc,
      const char *lpszMessageText,
      const uchar *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, (const uchar *)lpszMessageText, 0L, lpszSourceFile, iSourceLine); }

   KpException
   (
      HRESULT lhRetc,
      LONG lWindowsErrorCode, // return value of GetLastError() etc.
      const uchar *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, null, lWindowsErrorCode, lpszSourceFile, iSourceLine); }

   void Constructor
   (
      HRESULT lhRetc,
      const uchar *lpszMessageText,
      LONG lWindowsErrorCode,
      const uchar *lpszSourceFile,
      int iSourceLine
   );
};


// ----------------------------------------
class KpErrorClass
{
public:
    uchar m_lpszProdName[KP_MAX_FNAME_LEN + 1];

    static const unsigned char *m_lpszaKpMessages[NumOfKpMessages][KpNumOfLangs];

//  volatile int m_iInsideOfStackDump; // StackDump() recursion avoiding semaphore
    volatile int m_iInsideOfPutLogMessage; // PutLogMessage() recursion avoiding semaphore

    HRESULT m_lhLastRetc;
    uchar m_lpszLastMessageText[KP_MAX_FILE_LIN_LEN + 1];
    uchar m_lpszLastSourceFile[KP_MAX_FNAME_LEN + 1];
    int m_iLastSourceLine;

    KpErrorClass(const uchar *lpszProdName);

    void SetProdName(const uchar *lpszNameBuf); // lpszNameBuf[KP_MAX_FNAME_LEN + 1]
    void GetProdName(uchar *lpszNameBuf); // lpszNameBuf[KP_MAX_FNAME_LEN + 1]
    const uchar *GetProdNamePtr(void); // grąžina m_lpszProdName, taigi, ne ilgesnis už KP_MAX_FNAME_LEN

//  void StackDump(void);

    void GetLogFileName(uchar *lpszLogFNameBuf); // lpszFNameBuf[KP_MAX_FNAME_LEN + 1];
    void EncodeLogBuf(uchar *pBuffer, int iDataLen);

// --------------------
    void PutLogMessage(const uchar *lpszFmt, va_list Args);
    void PutLogMessage(const uchar *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage(lpszFmt, argptr);
    }
    void PutLogMessage(const char *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage((const uchar *)lpszFmt, argptr);
    }

// --------------------
    void SendDiagMsg
    (
        const uchar *lpszMessageText, // pranešimas klientui
        bool bSevereError,            // jei False – ne klaida, o tiesiog diag. msg siuntimas,
                                      //    formuoti atitinkamą ikoną ir kepurės tekstą
        const uchar *lpszAddMessage   // papildomas pranešimas apie klaidos kodą ir src failą,
                                      //    klientui nerodomas, siunčiamas helpdeskui
    );

// --------------------
    static void FormatErrorMessage
    (
        const HRESULT lhRetc,
        uchar *lpszMsg
    );                         // generates the error message
                               // lpszMsg is used to return back the error text, must
                               //    be not shorter, than KP_MAX_FILE_LIN_LEN bytes
                               // must be defined locally for processing special errors of application

    static HRESULT FormatSystemErrorMessage
    (
        LONG lWindowsErrorCode,
        uchar *lpszMsg,
        bool bFullFormat
    );
    static uchar *FormatSystemErrorMessage(LONG lWindowsErrorCode);
                               // formats windows system error message
                               // bFullFormat == False - tik lietuviškas pranešimas
                               // lpszMsg is used to return back the error text, must
                               //    be not shorter, than KP_MAX_FILE_LIN_LEN bytes

// --------------------
    void OutputErrorMessage          // outputs error message; calls FormatErrorMessage()
    (
        HRESULT lhRetc,
        const uchar *lpszMessageText,  // explanational error text
        bool bSevereError,      // True - pranešimas išvedamas ne tik į log failą, bet ir į ekraną su galimybe išsiųsti diagnostinį pranešimą
        const uchar *lpszSourceFile,
        int iSourceLine
    );

    void OutputErrorMessage
    (
        HRESULT lhRetc,
        const char *lpszMessageText,
        bool bSevereError,
        const uchar *lpszSourceFile,
        int iSourceLine
    ){ OutputErrorMessage(lhRetc, (const uchar *)lpszMessageText, bSevereError, lpszSourceFile, iSourceLine); }

    void OutputErrorMessage
    (
        HRESULT lhRetc,
        LONG lWindowsErrorCode, // return value of GetLastError() etc.
        bool bSevereError,
        const uchar *lpszSourceFile,
        int iSourceLine
    ){ OutputErrorMessage(lhRetc, FormatSystemErrorMessage(lWindowsErrorCode), bSevereError, lpszSourceFile, iSourceLine); };

// --------------------
    void Catch(const std::exception &e);
};

extern KpErrorClass KpError;

#endif // #ifdef __cplusplus

// call to KpError.OutputErrorMessage()
extern PLAIN_C void KpOutputErrorMessage
(
    HRESULT lhRetc,
    const uchar *lpszMessageText,
    bool bSevereError,
    const uchar *lpszSourceFile,
    int iSourceLine
);

// call to KpError.FormatSystemErrorMessage()
extern PLAIN_C uchar *KpFormatSystemErrorMessage(LONG lWindowsErrorCode);

// call to KpError.PutLogMessage()
extern PLAIN_C void KpPutLogMessage(const uchar *lpszFmt, ...);


// call to KpError.GetProdName() and KpApp->GetAppName()
// returns char string not longer than KP_MAX_FNAME_LEN
extern PLAIN_C const uchar *KpGetProdName(void);
// extern String program;  /* name of dvread program */
#define program KpGetProdName() // definition for dvread.c, etc.

// ----------------------------------------
#endif // #ifndef kperr_included
