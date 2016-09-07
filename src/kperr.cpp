/* -----------------------------------------------
 *
 * kperr.cpp
 *
 *    error processing, debug tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#include "envir.h"

#ifdef _MSC_VER
#define _WINSOCKAPI_ // kad neinkliudintų winsock.h – pjaunasi po to su ws2def.h (inkliudinamas iš WinSock2.h)
#endif

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#ifdef __WIN32__
#include <windows.h>
#ifdef __MINGW32__
#include <ddk\ntapi.h>
#endif
#ifdef _MSC_VER
#include <WinSock2.h>
#endif
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kptree.h"
#include "kpmsg.h"
#include "kpmsg_en.h"
#if (MsgLang == KpLangLt_p) || (MsgLang == KpLangSel_p)
#   include "kpmsg_lt.h"
#endif
#if (MsgLang == KpLangPl_1250_p) || (MsgLang == KpLangPl_p)
#   include "kpmsg_pl_1250.h"
#endif
#if (MsgLang == KpLangPl_1257_p) || (MsgLang == KpLangPl_p)
#   include "kpmsg_pl_1257.h"
#endif
#if (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p) || (MsgLang == KpLangRu_p)
#   include "kpmsg_ru.h"
#endif
#include "kperr.h"
#include "kpstdio.h"
#include "kpsock.h"
#include "kpcapp.h"

using namespace std;


// ------------------------------------ bendri kp programų pranešimai
const unsigned char *KpErrorClass::m_lpszaKpMessages[NumOfKpMessages_25][KpNumOfLangs_2] =
{
    { KP_MSG_TITLE_EN,                    KP_MSG_TITLE_LT,                    KP_MSG_TITLE_PL_1250,                     KP_MSG_TITLE_PL_1257,                     KP_MSG_TITLE_RU,                    KP_MSG_TITLE_EN,                    }, // "Pranešimas"
    { KP_INPUT_TITLE_EN,                  KP_INPUT_TITLE_LT,                  KP_INPUT_TITLE_PL_1250,                   KP_INPUT_TITLE_PL_1257,                   KP_INPUT_TITLE_RU,                  KP_INPUT_TITLE_EN,                  }, // "Įvedimas"

    { KP_MSG_TAIP_EN,                     KP_MSG_TAIP_LT,                     KP_MSG_TAIP_PL_1250,                      KP_MSG_TAIP_PL_1257,                      KP_MSG_TAIP_RU,                     KP_MSG_TAIP_EN,                     }, // "Taip"
    { KP_MSG_YES_EN,                      KP_MSG_YES_LT,                      KP_MSG_YES_PL_1250,                       KP_MSG_YES_PL_1257,                       KP_MSG_YES_RU,                      KP_MSG_YES_EN,                      }, // KP_MSG_TAIP
    { KP_MSG_NE_EN,                       KP_MSG_NE_LT,                       KP_MSG_NE_PL_1250,                        KP_MSG_NE_PL_1257,                        KP_MSG_NE_RU,                       KP_MSG_NE_EN,                       }, // "Ne"
    { KP_MSG_NO_EN,                       KP_MSG_NO_LT,                       KP_MSG_NO_PL_1250,                        KP_MSG_NO_PL_1257,                        KP_MSG_NO_RU,                       KP_MSG_NO_EN,                       }, // KP_MSG_NE
    { KP_MSG_GERAI_EN,                    KP_MSG_GERAI_LT,                    KP_MSG_GERAI_PL_1250,                     KP_MSG_GERAI_PL_1257,                     KP_MSG_GERAI_RU,                    KP_MSG_GERAI_EN,                    }, // "Gerai"
    { KP_MSG_OK_EN,                       KP_MSG_OK_LT,                       KP_MSG_OK_PL_1250,                        KP_MSG_OK_PL_1257,                        KP_MSG_OK_RU,                       KP_MSG_OK_EN,                       }, // KP_MSG_GERAI
    { KP_MSG_ATSAUKTI_EN,                 KP_MSG_ATSAUKTI_LT,                 KP_MSG_ATSAUKTI_PL_1250,                  KP_MSG_ATSAUKTI_PL_1257,                  KP_MSG_ATSAUKTI_RU,                 KP_MSG_ATSAUKTI_EN,                 }, // "Atšaukti"
    { KP_MSG_CANCEL_EN,                   KP_MSG_CANCEL_LT,                   KP_MSG_CANCEL_PL_1250,                    KP_MSG_CANCEL_PL_1257,                    KP_MSG_CANCEL_RU,                   KP_MSG_CANCEL_EN,                   }, // KP_MSG_ATSAUKTI
    { KP_MSG_TESTI_EN,                    KP_MSG_TESTI_LT,                    KP_MSG_TESTI_PL_1250,                     KP_MSG_TESTI_PL_1257,                     KP_MSG_TESTI_RU,                    KP_MSG_TESTI_EN,                    }, // "Toliau"
    { KP_MSG_BAIGTI_EN,                   KP_MSG_BAIGTI_LT,                   KP_MSG_BAIGTI_PL_1250,                    KP_MSG_BAIGTI_PL_1257,                    KP_MSG_BAIGTI_RU,                   KP_MSG_BAIGTI_EN,                   }, // "Baigti"
    { KP_MSG_PAMIRSAU_SLAPTAZODI_EN,      KP_MSG_PAMIRSAU_SLAPTAZODI_LT,      KP_MSG_PAMIRSAU_SLAPTAZODI_PL_1250,       KP_MSG_PAMIRSAU_SLAPTAZODI_PL_1257,       KP_MSG_PAMIRSAU_SLAPTAZODI_RU,      KP_MSG_PAMIRSAU_SLAPTAZODI_EN,      }, // "Pamiršau slaptažodį"

    { KP_MSG_ERROR_EN,                    KP_MSG_ERROR_LT,                    KP_MSG_ERROR_PL_1250,                     KP_MSG_ERROR_PL_1257,                     KP_MSG_ERROR_RU,                    KP_MSG_ERROR_RU,                    }, // "Klaida"
    { KP_MSG_WARNING_EN,                  KP_MSG_WARNING_LT,                  KP_MSG_WARNING_PL_1250,                   KP_MSG_WARNING_PL_1257,                   KP_MSG_WARNING_RU,                  KP_MSG_WARNING_RU,                  }, // "Perspėjimas"
    { KP_MSG_FILE_LINE_EN,                KP_MSG_FILE_LINE_LT,                KP_MSG_FILE_LINE_PL_1250,                 KP_MSG_FILE_LINE_PL_1257,                 KP_MSG_FILE_LINE_RU,                KP_MSG_FILE_LINE_RU,                }, // ", failas:%s, eilutė:%d"
    { KP_MSG_ENTRY_ID_EN,                 KP_MSG_ENTRY_ID_LT,                 KP_MSG_ENTRY_ID_PL_1250,                  KP_MSG_ENTRY_ID_PL_1257,                  KP_MSG_ENTRY_ID_RU,                 KP_MSG_ENTRY_ID_RU,                 }, // ", Įrašo nr.:%ld"
    { KP_MSG_ENTRY_EN,                    KP_MSG_ENTRY_LT,                    KP_MSG_ENTRY_PL_1250,                     KP_MSG_ENTRY_PL_1257,                     KP_MSG_ENTRY_RU,                    KP_MSG_ENTRY_RU,                    }, // ", Įrašas: %s"

    { KP_MSG_NO_STANDARD_PROG_EN,         KP_MSG_NO_STANDARD_PROG_LT,         KP_MSG_NO_STANDARD_PROG_PL_1250,          KP_MSG_NO_STANDARD_PROG_PL_1257,          KP_MSG_NO_STANDARD_PROG_RU,         KP_MSG_NO_STANDARD_PROG_RU,         }, // "Nerasta programa skirta atverti šio tipo failus"
    { KP_MSG_WND_NOT_FOUND_EN,            KP_MSG_WND_NOT_FOUND_LT,            KP_MSG_WND_NOT_FOUND_PL_1250,             KP_MSG_WND_NOT_FOUND_PL_1257,             KP_MSG_WND_NOT_FOUND_RU,            KP_MSG_WND_NOT_FOUND_RU,            }, // "Langas nerastas"
    { KP_MSG_PID_NOT_FOUND_EN,            KP_MSG_PID_NOT_FOUND_LT,            KP_MSG_PID_NOT_FOUND_PL_1250,             KP_MSG_PID_NOT_FOUND_PL_1257,             KP_MSG_PID_NOT_FOUND_RU,            KP_MSG_PID_NOT_FOUND_RU,            }, // "Nerastas proceso identifikatorius"
    { KP_MSG_NO_SOCKET_EN,                KP_MSG_NO_SOCKET_LT,                KP_MSG_NO_SOCKET_PL_1250,                 KP_MSG_NO_SOCKET_PL_1257,                 KP_MSG_NO_SOCKET_RU,                KP_MSG_NO_SOCKET_RU,                }, // "Jungtis dar nesukurta"
    { KP_MSG_SOCK_UNRESOLVED_EN,          KP_MSG_SOCK_UNRESOLVED_LT,          KP_MSG_SOCK_UNRESOLVED_PL_1250,           KP_MSG_SOCK_UNRESOLVED_PL_1257,           KP_MSG_SOCK_UNRESOLVED_RU,          KP_MSG_SOCK_UNRESOLVED_RU,          }, // "Tarnybines stoties adresas dar nesurastas"

    { KP_MSG_ERR_OK_EN,                   KP_MSG_ERR_OK_LT,                   KP_MSG_ERR_OK_PL_1250,                    KP_MSG_ERR_OK_PL_1257,                    KP_MSG_ERR_OK_RU,                   KP_MSG_ERR_OK_RU,                   }, // "Operacija atlikta sėkmingai" // !!!
    { KP_MSG_INVALIDARG_EN,               KP_MSG_INVALIDARG_LT,               KP_MSG_INVALIDARG_PL_1250,                KP_MSG_INVALIDARG_PL_1257,                KP_MSG_INVALIDARG_RU,               KP_MSG_INVALIDARG_RU,               }, // "Neteisingi parametrai"
    { KP_MSG_NOTIMPL_EN,                  KP_MSG_NOTIMPL_LT,                  KP_MSG_NOTIMPL_PL_1250,                   KP_MSG_NOTIMPL_PL_1257,                   KP_MSG_NOTIMPL_RU,                  KP_MSG_NOTIMPL_RU,                  }, // "Priedas neįdiegtas"
    { KP_MSG_UNEXPECTED_EN,               KP_MSG_UNEXPECTED_LT,               KP_MSG_UNEXPECTED_PL_1250,                KP_MSG_UNEXPECTED_PL_1257,                KP_MSG_UNEXPECTED_RU,               KP_MSG_UNEXPECTED_RU,               }, // "Netikėtas kreipinys į sąsają"
    { KP_MSG_FERROR_EN,                   KP_MSG_FERROR_LT,                   KP_MSG_FERROR_PL_1250,                    KP_MSG_FERROR_PL_1257,                    KP_MSG_FERROR_RU,                   KP_MSG_FERROR_RU,                   }, // "Failo skaitymo/rašymo klaida"
    { KP_MSG_SYSTEM_ERROR_EN,             KP_MSG_SYSTEM_ERROR_LT,             KP_MSG_SYSTEM_ERROR_PL_1250,              KP_MSG_SYSTEM_ERROR_PL_1257,              KP_MSG_SYSTEM_ERROR_RU,             KP_MSG_SYSTEM_ERROR_RU,             }, // "Klaida sistemoje"
    { KP_MSG_EOF_EN,                      KP_MSG_EOF_LT,                      KP_MSG_EOF_PL_1250,                       KP_MSG_EOF_PL_1257,                       KP_MSG_EOF_RU,                      KP_MSG_EOF_RU,                      }, // "Neteisinga failo pabaiga"
    { KP_MSG_FILE_FORMAT_EN,              KP_MSG_FILE_FORMAT_LT,              KP_MSG_FILE_FORMAT_PL_1250,               KP_MSG_FILE_FORMAT_PL_1257,               KP_MSG_FILE_FORMAT_RU,              KP_MSG_FILE_FORMAT_RU,              }, // "Neteisingas failo formatas"
    { KP_MSG_FILE_NOT_FOUND_EN,           KP_MSG_FILE_NOT_FOUND_LT,           KP_MSG_FILE_NOT_FOUND_PL_1250,            KP_MSG_FILE_NOT_FOUND_PL_1257,            KP_MSG_FILE_NOT_FOUND_RU,           KP_MSG_FILE_NOT_FOUND_RU,           }, // "Failas nerastas"
    { KP_MSG_DIR_ERROR_EN,                KP_MSG_DIR_ERROR_LT,                KP_MSG_DIR_ERROR_PL_1250,                 KP_MSG_DIR_ERROR_PL_1257,                 KP_MSG_DIR_ERROR_RU,                KP_MSG_DIR_ERROR_RU,                }, // "Nepavyko atverti/sukurti failo"
    { KP_MSG_OUTOFMEM_EN,                 KP_MSG_OUTOFMEM_LT,                 KP_MSG_OUTOFMEM_PL_1250,                  KP_MSG_OUTOFMEM_PL_1257,                  KP_MSG_OUTOFMEM_RU,                 KP_MSG_OUTOFMEM_RU,                 }, // "Trūksta atminties"
    { KP_MSG_NO_FILE_EN,                  KP_MSG_NO_FILE_LT,                  KP_MSG_NO_FILE_PL_1250,                   KP_MSG_NO_FILE_PL_1257,                   KP_MSG_NO_FILE_RU,                  KP_MSG_NO_FILE_RU,                  }, // "Failas neatvertas"
    { KP_MSG_DOUBLE_UNGET_EN,             KP_MSG_DOUBLE_UNGET_LT,             KP_MSG_DOUBLE_UNGET_PL_1250,              KP_MSG_DOUBLE_UNGET_PL_1257,              KP_MSG_DOUBLE_UNGET_RU,             KP_MSG_DOUBLE_UNGET_RU,             }, // "Dvigubas įvedimo grąžinimas"
    { KP_MSG_UNKN_CHR_EN,                 KP_MSG_UNKN_CHR_LT,                 KP_MSG_UNKN_CHR_PL_1250,                  KP_MSG_UNKN_CHR_PL_1257,                  KP_MSG_UNKN_CHR_RU,                 KP_MSG_UNKN_CHR_RU,                 }, // "Neatpažintas simbolis"
    { KP_MSG_COMMAND_ERROR_EN,            KP_MSG_COMMAND_ERROR_LT,            KP_MSG_COMMAND_ERROR_PL_1250,             KP_MSG_COMMAND_ERROR_PL_1257,             KP_MSG_COMMAND_ERROR_RU,            KP_MSG_COMMAND_ERROR_RU,            }, // "Išorinė klaida"
    { KP_MSG_BUFFER_OVERFLOW_EN,          KP_MSG_BUFFER_OVERFLOW_LT,          KP_MSG_BUFFER_OVERFLOW_PL_1250,           KP_MSG_BUFFER_OVERFLOW_PL_1257,           KP_MSG_BUFFER_OVERFLOW_RU,          KP_MSG_BUFFER_OVERFLOW_RU,          }, // "Persipildė buferis"
    { KP_MSG_FONT_UNDEF_EN,               KP_MSG_FONT_UNDEF_LT,               KP_MSG_FONT_UNDEF_PL_1250,                KP_MSG_FONT_UNDEF_PL_1257,                KP_MSG_FONT_UNDEF_RU,               KP_MSG_FONT_UNDEF_RU,               }, // "Neapibrėžtas šriftas"
    { KP_MSG_KWD_NOT_FOUND_EN,            KP_MSG_KWD_NOT_FOUND_LT,            KP_MSG_KWD_NOT_FOUND_PL_1250,             KP_MSG_KWD_NOT_FOUND_PL_1257,             KP_MSG_KWD_NOT_FOUND_RU,            KP_MSG_KWD_NOT_FOUND_RU,            }, // "Raktinis žodis nerastas"
    { KP_MSG_UNKNOWN_SYSTEM_EN,           KP_MSG_UNKNOWN_SYSTEM_LT,           KP_MSG_UNKNOWN_SYSTEM_PL_1250,            KP_MSG_UNKNOWN_SYSTEM_PL_1257,            KP_MSG_UNKNOWN_SYSTEM_RU,           KP_MSG_UNKNOWN_SYSTEM_RU,           }, // "Operacinė sistema neatpažinta"
    { KP_MSG_ILL_CODE_EN,                 KP_MSG_ILL_CODE_LT,                 KP_MSG_ILL_CODE_PL_1250,                  KP_MSG_ILL_CODE_PL_1257,                  KP_MSG_ILL_CODE_RU,                 KP_MSG_ILL_CODE_RU,                 }, // "Klaidingas registracijos kodas"
    { KP_MSG_CANCELLED_EN,                KP_MSG_CANCELLED_LT,                KP_MSG_CANCELLED_PL_1250,                 KP_MSG_CANCELLED_PL_1257,                 KP_MSG_CANCELLED_RU,                KP_MSG_CANCELLED_RU,                }, // "Operacija nutraukta"
    { KP_MSG_DOUBLE_CALL_EN,              KP_MSG_DOUBLE_CALL_LT,              KP_MSG_DOUBLE_CALL_PL_1250,               KP_MSG_DOUBLE_CALL_PL_1257,               KP_MSG_DOUBLE_CALL_RU,              KP_MSG_DOUBLE_CALL_RU,              }, // "Dvigubas iškvietimas"
    { KP_MSG_TIMEOUT_EN,                  KP_MSG_TIMEOUT_LT,                  KP_MSG_TIMEOUT_PL_1250,                   KP_MSG_TIMEOUT_PL_1257,                   KP_MSG_TIMEOUT_RU,                  KP_MSG_TIMEOUT_RU,                  }, // "Viršytas laukimo laikas"
    { KP_MSG_OBJ_NOT_FOUND_EN,            KP_MSG_OBJ_NOT_FOUND_LT,            KP_MSG_OBJ_NOT_FOUND_PL_1250,             KP_MSG_OBJ_NOT_FOUND_PL_1257,             KP_MSG_OBJ_NOT_FOUND_RU,            KP_MSG_OBJ_NOT_FOUND_RU,            }, // "Objektas nerastas"
    { KP_MSG_NO_CONN_EN,                  KP_MSG_NO_CONN_LT,                  KP_MSG_NO_CONN_PL_1250,                   KP_MSG_NO_CONN_PL_1257,                   KP_MSG_NO_CONN_RU,                  KP_MSG_NO_CONN_RU,                  }, // "Nėra ryšio"

    { KP_MSG_TRANS_ERR_EN,                KP_MSG_TRANS_ERR_LT,                KP_MSG_TRANS_ERR_PL_1250,                 KP_MSG_TRANS_ERR_PL_1257,                 KP_MSG_TRANS_ERR_RU,                KP_MSG_TRANS_ERR_RU,                }, // "Perdavimo klaida"
    { KP_MSG_TRANS_ERR_1_EN,              KP_MSG_TRANS_ERR_1_LT,              KP_MSG_TRANS_ERR_1_PL_1250,               KP_MSG_TRANS_ERR_1_PL_1257,               KP_MSG_TRANS_ERR_1_RU,              KP_MSG_TRANS_ERR_1_RU,              }, // "Ryšio klaida, pakartokite siuntimo procedūrą"

    { KP_MSG_REFUSED_EN,                  KP_MSG_REFUSED_LT,                  KP_MSG_REFUSED_PL_1250,                   KP_MSG_REFUSED_PL_1257,                   KP_MSG_REFUSED_RU,                  KP_MSG_REFUSED_RU,                  }, // "Registracija atmesta"
    { KP_MSG_ACCESS_DENIED_EN,            KP_MSG_ACCESS_DENIED_LT,            KP_MSG_ACCESS_DENIED_PL_1250,             KP_MSG_ACCESS_DENIED_PL_1257,             KP_MSG_ACCESS_DENIED_RU,            KP_MSG_ACCESS_DENIED_RU,            }, // "Neleista prisijungti"
    { KP_MSG_ILLEGAL_CHARACTER_EN,        KP_MSG_ILLEGAL_CHARACTER_LT,        KP_MSG_ILLEGAL_CHARACTER_PL_1250,         KP_MSG_ILLEGAL_CHARACTER_PL_1257,         KP_MSG_ILLEGAL_CHARACTER_RU,        KP_MSG_ILLEGAL_CHARACTER_RU,        }, // "Neleistinas simbolis"
    { KP_MSG_DIV_ZERO_EN,                 KP_MSG_DIV_ZERO_LT,                 KP_MSG_DIV_ZERO_PL_1250,                  KP_MSG_DIV_ZERO_PL_1257,                  KP_MSG_DIV_ZERO_RU,                 KP_MSG_DIV_ZERO_RU,                 }, // "Dalyba iš nulio"
    { KP_MSG_ILLMATHARG_EN,               KP_MSG_ILLMATHARG_LT,               KP_MSG_ILLMATHARG_PL_1250,                KP_MSG_ILLMATHARG_PL_1257,                KP_MSG_ILLMATHARG_RU,               KP_MSG_ILLMATHARG_RU,               }, // "Neleistinas matematinės funkcijos argumentas" // "Šaknis iš neigiamo skaičiaus"
    { KP_MSG_ILLFUNC_EN,                  KP_MSG_ILLFUNC_LT,                  KP_MSG_ILLFUNC_PL_1250,                   KP_MSG_ILLFUNC_PL_1257,                   KP_MSG_ILLFUNC_RU,                  KP_MSG_ILLFUNC_RU,                  }, // "Neleistina operacija" // illegal function call (at the moment)

    { KP_MSG_NOTINST_EN,                  KP_MSG_NOTINST_LT,                  KP_MSG_NOTINST_PL_1250,                   KP_MSG_NOTINST_PL_1257,                   KP_MSG_NOTINST_RU,                  KP_MSG_NOTINST_RU,                  }, // "Programa neįdiegta arba diegimas sugedo, pakartokite diegimo procedūrą"
    { KP_MSG_NOTINST_S_EN,                KP_MSG_NOTINST_S_LT,                KP_MSG_NOTINST_S_PL_1250,                 KP_MSG_NOTINST_S_PL_1257,                 KP_MSG_NOTINST_S_RU,                KP_MSG_NOTINST_S_RU,                }, // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
    { KP_MSG_NOTINST_DELETE_EN,           KP_MSG_NOTINST_DELETE_LT,           KP_MSG_NOTINST_DELETE_PL_1250,            KP_MSG_NOTINST_DELETE_PL_1257,            KP_MSG_NOTINST_DELETE_RU,           KP_MSG_NOTINST_DELETE_RU,           }, // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

    { KP_MSG_MSG_FORMAT_EN,               KP_MSG_MSG_FORMAT_LT,               KP_MSG_MSG_FORMAT_PL_1250,                KP_MSG_MSG_FORMAT_PL_1257,                KP_MSG_MSG_FORMAT_RU,               KP_MSG_MSG_FORMAT_RU,               }, // "Neteisingas pranešimo formatas"
    { KP_MSG_OBSOLETE_EN,                 KP_MSG_OBSOLETE_LT,                 KP_MSG_OBSOLETE_PL_1250,                  KP_MSG_OBSOLETE_PL_1257,                  KP_MSG_OBSOLETE_RU,                 KP_MSG_OBSOLETE_RU,                 }, // "Pasenusi funkcija"
    { KP_MSG_ERROR_HELP_EN,               KP_MSG_ERROR_HELP_LT,               KP_MSG_ERROR_HELP_PL_1250,                KP_MSG_ERROR_HELP_PL_1257,                KP_MSG_ERROR_HELP_RU,               KP_MSG_ERROR_HELP_RU,               }, // ".  Dėl techninės pagalbos kreipkitės elektroniniu paštu, adresu tech@tev.lt, prie laiško prikabinkite failą %s"
    { KP_MSG_ERROR_HELP_REST_EN,          KP_MSG_ERROR_HELP_REST_LT,          KP_MSG_ERROR_HELP_REST_PL_1250,           KP_MSG_ERROR_HELP_REST_PL_1257,           KP_MSG_ERROR_HELP_REST_RU,          KP_MSG_ERROR_HELP_REST_RU,          }, // ".  Dėl techninės pagalbos kreipkitės elektroniniu paštu, adresu tech@tev.lt, prie laiško prikabinkite failą %s"
    { KP_MSG_WSAEACCES_EN,                KP_MSG_WSAEACCES_LT,                KP_MSG_WSAEACCES_PL_1250,                 KP_MSG_WSAEACCES_PL_1257,                 KP_MSG_WSAEACCES_RU,                KP_MSG_WSAEACCES_RU,                }, // "Teisės nesuteiktos"
    { KP_MSG_WSAEADDRINUSE_EN,            KP_MSG_WSAEADDRINUSE_LT,            KP_MSG_WSAEADDRINUSE_PL_1250,             KP_MSG_WSAEADDRINUSE_PL_1257,             KP_MSG_WSAEADDRINUSE_RU,            KP_MSG_WSAEADDRINUSE_RU,            }, // "Adresas jau naudojamas"
    { KP_MSG_WSAEADDRNOTAVAIL_EN,         KP_MSG_WSAEADDRNOTAVAIL_LT,         KP_MSG_WSAEADDRNOTAVAIL_PL_1250,          KP_MSG_WSAEADDRNOTAVAIL_PL_1257,          KP_MSG_WSAEADDRNOTAVAIL_RU,         KP_MSG_WSAEADDRNOTAVAIL_RU,         }, // "Prašomas adresas negali būti priskirtas"
    { KP_MSG_WSAEAFNOSUPPORT_EN,          KP_MSG_WSAEAFNOSUPPORT_LT,          KP_MSG_WSAEAFNOSUPPORT_PL_1250,           KP_MSG_WSAEAFNOSUPPORT_PL_1257,           KP_MSG_WSAEAFNOSUPPORT_RU,          KP_MSG_WSAEAFNOSUPPORT_RU,          }, // "Adresų šeimos grupė nepalaikoma protokolo"
    { KP_MSG_WSAEALREADY_EN,              KP_MSG_WSAEALREADY_LT,              KP_MSG_WSAEALREADY_PL_1250,               KP_MSG_WSAEALREADY_PL_1257,               KP_MSG_WSAEALREADY_RU,              KP_MSG_WSAEALREADY_RU,              }, // "Operacija jau vykdoma"
    { KP_MSG_WSAECONNABORTED_EN,          KP_MSG_WSAECONNABORTED_LT,          KP_MSG_WSAECONNABORTED_PL_1250,           KP_MSG_WSAECONNABORTED_PL_1257,           KP_MSG_WSAECONNABORTED_RU,          KP_MSG_WSAECONNABORTED_RU,          }, // "Programa iššaukė ryšio nutraukimą"
    { KP_MSG_WSAECONNREFUSED_EN,          KP_MSG_WSAECONNREFUSED_LT,          KP_MSG_WSAECONNREFUSED_PL_1250,           KP_MSG_WSAECONNREFUSED_PL_1257,           KP_MSG_WSAECONNREFUSED_RU,          KP_MSG_WSAECONNREFUSED_RU,          }, // "Susijungimas atmestas"
    { KP_MSG_WSAECONNRESET_EN,            KP_MSG_WSAECONNRESET_LT,            KP_MSG_WSAECONNRESET_PL_1250,             KP_MSG_WSAECONNRESET_PL_1257,             KP_MSG_WSAECONNRESET_RU,            KP_MSG_WSAECONNRESET_RU,            }, // "Sujungimas nutrauktas"
    { KP_MSG_WSAEDESTADDRREQ_EN,          KP_MSG_WSAEDESTADDRREQ_LT,          KP_MSG_WSAEDESTADDRREQ_PL_1250,           KP_MSG_WSAEDESTADDRREQ_PL_1257,           KP_MSG_WSAEDESTADDRREQ_RU,          KP_MSG_WSAEDESTADDRREQ_RU,          }, // "Būtinas kreities adresas"
    { KP_MSG_WSAEFAULT_EN,                KP_MSG_WSAEFAULT_LT,                KP_MSG_WSAEFAULT_PL_1250,                 KP_MSG_WSAEFAULT_PL_1257,                 KP_MSG_WSAEFAULT_RU,                KP_MSG_WSAEFAULT_RU,                }, // "Neteisingas adresas"
    { KP_MSG_WSAEHOSTDOWN_EN,             KP_MSG_WSAEHOSTDOWN_LT,             KP_MSG_WSAEHOSTDOWN_PL_1250,              KP_MSG_WSAEHOSTDOWN_PL_1257,              KP_MSG_WSAEHOSTDOWN_RU,             KP_MSG_WSAEHOSTDOWN_RU,             }, // "Serveris laikinai neveikia"
    { KP_MSG_WSAEHOSTUNREACH_EN,          KP_MSG_WSAEHOSTUNREACH_LT,          KP_MSG_WSAEHOSTUNREACH_PL_1250,           KP_MSG_WSAEHOSTUNREACH_PL_1257,           KP_MSG_WSAEHOSTUNREACH_RU,          KP_MSG_WSAEHOSTUNREACH_RU,          }, // "Serveris nepasiekiamas"
    { KP_MSG_WSAEINPROGRESS_EN,           KP_MSG_WSAEINPROGRESS_LT,           KP_MSG_WSAEINPROGRESS_PL_1250,            KP_MSG_WSAEINPROGRESS_PL_1257,            KP_MSG_WSAEINPROGRESS_RU,           KP_MSG_WSAEINPROGRESS_RU,           }, // "Operacija vykdoma"
    { KP_MSG_WSAEINTR_EN,                 KP_MSG_WSAEINTR_LT,                 KP_MSG_WSAEINTR_PL_1250,                  KP_MSG_WSAEINTR_PL_1257,                  KP_MSG_WSAEINTR_RU,                 KP_MSG_WSAEINTR_RU,                 }, // "Funkcija nutraukta"
    { KP_MSG_WSAEINVAL_EN,                KP_MSG_WSAEINVAL_LT,                KP_MSG_WSAEINVAL_PL_1250,                 KP_MSG_WSAEINVAL_PL_1257,                 KP_MSG_WSAEINVAL_RU,                KP_MSG_WSAEINVAL_RU,                }, // "Neteisingi parametrai"
    { KP_MSG_WSAEISCONN_EN,               KP_MSG_WSAEISCONN_LT,               KP_MSG_WSAEISCONN_PL_1250,                KP_MSG_WSAEISCONN_PL_1257,                KP_MSG_WSAEISCONN_RU,               KP_MSG_WSAEISCONN_RU,               }, // "Susijungimas jau įvykęs"
    { KP_MSG_WSAEMFILE_EN,                KP_MSG_WSAEMFILE_LT,                KP_MSG_WSAEMFILE_PL_1250,                 KP_MSG_WSAEMFILE_PL_1257,                 KP_MSG_WSAEMFILE_RU,                KP_MSG_WSAEMFILE_RU,                }, // "Perdaug atvertų failų"
    { KP_MSG_WSAEMSGSIZE_EN,              KP_MSG_WSAEMSGSIZE_LT,              KP_MSG_WSAEMSGSIZE_PL_1250,               KP_MSG_WSAEMSGSIZE_PL_1257,               KP_MSG_WSAEMSGSIZE_RU,              KP_MSG_WSAEMSGSIZE_RU,              }, // "Perdaug ilgas pranešimas"
    { KP_MSG_WSAENETDOWN_EN,              KP_MSG_WSAENETDOWN_LT,              KP_MSG_WSAENETDOWN_PL_1250,               KP_MSG_WSAENETDOWN_PL_1257,               KP_MSG_WSAENETDOWN_RU,              KP_MSG_WSAENETDOWN_RU,              }, // "Tinklas neveikia"
    { KP_MSG_WSAENETRESET_EN,             KP_MSG_WSAENETRESET_LT,             KP_MSG_WSAENETRESET_PL_1250,              KP_MSG_WSAENETRESET_PL_1257,              KP_MSG_WSAENETRESET_RU,             KP_MSG_WSAENETRESET_RU,             }, // "Atsijungė nuo tinklo"
    { KP_MSG_WSAENETUNREACH_EN,           KP_MSG_WSAENETUNREACH_LT,           KP_MSG_WSAENETUNREACH_PL_1250,            KP_MSG_WSAENETUNREACH_PL_1257,            KP_MSG_WSAENETUNREACH_RU,           KP_MSG_WSAENETUNREACH_RU,           }, // "Tinklas nepasiekiamas"
    { KP_MSG_WSAENOBUFS_EN,               KP_MSG_WSAENOBUFS_LT,               KP_MSG_WSAENOBUFS_PL_1250,                KP_MSG_WSAENOBUFS_PL_1257,                KP_MSG_WSAENOBUFS_RU,               KP_MSG_WSAENOBUFS_RU,               }, // "Trūksta vietos buferyje"
    { KP_MSG_WSAENOPROTOOPT_EN,           KP_MSG_WSAENOPROTOOPT_LT,           KP_MSG_WSAENOPROTOOPT_PL_1250,            KP_MSG_WSAENOPROTOOPT_PL_1257,            KP_MSG_WSAENOPROTOOPT_RU,           KP_MSG_WSAENOPROTOOPT_RU,           }, // "Neteisinga protokolo parinktis"
    { KP_MSG_WSAENOTCONN_EN,              KP_MSG_WSAENOTCONN_LT,              KP_MSG_WSAENOTCONN_PL_1250,               KP_MSG_WSAENOTCONN_PL_1257,               KP_MSG_WSAENOTCONN_RU,              KP_MSG_WSAENOTCONN_RU,              }, // "Sujungimas nepavyko"
    { KP_MSG_WSAENOTSOCK_EN,              KP_MSG_WSAENOTSOCK_LT,              KP_MSG_WSAENOTSOCK_PL_1250,               KP_MSG_WSAENOTSOCK_PL_1257,               KP_MSG_WSAENOTSOCK_RU,              KP_MSG_WSAENOTSOCK_RU,              }, // "Socket operation on non-socket"
    { KP_MSG_WSAEOPNOTSUPP_EN,            KP_MSG_WSAEOPNOTSUPP_LT,            KP_MSG_WSAEOPNOTSUPP_PL_1250,             KP_MSG_WSAEOPNOTSUPP_PL_1257,             KP_MSG_WSAEOPNOTSUPP_RU,            KP_MSG_WSAEOPNOTSUPP_RU,            }, // "Operacija negali būti atlikta"
    { KP_MSG_WSAEPFNOSUPPORT_EN,          KP_MSG_WSAEPFNOSUPPORT_LT,          KP_MSG_WSAEPFNOSUPPORT_PL_1250,           KP_MSG_WSAEPFNOSUPPORT_PL_1257,           KP_MSG_WSAEPFNOSUPPORT_RU,          KP_MSG_WSAEPFNOSUPPORT_RU,          }, // "Protokolo šeima nepalaikoma"
    { KP_MSG_WSAEPROCLIM_EN,              KP_MSG_WSAEPROCLIM_LT,              KP_MSG_WSAEPROCLIM_PL_1250,               KP_MSG_WSAEPROCLIM_PL_1257,               KP_MSG_WSAEPROCLIM_RU,              KP_MSG_WSAEPROCLIM_RU,              }, // "Perdaug procesų"
    { KP_MSG_WSAEPROTONOSUPPORT_EN,       KP_MSG_WSAEPROTONOSUPPORT_LT,       KP_MSG_WSAEPROTONOSUPPORT_PL_1250,        KP_MSG_WSAEPROTONOSUPPORT_PL_1257,        KP_MSG_WSAEPROTONOSUPPORT_RU,       KP_MSG_WSAEPROTONOSUPPORT_RU,       }, // "Protokolas nepalaikomas"
    { KP_MSG_WSAEPROTOTYPE_EN,            KP_MSG_WSAEPROTOTYPE_LT,            KP_MSG_WSAEPROTOTYPE_PL_1250,             KP_MSG_WSAEPROTOTYPE_PL_1257,             KP_MSG_WSAEPROTOTYPE_RU,            KP_MSG_WSAEPROTOTYPE_RU,            }, // "Neteisingas protokolo sujungimo tipas"
    { KP_MSG_WSAESHUTDOWN_EN,             KP_MSG_WSAESHUTDOWN_LT,             KP_MSG_WSAESHUTDOWN_PL_1250,              KP_MSG_WSAESHUTDOWN_PL_1257,              KP_MSG_WSAESHUTDOWN_RU,             KP_MSG_WSAESHUTDOWN_RU,             }, // "Siuntimas nebegalimas, sujungimas nutrauktas"
    { KP_MSG_WSAESOCKTNOSUPPORT_EN,       KP_MSG_WSAESOCKTNOSUPPORT_LT,       KP_MSG_WSAESOCKTNOSUPPORT_PL_1250,        KP_MSG_WSAESOCKTNOSUPPORT_PL_1257,        KP_MSG_WSAESOCKTNOSUPPORT_RU,       KP_MSG_WSAESOCKTNOSUPPORT_RU,       }, // "Sujungimo tipas nepalaikomas"
    { KP_MSG_WSAETIMEDOUT_EN,             KP_MSG_WSAETIMEDOUT_LT,             KP_MSG_WSAETIMEDOUT_PL_1250,              KP_MSG_WSAETIMEDOUT_PL_1257,              KP_MSG_WSAETIMEDOUT_RU,             KP_MSG_WSAETIMEDOUT_RU,             }, // "Maksimalus sujungimo laukimo laikas viršytas"
    { KP_MSG_WSATYPE_NOT_FOUND_EN,        KP_MSG_WSATYPE_NOT_FOUND_LT,        KP_MSG_WSATYPE_NOT_FOUND_PL_1250,         KP_MSG_WSATYPE_NOT_FOUND_PL_1257,         KP_MSG_WSATYPE_NOT_FOUND_RU,        KP_MSG_WSATYPE_NOT_FOUND_RU,        }, // "Klasės tipas nerastas"
    { KP_MSG_WSAEWOULDBLOCK_EN,           KP_MSG_WSAEWOULDBLOCK_LT,           KP_MSG_WSAEWOULDBLOCK_PL_1250,            KP_MSG_WSAEWOULDBLOCK_PL_1257,            KP_MSG_WSAEWOULDBLOCK_RU,           KP_MSG_WSAEWOULDBLOCK_RU,           }, // "Šaltinis laikinai nepasiekiamas"
    { KP_MSG_WSAHOST_NOT_FOUND_EN,        KP_MSG_WSAHOST_NOT_FOUND_LT,        KP_MSG_WSAHOST_NOT_FOUND_PL_1250,         KP_MSG_WSAHOST_NOT_FOUND_PL_1257,         KP_MSG_WSAHOST_NOT_FOUND_RU,        KP_MSG_WSAHOST_NOT_FOUND_RU,        }, // "Serveris nerastas"
    { KP_MSG_WSA_INVALID_HANDLE_EN,       KP_MSG_WSA_INVALID_HANDLE_LT,       KP_MSG_WSA_INVALID_HANDLE_PL_1250,        KP_MSG_WSA_INVALID_HANDLE_PL_1257,        KP_MSG_WSA_INVALID_HANDLE_RU,       KP_MSG_WSA_INVALID_HANDLE_RU,       }, // "Klaidingas objekto valdiklis" // "Klaidingas pasirinkto įvykio objekto valdiklis"
    { KP_MSG_WSA_INVALID_PARAMETER_EN,    KP_MSG_WSA_INVALID_PARAMETER_LT,    KP_MSG_WSA_INVALID_PARAMETER_PL_1250,     KP_MSG_WSA_INVALID_PARAMETER_PL_1257,     KP_MSG_WSA_INVALID_PARAMETER_RU,    KP_MSG_WSA_INVALID_PARAMETER_RU,    }, // "Neteisingi parametrai" // "Neteisingi vienas ar daugiau parametrų"
    { KP_MSG_WSAINVALIDPROCTABLE_EN,      KP_MSG_WSAINVALIDPROCTABLE_LT,      KP_MSG_WSAINVALIDPROCTABLE_PL_1250,       KP_MSG_WSAINVALIDPROCTABLE_PL_1257,       KP_MSG_WSAINVALIDPROCTABLE_RU,      KP_MSG_WSAINVALIDPROCTABLE_RU,      }, // "Klaidinga procedūrų lentelė"
    { KP_MSG_WSAINVALIDPROVIDER_EN,       KP_MSG_WSAINVALIDPROVIDER_LT,       KP_MSG_WSAINVALIDPROVIDER_PL_1250,        KP_MSG_WSAINVALIDPROVIDER_PL_1257,        KP_MSG_WSAINVALIDPROVIDER_RU,       KP_MSG_WSAINVALIDPROVIDER_RU,       }, // "Neteisingas tiekėjo kodas"
    { KP_MSG_WSA_IO_INCOMPLETE_EN,        KP_MSG_WSA_IO_INCOMPLETE_LT,        KP_MSG_WSA_IO_INCOMPLETE_PL_1250,         KP_MSG_WSA_IO_INCOMPLETE_PL_1257,         KP_MSG_WSA_IO_INCOMPLETE_RU,        KP_MSG_WSA_IO_INCOMPLETE_RU,        }, // "Persikloja įvesties/išvesties įvykiai"
    { KP_MSG_WSA_IO_PENDING_EN,           KP_MSG_WSA_IO_PENDING_LT,           KP_MSG_WSA_IO_PENDING_PL_1250,            KP_MSG_WSA_IO_PENDING_PL_1257,            KP_MSG_WSA_IO_PENDING_RU,           KP_MSG_WSA_IO_PENDING_RU,           }, // "Persiklojančios operacijos bus atliktos vėliau"

    { KP_MSG_WSA_NOT_ENOUGH_MEMORY_EN,    KP_MSG_WSA_NOT_ENOUGH_MEMORY_LT,    KP_MSG_WSA_NOT_ENOUGH_MEMORY_PL_1250,     KP_MSG_WSA_NOT_ENOUGH_MEMORY_PL_1257,     KP_MSG_WSA_NOT_ENOUGH_MEMORY_RU,    KP_MSG_WSA_NOT_ENOUGH_MEMORY_RU,    }, // "Nepakanka atminties"
    { KP_MSG_WSANOTINITIALISED_EN,        KP_MSG_WSANOTINITIALISED_LT,        KP_MSG_WSANOTINITIALISED_PL_1250,         KP_MSG_WSANOTINITIALISED_PL_1257,         KP_MSG_WSANOTINITIALISED_RU,        KP_MSG_WSANOTINITIALISED_RU,        }, // "Tinklo posistemis neaktyvuotas"
    { KP_MSG_WSANO_DATA_EN,               KP_MSG_WSANO_DATA_LT,               KP_MSG_WSANO_DATA_PL_1250,                KP_MSG_WSANO_DATA_PL_1257,                KP_MSG_WSANO_DATA_RU,               KP_MSG_WSANO_DATA_RU,               }, // "Vardas teisingas, tačiau nėra reikiamo tipo duomenų"
    { KP_MSG_WSANO_RECOVERY_EN,           KP_MSG_WSANO_RECOVERY_LT,           KP_MSG_WSANO_RECOVERY_PL_1250,            KP_MSG_WSANO_RECOVERY_PL_1257,            KP_MSG_WSANO_RECOVERY_RU,           KP_MSG_WSANO_RECOVERY_RU,           }, // "Nepataisoma klaida"
    { KP_MSG_WSAPROVIDERFAILEDINIT_EN,    KP_MSG_WSAPROVIDERFAILEDINIT_LT,    KP_MSG_WSAPROVIDERFAILEDINIT_PL_1250,     KP_MSG_WSAPROVIDERFAILEDINIT_PL_1257,     KP_MSG_WSAPROVIDERFAILEDINIT_RU,    KP_MSG_WSAPROVIDERFAILEDINIT_RU,    }, // "Negalima inicializuoti paslaugos tiekėjo"
    { KP_MSG_WSASYSCALLFAILURE_EN,        KP_MSG_WSASYSCALLFAILURE_LT,        KP_MSG_WSASYSCALLFAILURE_PL_1250,         KP_MSG_WSASYSCALLFAILURE_PL_1257,         KP_MSG_WSASYSCALLFAILURE_RU,        KP_MSG_WSASYSCALLFAILURE_RU,        }, // "Sistemos kreipinio klaida"
    { KP_MSG_WSASYSNOTREADY_EN,           KP_MSG_WSASYSNOTREADY_LT,           KP_MSG_WSASYSNOTREADY_PL_1250,            KP_MSG_WSASYSNOTREADY_PL_1257,            KP_MSG_WSASYSNOTREADY_RU,           KP_MSG_WSASYSNOTREADY_RU,           }, // "Tinklo posistemė nepasiekiama"
    { KP_MSG_WSATRY_AGAIN_EN,             KP_MSG_WSATRY_AGAIN_LT,             KP_MSG_WSATRY_AGAIN_PL_1250,              KP_MSG_WSATRY_AGAIN_PL_1257,              KP_MSG_WSATRY_AGAIN_RU,             KP_MSG_WSATRY_AGAIN_RU,             }, // "Neautorizuotas serveris nerastas"
    { KP_MSG_WSAVERNOTSUPPORTED_EN,       KP_MSG_WSAVERNOTSUPPORTED_LT,       KP_MSG_WSAVERNOTSUPPORTED_PL_1250,        KP_MSG_WSAVERNOTSUPPORTED_PL_1257,        KP_MSG_WSAVERNOTSUPPORTED_RU,       KP_MSG_WSAVERNOTSUPPORTED_RU,       }, // "Netinka WINSOCK.DLL versija"
    { KP_MSG_WSAEDISCON_EN,               KP_MSG_WSAEDISCON_LT,               KP_MSG_WSAEDISCON_PL_1250,                KP_MSG_WSAEDISCON_PL_1257,                KP_MSG_WSAEDISCON_RU,               KP_MSG_WSAEDISCON_RU,               }, // "Pradėtas tvarkingas išjungimas" // "Pradėtas gracingas išjungimas"
    { KP_MSG_WSA_OPERATION_ABORTED_EN,    KP_MSG_WSA_OPERATION_ABORTED_LT,    KP_MSG_WSA_OPERATION_ABORTED_PL_1250,     KP_MSG_WSA_OPERATION_ABORTED_PL_1257,     KP_MSG_WSA_OPERATION_ABORTED_RU,    KP_MSG_WSA_OPERATION_ABORTED_RU,    }, // "Persiklojanti operacija nutraukta"

    { KP_MSG_OUT_OF_MEM_RES_EN,           KP_MSG_OUT_OF_MEM_RES_LT,           KP_MSG_OUT_OF_MEM_RES_PL_1250,            KP_MSG_OUT_OF_MEM_RES_PL_1257,            KP_MSG_OUT_OF_MEM_RES_RU,           KP_MSG_OUT_OF_MEM_RES_RU,           }, // "Operacinei sistemai trūksta atminties"
    { KP_MSG_ERROR_FILE_NOT_FOUND_EN,     KP_MSG_ERROR_FILE_NOT_FOUND_LT,     KP_MSG_ERROR_FILE_NOT_FOUND_PL_1250,      KP_MSG_ERROR_FILE_NOT_FOUND_PL_1257,      KP_MSG_ERROR_FILE_NOT_FOUND_RU,     KP_MSG_ERROR_FILE_NOT_FOUND_RU,     }, // "Nurodytas failas nerastas"
    { KP_MSG_ERROR_PATH_NOT_FOUND_EN,     KP_MSG_ERROR_PATH_NOT_FOUND_LT,     KP_MSG_ERROR_PATH_NOT_FOUND_PL_1250,      KP_MSG_ERROR_PATH_NOT_FOUND_PL_1257,      KP_MSG_ERROR_PATH_NOT_FOUND_RU,     KP_MSG_ERROR_PATH_NOT_FOUND_RU,     }, // "Nurodytas kelias iki failų nerastas"
    { KP_MSG_ERROR_BAD_FORMAT_EN,         KP_MSG_ERROR_BAD_FORMAT_LT,         KP_MSG_ERROR_BAD_FORMAT_PL_1250,          KP_MSG_ERROR_BAD_FORMAT_PL_1257,          KP_MSG_ERROR_BAD_FORMAT_RU,         KP_MSG_ERROR_BAD_FORMAT_RU,         }, // "Pasirinktas .exe failas sugadintas"
    { KP_MSG_SE_ERR_ACCESSDENIED_EN,      KP_MSG_SE_ERR_ACCESSDENIED_LT,      KP_MSG_SE_ERR_ACCESSDENIED_PL_1250,       KP_MSG_SE_ERR_ACCESSDENIED_PL_1257,       KP_MSG_SE_ERR_ACCESSDENIED_RU,      KP_MSG_SE_ERR_ACCESSDENIED_RU,      }, // "Operacinė sistema uždraudė prisijungimą prie reikiamų failų"
    { KP_MSG_SE_ERR_ASSOCINCOMPLETE_EN,   KP_MSG_SE_ERR_ASSOCINCOMPLETE_LT,   KP_MSG_SE_ERR_ASSOCINCOMPLETE_PL_1250,    KP_MSG_SE_ERR_ASSOCINCOMPLETE_PL_1257,    KP_MSG_SE_ERR_ASSOCINCOMPLETE_RU,   KP_MSG_SE_ERR_ASSOCINCOMPLETE_RU,   }, // "Failo sąryšis su programa nepilnas arba neteisingas"
    { KP_MSG_SE_ERR_DDEBUSY_EN,           KP_MSG_SE_ERR_DDEBUSY_LT,           KP_MSG_SE_ERR_DDEBUSY_PL_1250,            KP_MSG_SE_ERR_DDEBUSY_PL_1257,            KP_MSG_SE_ERR_DDEBUSY_RU,           KP_MSG_SE_ERR_DDEBUSY_RU,           }, // "DDE transakcija negali būti baigta, nes kitos DDE transakcijos dar vykdomos"
    { KP_MSG_SE_ERR_DDEFAIL_EN,           KP_MSG_SE_ERR_DDEFAIL_LT,           KP_MSG_SE_ERR_DDEFAIL_PL_1250,            KP_MSG_SE_ERR_DDEFAIL_PL_1257,            KP_MSG_SE_ERR_DDEFAIL_RU,           KP_MSG_SE_ERR_DDEFAIL_RU,           }, // "DDE transakcija nutraukta"
    { KP_MSG_SE_ERR_DDETIMEOUT_EN,        KP_MSG_SE_ERR_DDETIMEOUT_LT,        KP_MSG_SE_ERR_DDETIMEOUT_PL_1250,         KP_MSG_SE_ERR_DDETIMEOUT_PL_1257,         KP_MSG_SE_ERR_DDETIMEOUT_RU,        KP_MSG_SE_ERR_DDETIMEOUT_RU,        }, // "DDE transakcija negali būti baigta, nes neužteko nurodyto laukimo laiko"
    { KP_MSG_SE_ERR_DLLNOTFOUND_EN,       KP_MSG_SE_ERR_DLLNOTFOUND_LT,       KP_MSG_SE_ERR_DLLNOTFOUND_PL_1250,        KP_MSG_SE_ERR_DLLNOTFOUND_PL_1257,        KP_MSG_SE_ERR_DLLNOTFOUND_RU,       KP_MSG_SE_ERR_DLLNOTFOUND_RU,       }, // "Nurodyta dinaminė biblioteka nerasta"
    { KP_MSG_SE_ERR_FNF_EN,               KP_MSG_SE_ERR_FNF_LT,               KP_MSG_SE_ERR_FNF_PL_1250,                KP_MSG_SE_ERR_FNF_PL_1257,                KP_MSG_SE_ERR_FNF_RU,               KP_MSG_SE_ERR_FNF_RU,               }, // "Nurodytas failas nerastas"
    { KP_MSG_SE_ERR_NOASSOC_EN,           KP_MSG_SE_ERR_NOASSOC_LT,           KP_MSG_SE_ERR_NOASSOC_PL_1250,            KP_MSG_SE_ERR_NOASSOC_PL_1257,            KP_MSG_SE_ERR_NOASSOC_RU,           KP_MSG_SE_ERR_NOASSOC_RU,           }, // "Nerasta programa skirta atverti šio tipo failus"
    { KP_MSG_SE_ERR_OOM_EN,               KP_MSG_SE_ERR_OOM_LT,               KP_MSG_SE_ERR_OOM_PL_1250,                KP_MSG_SE_ERR_OOM_PL_1257,                KP_MSG_SE_ERR_OOM_RU,               KP_MSG_SE_ERR_OOM_RU,               }, // "Nepakanka atminties atlikti operacijai"
    { KP_MSG_SE_ERR_PNF_EN,               KP_MSG_SE_ERR_PNF_LT,               KP_MSG_SE_ERR_PNF_PL_1250,                KP_MSG_SE_ERR_PNF_PL_1257,                KP_MSG_SE_ERR_PNF_RU,               KP_MSG_SE_ERR_PNF_RU,               }, // "Nurodytas kelias nerastas"
    { KP_MSG_SE_ERR_SHARE_EN,             KP_MSG_SE_ERR_SHARE_LT,             KP_MSG_SE_ERR_SHARE_PL_1250,              KP_MSG_SE_ERR_SHARE_PL_1257,              KP_MSG_SE_ERR_SHARE_RU,             KP_MSG_SE_ERR_SHARE_RU,             }, // "Dalijimosi klaida"

    { KP_MSG_FIRST_TIME_ADMIN_EN,         KP_MSG_FIRST_TIME_ADMIN_LT,         KP_MSG_FIRST_TIME_ADMIN_PL_1250,          KP_MSG_FIRST_TIME_ADMIN_PL_1257,          KP_MSG_FIRST_TIME_ADMIN_RU,         KP_MSG_FIRST_TIME_ADMIN_RU,         }, // "Programą paleidžiant pirmą kartą, reikalingos\n administratoriaus teisės. Paleiskite programą iš naujo administratoriaus teisėmis."
    { KP_MSG_NOW_NOT_ADMIN_EN,            KP_MSG_NOW_NOT_ADMIN_LT,            KP_MSG_NOW_NOT_ADMIN_PL_1250,             KP_MSG_NOW_NOT_ADMIN_PL_1257,             KP_MSG_NOW_NOT_ADMIN_RU,            KP_MSG_NOW_NOT_ADMIN_RU,            }, // KP_MSG_NOT_ADMIN // "Dabar programą paleiskite dar kartą paprasto vartotojo teisėmis"
    { KP_MSG_NOT_ADMIN_EN,                KP_MSG_NOT_ADMIN_LT,                KP_MSG_NOT_ADMIN_PL_1250,                 KP_MSG_NOT_ADMIN_PL_1257,                 KP_MSG_NOT_ADMIN_RU,                KP_MSG_NOT_ADMIN_RU,                }, // "Programą paleiskite iš naujo paprasto vartotojo teisėmis"
    { KP_MSG_COPY_FILE_ACCESS_DENIED_EN,  KP_MSG_COPY_FILE_ACCESS_DENIED_LT,  KP_MSG_COPY_FILE_ACCESS_DENIED_PL_1250,   KP_MSG_COPY_FILE_ACCESS_DENIED_PL_1257,   KP_MSG_COPY_FILE_ACCESS_DENIED_RU,  KP_MSG_COPY_FILE_ACCESS_DENIED_RU,  }, // "Failo nukopijuoti nepavyko, programą paleiskite iš naujo administratoriaus teisėmis"

    { KP_PROGRESS_TITLE_EN,               KP_PROGRESS_TITLE_LT,               KP_PROGRESS_TITLE_PL_1250,                KP_PROGRESS_TITLE_PL_1257,                KP_PROGRESS_TITLE_RU,               KP_PROGRESS_TITLE_EN,               }, // "Palaukite..." // naudojamas kaip progress langelio antraštė
    { KP_MSG_DELETING_FILE_EN,            KP_MSG_DELETING_FILE_LT,            KP_MSG_DELETING_FILE_PL_1250,             KP_MSG_DELETING_FILE_PL_1257,             KP_MSG_DELETING_FILE_RU,            KP_MSG_DELETING_FILE_RU,            }, // "Naikinamas failas %s.%s..."
    { KP_MSG_COPYING_EN,                  KP_MSG_COPYING_LT,                  KP_MSG_COPYING_PL_1250,                   KP_MSG_COPYING_PL_1257,                   KP_MSG_COPYING_RU,                  KP_MSG_COPYING_RU,                  }, // "Kopijuojamas failas..."
    { KP_MSG_COPYING_DIR_EN,              KP_MSG_COPYING_DIR_LT,              KP_MSG_COPYING_DIR_PL_1250,               KP_MSG_COPYING_DIR_PL_1257,               KP_MSG_COPYING_DIR_RU,              KP_MSG_COPYING_DIR_RU,              }, // "Kopijuojamas aplankas %s.%s..."
    { KP_MSG_COPYING_FILE_EN,             KP_MSG_COPYING_FILE_LT,             KP_MSG_COPYING_FILE_PL_1250,              KP_MSG_COPYING_FILE_PL_1257,              KP_MSG_COPYING_FILE_RU,             KP_MSG_COPYING_FILE_RU,             }, // "Kopijuojamas failas %s.%s..."

    { KP_MSG_NEG_ANSW_EN,                 KP_MSG_NEG_ANSW_LT,                 KP_MSG_NEG_ANSW_PL_1250,                  KP_MSG_NEG_ANSW_PL_1257,                  KP_MSG_NEG_ANSW_RU,                 KP_MSG_NEG_ANSW_RU,                 }, // "Neigiamas atsakymas"

    { KP_MSG_UNABLE_TO_EXECUTE_EN,        KP_MSG_UNABLE_TO_EXECUTE_LT,        KP_MSG_UNABLE_TO_EXECUTE_PL_1250,         KP_MSG_UNABLE_TO_EXECUTE_PL_1257,         KP_MSG_UNABLE_TO_EXECUTE_RU,        KP_MSG_UNABLE_TO_EXECUTE_RU,        }, // "Komandos %s įvykdyti negaliu - patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

    { KP_MSG_FLASH_PLAYER_INSTALL_EN,     KP_MSG_FLASH_PLAYER_INSTALL_LT,     KP_MSG_FLASH_PLAYER_INSTALL_PL_1250,      KP_MSG_FLASH_PLAYER_INSTALL_PL_1257,      KP_MSG_FLASH_PLAYER_INSTALL_RU,     KP_MSG_FLASH_PLAYER_INSTALL_RU,     }, // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

    { KP_MSG_FILE_CHANGED_EN,             KP_MSG_FILE_CHANGED_LT,             KP_MSG_FILE_CHANGED_PL_1250,              KP_MSG_FILE_CHANGED_PL_1257,              KP_MSG_FILE_CHANGED_RU,             KP_MSG_FILE_CHANGED_RU,             }, // "Failas pasikeitė"

    { KP_MSG_ALL_FILES_EN,                KP_MSG_ALL_FILES_LT,                KP_MSG_ALL_FILES_PL_1250,                 KP_MSG_ALL_FILES_PL_1257,                 KP_MSG_ALL_FILES_RU,                KP_MSG_ALL_FILES_RU,                }, // "Visi failai (*.*)"
    { KP_MSG_SAVE_AS_EN,                  KP_MSG_SAVE_AS_LT,                  KP_MSG_SAVE_AS_PL_1250,                   KP_MSG_SAVE_AS_PL_1257,                   KP_MSG_SAVE_AS_RU,                  KP_MSG_SAVE_AS_RU,                  }, // "Įrašyti kaip"

    { KP_MSG_FILE_EXISTS_EN,              KP_MSG_FILE_EXISTS_LT,              KP_MSG_FILE_EXISTS_PL_1250,               KP_MSG_FILE_EXISTS_PL_1257,               KP_MSG_FILE_EXISTS_RU,              KP_MSG_FILE_EXISTS_RU,              }, // "Failas %s jau yra, perrašyti?"

    { KP_MSG_DIAG_MSG_EN,                 KP_MSG_DIAG_MSG_LT,                 KP_MSG_DIAG_MSG_PL_1250,                  KP_MSG_DIAG_MSG_PL_1257,                  KP_MSG_DIAG_MSG_RU,                 KP_MSG_DIAG_MSG_RU,                 }, // "Formuojamas diagnostinis pranešimas"
    { KP_MSG_DIAG_MSG_TITLE_EN,           KP_MSG_DIAG_MSG_TITLE_LT,           KP_MSG_DIAG_MSG_TITLE_PL_1250,            KP_MSG_DIAG_MSG_TITLE_PL_1257,            KP_MSG_DIAG_MSG_TITLE_RU,           KP_MSG_DIAG_MSG_TITLE_EN,           }, // "Diagnostinis pranešimas"
    { KP_MSG_DIAG_MSG_EXPL_EN,            KP_MSG_DIAG_MSG_EXPL_LT,            KP_MSG_DIAG_MSG_EXPL_PL_1250,             KP_MSG_DIAG_MSG_EXPL_PL_1257,             KP_MSG_DIAG_MSG_EXPL_RU,            KP_MSG_DIAG_MSG_EXPL_RU,            }, // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
    { KP_MSG_DIAG_MSG_EMAIL_PROMPT_EN,    KP_MSG_DIAG_MSG_EMAIL_PROMPT_LT,    KP_MSG_DIAG_MSG_EMAIL_PROMPT_PL_1250,     KP_MSG_DIAG_MSG_EMAIL_PROMPT_PL_1257,     KP_MSG_DIAG_MSG_EMAIL_PROMPT_RU,    KP_MSG_DIAG_MSG_EMAIL_PROMPT_RU,    }, // "Jūsų e-pašto adresas:")
    { KP_MSG_DIAG_MSG_COMMENTS_PROMPT_EN, KP_MSG_DIAG_MSG_COMMENTS_PROMPT_LT, KP_MSG_DIAG_MSG_COMMENTS_PROMPT_PL_1250,  KP_MSG_DIAG_MSG_COMMENTS_PROMPT_PL_1257,  KP_MSG_DIAG_MSG_COMMENTS_PROMPT_RU, KP_MSG_DIAG_MSG_COMMENTS_PROMPT_RU, }, // "Komentarai apie klaidos atsiradimo aplinkybes:")
    { KP_MSG_DIAG_MSG_FILE_PROMPT_EN,     KP_MSG_DIAG_MSG_FILE_PROMPT_LT,     KP_MSG_DIAG_MSG_FILE_PROMPT_PL_1250,      KP_MSG_DIAG_MSG_FILE_PROMPT_PL_1257,      KP_MSG_DIAG_MSG_FILE_PROMPT_RU,     KP_MSG_DIAG_MSG_FILE_PROMPT_RU,     }, // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

    { KP_MSG_BAD_EMAIL_ADDRESS_EN,        KP_MSG_BAD_EMAIL_ADDRESS_LT,        KP_MSG_BAD_EMAIL_ADDRESS_PL_1250,         KP_MSG_BAD_EMAIL_ADDRESS_PL_1257,         KP_MSG_BAD_EMAIL_ADDRESS_RU,        KP_MSG_BAD_EMAIL_ADDRESS_RU,        }, // "Neteisingas e-pašto adresas"

    { KP_MSG_DIAG_MSG_SEL_FILE_EN,        KP_MSG_DIAG_MSG_SEL_FILE_LT,        KP_MSG_DIAG_MSG_SEL_FILE_PL_1250,         KP_MSG_DIAG_MSG_SEL_FILE_PL_1257,         KP_MSG_DIAG_MSG_SEL_FILE_RU,        KP_MSG_DIAG_MSG_SEL_FILE_EN,        }, // "Pasirinkite siunčiamą failą"

    { KP_MSG_DIAG_MSG_SUCCEEDED_EN,       KP_MSG_DIAG_MSG_SUCCEEDED_LT,       KP_MSG_DIAG_MSG_SUCCEEDED_PL_1250,        KP_MSG_DIAG_MSG_SUCCEEDED_PL_1257,        KP_MSG_DIAG_MSG_SUCCEEDED_RU,       KP_MSG_DIAG_MSG_SUCCEEDED_RU,       }, // "Diagnostinis pranešimas nusiųstas sėkmingai"

    { KP_MSG_DIAG_MSG_EXPL1_EN,           KP_MSG_DIAG_MSG_EXPL1_LT,           KP_MSG_DIAG_MSG_EXPL1_PL_1250,            KP_MSG_DIAG_MSG_EXPL1_PL_1257,            KP_MSG_DIAG_MSG_EXPL1_RU,           KP_MSG_DIAG_MSG_EXPL1_RU,           }, // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
    { KP_MSG_SIUSTI_EN,                   KP_MSG_SIUSTI_LT,                   KP_MSG_SIUSTI_PL_1250,                    KP_MSG_SIUSTI_PL_1257,                    KP_MSG_SIUSTI_RU,                   KP_MSG_SIUSTI_EN,                   }, // "Siųsti"
    { KP_MSG_DIAG_MSG_EXPL2_EN,           KP_MSG_DIAG_MSG_EXPL2_LT,           KP_MSG_DIAG_MSG_EXPL2_PL_1250,            KP_MSG_DIAG_MSG_EXPL2_PL_1257,            KP_MSG_DIAG_MSG_EXPL2_RU,           KP_MSG_DIAG_MSG_EXPL2_RU,           }, // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

    { KP_MSG_DOWNLOADING_EN,              KP_MSG_DOWNLOADING_LT,              KP_MSG_DOWNLOADING_PL_1250,               KP_MSG_DOWNLOADING_PL_1257,               KP_MSG_DOWNLOADING_RU,              KP_MSG_DOWNLOADING_RU,              }, // "Siunčiamas failas..."
    { KP_MSG_DOWNLOADING_FILE_EN,         KP_MSG_DOWNLOADING_FILE_LT,         KP_MSG_DOWNLOADING_FILE_PL_1250,          KP_MSG_DOWNLOADING_FILE_PL_1257,          KP_MSG_DOWNLOADING_FILE_RU,         KP_MSG_DOWNLOADING_FILE_RU,         }, // "Siunčiamas failas %s.%s..."

    { KP_MSG_FIREWALL_EN,                 KP_MSG_FIREWALL_LT,                 KP_MSG_FIREWALL_PL_1250,                  KP_MSG_FIREWALL_PL_1257,                  KP_MSG_FIREWALL_RU,                 KP_MSG_FIREWALL_RU,                 }, // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

    { KP_MSG_POINTER_EN,                  KP_MSG_POINTER_LT,                  KP_MSG_POINTER_PL_1250,                   KP_MSG_POINTER_PL_1257,                   KP_MSG_POINTER_RU,                  KP_MSG_POINTER_RU,                  }, // "Bloga rodyklė"

    { KP_MSG_LOG_STARTED_EN,              KP_MSG_LOG_STARTED_LT,              KP_MSG_LOG_STARTED_PL_1250,               KP_MSG_LOG_STARTED_PL_1257,               KP_MSG_LOG_STARTED_RU,              KP_MSG_LOG_STARTED_RU,              }, // "Žurnalas išvedamas ir į failą %s"
    { KP_MSG_CONS_TITLE_EN,               KP_MSG_CONS_TITLE_LT,               KP_MSG_CONS_TITLE_PL_1250,                KP_MSG_CONS_TITLE_PL_1257,                KP_MSG_CONS_TITLE_RU,               KP_MSG_CONS_TITLE_RU,               }, // "%s: Pranešimų žurnalas"

    { KP_MSG_UNHANDLED_EXCEPTION_EN,      KP_MSG_UNHANDLED_EXCEPTION_LT,      KP_MSG_UNHANDLED_EXCEPTION_PL_1250,       KP_MSG_UNHANDLED_EXCEPTION_PL_1257,       KP_MSG_UNHANDLED_EXCEPTION_RU,      KP_MSG_UNHANDLED_EXCEPTION_RU,      }, // "Neapdorojamas trūkis"

	{ KP_MSG_DATA_FORMAT_EN,			KP_MSG_DATA_FORMAT_LT,				KP_MSG_DATA_FORMAT_PL_1250,					KP_MSG_DATA_FORMAT_PL_1257,				KP_MSG_DATA_FORMAT_RU,				KP_MSG_DATA_FORMAT_RU,				}, // "Neteisingas duomenų formatas"
	{ KP_MSG_DBERROR_EN,				KP_MSG_DBERROR_LT,					KP_MSG_DBERROR_PL_1250,						KP_MSG_DBERROR_PL_1257,					KP_MSG_DBERROR_RU,					KP_MSG_DBERROR_RU,					}, // "Duomenų bazės klaida"
};


// ---------------------
void KpException::Constructor
(
   HRESULT lhErrCode,
   const uchar *lpszMsg,
   LONG lWindowsErrorCode,
   const uchar *lpszSourceFile,
   int iSourceLine
)
{
   m_lhErrCode = lhErrCode;

   m_lpszMsg[0] = Nul;
   if (lpszMsg)
   {
      strncpy(m_lpszMsg, lpszMsg, KP_MAX_FILE_LIN_LEN);
      m_lpszMsg[KP_MAX_FILE_LIN_LEN] = Nul;
   }

   m_lWindowsErrorCode = lWindowsErrorCode;

   m_lpszSourceFile[0] = Nul;
   if ((const uchar *)lpszSourceFile)
   {
      strncpy(m_lpszSourceFile, lpszSourceFile, KP_MAX_FNAME_LEN);
      m_lpszSourceFile[KP_MAX_FNAME_LEN] = Nul;
   }

   m_iSourceLine = iSourceLine;
}


// ---------------------
KpErrorClass::KpErrorClass(const uchar *lpszProdName, bool bOutMsg)
{
//  m_iInsideOfStackDump = 0;
    m_iInsideOfPutLogMessage = 0;

    m_lhLastRetc = S_OK;
    m_lpszLastMessageText[0] = Nul;
    m_lpszLastSourceFile[0] = Nul;
    m_iLastSourceLine = 0;

    m_lpszProdName[0] = Nul;

    KP_ASSERT(lpszProdName, E_INVALIDARG, null);
    strncpy(m_lpszProdName, lpszProdName, KP_MAX_FNAME_LEN);
    m_lpszProdName[KP_MAX_FNAME_LEN] = Nul;
    
    m_bOutMsg = bOutMsg;
}




// ----------------------------------
void KpErrorClass::GetProdName(uchar *lpszNameBuf)
{
    KP_ASSERT(lpszNameBuf, E_INVALIDARG, null);
    strcpy(lpszNameBuf, m_lpszProdName);
}

const uchar *KpErrorClass::GetProdNamePtr(void)
{
return(m_lpszProdName);
}

const uchar *KpGetProdName(void)
{
return(KpError.GetProdNamePtr());
}


// ----------------------------------
void KpErrorClass::SetProdName(const uchar *lpszNameBuf)
{
    KP_ASSERT(lpszNameBuf, E_INVALIDARG, null);
    KP_ASSERT(strlen(lpszNameBuf) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(m_lpszProdName, lpszNameBuf);
}


// ---------------------
void KpErrorClass::FormatErrorMessage
(
const HRESULT lhRetc,
unsigned char *lpszMsg
)
{
   if (lpszMsg)
   {
const uchar *msgptr = (const uchar *)"";

      switch(lhRetc)
      {
         case S_OK:                 msgptr = KP_MSG_ERR_OK; break;
         case E_INVALIDARG:         msgptr = KP_MSG_INVALIDARG; break;
         case E_NOTIMPL:            msgptr = KP_MSG_NOTIMPL; break;
         case E_UNEXPECTED:         msgptr = KP_MSG_UNEXPECTED; break;
//       case E_NOINTERFACE:
         case E_POINTER:            msgptr = KP_MSG_POINTER; break;
//       case E_HANDLE:
//       case E_FAIL:
// TODO: case E_OBJECT_BUSY:        msgptr = KP_MSG_OBJBUSY; break;
         case KP_E_FERROR:          msgptr = KP_MSG_FERROR; break;
         case KP_E_SYSTEM_ERROR:    msgptr = KP_MSG_SYSTEM_ERROR; break;
         case KP_E_EOF:             msgptr = KP_MSG_EOF; break;
         case KP_E_FILE_FORMAT:     msgptr = KP_MSG_FILE_FORMAT; break;
         case KP_E_FILE_NOT_FOUND:  msgptr = KP_MSG_FILE_NOT_FOUND; break;
         case KP_E_DIR_ERROR:       msgptr = KP_MSG_DIR_ERROR; break;
         case KP_E_OUTOFMEM:        msgptr = KP_MSG_OUTOFMEM; break;
         case KP_E_NO_FILE:         msgptr = KP_MSG_NO_FILE; break;
         case KP_E_DOUBLE_UNGET:    msgptr = KP_MSG_DOUBLE_UNGET; break;
         case KP_E_UNKN_CHR:        msgptr = KP_MSG_UNKN_CHR; break;
         case KP_E_COMMAND_ERROR:   msgptr = KP_MSG_COMMAND_ERROR; break;
         case KP_E_BUFFER_OVERFLOW: msgptr = KP_MSG_BUFFER_OVERFLOW; break;
         case KP_E_FONT_UNDEF:      msgptr = KP_MSG_FONT_UNDEF; break;
         case KP_E_KWD_NOT_FOUND:   msgptr = KP_MSG_KWD_NOT_FOUND; break;
         case KP_E_UNKNOWN_SYSTEM:  msgptr = KP_MSG_UNKNOWN_SYSTEM; break;
         case KP_E_ILL_CODE:        msgptr = KP_MSG_ILL_CODE; break;
         case KP_E_CANCEL:          msgptr = KP_MSG_CANCELLED; break;
         case KP_E_DOUBLE_CALL:     msgptr = KP_MSG_DOUBLE_CALL; break;
         case KP_E_TIMEOUT:         msgptr = KP_MSG_TIMEOUT; break;
         case KP_E_OBJ_NOT_FOUND:   msgptr = KP_MSG_OBJ_NOT_FOUND; break;
         case KP_E_NO_CONN:         msgptr = KP_MSG_NO_CONN; break;
         case KP_E_TRANS_ERR:       msgptr = KP_MSG_TRANS_ERR; break;
         case KP_E_REFUSED:         msgptr = KP_MSG_REFUSED; break;
         case KP_E_ACCESS_DENIED:   msgptr = KP_MSG_ACCESS_DENIED; break;
         case KP_E_ILL_CHR:         msgptr = KP_MSG_ILLEGAL_CHARACTER; break;
         case KP_E_DIV_ZERO:        msgptr = KP_MSG_DIV_ZERO; break;
         case KP_E_ILLMATHARG:      msgptr = KP_MSG_ILLMATHARG; break;
         case KP_E_ILLFUNC:         msgptr = KP_MSG_ILLFUNC; break;
         case KP_E_NOTINST:         msgptr = KP_MSG_NOTINST; break;
         case KP_E_MSG_FORMAT:      msgptr = KP_MSG_MSG_FORMAT; break;
         case KP_E_OBSOLETE:        msgptr = KP_MSG_OBSOLETE; break;
         case KP_E_NEG_ANSW:        msgptr = KP_MSG_NEG_ANSW; break;
         case KP_E_FILE_CHANGED:    msgptr = KP_MSG_FILE_CHANGED; break;
         case KP_S_DIAG_MSG:        msgptr = KP_MSG_DIAG_MSG; break;
         case KP_E_BAD_EMAIL:       msgptr = KP_MSG_BAD_EMAIL_ADDRESS; break;
         case KP_E_UNHANDLED_EXCEPTION:
                                    msgptr = KP_MSG_UNHANDLED_EXCEPTION; break;
         case KP_E_DATA_FORMAT:     msgptr = KP_MSG_DATA_FORMAT; break;
         case KP_E_DBERROR:         msgptr = KP_MSG_DBERROR; break;
      }

      strncpy(lpszMsg, msgptr, KP_MAX_FILE_LIN_LEN);
      lpszMsg[KP_MAX_FILE_LIN_LEN] = Nul;
   }
}


// ---------------------
HRESULT KpErrorClass::FormatSystemErrorMessage
(
long lWindowsErrorCode,
uchar *lpszMsg,
bool bFullFormat
)
{
HRESULT retc = S_OK;
const uchar *pszMsg0 = null;
uchar *pszMsg1 = null;
const uchar *pszMsg = null;
uchar *pnts;
uchar str_buf[MAX_LONG_DIGITS + 20];
    str_buf[0] = Nul;
int ii;

    KP_ASSERT(lpszMsg, E_INVALIDARG, null);

    if (SUCCEEDED(retc)) lpszMsg[0] = Nul;

    if (lWindowsErrorCode)
    {
        switch(lWindowsErrorCode)
        {
#ifdef __WIN32__
        case WSAEACCES:               pszMsg0=KP_MSG_WSAEACCES; break;
        case WSAEADDRINUSE:           pszMsg0=KP_MSG_WSAEADDRINUSE; break;
        case WSAEADDRNOTAVAIL:        pszMsg0=KP_MSG_WSAEADDRNOTAVAIL; break;
        case WSAEAFNOSUPPORT:         pszMsg0=KP_MSG_WSAEAFNOSUPPORT; break;
        case WSAEALREADY:             pszMsg0=KP_MSG_WSAEALREADY; break;
        case WSAECONNABORTED:         pszMsg0=KP_MSG_WSAECONNABORTED; break;
        case WSAECONNREFUSED:         pszMsg0=KP_MSG_WSAECONNREFUSED; break;
        case WSAECONNRESET:           pszMsg0=KP_MSG_WSAECONNRESET; break;
        case WSAEDESTADDRREQ:         pszMsg0=KP_MSG_WSAEDESTADDRREQ; break;
        case WSAEFAULT:               pszMsg0=KP_MSG_WSAEFAULT; break;
        case WSAEHOSTDOWN:            pszMsg0=KP_MSG_WSAEHOSTDOWN; break;
        case WSAEHOSTUNREACH:         pszMsg0=KP_MSG_WSAEHOSTUNREACH; break;
        case WSAEINPROGRESS:          pszMsg0=KP_MSG_WSAEINPROGRESS; break;
        case WSAEINTR:                pszMsg0=KP_MSG_WSAEINTR; break;
        case WSAEINVAL:               pszMsg0=KP_MSG_WSAEINVAL; break;
        case WSAEISCONN:              pszMsg0=KP_MSG_WSAEISCONN; break;
        case WSAEMFILE:               pszMsg0=KP_MSG_WSAEMFILE; break;
        case WSAEMSGSIZE:             pszMsg0=KP_MSG_WSAEMSGSIZE; break;
        case WSAENETDOWN:             pszMsg0=KP_MSG_WSAENETDOWN; break;
        case WSAENETRESET:            pszMsg0=KP_MSG_WSAENETRESET; break;
        case WSAENETUNREACH:          pszMsg0=KP_MSG_WSAENETUNREACH; break;
        case WSAENOBUFS:              pszMsg0=KP_MSG_WSAENOBUFS; break;
        case WSAENOPROTOOPT:          pszMsg0=KP_MSG_WSAENOPROTOOPT; break;
        case WSAENOTCONN:             pszMsg0=KP_MSG_WSAENOTCONN; break;
        case WSAENOTSOCK:             pszMsg0=KP_MSG_WSAENOTSOCK; break;
        case WSAEOPNOTSUPP:           pszMsg0=KP_MSG_WSAEOPNOTSUPP; break;
        case WSAEPFNOSUPPORT:         pszMsg0=KP_MSG_WSAEPFNOSUPPORT; break;
        case WSAEPROCLIM:             pszMsg0=KP_MSG_WSAEPROCLIM; break;
        case WSAEPROTONOSUPPORT:      pszMsg0=KP_MSG_WSAEPROTONOSUPPORT; break;
        case WSAEPROTOTYPE:           pszMsg0=KP_MSG_WSAEPROTOTYPE; break;
        case WSAESHUTDOWN:            pszMsg0=KP_MSG_WSAESHUTDOWN; break;
        case WSAESOCKTNOSUPPORT:      pszMsg0=KP_MSG_WSAESOCKTNOSUPPORT; break;
        case WSAETIMEDOUT:            pszMsg0=KP_MSG_WSAETIMEDOUT; break;
        case WSATYPE_NOT_FOUND:       pszMsg0=KP_MSG_WSATYPE_NOT_FOUND; break;
        case WSAEWOULDBLOCK:          pszMsg0=KP_MSG_WSAEWOULDBLOCK; break;
        case WSAHOST_NOT_FOUND:       pszMsg0=KP_MSG_WSAHOST_NOT_FOUND; break;
        case WSA_INVALID_HANDLE:      pszMsg0=KP_MSG_WSA_INVALID_HANDLE; break;
        case WSA_INVALID_PARAMETER:   pszMsg0=KP_MSG_WSA_INVALID_PARAMETER; break;
//      case WSAINVALIDPROCTABLE:     pszMsg0=KP_MSG_WSAINVALIDPROCTABLE; break;
//      case WSAINVALIDPROVIDER:      pszMsg0=KP_MSG_WSAINVALIDPROVIDER; break;
        case WSA_IO_INCOMPLETE:       pszMsg0=KP_MSG_WSA_IO_INCOMPLETE; break;
        case WSA_IO_PENDING:          pszMsg0=KP_MSG_WSA_IO_PENDING; break;
// tas pat, kaip SE_ERR_OOM
//      case WSA_NOT_ENOUGH_MEMORY:   pszMsg0=KP_MSG_WSA_NOT_ENOUGH_MEMORY; break;
        case WSANOTINITIALISED:       pszMsg0=KP_MSG_WSANOTINITIALISED; break;
        case WSANO_DATA:              pszMsg0=KP_MSG_WSANO_DATA; break;
        case WSANO_RECOVERY:          pszMsg0=KP_MSG_WSANO_RECOVERY; break;
//      case WSAPROVIDERFAILEDINIT:   pszMsg0=KP_MSG_WSAPROVIDERFAILEDINIT; break;
        case WSASYSCALLFAILURE:       pszMsg0=KP_MSG_WSASYSCALLFAILURE; break;
        case WSASYSNOTREADY:          pszMsg0=KP_MSG_WSASYSNOTREADY; break;
        case WSATRY_AGAIN:            pszMsg0=KP_MSG_WSATRY_AGAIN; break;
        case WSAVERNOTSUPPORTED:      pszMsg0=KP_MSG_WSAVERNOTSUPPORTED; break;
        case WSAEDISCON:              pszMsg0=KP_MSG_WSAEDISCON; break;
        case WSA_OPERATION_ABORTED:   pszMsg0=KP_MSG_WSA_OPERATION_ABORTED; break;

//      switch((int)hErrorCode)
//      {
// !!! case 0:                      pszMsg0=KP_MSG_OUT_OF_MEM_RES; break;
        case ERROR_FILE_NOT_FOUND:    pszMsg0=KP_MSG_ERROR_FILE_NOT_FOUND; break;
        case ERROR_PATH_NOT_FOUND:    pszMsg0=KP_MSG_ERROR_PATH_NOT_FOUND; break;
        case ERROR_BAD_FORMAT:        pszMsg0=KP_MSG_ERROR_BAD_FORMAT; break;
        case SE_ERR_ACCESSDENIED:     pszMsg0=KP_MSG_SE_ERR_ACCESSDENIED; break;
        case SE_ERR_ASSOCINCOMPLETE:  pszMsg0=KP_MSG_SE_ERR_ASSOCINCOMPLETE; break;
        case SE_ERR_DDEBUSY:          pszMsg0=KP_MSG_SE_ERR_DDEBUSY; break;
        case SE_ERR_DDEFAIL:          pszMsg0=KP_MSG_SE_ERR_DDEFAIL; break;
        case SE_ERR_DDETIMEOUT:       pszMsg0=KP_MSG_SE_ERR_DDETIMEOUT; break;
        case SE_ERR_DLLNOTFOUND:      pszMsg0=KP_MSG_SE_ERR_DLLNOTFOUND; break;
//      case SE_ERR_FNF:              pszMsg1=KP_MSG_SE_ERR_FNF; break;
        case SE_ERR_NOASSOC:          pszMsg0=KP_MSG_SE_ERR_NOASSOC; break;
        case SE_ERR_OOM:              pszMsg0=KP_MSG_SE_ERR_OOM; break;
//      case SE_ERR_PNF:              pszMsg0=KP_MSG_SE_ERR_PNF; break;
        case SE_ERR_SHARE:            pszMsg0=KP_MSG_SE_ERR_SHARE; break;

// klaidos i­ GetAdaptersAddresses(), naudojama KpSocket::Bind()
//      case ERROR_ADDRESS_NOT_ASSOCIATED:  "DHCP lease information was available."
//      case ERROR_BUFFER_OVERFLOW:         "The buffer size indicated by the SizePointer parameter is too small to hold the adapter information or the AdapterAddresses parameter is NULL. The SizePointer parameter returned points to the required size of the buffer to hold the adapter information."
//      case ERROR_INVALID_PARAMETER:       "One of the parameters is invalid. This error is returned for any of the following conditions: the SizePointer parameter is NULL, the Address parameter is not AF_INET, AF_INET6, or AF_UNSPEC, or the address information for the parameters requested is greater than ULONG_MAX."
//      case ERROR_NOT_ENOUGH_MEMORY:       "Insufficient memory resources are available to complete the operation."
//      case ERROR_NO_DATA:                 "No addresses were found for the requested parameters."

// FindFirstFile(), FindNextFile(), FindClose()
//      case ERROR_NO_MORE_FILES:
#endif
        default: pszMsg0 = null; break;
        }

        pszMsg = null;
#ifdef __WIN32__
#ifdef UNICODE
// TODO:
#else
        if ((pszMsg0 == null) || bFullFormat) if(FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_IGNORE_INSERTS |
            FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, lWindowsErrorCode, 0,
            (char *)&pszMsg, 0, NULL) == 0)
        {
            pszMsg = null; // nesuformavo
        }
#endif
#endif
//      if ((pszMsg0 == null) && (pszMsg == null))
        {
            sprintf((char *)str_buf, " %ld", lWindowsErrorCode);
//          pszMsg0 = str_buf;
        }

    } // if (lWindowsErrorCode)

    if ((pszMsg0 || pszMsg || str_buf[0]) && SUCCEEDED(retc))
    {
        ii = 20;
        if (pszMsg0) ii += strlen(pszMsg0);
        if (pszMsg) ii += strlen(pszMsg);
        ii += strlen(str_buf);

//      KP_NEWA(pszMsg1, unsigned char, ii + 1); // isvieciamas ir is KP_NEWA(), gali uzsiciklint
        pszMsg1 = new uchar[ii + 1];

        if (pszMsg1 && SUCCEEDED(retc))
        {
            pszMsg1[0] = Nul;
            if (pszMsg0)
            {
                strcat(pszMsg1, pszMsg0);
                if (pszMsg) strcat(pszMsg1, "; ");
            }

            if (pszMsg) strcat(pszMsg1, pszMsg);

            pnts = pszMsg1 + strlen(pszMsg1);
            if (pnts > pszMsg1) if (*(--pnts) == Lf) *pnts = Nul;
            if (pnts > pszMsg1) if (*(--pnts) == Cr) *pnts = Nul;
            if (pnts > pszMsg1) if (*(--pnts) == '.') *pnts = Nul;

            if (pszMsg1[0] && str_buf[0]) strcat(pszMsg1, "; ");
            strcat(pszMsg1, str_buf);
        }
    }

    if (pszMsg1 && SUCCEEDED(retc))
    {
        if (strlen(pszMsg1) > KP_MAX_FILE_LIN_LEN)
        {
            pszMsg1[KP_MAX_FILE_LIN_LEN] = Nul;
            KP_WARNING(KP_E_BUFFER_OVERFLOW, null);
        }
        strcpy(lpszMsg, pszMsg1);
    }

//  KP_DELETEA(pszMsg1); // siaip iskvieciamas ir is KP_DELETE(), gali ir uzsiciklint
    if (pszMsg1) delete [] pszMsg1;
    pszMsg1 = null;

#ifdef __WIN32__
    if (pszMsg!=null) LocalFree((HLOCAL)pszMsg);
#endif

return(S_OK);
}


uchar *KpErrorClass::FormatSystemErrorMessage(long lWindowsErrorCode)
{
static uchar sys_err_msg[KP_MAX_FILE_LIN_LEN + 1];
    FormatSystemErrorMessage(lWindowsErrorCode, sys_err_msg, True);
return(sys_err_msg);
}


// ------------------------------------
const uchar *KpErrorClass::FormatErrorMessageHTTP(int p_iHTTP_RetCode)
{
static uchar out_buf[MAX_LONG_DIGITS + 100];
    sprintf((char *)out_buf, "HTTP status: %d", p_iHTTP_RetCode);
const uchar *retv = out_buf;

    switch(p_iHTTP_RetCode)
    {
        case HTTP_ANSW_CONTINUE /* 100 */:
            retv = (const uchar *)"Continue"; break;
        case 101: retv = (const uchar *)"Switching Protocols"; break;
        case HTTP_ANSW_OK /* 200 */: retv = (const uchar *)"OK"; break;
        case 201: retv = (const uchar *)"Created"; break;
        case 202: retv = (const uchar *)"Accepted"; break;
        case 203: retv = (const uchar *)"Non-Authoritative Information"; break;
        case 204: retv = (const uchar *)"No Content"; break;
        case 205: retv = (const uchar *)"Reset Content"; break;
        case 206: retv = (const uchar *)"Partial Content"; break;
        case 300: retv = (const uchar *)"Multiple Choices"; break;
        case 301: retv = (const uchar *)"Moved Permanently"; break;
        case HTTP_ANSW_FOUND /* 302 */: retv = (const uchar *)"Found"; break;
        case 303: retv = (const uchar *)"See Other"; break;
        case 304: retv = (const uchar *)"Not Modified"; break;
        case 305: retv = (const uchar *)"Use Proxy"; break;
        case 307: retv = (const uchar *)"Temporary Redirect"; break;
        case 400: retv = (const uchar *)"Bad Request"; break;
        case 401: retv = (const uchar *)"Unauthorized"; break;
        case 402: retv = (const uchar *)"Payment Required"; break;
        case 403: retv = (const uchar *)"Forbidden"; break;
        case HTTP_ANSW_FILE_NOT_FOUND /* 404 */:
            retv = (const uchar *)"Not Found"; break;
        case 405: retv = (const uchar *)"Method Not Allowed"; break;
        case 406: retv = (const uchar *)"Not Acceptable"; break;
            // serveris negali i�si�sti failo u�koduoto n� vienu i� metod�,
            // nurodyt� HTTP u�klausos lauke Accept-Encoding:
        case 407: retv = (const uchar *)"Proxy Authentication Required"; break;
        case 408: retv = (const uchar *)"Request Timeout"; break;
        case 409: retv = (const uchar *)"Conflict"; break;
        case 410: retv = (const uchar *)"Gone"; break;
        case 411: retv = (const uchar *)"Length Required"; break;
        case 412: retv = (const uchar *)"Precondition Failed"; break;
        case 413: retv = (const uchar *)"Request Entity Too Large"; break;
        case 414: retv = (const uchar *)"Request-URI Too Long"; break;
        case 415: retv = (const uchar *)"Unsupported Media Type"; break;
        case 416: retv =
            (const uchar *)"Requested Range Not Satisfiable"; break;
        case 417: retv = (const uchar *)"Expectation Failed"; break;
        case 500: retv = (const uchar *)"Internal Server Error"; break;
        case 501: retv = (const uchar *)"Not Implemented"; break;
        case 502: retv = (const uchar *)"Bad Gateway"; break;
        case 503: retv = (const uchar *)"Service Unavailable"; break;
        case 504: retv = (const uchar *)"Gateway Timeout"; break;
        case 505: retv = (const uchar *)"HTTP Version Not Supported"; break;
   }

