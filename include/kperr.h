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

#ifdef __cplusplus

// ---------------------------------------- assertions
// KP_ASSERT[W[0]](bool bCond, HRESULT lhErrCode, UCHAR *Msg);
//    assertion, whether bCond is kept
//    Msg could be null
//
// severe error – throws an exception if bCond not kept
#define KP_ASSERT(bCond, lhErrCode, Msg) {{ if(!(bCond)){ KP_THROW(lhErrCode, Msg); } }}
// local fault – puts warning to the log file and sets local variable retc (HRESULT retc)
#define KP_ASSERTW(bCond, lhErrCode, Msg) {{ if(SUCCEEDED(retc)) if(!(bCond)){ KP_WARNING(lhErrCode, Msg); retc = lhErrCode; } }}
// the same as KP_ASSERTW, but does not bother with retc
#define KP_ASSERTW0(bCond, lhErrCode, Msg) {{ if(!(bCond)){ KP_WARNING(lhErrCode, Msg); } }}


// ---------------------------------------- exceptions
#define KP_THROW(lhErrCode, Msg) {{ throw(new KpException(lhErrCode, Msg, (const UCHAR *)__FILE__, __LINE__)); }}

// KP_CATCH(const std::exception &e);
// KP_CATCH(KpException &e);
#define KP_CATCH(e) {{ KpError.Catch(e); }}

#define KP_CATCH_ALL \
    catch(const KpException *exc) \
    { \
        KP_CATCH(*exc); \
    } \
    catch(const exception &exc) \
    { \
        KP_CATCH(exc); \
    } \
    catch(...) \
    { \
        KP_ERROR(KP_E_UNHANDLED_EXCEPTION, null); \
    }


// ---------------------------------------- error messages
#define KP_ERROR(lhErrCode, Msg) {{ KpError.OutputErrorMessage(lhErrCode, Msg, True, (const UCHAR *)__FILE__, __LINE__); }}
#define KP_WARNING(lhErrCode, Msg) {{ KpError.OutputErrorMessage(lhErrCode, Msg, False, (const UCHAR *)__FILE__, __LINE__); }}


class KpException : public std::exception
{
public:
   // KpErrorClass::OutputErrorMessage() parametrai
   HRESULT m_lhErrCode;
   UCHAR m_lpszMsg[KP_MAX_FILE_LIN_LEN + 1];
   LONG m_lWindowsErrorCode;
   UCHAR m_lpszSourceFile[KP_MAX_FNAME_LEN + 1];
   int m_iSourceLine;
   
   KpException
   (
      HRESULT lhRetc,
      const UCHAR *lpszMessageText,
      const UCHAR *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, lpszMessageText, 0L, lpszSourceFile, iSourceLine); }

   KpException
   (
      HRESULT lhRetc,
      const CHAR *lpszMessageText,
      const UCHAR *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, (const UCHAR *)lpszMessageText, 0L, lpszSourceFile, iSourceLine); }

   KpException
   (
      HRESULT lhRetc,
      LONG lWindowsErrorCode, // return value of GetLastError() etc.
      const UCHAR *lpszSourceFile,
      int iSourceLine
   ){ Constructor(lhRetc, null, lWindowsErrorCode, lpszSourceFile, iSourceLine); }

   void Constructor
   (
      HRESULT lhRetc,
      const UCHAR *lpszMessageText,
      LONG lWindowsErrorCode,
      const UCHAR *lpszSourceFile,
      int iSourceLine
   );
};


// ----------------------------------------
class KpErrorClass
{
public:
    UCHAR m_lpszProdName[KP_MAX_FNAME_LEN + 1];

    static const unsigned char *m_lpszaKpMessages[NumOfKpMessages][KpNumOfLangs];

//  volatile int m_iInsideOfStackDump; // StackDump() recursion avoiding semaphore
    volatile int m_iInsideOfPutLogMessage; // PutLogMessage() recursion avoiding semaphore
    
    HRESULT m_lhLastRetc;
    UCHAR m_lpszLastMessageText[KP_MAX_FILE_LIN_LEN + 1];
    UCHAR m_lpszLastSourceFile[KP_MAX_FNAME_LEN + 1];
    int m_iLastSourceLine;
    
    KpErrorClass(const UCHAR *lpszProdName);
    
    void GetProdName(UCHAR *lpszNameBuf); // lpszNameBuf[KP_MAX_FNAME_LEN + 1]

//  void StackDump(void);
    
    void GetLogFileName(UCHAR *lpszLogFNameBuf); // lpszFNameBuf[KP_MAX_FNAME_LEN + 1];
    void EncodeLogBuf(UCHAR *pBuffer, int iDataLen);
    
// --------------------   
    void PutLogMessage(const UCHAR *lpszFmt, va_list Args);
    void PutLogMessage(const UCHAR *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage(lpszFmt, argptr);
    }
    void PutLogMessage(const CHAR *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage((const UCHAR *)lpszFmt, argptr);
    }

// --------------------   
    void SendDiagMsg
    (
        const UCHAR *lpszMessageText, // pranešimas klientui 
        bool bSevereError,            // jei False – ne klaida, o tiesiog diag. msg siuntimas, 
                                      //    formuoti atitinkamą ikoną ir kepurės tekstą
        const UCHAR *lpszAddMessage   // papildomas pranešimas apie klaidos kodą ir src failą, 
                                      //    klientui nerodomas, siunčiamas helpdeskui
    );

// --------------------   
    static HRESULT FormatErrorMessage
    (
        const HRESULT lhRetc,
        UCHAR *lpszMsg
    );                         // generates the error message
                               // lpszMsg is used to return back the error text, must
                               //    be not shorter, than KP_MAX_FILE_LIN_LEN bytes
                               // must be defined locally for processing special errors of application
                               // usually calls FormatErrorMessageMain()

    static HRESULT FormatErrorMessageSystem
    (
        long lWindowsErrorCode,
        UCHAR *lpszMsg,
        bool bFullFormat
    );                         // formats windows system error message
                               // bFullFormat == False - tik lietuviškas pranešimas
                               // lpszMsg is used to return back the error text, must
                               //    be not shorter, than KP_MAX_FILE_LIN_LEN bytes
// --------------------   
    void OutputErrorMessage          // outputs error message; calls FormatErrorMessage()
    (
        HRESULT lhRetc,
        const UCHAR *lpszMessageText,  // explanational error text
        bool bSevereError,      // True - pranešimas išvedamas ne tik į log failą, bet ir į ekraną su galimybe išsiųsti diagnostinį pranešimą
        const UCHAR *lpszSourceFile,
        int iSourceLine
    );
    
    void OutputErrorMessage
    (
        HRESULT lhRetc,
        const CHAR *lpszMessageText,
        bool bSevereError,
        const UCHAR *lpszSourceFile,
        int iSourceLine
    ){ OutputErrorMessage(lhRetc, (const UCHAR *)lpszMessageText, bSevereError, lpszSourceFile, iSourceLine); }
    
    void OutputErrorMessage
    (
        HRESULT lhRetc,
        LONG lWindowsErrorCode, // return value of GetLastError() etc.
        bool bSevereError,
        const UCHAR *lpszSourceFile,
        int iSourceLine
    );
    
// --------------------   
    void Catch(const std::exception &e);
};

extern KpErrorClass KpError;

// ----------------------------------------
#endif // #ifdef __cplusplus
#endif // #ifndef kperr_included
