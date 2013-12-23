/* ==================================================
 *
 * kperrno.h
 *
 *    kp error codes
 *
 * 2013-02-22  mp  initial creation
 *
 */

// -------------------------------------------------
#ifndef KPERRNO_INCLUDED
#define KPERRNO_INCLUDED


// ================================================== return codes
#ifndef WIN32

typedef long HRESULT;

#define SUCCEEDED(Status) ((HRESULT)(Status) >= 0)
#define FAILED(Status) ((HRESULT)(Status)<0)

#define MAKE_HRESULT(s,f,c) ((HRESULT)(((unsigned long)(s)<<31)|((unsigned long)(f)<<16)|((unsigned long)(c))))

#define SEVERITY_SUCCESS 0
#define SEVERITY_ERROR 1
#define FACILITY_WINDOWS 8
#define FACILITY_STORAGE 3
#define FACILITY_RPC 1
#define FACILITY_WIN32 7
#define FACILITY_CONTROL 10
#define FACILITY_NULL 0
#define FACILITY_ITF 4
#define FACILITY_DISPATCH 2

// ok
#define S_OK         0 // (MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0))
// invalid parameter
#define E_INVALIDARG (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 1))
// feature not implemented yet
#define E_NOTIMPL    (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 2))
// out of memory
#define E_OUTOFMEMORY ((HRESULT)0x8007000EL)
// illegal function call (at the moment)
#define E_UNEXPECTED ((HRESULT)0x8000FFFFL)
#define E_NOINTERFACE ((HRESULT)0x80004002L)
#define E_POINTER ((HRESULT)0x80004003L)
#define E_HANDLE ((HRESULT)0x80070006L)
// job cancelled
#define E_ABORT ((HRESULT)0x80004004L)
#define E_FAIL ((HRESULT)0x80004005L)
// Access denied
#define E_ACCESSDENIED ((HRESULT)0x80070005L)
#define E_PENDING ((HRESULT)0x8000000AL)