return (retv);
}


// ------------------------------------
int KpErrorClass::TranslToHTTP_RetCode(HRESULT p_lRetc)
{
int retv = 500 /* Internal Server Error */;

    switch(p_lRetc)
    {
        case S_OK:                  retv = HTTP_ANSW_OK /* 200 OK */; break;
                                        // 100 continue
                                        // 201 Created
                                        // 202 Accepted
                                        // 302 Found
                                        // 300 Multiple Choices

//      case E_INVALIDARG:          retv = ; break; // 411 Length Required

        case E_NOTIMPL:             retv = 501 /* Not Implemented */; break;
                                        // 505 HTTP Version Not Supported

//      case KP_E_FERROR:           retv = ; break;

        case KP_E_SYSTEM_ERROR:     retv = 500 /* Internal Server Error */;
                                        break;
                                        // 409 Conflict
                                        // 412 Precondition Failed

//      case KP_E_EOF:              retv = ; break;

        case KP_E_FILE_FORMAT:      retv = 415; break;
                                        // Unsupported Media Type
                                        // 417 Expectation Failed
                                        // 406 Not Acceptable

        case KP_E_FILE_NOT_FOUND:   retv = HTTP_ANSW_FILE_NOT_FOUND
                                        /* 404 Not Found */; break;
                                        // 410 Gone
                                        // 301 Moved Permanently

//      case KP_E_DIR_ERROR:        retv = ; break;
//      case KP_E_OUTOFMEM:         retv = ; break;
        case KP_E_NO_FILE:          retv = 204 /* No Content */; break;
//      case KP_E_DOUBLE_UNGET:     retv = ; break;
//      case KP_E_UNKN_CHR:         retv = ; break;
//      case KP_E_COMMAND_ERROR:    retv = ; break;

        case KP_E_BUFFER_OVERFLOW:  retv = 413 /* Request Entity Too Large */;
                                        break;
                                        // 414 Request-URI Too long
                                        // 416 Requested Range Not Satisfiable

//      case KP_E_FONT_UNDEF:       retv = ; break;
//      case KP_E_KWD_NOT_FOUND:    retv = ; break;
//      case KP_E_UNKNOWN_SYSTEM:   retv = ; break;
//      case KP_E_ILL_CODE:         retv = ; break;
//      case KP_E_CANCEL:           retv = ; break;
//      case KP_E_DOUBLE_CALL:      retv = ; break;

        case KP_E_TIMEOUT:          retv = 408 /* Request Timeout */; break;
                                        // 504 Gateway Timeout

//      case KP_E_OBJ_NOT_FOUND:    retv = ; break;

        case KP_E_NO_CONN:          retv = 408 /* Request Timeout */; break;

        case KP_E_TRANS_ERR:        retv = 408 /* Request Timeout */; break;
                                        // 305 Use Proxy
                                        // 502 Bad Gateway

        case KP_E_REFUSED:          retv = 403 /* Forbidden */; break;

        case KP_E_ACCESS_DENIED:    retv = 401 /* Unauthorized */; break;
                                        // 402 Payment Required
                                        // 407 Proxy Authentication Required

//      case KP_E_ILL_CHR:          retv = ; break;
//      case KP_E_DIV_ZERO:         retv = ; break;
//      case KP_E_ILLMATHARG:       retv = ; break;

        case KP_E_ILLFUNC:          retv = 400 /* Bad Request */; break;
                                        // 405 Method Not Allowed

        case KP_E_NOTINST:          retv = 503 /* Service Unavailable */;
                                        break;
    }

// 101 Switching Protocols
// 203 Non-Authoritative Information
// 205 Reset Content
// 206 Partial Content
// 303 See Other
// 304 Not Modified
// 307 Temporary Redirect

return(retv);
}