/*
http://research.microsoft.com/en-us/um/redmond/projects/invisible/iunknown.htm

See also AtomicDec IUnknown.QueryInterface IUnknown.AddRef
C++

UINT IUnknown::Release( void )

SCODE Constant
Generic success codes

S_OK 0x0    Generic all OK success used by all methods that return SCODEs.
S_FALSE 0x1    Generic secondary success, indicates last entry or similar.

MMLite error SCODE Constant
MMLite specific error codes

E_UNEXPECTED_ERROR 0x80060000    Object is in a state where the operation is not allowed.
E_OBJECT_NOT_INITIALIZED 0x80060001    Object is in a state where it is unable to service method call.
E_TIMED_OUT 0x80060003    Operation timed out and was not completed. In many cases this is intentional behavior and does not indicate any kind of failure.
E_ALREADY_RESERVED 0x8006000d    Memory region was already reserved. A region cannot be reserved twice.
E_NOT_RESERVED 0x8006000e    Memory region was not reserved. It must be reserved before mappings can be mapped to it.
E_ALREADY_COMMITTED 0x8006000f    A memory region already had a mapping and/or physical pages.
E_NOT_COMMITTED 0x80060010    Operation required a mapping but there was none.
E_TOO_MANY_CONTIGUOUS 0x80060012    The image has too many sections.
E_RESTART 0x80060014    Operation could not be completed atomically and must be restarted.
E_END_OF_DATA 0x80060015    Parser reached maximum content size.
E_PARSE_ERROR 0x80060016    Data format error.
E_SCHEMA_CHECK 0x80060017    Data format error.
E_WOULD_BLOCK 0x80060018    The method is done for now but ought to be restarted in the future.
E_PARSING_ERROR 0x80060020    Invalid input encountered
E_ERROR_RESPONSE_RECEIVED 0x80060021    Invalid input encountered
E_AUTHORIZATION_REQUIRED 0x80060022    The client authorization is lacking (e.g. HTTP 401).
E_NAME_NOT_FOUND E_PATH_NOT_FOUND    The name referred to did not exist in namespace.
E_OBJECT_NOT_FOUND E_ENTRY_NOT_FOUND    Lookup failed.
E_INVALID_METHOD E_INVALID_ORDINAL    Protocol error. Message referred to method not in schema.

MMLite success SCODE Constant
MMLite specific success codes

S_OUTATIME 0x60004    The previous constraint overran its estimate.
S_ALREADY_EXISTS 0x600b7    Entry already existed but was overwritten.
S_BUFFER_TOO_SMALL 0x6007a    The buffer provided was too small. This means usually the size of an out parameter of a method call. Nevertheless the call was completed and the return value was filled in up to the size.
S_NAME_SEARCH_INCOMPLETE 0x6007b    A symbolic link was encountered in the middle of a name resolution when NAME_SPACE_NOFOLLOW was set.
S_NO_RESPONSE 0x6007c    The application already sent a response or will send a response so the server should not do it.
S_MUST_REPLY 0x6007d    The application has generated a response and it should be forwarded to the server. Used by intermediaries that can handle data in either directions.
S_NO_MORE_ENTRIES S_FALSE    Last entry in namespace.

Ole32 SCODE Constant
OLE derived error codes

E_NOT_IMPLEMENTED 0x80040001    The method is not implementation by the server. Same as E_NOTIMPL in Ole.
E_NO_INTERFACE 0x80040002    The server does not support the given interface. In other words the Interface ID given to QueryInterface was not recognized. Same as E_NOINTERFACE in Ole.
E_FAIL 0x80040005    Generic catch-all failure.

Win32 SCODE Constant
Win32 derived error codes

E_FILE_NOT_FOUND 0x80070002    Specified name is not present in namespace.
E_PATH_NOT_FOUND 0x80070003    The name referred to did not exist in namespace.
E_ACCESS_DENIED 0x80070005    Access was denied. For example a write to a read-only file.
E_INVALID_HANDLE 0x80070006    Operation could not be completed because a required object was not available.
E_NOT_ENOUGH_MEMORY 0x80070008    Resource shortage.
E_WRITE_PROTECT 0x80070013    Disk was read-only.
E_BAD_UNIT 0x80070014    Disk error.
E_NOT_READY 0x80070015    Disk error. // "Árenginys nëra pasirengæs" (PK910v/klaida_20120911_Algimantas_Lazauskas, bandant surasti My Documents su SHGetFolderPath())
E_CRC 0x80070017    Disk error.
E_DMA_FAILURE 0x80070018    Driver error.
E_SEEK 0x80070019    Disk error.
E_SECTOR_NOT_FOUND 0x8007001b    Disk error.
E_OUT_OF_STRUCTURES 0x80070054    Allocation from fixed size pool failed. Resource shortage.
E_INVALID_PARAMETER 0x80070057    A method argument had a value not allowed in call.
E_NULL_PARAMETER 0x80070058    A method argument had a value not allowed in call.
E_BUFFER_TOO_SMALL 0x8007007a    The buffer provided was too small. This means usually the size of an out parameter of a method call. The call could not be completed and the out parameters were not updated.
E_MOD_NOT_FOUND 0x8007007e    Module not found.
E_PROC_NOT_FOUND 0x8007007f    Method not found. DLL import was not found in export table.
E_INVALID_ORDINAL 0x800700b6    Method number out of range. DLL entry was not exported.
E_ALREADY_EXISTS 0x800700b7    Entry could not be created because it was already present.
E_INVALID_EXE_SIGNATURE 0x800700bf    Image could not be loaded for execution.
E_EXE_MARKED_INVALID 0x800700c0
E_BAD_EXE_FORMAT 0x800700c1    Image could not be loaded for execution.
E_LOCKED 0x800700d4
E_INCOMPATIBLE_VERSION 0x800700d8    An object's version is incompatible with another object, like between the loader and an executable image.
E_INVALID_ADDRESS 0x800701e7    Pointer argument was not within range.
E_IO_PENDING 0x800703e5    I/O in progress.
E_NOACCESS 0x800703e6
E_MEDIA_CHANGED 0x80070456    Disk error.
E_NO_MEDIA_IN_DRIVE 0x80070458    Disk error.
E_DLL_INIT_FAILED 0x8007045a    Image load failed.
E_FLOPPY_ID_MARK_NOT_FOUND 0x80070462    Disk error.
E_FLOPPY_WRONG_CYLINDER 0x80070463    Disk error.
E_FLOPPY_UNKNOWN_ERROR 0x80070464    Disk error.
E_FLOPPY_BAD_REGISTERS 0x80070465    Disk error.
E_DISK_RECALIBRATE_FAILED 0x80070466    Disk error.
E_DISK_OPERATION_FAILED 0x80070467    Disk error.
E_DISK_RESET_FAILED 0x80070468    Disk error.
E_INTERNAL_ERROR 0x8007054f    Should not happen.
E_ENTRY_NOT_FOUND 0x800706e1    Name was not found in namespace.
E_UNRECOGNIZED_MEDIA 0x800706f9    Disk error.
E_SIG_NOT_FOUND 0x80070715
E_DEVICE_IN_USE 0x80070964    Driver error. Exclusive access.
E_HTTP_ERROR 0x80070965    Driver error. Exclusive access.
*/

#endif // #ifndef WIN32