// ------------------------------------
HRESULT KpErrorClass::TranslFromHTTP_RetCode(int p_iHTTP_RetCode)
{
HRESULT retc = (p_iHTTP_RetCode == HTTP_ANSW_OK)?S_OK:KP_E_NEG_ANSW;

    switch(p_iHTTP_RetCode)
    {
        case HTTP_ANSW_OK /* 200 OK */:
        case HTTP_ANSW_CONTINUE /* 100 */:
        case 201 /* Created */:
        case 202 /* Accepted */:
        case 300 /* Multiple Choices */:
                                            retc = S_OK; break;

// �itais atvejais reik�t� �okti nuoroda, nurodyta headerio lauke Location:,
// kol kas nerealizuota (kliento gale)
        case 302 /* Found */ /* Moved Temporarily */:
        case 303 /* See Other */:
        case 307 /* Temporary Redirect */:
        case 301 /* Moved Permanently */:
        case 305 /* Use Proxy */:
                                            retc = E_NOTIMPL; break;

        case 304 /* Not Modified */:
            // atsakymas � s�lygin� GET u�klaus� � tu��ias atsakymas apie
            //      nepasikeitus� fail� (tikriausiai, pasitikrinimui, ar reikia
            //      perkrauti cache'int� fail�)
            // a� toki� u�klaus� kol kas nesiun�iu, tai ir atsakymo tur�t�
            //      neateiti
                                            retc = KP_E_FILE_FORMAT; break;

        case 411 /* Length Required */:     retc = E_INVALIDARG; break;

        case 501 /* Not Implemented */:
        case 505 /* HTTP Version Not Supported */:
            // nerealizuota funkcija serverio gale
                                            retc = E_NOTIMPL; break;

//      case :                              retc = KP_E_FERROR; break;

        case 500 /* Internal Server Error */:
        case 409 /* Conflict */:
        case 412 /* Precondition Failed */: retc = KP_E_SYSTEM_ERROR; break;

//      case :                              retc = KP_E_EOF; break;

        case 415 /* Unsupported Media Type */:
        case 417 /* Expectation Failed */:
        case 406 /* Not Acceptable */:      retc = KP_E_FILE_FORMAT; break;

        case HTTP_ANSW_FILE_NOT_FOUND /* 404 Not Found */:
        case 410 /* Gone */:
                                            retc = KP_E_FILE_NOT_FOUND; break;

//      case :                              retc = KP_E_DIR_ERROR; break;
//      case :                              retc = KP_E_OUTOFMEM; break;
        case 204 /* No Content */:          retc = KP_E_NO_FILE; break;
//      case :                              retc = KP_E_DOUBLE_UNGET; break;
//      case :                              retc = KP_E_UNKN_CHR; break;
//      case :                              retc = KP_E_COMMAND_ERROR; break;

        case 413 /* Request Entity Too Large */:
        case 414 /* Request-URI Too long */:
        case 416 /* Requested Range Not Satisfiable */:
                                            retc = KP_E_BUFFER_OVERFLOW; break;

//      case :                              retc = KP_E_FONT_UNDEF; break;
//      case :                              retc = KP_E_KWD_NOT_FOUND; break;
//      case :                              retc = KP_E_UNKNOWN_SYSTEM; break;
//      case :                              retc = KP_E_ILL_CODE; break;
//      case :                              retc = KP_E_CANCEL; break;
//      case :                              retc = KP_E_DOUBLE_CALL; break;

        case 502 /* Bad Gateway */:         retc = KP_E_TRANS_ERR; break;

        case 408 /* Request Timeout */:  // retc = KP_E_TRANS_ERR; break;
                                         // retc = KP_E_NO_CONN; break;
        case 504 /* Gateway Timeout */:     retc = KP_E_TIMEOUT; break;

//      case :                              retc = KP_E_OBJ_NOT_FOUND; break;

        case 401 /* Unauthorized */:        retc = KP_E_ACCESS_DENIED; break;
        case 403 /* Forbidden */:
        case 402 /* Payment Required */:
        case 407 /* Proxy Authentication Required */:
                                            retc = KP_E_REFUSED; break;

//      case :                              retc = KP_E_ILL_CHR; break;
//      case :                              retc = KP_E_DIV_ZERO; break;
//      case :                              retc = KP_E_ILLMATHARG; break;

        case 400 /* Bad Request */:
        case 405 /* Method Not Allowed */:  retc = KP_E_ILLFUNC; break;

        case 503 /* Service Unavailable */: retc = KP_E_NOTINST; break;
    }

// 101 Switching Protocols
// 203 Non-Authoritative Information
// 205 Reset Content
// 206 Partial Content
// 303 See Other
// 304 Not Modified
// 307 Temporary Redirect

return(retc);
}


// ---------------------
void KpErrorClass::SendDiagMsg(const uchar *lpszMessageText, bool bSevereError, const uchar *lpszAddMessage)
{
// TODO:
#ifdef KP_CONSOLE
#if (!defined(KP_VERBOSE)) && (!defined(Debug))
   // KP_VERBOSE ar Debug re�ime OutputErrorMessage() (PutLogMessage()) jau i�ved�
   cerr << lpszMessageText << endl;
#endif
#else
// #error Not yet implemented
#endif
}

// ---------------------
void KpErrorClass::OutputErrorMessage(HRESULT lhRetc, const uchar *lpszMessageText,
   bool bSevereError, const uchar *lpszSourceFile, int iSourceLine)
{
HRESULT retc = lhRetc;
   if (retc == KP_S_DIAG_MSG) retc = S_OK;

// -----------------------
uchar msg_text[KP_MAX_FILE_LIN_LEN + 1];
   msg_text[0] = Nul;
   if (lpszMessageText)
   {
      strcpy(msg_text, ": ");
int ll = strlen(msg_text);
      strncpy(msg_text + ll, lpszMessageText, KP_MAX_FILE_LIN_LEN - ll);
      msg_text[KP_MAX_FILE_LIN_LEN] = Nul;
   }

// -----------------------
   if
   (
      (m_lhLastRetc != retc) ||
      strcmp(m_lpszLastMessageText, msg_text) ||
      strcmp(m_lpszLastSourceFile, lpszSourceFile) ||
      (m_iLastSourceLine != iSourceLine)
   )
   {
      m_lhLastRetc = lhRetc;
      strncpy(m_lpszLastMessageText, msg_text, KP_MAX_FILE_LIN_LEN);
      m_lpszLastMessageText[KP_MAX_FILE_LIN_LEN] = Nul;
      strncpy(m_lpszLastSourceFile, lpszSourceFile, KP_MAX_FNAME_LEN);
      m_lpszLastSourceFile[KP_MAX_FNAME_LEN] = Nul;
      m_iLastSourceLine = iSourceLine;

// -----------------------
uchar out_text[KP_MAX_FILE_LIN_LEN * 2 + 1];
      out_text[0] = Nul;

      if (FAILED(retc))
      {
         strncpy(out_text, bSevereError?KP_MSG_ERROR:KP_MSG_WARNING, KP_MAX_FILE_LIN_LEN - 2);
         out_text[KP_MAX_FILE_LIN_LEN - 2] = Nul;
         strcat(out_text, ": ");
      }

      FormatErrorMessage(lhRetc, out_text + strlen(out_text));

int ll = strlen(out_text);
      strncpy(out_text + ll, msg_text, KP_MAX_FILE_LIN_LEN - ll);
      out_text[KP_MAX_FILE_LIN_LEN] = Nul;

int msg_tail_pos = ll = strlen(out_text);
      sprintf((char *)out_text + ll, (const char *)KP_MSG_FILE_LINE, lhRetc, lpszSourceFile, iSourceLine);
      out_text[KP_MAX_FILE_LIN_LEN] = Nul;

// ----------------------
      PutLogMessage(out_text);
//    if (bSevereError) StackDump();

#ifndef Debug
      out_text[msg_tail_pos] = Nul;
#endif
      if (bSevereError || (lhRetc == KP_S_DIAG_MSG))
         SendDiagMsg(out_text, bSevereError, out_text + msg_tail_pos + 1);
#if ((defined(KP_VERBOSE)) && (!defined(Debug)) && (defined(KP_CONSOLE)))
      // Debug re�ime PutLogMessage() jau i�ved�
      else
         cerr << out_text << endl;
#endif
   }
}