// Object is busy
// The method can't proceed since a resource needed is currently in use but this ought to be restarted in the future.
#define E_OBJECT_BUSY ((HRESULT)0x80060019L)


// --------------------------------------------------------
// out of memory
#define KP_E_OUTOFMEM         E_OUTOFMEMORY  // (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x01))
// double unget
#define KP_E_DOUBLE_UNGET     (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x02))
// file not found
#define KP_E_FILE_NOT_FOUND   (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x03))
// unable to create file
#define KP_E_DIR_ERROR        (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x04))
// file error
#define KP_E_FERROR           (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x05))
// internal error
#define KP_E_SYSTEM_ERROR     (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x06))
// unexpected end of input file
#define KP_E_EOF              (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x07))
// unexpected input file format
#define KP_E_FILE_FORMAT      (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x08))
// no file open
#define KP_E_NO_FILE          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 +  0x09))
// unknown character
#define KP_E_UNKN_CHR         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0a))
// external error
#define KP_E_COMMAND_ERROR    (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0b))
// buffer overflow
#define KP_E_BUFFER_OVERFLOW  (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0c))
// font undefined
#define KP_E_FONT_UNDEF       (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0d))
// keyword not found
#define KP_E_KWD_NOT_FOUND    (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0e))
// unknown OS version
#define KP_E_UNKNOWN_SYSTEM   (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x0f))
// illegal registration code
#define KP_E_ILL_CODE         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x10))
// job cancelled
#define KP_E_CANCEL           E_ABORT  // (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x011))
// duplicated call to function, illegal recursion etc.
#define KP_E_DOUBLE_CALL      E_PENDING // (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x012))
// timeout when waiting for answer
#define KP_E_TIMEOUT          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x013))
// object not found
#define KP_E_OBJ_NOT_FOUND    (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x014))
// no connection
#define KP_E_NO_CONN          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x015))
// transfer error
#define KP_E_TRANS_ERR        (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x016))
// registration refused
#define KP_E_REFUSED          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x017))
// Access denied
#define KP_E_ACCESS_DENIED    E_ACCESSDENIED    // (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x018))
// illegal character
#define KP_E_ILL_CHR          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x019))
// skip next operation - return code, not error
#define KP_E_SKIP             (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01a))
// division by zero
#define KP_E_DIV_ZERO         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01b))
// negative sqrt() parameter
#define KP_E_ILLMATHARG       (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01c)) // former KP_E_IRRAC
// illegal function call
#define KP_E_ILLFUNC          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01d))
// program not installed
#define KP_E_NOTINST          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01e))
// unexpected message format
#define KP_E_MSG_FORMAT       (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x01f))
// obsolete function
#define KP_E_OBSOLETE         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x020))
// help, forgot an password, etc
#define KP_E_HELP             (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x021))
// negative answer from called function / received IP message
// bendras klaidos kodas visiems neigiamiams HTTP atsakymams; norint konkretinti – KpErrorProcClass::TranslFromHTTP_RetCode(KpSocket::m_iRetCode)
#define KP_E_NEG_ANSW         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x022))
// file changed // pvz., uþsikrëtë virusu
#define KP_E_FILE_CHANGED     (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x023))
// formuojamas diagnostinis praneðimas
#define KP_S_DIAG_MSG         (MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 0x100 + 0x024))
// Neteisingas e-paðto adresas
#define KP_E_BAD_EMAIL        (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x025))
// programa baigta iðsiloginimo procedûra
#define KP_S_LOGOFF           (MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 0x100 + 0x026))
// operacija atlikta sëkmingai (naudojama iðëjimui ið dialogø)
#define KP_S_DONE             (MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x200 + 0x100 + 0x027))
// licence expired
#define KP_E_EXPIRED          (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x028))
// memory fault
// #define KP_E_MEMORY_FAULT     (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x029))
// arithmetic overflow
// #define KP_E_ARITHM_OVERFL    (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x02a))
// unhandled exception
#define KP_E_UNHANDLED_EXCEPTION  (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x100 + 0x02b))


// =========================================
// interaktyviø praneðimø tipai kpwindow.cpp: KpMsgOut()
//
typedef enum
{
    KP_MB_OK,
    KP_MB_GERAI,
    KP_MB_TESTI,
    KP_MB_BAIGTI,
    KP_MB_OK_CANCEL,
    KP_MB_GERAI_ATSAUKTI,
    KP_MB_TESTI_ATSAUKTI,
    KP_MB_YES_NO,
    KP_MB_TAIP_NE,
    KP_MB_GERAI_ATSAUKTI_PAMIRSAU,
    KP_MB_NONE, // tik iðveda praneðimà be mygtukø ir iðkart gráþta
} KpMsgTypes;


#endif // #ifndef KPERRNO_INCLUDED