// ---------------------
#if FALSE
void KpErrorClass::StackDump(void)
{
    if (m_iInsideOfStackDump++ == 0)
    {
// --------------------
        KP_ASSERT(sizeof(int) == sizeof(unsigned int *), KP_E_SYSTEM_ERROR, null);

// --------------------
unsigned int ebp_buf = 0;
#ifdef __MINGW32__
        asm("movl %%ebp, %0\n":"=r"(ebp_buf));
        KP_ASSERT(ebp_buf, KP_E_SYSTEM_ERROR, null);
#endif
const unsigned int *stack_ptr = (const unsigned int *)ebp_buf;

// --------------------
const unsigned int *stack_top = NULL;
const unsigned int *stack_top_os = NULL;
#ifdef __MINGW32__
THREAD_BASIC_INFORMATION basicInfo;
NT_TIB *tib_ptr = NULL;
NTSTATUS retw = STATUS_SEVERITY_SUCCESS;

        retw = NtQueryInformationThread(GetCurrentThread(),
            ThreadBasicInformation, &basicInfo, sizeof(THREAD_BASIC_INFORMATION), NULL);
        KP_ASSERT(retw == STATUS_SEVERITY_SUCCESS, KP_E_SYSTEM_ERROR, retw);

        tib_ptr = (NT_TIB *)basicInfo.TebBaseAddress;
        KP_ASSERT(tib_ptr, KP_E_SYSTEM_ERROR, null);

        stack_top = stack_top_os = (unsigned int *)tib_ptr->StackBase;
        KP_ASSERT(stack_top, KP_E_SYSTEM_ERROR, null);
#endif
        if (KpApp) if (KpApp->m_pStackTop)
            stack_top = (const unsigned int *)KpApp->m_pStackTop;

        KpError.PutLogMessage("Stack ptr: %lx  Stack top: %lx  Stack top local: %lx", stack_ptr, stack_top_os, stack_top);

// --------------------
        if (ebp_buf && stack_top)
        {
uchar *out_buf = null;
            KP_NEWA(out_buf, uchar, KP_MAX_FILE_LIN_LEN + 1);

            strcpy(out_buf, "Stack call trace: ");
            while ((stack_ptr < stack_top - 4 /* 0x40 */) && (strlen(out_buf) <= (KP_MAX_FILE_LIN_LEN - MAX_LONG_HEX_DIGITS - 1)))
            {
uchar hex_buf[MAX_LONG_HEX_DIGITS + 1 + 1];
                sprintf((char *)hex_buf, "%08x ", stack_ptr[1]);
                strcat(out_buf, hex_buf);
                stack_ptr = (const unsigned int *)(*stack_ptr);
                if (stack_ptr == NULL) break;
            }

            KpError.PutLogMessage(out_buf);

            KP_DELETEA(out_buf);
        }

// --------------------
    }
    m_iInsideOfStackDump--;
    if (m_iInsideOfStackDump < 0) m_iInsideOfStackDump = 0;
}
#endif


// ----------------------------------------------
void KpErrorClass::EncodeLogBuf(uchar *pBuffer, int iDataLen)
{
   KP_ASSERT(pBuffer, E_INVALIDARG, null);
   for (int ii = 0; ii < iDataLen; ii++) pBuffer[ii] ^= 0xAA;
}


// ----------------------------------------------
void KpErrorClass::GetLogFileName(uchar *lpszLogFNameBuf)
{
    KP_ASSERT(lpszLogFNameBuf, E_INVALIDARG, null);

const uchar *temp_dir = null;
#ifdef __WIN32__
    temp_dir = (const uchar *)getenv("TEMP");
    KP_ASSERT(temp_dir, KP_E_SYSTEM_ERROR, null);
#else
    temp_dir = KP_CUR_DIR_STR;
#endif

static uchar app_name[KP_MAX_FNAME_LEN + 1];
    KpError.GetProdName(app_name);
    if (KpApp) KpApp->GetAppName(app_name);

static uchar app_disk[KP_MAX_FNAME_LEN + 1];
static uchar app_path[KP_MAX_FNAME_LEN + 1];
static uchar app_fname[KP_MAX_FNAME_LEN + 1];
static uchar app_ftype[KP_MAX_FNAME_LEN + 1];
    KpStdIo::TvFnameSplit(app_disk, app_path, app_fname, app_ftype, app_name);

const uchar *log_ftype = (const uchar *)".log";
    KP_ASSERT(strlen(temp_dir) + 1 + strlen(app_fname) + strlen(log_ftype) < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(lpszLogFNameBuf, temp_dir);
    strcat(lpszLogFNameBuf, "/");
    strcat(lpszLogFNameBuf, app_fname);
    strcat(lpszLogFNameBuf, log_ftype);
}


// ----------------------------------------------
void KpErrorClass::PutLogMessage(const uchar *lpszFmt, va_list Args)
{
    if (m_iInsideOfPutLogMessage++ == 0)
    {
// --------------------

uchar *out_str = null;
        KP_NEWA(out_str, uchar, KP_MAX_FILE_LIN_LEN + strlen(lpszFmt) * 10 + 1);

// --------------------
time_t ltime;
        time(&ltime);
tm *tm_ptr = NULL;
        tm_ptr = gmtime(&ltime);
        KP_ASSERT(tm_ptr, KP_E_SYSTEM_ERROR, null);
const uchar *prod_name = (const uchar *)"kperr";
int prod_ver = 0;
const uchar *prod_date = (const uchar *)"0000-00-00";
        if (KpApp)
        {
            prod_name = m_lpszProdName;
            prod_ver = KpApp->m_iProdVer;
            prod_date = KpApp->m_lpszProdDate;
        }
        sprintf((char *)out_str, "%04d.%02d.%02d %02d:%02d:%02d %s[%05d:%s] %ld ",
            1900 + tm_ptr->tm_year, 1 + tm_ptr->tm_mon, tm_ptr->tm_mday, tm_ptr->tm_hour + 2, tm_ptr->tm_min, tm_ptr->tm_sec,
            prod_name, prod_ver, prod_date, ltime);

// --------------------
        if (lpszFmt)
            vsprintf((char *)out_str + strlen(out_str), (const char *)lpszFmt, Args);
        strcat(out_str, "\n");

#if (defined Debug) && (defined KP_CONSOLE)
        cerr /* cout */ << out_str;
#endif

// --------------------
int out_str_len = strlen(out_str);
#  ifdef ENCODE_LOG
        if (SUCCEEDED(retc)) retc = EncodeLogBuf(out_str, out_str_len);
#  endif

// --------------------
static uchar log_fname[KP_MAX_FNAME_LEN + 1];
        GetLogFileName(log_fname);

// --------------------
FILE *log_file = NULL;
        log_file = fopen((const char *)log_fname,
#  ifdef KP_ENCODE_LOG
            "ab"
#  else
            "a"
#  endif
            );
        KP_ASSERT(log_file, KP_E_DIR_ERROR, log_fname);

// --------------------
        fwrite(out_str, out_str_len, 1, log_file);
        KP_ASSERT((!feof(log_file)) && (!ferror(log_file)), KP_E_FERROR, log_fname);

// --------------------
        KP_ASSERT(fclose(log_file) == 0, KP_E_FERROR, log_fname);

// --------------------
        KP_DELETEA(out_str);

// --------------------
    }
    m_iInsideOfPutLogMessage--;
    if (m_iInsideOfPutLogMessage < 0) m_iInsideOfPutLogMessage = 0;
}


// --------------------
void KpErrorClass::Catch(const exception &KpExc)
{
   try
   {
      if (&KpExc == NULL)
      {
         KP_ERROR(E_POINTER, null);
      }
      else
      {
const KpException *exc = dynamic_cast<const KpException *>(&KpExc);

         if (exc == NULL)
         {
            KP_ERROR(KP_E_UNHANDLED_EXCEPTION, KpExc.what());
         }
         else
         {
// TODO: perdaryt į KpError.OutputErrorMessage(KpExc.what(), True, null); (parametrai kaip SendDiagMsg)
            if (exc->m_lpszMsg[0])
               KpError.OutputErrorMessage(exc->m_lhErrCode, exc->m_lpszMsg, True, exc->m_lpszSourceFile, exc->m_iSourceLine);
            else
               KpError.OutputErrorMessage(exc->m_lhErrCode, exc->m_lWindowsErrorCode, True, exc->m_lpszSourceFile, exc->m_iSourceLine);
         }
      }
   }
   catch(exception& Exc)
   {
      KP_ERROR(KP_E_UNHANDLED_EXCEPTION, Exc.what());
   }
}

// --------------------------------------------------
void KpOutputErrorMessage
(
    HRESULT lhRetc,
    const uchar *lpszMessageText,
    bool bSevereError,
    const uchar *lpszSourceFile,
    int iSourceLine
)
{
    KpError.OutputErrorMessage(lhRetc, lpszMessageText, bSevereError, lpszSourceFile, iSourceLine);
}

uchar *KpFormatSystemErrorMessage(LONG lWindowsErrorCode)
{
return(KpError.FormatSystemErrorMessage(lWindowsErrorCode));
}

void KpPutLogMessage(const uchar *lpszFmt, ...)
{
va_list argptr;
    va_start(argptr, lpszFmt);
    KpError.PutLogMessage(lpszFmt, argptr);
}
