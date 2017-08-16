// -----------------------------------------
// kpmsg.h
// kp programų pranešimai
//

#ifndef KPMSG_INCLUDED
#define KPMSG_INCLUDED

// --------------------------------------- common kp messages
enum
{
KP_MSG_TITLE_IX,                    // "Pranešimas"
KP_INPUT_TITLE_IX,                  // "Įvedimas"

KP_MSG_TAIP_IX,                     // "Taip"
KP_MSG_YES_IX,                      // KP_MSG_TAIP
KP_MSG_NE_IX,                       // "Ne"
KP_MSG_NO_IX,                       // KP_MSG_NE
KP_MSG_GERAI_IX,                    // "Gerai"
KP_MSG_OK_IX,                       // KP_MSG_GERAI
KP_MSG_ATSAUKTI_IX,                 // "Atšaukti"
KP_MSG_CANCEL_IX,                   // KP_MSG_ATSAUKTI
KP_MSG_TESTI_IX,                    // "Toliau"
KP_MSG_BAIGTI_IX,                   // "Baigti"
KP_MSG_PAMIRSAU_SLAPTAZODI_IX,      // "Pamiršau slaptažodį"

KP_MSG_ERROR_IX,                    // "Klaida"
KP_MSG_WARNING_IX,                  // "Perspėjimas"
KP_MSG_FILE_LINE_IX,                // ", failas:%s, eilutė:%d"
KP_MSG_ENTRY_ID_IX,                 // ", Įrašo nr.:%ld"
KP_MSG_ENTRY_IX,                    // ", Įrašas: %s"

KP_MSG_NO_STANDARD_PROG_IX,         // "Nerasta programa skirta atverti šio tipo failus"
KP_MSG_WND_NOT_FOUND_IX,            // "Langas nerastas"
KP_MSG_PID_NOT_FOUND_IX,            // "Nerastas proceso identifikatorius"
KP_MSG_NO_SOCKET_IX,                // "Jungtis dar nesukurta"
KP_MSG_SOCK_UNRESOLVED_IX,          // "Tarnybinės stoties adresas dar nesurastas"

KP_MSG_ERR_OK_IX,                   // "Operacija atlikta sėkmingai" // !!!
KP_MSG_INVALIDARG_IX,               // "Neteisingi parametrai"
KP_MSG_NOTIMPL_IX,                  // "Priedas neįdiegtas"
KP_MSG_UNEXPECTED_IX,               // "Netikėtas kreipinys į sąsają"
KP_MSG_FERROR_IX,                   // "Failo skaitymo/rašymo klaida"
KP_MSG_SYSTEM_ERROR_IX,             // "Klaida sistemoje"
KP_MSG_EOF_IX,                      // "Neteisinga failo pabaiga"
KP_MSG_FILE_FORMAT_IX,              // "Neteisingas failo formatas"
KP_MSG_FILE_NOT_FOUND_IX,           // "Failas nerastas"
KP_MSG_DIR_ERROR_IX,                // "Nepavyko atverti/sukurti failo"
KP_MSG_OUTOFMEM_IX,                 // "Trūksta atminties"
KP_MSG_NO_FILE_IX,                  // "Failas neatvertas"
KP_MSG_DOUBLE_UNGET_IX,             // "Dvigubas įvedimo grąžinimas"
KP_MSG_UNKN_CHR_IX,                 // "Neatpažintas simbolis"
KP_MSG_COMMAND_ERROR_IX,            // "Išorinė klaida"
KP_MSG_BUFFER_OVERFLOW_IX,          // "Persipildė buferis"
KP_MSG_FONT_UNDEF_IX,               // "Neapibrėžtas šriftas"
KP_MSG_KWD_NOT_FOUND_IX,            // "Raktinis žodis nerastas"
KP_MSG_UNKNOWN_SYSTEM_IX,           // "Operacinė sistema neatpažinta"
KP_MSG_ILL_CODE_IX,                 // "Klaidingas registracijos kodas"
KP_MSG_CANCELLED_IX,                // "Operacija nutraukta"
KP_MSG_DOUBLE_CALL_IX,              // "Dvigubas iškvietimas"
KP_MSG_TIMEOUT_IX,                  // "Viršytas laukimo laikas"
KP_MSG_OBJ_NOT_FOUND_IX,            // "Objektas nerastas"
KP_MSG_NO_CONN_IX,                  // "Nėra ryšio"

KP_MSG_TRANS_ERR_IX,                // "Perdavimo klaida"
KP_MSG_TRANS_ERR_1_IX,              // "Ryšio klaida, pakartokite siuntimo procedūrą"

KP_MSG_REFUSED_IX,                  // "Registracija atmesta"
KP_MSG_ACCESS_DENIED_IX,            // "Neleista prisijungti"
KP_MSG_ILLEGAL_CHARACTER_IX,        // "Neleistinas simbolis"
KP_MSG_DIV_ZERO_IX,                 // "Dalyba iš nulio"
KP_MSG_ILLMATHARG_IX,               // "Neleistinas matematinės funkcijos argumentas" // "Šaknis iš neigiamo skaičiaus"
KP_MSG_ILLFUNC_IX,                  // "Neleistina operacija" // illegal function call (at the moment)

KP_MSG_NOTINST_IX,                  // "Programa neįdiegta arba diegimas sugedo, pakartokite diegimo procedūrą"
KP_MSG_NOTINST_S_IX,                // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
KP_MSG_NOTINST_DELETE_IX,           // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

KP_MSG_MSG_FORMAT_IX,               // "Neteisingas pranešimo formatas"
KP_MSG_OBSOLETE_IX,                 // "Pasenusi funkcija"
KP_MSG_ERROR_HELP_IX,               // ".  Dėl techninės pagalbos kreipkitės elektroniniu paštu, adresu tech@tev.lt"
KP_MSG_ERROR_HELP_REST_IX,          // "   Prie laiško prikabinkite failą %s"
KP_MSG_WSAEACCES_IX,                // "Teisės nesuteiktos"
KP_MSG_WSAEADDRINUSE_IX,            // "Adresas jau naudojamas"
KP_MSG_WSAEADDRNOTAVAIL_IX,         // "Prašomas adresas negali būti priskirtas"
KP_MSG_WSAEAFNOSUPPORT_IX,          // "Adresų šeimos grupė nepalaikoma protokolo"
KP_MSG_WSAEALREADY_IX,              // "Operacija jau vykdoma"
KP_MSG_WSAECONNABORTED_IX,          // "Programa iššaukė ryšio nutraukimą"
KP_MSG_WSAECONNREFUSED_IX,          // "Susijungimas atmestas"
KP_MSG_WSAECONNRESET_IX,            // "Sujungimas nutrauktas"
KP_MSG_WSAEDESTADDRREQ_IX,          // "Būtinas kreipties adresas"
KP_MSG_WSAEFAULT_IX,                // "Neteisingas adresas"
KP_MSG_WSAEHOSTDOWN_IX,             // "Serveris laikinai neveikia"
KP_MSG_WSAEHOSTUNREACH_IX,          // "Serveris nepasiekiamas"
KP_MSG_WSAEINPROGRESS_IX,           // "Operacija vykdoma"
KP_MSG_WSAEINTR_IX,                 // "Funkcija nutraukta"
KP_MSG_WSAEINVAL_IX,                // "Neteisingi parametrai"
KP_MSG_WSAEISCONN_IX,               // "Susijungimas jau įvykęs"
KP_MSG_WSAEMFILE_IX,                // "Perdaug atvertų failų"
KP_MSG_WSAEMSGSIZE_IX,              // "Perdaug ilgas pranešimas"
KP_MSG_WSAENETDOWN_IX,              // "Tinklas neveikia"
KP_MSG_WSAENETRESET_IX,             // "Atsijungė nuo tinklo"
KP_MSG_WSAENETUNREACH_IX,           // "Tinklas nepasiekiamas"
KP_MSG_WSAENOBUFS_IX,               // "Trūksta vietos buferyje"
KP_MSG_WSAENOPROTOOPT_IX,           // "Neteisinga protokolo parinktis"
KP_MSG_WSAENOTCONN_IX,              // "Sujungimas nepavyko"
KP_MSG_WSAENOTSOCK_IX,              // "Socket operation on non-socket"
KP_MSG_WSAEOPNOTSUPP_IX,            // "Operacija negali būti atlikta"
KP_MSG_WSAEPFNOSUPPORT_IX,          // "Protokolo šeima nepalaikoma"
KP_MSG_WSAEPROCLIM_IX,              // "Perdaug procesų"
KP_MSG_WSAEPROTONOSUPPORT_IX,       // "Protokolas nepalaikomas"
KP_MSG_WSAEPROTOTYPE_IX,            // "Neteisingas protokolo sujungimo tipas"
KP_MSG_WSAESHUTDOWN_IX,             // "Siuntimas nebegalimas, sujungimas nutrauktas"
KP_MSG_WSAESOCKTNOSUPPORT_IX,       // "Sujungimo tipas nepalaikomas"
KP_MSG_WSAETIMEDOUT_IX,             // "Viršytas maksimalus sujungimo laukimo laikas"
KP_MSG_WSATYPE_NOT_FOUND_IX,        // "Klasės tipas nerastas"
KP_MSG_WSAEWOULDBLOCK_IX,           // "Šaltinis laikinai nepasiekiamas"
KP_MSG_WSAHOST_NOT_FOUND_IX,        // "Serveris nerastas"
KP_MSG_WSA_INVALID_HANDLE_IX,       // "Klaidingas objekto valdiklis" // "Klaidingas pasirinkto įvykio objekto valdiklis"
KP_MSG_WSA_INVALID_PARAMETER_IX,    // "Neteisingi parametrai" // "Neteisingi vienas ar daugiau parametrų"
KP_MSG_WSAINVALIDPROCTABLE_IX,      // "Klaidinga procedūrų lentelė"
KP_MSG_WSAINVALIDPROVIDER_IX,       // "Neteisingas tiekėjo kodas"
KP_MSG_WSA_IO_INCOMPLETE_IX,        // "Persikloja įvesties/išvesties įvykiai"
KP_MSG_WSA_IO_PENDING_IX,           // "Persiklojančios operacijos bus atliktos vėliau"

KP_MSG_WSA_NOT_ENOUGH_MEMORY_IX,    // "Nepakanka atminties"
KP_MSG_WSANOTINITIALISED_IX,        // "Tinklo posistemis neaktyvuotas"
KP_MSG_WSANO_DATA_IX,               // "Vardas teisingas, tačiau nėra reikiamo tipo duomenų"
KP_MSG_WSANO_RECOVERY_IX,           // "Nepataisoma klaida"
KP_MSG_WSAPROVIDERFAILEDINIT_IX,    // "Negalima inicializuoti paslaugos tiekėjo"
KP_MSG_WSASYSCALLFAILURE_IX,        // "Sistemos kreipinio klaida"
KP_MSG_WSASYSNOTREADY_IX,           // "Tinklo posistemė nepasiekiama"
KP_MSG_WSATRY_AGAIN_IX,             // "Neautorizuotas serveris nerastas"
KP_MSG_WSAVERNOTSUPPORTED_IX,       // "Netinka WINSOCK.DLL versija"
KP_MSG_WSAEDISCON_IX,               // "Pradėtas tvarkingas išjungimas" // "Pradėtas gracingas išjungimas"
KP_MSG_WSA_OPERATION_ABORTED_IX,    // "Persiklojanti operacija nutraukta"

KP_MSG_OUT_OF_MEM_RES_IX,           // "Operacinei sistemai trūksta atminties"
KP_MSG_ERROR_FILE_NOT_FOUND_IX,     // "Nurodytas failas nerastas"
KP_MSG_ERROR_PATH_NOT_FOUND_IX,     // "Nurodytas kelias iki failų nerastas"
KP_MSG_ERROR_BAD_FORMAT_IX,         // "Pasirinktas .exe failas sugadintas"
KP_MSG_SE_ERR_ACCESSDENIED_IX,      // "Operacinė sistema uždraudė prisijungimą prie reikiamų failų"
KP_MSG_SE_ERR_ASSOCINCOMPLETE_IX,   // "Failo sąryšis su programa nepilnas arba neteisingas"
KP_MSG_SE_ERR_DDEBUSY_IX,           // "DDE transakcija negali būti baigta, nes kitos DDE transakcijos dar vykdomos"
KP_MSG_SE_ERR_DDEFAIL_IX,           // "DDE transakcija nutraukta"
KP_MSG_SE_ERR_DDETIMEOUT_IX,        // "DDE transakcija negali būti baigta, nes neužteko nurodyto laukimo laiko"
KP_MSG_SE_ERR_DLLNOTFOUND_IX,       // "Nurodyta dinaminė biblioteka nerasta"
KP_MSG_SE_ERR_FNF_IX,               // "Nurodytas failas nerastas"
KP_MSG_SE_ERR_NOASSOC_IX,           // "Nerasta programa skirta atverti šio tipo failus"
KP_MSG_SE_ERR_OOM_IX,               // "Nepakanka atminties atlikti operacijai"
KP_MSG_SE_ERR_PNF_IX,               // "Nurodytas kelias nerastas"
KP_MSG_SE_ERR_SHARE_IX,             // "Dalijimosi klaida"

KP_MSG_FIRST_TIME_ADMIN_IX,         // "Programą paleidžiant pirmą kartą, reikalingos\n administratoriaus teisės. Paleiskite programą iš naujo administratoriaus teisėmis."
KP_MSG_NOW_NOT_ADMIN_IX,            // KP_MSG_NOT_ADMIN // "Dabar programą paleiskite dar kartą paprasto vartotojo teisėmis"
KP_MSG_NOT_ADMIN_IX,                // "Programą paleiskite iš naujo paprasto vartotojo teisėmis"
KP_MSG_COPY_FILE_ACCESS_DENIED_IX,  // "Failo nukopijuoti nepavyko, programą paleiskite iš naujo administratoriaus teisėmis"

KP_PROGRESS_TITLE_IX,               // "Palaukite..."
KP_MSG_DELETING_FILE_IX,            // "Naikinamas failas %s.%s..."
KP_MSG_COPYING_IX,                  // "Kopijuojamas failas..."
KP_MSG_COPYING_DIR_IX,              // "Kopijuojamas aplankas %s.%s..."
KP_MSG_COPYING_FILE_IX,             // "Kopijuojamas failas %s.%s..."

KP_MSG_NEG_ANSW_IX,                 // "Neigiamas atsakymas"

KP_MSG_UNABLE_TO_EXECUTE_IX,        // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

KP_MSG_FLASH_PLAYER_INSTALL_IX,     // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

KP_MSG_FILE_CHANGED_IX,             // "Failas pasikeitė"

KP_MSG_ALL_FILES_IX,                // "Visi failai (*.*)"
KP_MSG_SAVE_AS_IX,                  // "Įrašyti kaip"

KP_MSG_FILE_EXISTS_IX,              // "Failas %s jau yra, perrašyti?"

KP_MSG_DIAG_MSG_IX,                 // "Formuojamas diagnostinis pranešimas"
KP_MSG_DIAG_MSG_TITLE_IX,           // "Diagnostinis pranešimas"
KP_MSG_DIAG_MSG_EXPL_IX,            // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
KP_MSG_DIAG_MSG_EMAIL_PROMPT_IX,    // "Jūsų e-pašto adresas:")
KP_MSG_DIAG_MSG_COMMENTS_PROMPT_IX, // "Komentarai apie klaidos atsiradimo aplinkybes:")
KP_MSG_DIAG_MSG_FILE_PROMPT_IX,     // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

KP_MSG_BAD_EMAIL_ADDRESS_IX,        // "Neteisingas e-pašto adresas"

KP_MSG_DIAG_MSG_SEL_FILE_IX,        // "Pasirinkite siunčiamą failą"

KP_MSG_DIAG_MSG_SUCCEEDED_IX,       // "Diagnostinis pranešimas nusiųstas sėkmingai"

KP_MSG_DIAG_MSG_EXPL1_IX,           // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
KP_MSG_SIUSTI_IX,                   // "Siųsti"
KP_MSG_DIAG_MSG_EXPL2_IX,           // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

KP_MSG_DOWNLOADING_IX,              // "Siunčiamas failas..."
KP_MSG_DOWNLOADING_FILE_IX,         // "Siunčiamas failas %s.%s..."

KP_MSG_FIREWALL_IX,                 // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

KP_MSG_POINTER_IX,                  // "Bloga rodyklė"

KP_MSG_LOG_STARTED_IX,              // "Žurnalas išvedamas ir į failą %s"
KP_MSG_CONS_TITLE_IX,               // "%s: Pranešimų žurnalas"

KP_MSG_UNHANDLED_EXCEPTION_IX,      // "Neapdorojamas trūkis"

KP_MSG_DATA_FORMAT_IX,              // "Neteisingas duomenų formatas"
KP_MSG_DBERROR_IX,                  // "Duomenų bazės klaida"

NumOfKpMessages
};

#define NumOfKpMessages_25 NumOfKpMessages

// -----------------------------------------
#define KP_MSG_TITLE                    KpErrorClass::m_pszaKpMessages[KP_MSG_TITLE_IX                  ][iMsgLangOff]  // "Pranešimas"
#define KP_INPUT_TITLE                  KpErrorClass::m_pszaKpMessages[KP_INPUT_TITLE_IX                ][KpCommonApp::m_iMsgLangOff]  // "Įvedimas"

#define KP_MSG_TAIP                     KpErrorClass::m_pszaKpMessages[KP_MSG_TAIP_IX                   ][KpCommonApp::m_iMsgLangOff]  // "Taip"
#define KP_MSG_YES                      KpErrorClass::m_pszaKpMessages[KP_MSG_YES_IX                    ][KpCommonApp::m_iMsgLangOff]  // KP_MSG_TAIP
#define KP_MSG_NE                       KpErrorClass::m_pszaKpMessages[KP_MSG_NE_IX                     ][KpCommonApp::m_iMsgLangOff]  // "Ne"
#define KP_MSG_NO                       KpErrorClass::m_pszaKpMessages[KP_MSG_NO_IX                     ][KpCommonApp::m_iMsgLangOff]  // KP_MSG_NE
#define KP_MSG_GERAI                    KpErrorClass::m_pszaKpMessages[KP_MSG_GERAI_IX                  ][KpCommonApp::m_iMsgLangOff]  // "Gerai"
#define KP_MSG_OK                       KpErrorClass::m_pszaKpMessages[KP_MSG_OK_IX                     ][KpCommonApp::m_iMsgLangOff]  // KP_MSG_GERAI
#define KP_MSG_ATSAUKTI                 KpErrorClass::m_pszaKpMessages[KP_MSG_ATSAUKTI_IX               ][KpCommonApp::m_iMsgLangOff]  // "Atšaukti"
#define KP_MSG_CANCEL                   KpErrorClass::m_pszaKpMessages[KP_MSG_CANCEL_IX                 ][KpCommonApp::m_iMsgLangOff]  // KP_MSG_ATSAUKTI
#define KP_MSG_TESTI                    KpErrorClass::m_pszaKpMessages[KP_MSG_TESTI_IX                  ][KpCommonApp::m_iMsgLangOff]  // "Toliau"
#define KP_MSG_BAIGTI                   KpErrorClass::m_pszaKpMessages[KP_MSG_BAIGTI_IX                 ][KpCommonApp::m_iMsgLangOff]  // "Baigti"
#define KP_MSG_PAMIRSAU_SLAPTAZODI      KpErrorClass::m_pszaKpMessages[KP_MSG_PAMIRSAU_SLAPTAZODI_IX    ][KpCommonApp::m_iMsgLangOff]  // "Pamiršau slaptažodį"

#define KP_MSG_ERROR                    KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_IX                  ][KpCommonApp::m_iMsgLangOff]  // "Klaida"
#define KP_MSG_WARNING                  KpErrorClass::m_pszaKpMessages[KP_MSG_WARNING_IX                ][KpCommonApp::m_iMsgLangOff]  // "Perspėjimas"
#define KP_MSG_FILE_LINE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_FILE_LINE_IX              ][KpCommonApp::m_iMsgLangOff]) // ", failas:%s, eilutė:%d"
#define KP_MSG_ENTRY_ID  ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_ENTRY_ID_IX               ][KpCommonApp::m_iMsgLangOff]) // ", Įrašo nr.:%ld"
#define KP_MSG_ENTRY     ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_ENTRY_IX                  ][KpCommonApp::m_iMsgLangOff]) // ", Įrašas: %s"

#define KP_MSG_NO_STANDARD_PROG         KpErrorClass::m_pszaKpMessages[KP_MSG_NO_STANDARD_PROG_IX       ][KpCommonApp::m_iMsgLangOff]  // "Nerasta programa skirta atverti šio tipo failus"
#define KP_MSG_WND_NOT_FOUND            KpErrorClass::m_pszaKpMessages[KP_MSG_WND_NOT_FOUND_IX          ][KpCommonApp::m_iMsgLangOff]  // "Langas nerastas"
#define KP_MSG_PID_NOT_FOUND            KpErrorClass::m_pszaKpMessages[KP_MSG_PID_NOT_FOUND_IX          ][KpCommonApp::m_iMsgLangOff]  // "Nerastas proceso identifikatorius"
#define KP_MSG_NO_SOCKET                KpErrorClass::m_pszaKpMessages[KP_MSG_NO_SOCKET_IX              ][KpCommonApp::m_iMsgLangOff]  // "Jungtis dar nesukurta"
#define KP_MSG_SOCK_UNRESOLVED          KpErrorClass::m_pszaKpMessages[KP_MSG_SOCK_UNRESOLVED_IX        ][KpCommonApp::m_iMsgLangOff]  // "Tarnybinės stoties adresas dar nesurastas"

#define KP_MSG_ERR_OK                   KpErrorClass::m_pszaKpMessages[KP_MSG_ERR_OK_IX                 ][KpCommonApp::m_iMsgLangOff]  // "Operacija atlikta sėkmingai"
#define KP_MSG_INVALIDARG               KpErrorClass::m_pszaKpMessages[KP_MSG_INVALIDARG_IX             ][KpCommonApp::m_iMsgLangOff]  // "Neteisingi parametrai"
#define KP_MSG_NOTIMPL                  KpErrorClass::m_pszaKpMessages[KP_MSG_NOTIMPL_IX                ][KpCommonApp::m_iMsgLangOff]  // "Priedas neįdiegtas"
#define KP_MSG_UNEXPECTED               KpErrorClass::m_pszaKpMessages[KP_MSG_UNEXPECTED_IX             ][KpCommonApp::m_iMsgLangOff]  // "Netikėtas kreipinys į sąsają"
#define KP_MSG_FERROR                   KpErrorClass::m_pszaKpMessages[KP_MSG_FERROR_IX                 ][KpCommonApp::m_iMsgLangOff]  // "Failo skaitymo/rašymo klaida"
#define KP_MSG_SYSTEM_ERROR             KpErrorClass::m_pszaKpMessages[KP_MSG_SYSTEM_ERROR_IX           ][KpCommonApp::m_iMsgLangOff]  // "Klaida sistemoje"
#define KP_MSG_EOF                      KpErrorClass::m_pszaKpMessages[KP_MSG_EOF_IX                    ][KpCommonApp::m_iMsgLangOff]  // "Neteisinga failo pabaiga"
#define KP_MSG_FILE_FORMAT              KpErrorClass::m_pszaKpMessages[KP_MSG_FILE_FORMAT_IX            ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas failo formatas"
#define KP_MSG_FILE_NOT_FOUND           KpErrorClass::m_pszaKpMessages[KP_MSG_FILE_NOT_FOUND_IX         ][KpCommonApp::m_iMsgLangOff]  // "Failas nerastas"
#define KP_MSG_DIR_ERROR                KpErrorClass::m_pszaKpMessages[KP_MSG_DIR_ERROR_IX              ][KpCommonApp::m_iMsgLangOff]  // "Nepavyko atverti/sukurti failo"
#define KP_MSG_OUTOFMEM                 KpErrorClass::m_pszaKpMessages[KP_MSG_OUTOFMEM_IX               ][KpCommonApp::m_iMsgLangOff]  // "Trūksta atminties"
#define KP_MSG_NO_FILE                  KpErrorClass::m_pszaKpMessages[KP_MSG_NO_FILE_IX                ][KpCommonApp::m_iMsgLangOff]  // "Failas neatvertas"
#define KP_MSG_DOUBLE_UNGET             KpErrorClass::m_pszaKpMessages[KP_MSG_DOUBLE_UNGET_IX           ][KpCommonApp::m_iMsgLangOff]  // "Dvigubas įvedimo grąžinimas"
#define KP_MSG_UNKN_CHR                 KpErrorClass::m_pszaKpMessages[KP_MSG_UNKN_CHR_IX               ][KpCommonApp::m_iMsgLangOff]  // "Neatpažintas simbolis"
#define KP_MSG_COMMAND_ERROR            KpErrorClass::m_pszaKpMessages[KP_MSG_COMMAND_ERROR_IX          ][KpCommonApp::m_iMsgLangOff]  // "Išorinė klaida"
#define KP_MSG_BUFFER_OVERFLOW          KpErrorClass::m_pszaKpMessages[KP_MSG_BUFFER_OVERFLOW_IX        ][KpCommonApp::m_iMsgLangOff]  // "Persipildė buferis"
#define KP_MSG_FONT_UNDEF               KpErrorClass::m_pszaKpMessages[KP_MSG_FONT_UNDEF_IX             ][KpCommonApp::m_iMsgLangOff]  // "Neapibrėžtas šriftas"
#define KP_MSG_KWD_NOT_FOUND            KpErrorClass::m_pszaKpMessages[KP_MSG_KWD_NOT_FOUND_IX          ][KpCommonApp::m_iMsgLangOff]  // "Raktinis žodis nerastas"
#define KP_MSG_UNKNOWN_SYSTEM           KpErrorClass::m_pszaKpMessages[KP_MSG_UNKNOWN_SYSTEM_IX         ][KpCommonApp::m_iMsgLangOff]  // "Operacinė sistema neatpažinta"
#define KP_MSG_ILL_CODE                 KpErrorClass::m_pszaKpMessages[KP_MSG_ILL_CODE_IX               ][KpCommonApp::m_iMsgLangOff]  // "Klaidingas registracijos kodas"
#define KP_MSG_CANCELLED                KpErrorClass::m_pszaKpMessages[KP_MSG_CANCELLED_IX              ][KpCommonApp::m_iMsgLangOff]  // "Operacija nutraukta"
#define KP_MSG_DOUBLE_CALL              KpErrorClass::m_pszaKpMessages[KP_MSG_DOUBLE_CALL_IX            ][KpCommonApp::m_iMsgLangOff]  // "Dvigubas iškvietimas"
#define KP_MSG_TIMEOUT                  KpErrorClass::m_pszaKpMessages[KP_MSG_TIMEOUT_IX                ][KpCommonApp::m_iMsgLangOff]  // "Viršytas laukimo laikas"
#define KP_MSG_OBJ_NOT_FOUND            KpErrorClass::m_pszaKpMessages[KP_MSG_OBJ_NOT_FOUND_IX          ][KpCommonApp::m_iMsgLangOff]  // "Objektas nerastas"
#define KP_MSG_NO_CONN                  KpErrorClass::m_pszaKpMessages[KP_MSG_NO_CONN_IX                ][KpCommonApp::m_iMsgLangOff]  // "Nėra ryšio"

#define KP_MSG_TRANS_ERR                KpErrorClass::m_pszaKpMessages[KP_MSG_TRANS_ERR_IX              ][KpCommonApp::m_iMsgLangOff]  // "Perdavimo klaida"
#define KP_MSG_TRANS_ERR_1              KpErrorClass::m_pszaKpMessages[KP_MSG_TRANS_ERR_1_IX            ][KpCommonApp::m_iMsgLangOff]  // "Ryšio klaida, pakartokite siuntimo procedūrą"

#define KP_MSG_REFUSED                  KpErrorClass::m_pszaKpMessages[KP_MSG_REFUSED_IX                ][KpCommonApp::m_iMsgLangOff]  // "Registracija atmesta"
#define KP_MSG_ACCESS_DENIED            KpErrorClass::m_pszaKpMessages[KP_MSG_ACCESS_DENIED_IX          ][KpCommonApp::m_iMsgLangOff]  // "Neleista prisijungti"
#define KP_MSG_ILLEGAL_CHARACTER        KpErrorClass::m_pszaKpMessages[KP_MSG_ILLEGAL_CHARACTER_IX      ][KpCommonApp::m_iMsgLangOff]  // "Neleistinas simbolis"
#define KP_MSG_DIV_ZERO                 KpErrorClass::m_pszaKpMessages[KP_MSG_DIV_ZERO_IX               ][KpCommonApp::m_iMsgLangOff]  // "Dalyba iš nulio"
#define KP_MSG_ILLMATHARG               KpErrorClass::m_pszaKpMessages[KP_MSG_ILLMATHARG_IX             ][KpCommonApp::m_iMsgLangOff]  // "Neleistinas matematinės funkcijos argumentas"
#define KP_MSG_ILLFUNC                  KpErrorClass::m_pszaKpMessages[KP_MSG_ILLFUNC_IX                ][KpCommonApp::m_iMsgLangOff]  // "Neleistina operacija"

#define KP_MSG_NOTINST                  KpErrorClass::m_pszaKpMessages[KP_MSG_NOTINST_IX                ][KpCommonApp::m_iMsgLangOff]  // "Programa neįdiegta arba diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_S ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_NOTINST_S_IX              ][KpCommonApp::m_iMsgLangOff]) // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE           KpErrorClass::m_pszaKpMessages[KP_MSG_NOTINST_DELETE_IX         ][KpCommonApp::m_iMsgLangOff]  // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT               KpErrorClass::m_pszaKpMessages[KP_MSG_MSG_FORMAT_IX             ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas pranešimo formatas"
#define KP_MSG_OBSOLETE                 KpErrorClass::m_pszaKpMessages[KP_MSG_OBSOLETE_IX               ][KpCommonApp::m_iMsgLangOff]  // "Pasenusi funkcija"
#define KP_MSG_ERROR_HELP               KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_HELP_IX             ][KpCommonApp::m_iMsgLangOff]  // ".  Dėl techninės pagalbos kreipkitės elektroniniu paštu, adresu tech@tev.lt"
#define KP_MSG_ERROR_HELP_REST ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_HELP_REST_IX  ][KpCommonApp::m_iMsgLangOff]) // "   Prie laiško prikabinkite failą %s"
#define KP_MSG_WSAEACCES                KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEACCES_IX              ][KpCommonApp::m_iMsgLangOff]  // "Teisės nesuteiktos"
#define KP_MSG_WSAEADDRINUSE            KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEADDRINUSE_IX          ][KpCommonApp::m_iMsgLangOff]  // "Adresas jau naudojamas"
#define KP_MSG_WSAEADDRNOTAVAIL         KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEADDRNOTAVAIL_IX       ][KpCommonApp::m_iMsgLangOff]  // "Prašomas adresas negali būti priskirtas"
#define KP_MSG_WSAEAFNOSUPPORT          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEAFNOSUPPORT_IX        ][KpCommonApp::m_iMsgLangOff]  // "Adresų šeimos grupė nepalaikoma protokolo"
#define KP_MSG_WSAEALREADY              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEALREADY_IX            ][KpCommonApp::m_iMsgLangOff]  // "Operacija jau vykdoma"
#define KP_MSG_WSAECONNABORTED          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAECONNABORTED_IX        ][KpCommonApp::m_iMsgLangOff]  // "Programa iššaukė ryšio nutraukimą"
#define KP_MSG_WSAECONNREFUSED          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAECONNREFUSED_IX        ][KpCommonApp::m_iMsgLangOff]  // "Susijungimas atmestas"
#define KP_MSG_WSAECONNRESET            KpErrorClass::m_pszaKpMessages[KP_MSG_WSAECONNRESET_IX          ][KpCommonApp::m_iMsgLangOff]  // "Sujungimas nutrauktas"
#define KP_MSG_WSAEDESTADDRREQ          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEDESTADDRREQ_IX        ][KpCommonApp::m_iMsgLangOff]  // "Būtinas kreities adresas"
#define KP_MSG_WSAEFAULT                KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEFAULT_IX              ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas adresas"
#define KP_MSG_WSAEHOSTDOWN             KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEHOSTDOWN_IX           ][KpCommonApp::m_iMsgLangOff]  // "Serveris laikinai neveikia"
#define KP_MSG_WSAEHOSTUNREACH          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEHOSTUNREACH_IX        ][KpCommonApp::m_iMsgLangOff]  // "Serveris nepasiekiamas"
#define KP_MSG_WSAEINPROGRESS           KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEINPROGRESS_IX         ][KpCommonApp::m_iMsgLangOff]  // "Operacija vykdoma"
#define KP_MSG_WSAEINTR                 KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEINTR_IX               ][KpCommonApp::m_iMsgLangOff]  // "Funkcija nutraukta"
#define KP_MSG_WSAEINVAL                KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEINVAL_IX              ][KpCommonApp::m_iMsgLangOff]  // "Neteisingi parametrai"
#define KP_MSG_WSAEISCONN               KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEISCONN_IX             ][KpCommonApp::m_iMsgLangOff]  // "Susijungimas jau įvykęs"
#define KP_MSG_WSAEMFILE                KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEMFILE_IX              ][KpCommonApp::m_iMsgLangOff]  // "Perdaug atvertų failų"
#define KP_MSG_WSAEMSGSIZE              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEMSGSIZE_IX            ][KpCommonApp::m_iMsgLangOff]  // "Perdaug ilgas pranešimas"
#define KP_MSG_WSAENETDOWN              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENETDOWN_IX            ][KpCommonApp::m_iMsgLangOff]  // "Tinklas neveikia"
#define KP_MSG_WSAENETRESET             KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENETRESET_IX           ][KpCommonApp::m_iMsgLangOff]  // "Atsijungė nuo tinklo"
#define KP_MSG_WSAENETUNREACH           KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENETUNREACH_IX         ][KpCommonApp::m_iMsgLangOff]  // "Tinklas nepasiekiamas"
#define KP_MSG_WSAENOBUFS               KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENOBUFS_IX             ][KpCommonApp::m_iMsgLangOff]  // "Trūksta vietos buferyje"
#define KP_MSG_WSAENOPROTOOPT           KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENOPROTOOPT_IX         ][KpCommonApp::m_iMsgLangOff]  // "Neteisinga protokolo parinktis"
#define KP_MSG_WSAENOTCONN              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENOTCONN_IX            ][KpCommonApp::m_iMsgLangOff]  // "Sujungimas nepavyko"
#define KP_MSG_WSAENOTSOCK              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAENOTSOCK_IX            ][KpCommonApp::m_iMsgLangOff]  // "Socket operation on non-socket"
#define KP_MSG_WSAEOPNOTSUPP            KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEOPNOTSUPP_IX          ][KpCommonApp::m_iMsgLangOff]  // "Operacija negali būti atlikta"
#define KP_MSG_WSAEPFNOSUPPORT          KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEPFNOSUPPORT_IX        ][KpCommonApp::m_iMsgLangOff]  // "Protokolo šeima nepalaikoma"
#define KP_MSG_WSAEPROCLIM              KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEPROCLIM_IX            ][KpCommonApp::m_iMsgLangOff]  // "Perdaug procesų"
#define KP_MSG_WSAEPROTONOSUPPORT       KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEPROTONOSUPPORT_IX     ][KpCommonApp::m_iMsgLangOff]  // "Protokolas nepalaikomas"
#define KP_MSG_WSAEPROTOTYPE            KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEPROTOTYPE_IX          ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas protokolo sujungimo tipas"
#define KP_MSG_WSAESHUTDOWN             KpErrorClass::m_pszaKpMessages[KP_MSG_WSAESHUTDOWN_IX           ][KpCommonApp::m_iMsgLangOff]  // "Siuntimas nebegalimas, sujungimas nutrauktas"
#define KP_MSG_WSAESOCKTNOSUPPORT       KpErrorClass::m_pszaKpMessages[KP_MSG_WSAESOCKTNOSUPPORT_IX     ][KpCommonApp::m_iMsgLangOff]  // "Sujungimo tipas nepalaikomas"
#define KP_MSG_WSAETIMEDOUT             KpErrorClass::m_pszaKpMessages[KP_MSG_WSAETIMEDOUT_IX           ][KpCommonApp::m_iMsgLangOff]  // "Maksimalus sujungimo laukimo laikas viršytas"
#define KP_MSG_WSATYPE_NOT_FOUND        KpErrorClass::m_pszaKpMessages[KP_MSG_WSATYPE_NOT_FOUND_IX      ][KpCommonApp::m_iMsgLangOff]  // "Klasės tipas nerastas"
#define KP_MSG_WSAEWOULDBLOCK           KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEWOULDBLOCK_IX         ][KpCommonApp::m_iMsgLangOff]  // "Šaltinis laikinai nepasiekiamas"
#define KP_MSG_WSAHOST_NOT_FOUND        KpErrorClass::m_pszaKpMessages[KP_MSG_WSAHOST_NOT_FOUND_IX      ][KpCommonApp::m_iMsgLangOff]  // "Serveris nerastas"
#define KP_MSG_WSA_INVALID_HANDLE       KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_INVALID_HANDLE_IX     ][KpCommonApp::m_iMsgLangOff]  // "Klaidingas objekto valdiklis"
#define KP_MSG_WSA_INVALID_PARAMETER    KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_INVALID_PARAMETER_IX  ][KpCommonApp::m_iMsgLangOff]  // "Neteisingi parametrai"
#define KP_MSG_WSAINVALIDPROCTABLE      KpErrorClass::m_pszaKpMessages[KP_MSG_WSAINVALIDPROCTABLE_IX    ][KpCommonApp::m_iMsgLangOff]  // "Klaidinga procedūrų lentelė"
#define KP_MSG_WSAINVALIDPROVIDER       KpErrorClass::m_pszaKpMessages[KP_MSG_WSAINVALIDPROVIDER_IX     ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas tiekėjo kodas"
#define KP_MSG_WSA_IO_INCOMPLETE        KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_IO_INCOMPLETE_IX      ][KpCommonApp::m_iMsgLangOff]  // "Persikloja įvesties/išvesties įvykiai"
#define KP_MSG_WSA_IO_PENDING           KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_IO_PENDING_IX         ][KpCommonApp::m_iMsgLangOff]  // "Persiklojančios operacijos bus atliktos vėliau"

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY    KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_NOT_ENOUGH_MEMORY_IX  ][KpCommonApp::m_iMsgLangOff]  // "Nepakanka atminties"
#define KP_MSG_WSANOTINITIALISED        KpErrorClass::m_pszaKpMessages[KP_MSG_WSANOTINITIALISED_IX      ][KpCommonApp::m_iMsgLangOff]  // "Tinklo posistemis neaktyvuotas"
#define KP_MSG_WSANO_DATA               KpErrorClass::m_pszaKpMessages[KP_MSG_WSANO_DATA_IX             ][KpCommonApp::m_iMsgLangOff]  // "Vardas teisingas, tačiau nėra reikiamo tipo duomenų"
#define KP_MSG_WSANO_RECOVERY           KpErrorClass::m_pszaKpMessages[KP_MSG_WSANO_RECOVERY_IX         ][KpCommonApp::m_iMsgLangOff]  // "Nepataisoma klaida"
#define KP_MSG_WSAPROVIDERFAILEDINIT    KpErrorClass::m_pszaKpMessages[KP_MSG_WSAPROVIDERFAILEDINIT_IX  ][KpCommonApp::m_iMsgLangOff]  // "Negalima inicializuoti paslaugos tiekėjo"
#define KP_MSG_WSASYSCALLFAILURE        KpErrorClass::m_pszaKpMessages[KP_MSG_WSASYSCALLFAILURE_IX      ][KpCommonApp::m_iMsgLangOff]  // "Sistemos kreipinio klaida"
#define KP_MSG_WSASYSNOTREADY           KpErrorClass::m_pszaKpMessages[KP_MSG_WSASYSNOTREADY_IX         ][KpCommonApp::m_iMsgLangOff]  // "Tinklo posistemė nepasiekiama"
#define KP_MSG_WSATRY_AGAIN             KpErrorClass::m_pszaKpMessages[KP_MSG_WSATRY_AGAIN_IX           ][KpCommonApp::m_iMsgLangOff]  // "Neautorizuotas serveris nerastas"
#define KP_MSG_WSAVERNOTSUPPORTED       KpErrorClass::m_pszaKpMessages[KP_MSG_WSAVERNOTSUPPORTED_IX     ][KpCommonApp::m_iMsgLangOff]  // "Netinka WINSOCK.DLL versija"
#define KP_MSG_WSAEDISCON               KpErrorClass::m_pszaKpMessages[KP_MSG_WSAEDISCON_IX             ][KpCommonApp::m_iMsgLangOff]  // "Pradėtas tvarkingas išjungimas"
#define KP_MSG_WSA_OPERATION_ABORTED    KpErrorClass::m_pszaKpMessages[KP_MSG_WSA_OPERATION_ABORTED_IX  ][KpCommonApp::m_iMsgLangOff]  // "Persiklojanti operacija nutraukta"

#define KP_MSG_OUT_OF_MEM_RES           KpErrorClass::m_pszaKpMessages[KP_MSG_OUT_OF_MEM_RES_IX         ][KpCommonApp::m_iMsgLangOff]  // "Operacinei sistemai trūksta atminties"
#define KP_MSG_ERROR_FILE_NOT_FOUND     KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_FILE_NOT_FOUND_IX   ][KpCommonApp::m_iMsgLangOff]  // "Nurodytas failas nerastas"
#define KP_MSG_ERROR_PATH_NOT_FOUND     KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_PATH_NOT_FOUND_IX   ][KpCommonApp::m_iMsgLangOff]  // "Nurodytas kelias iki failų nerastas"
#define KP_MSG_ERROR_BAD_FORMAT         KpErrorClass::m_pszaKpMessages[KP_MSG_ERROR_BAD_FORMAT_IX       ][KpCommonApp::m_iMsgLangOff]  // "Pasirinktas .exe failas sugadintas"
#define KP_MSG_SE_ERR_ACCESSDENIED      KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_ACCESSDENIED_IX    ][KpCommonApp::m_iMsgLangOff]  // "Operacinė sistema uždraudė prisijungimą prie reikiamų failų"
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE   KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_ASSOCINCOMPLETE_IX ][KpCommonApp::m_iMsgLangOff]  // "Failo sąryšis su programa nepilnas arba neteisingas"
#define KP_MSG_SE_ERR_DDEBUSY           KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_DDEBUSY_IX         ][KpCommonApp::m_iMsgLangOff]  // "DDE transakcija negali būti baigta, nes kitos DDE transakcijos dar vykdomos"
#define KP_MSG_SE_ERR_DDEFAIL           KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_DDEFAIL_IX         ][KpCommonApp::m_iMsgLangOff]  // "DDE transakcija nutraukta"
#define KP_MSG_SE_ERR_DDETIMEOUT        KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_DDETIMEOUT_IX      ][KpCommonApp::m_iMsgLangOff]  // "DDE transakcija negali būti baigta, nes neužteko nurodyto laukimo laiko"
#define KP_MSG_SE_ERR_DLLNOTFOUND       KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_DLLNOTFOUND_IX     ][KpCommonApp::m_iMsgLangOff]  // "Nurodyta dinaminė biblioteka nerasta"
#define KP_MSG_SE_ERR_FNF               KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_FNF_IX             ][KpCommonApp::m_iMsgLangOff]  // "Nurodytas failas nerastas"
#define KP_MSG_SE_ERR_NOASSOC           KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_NOASSOC_IX         ][KpCommonApp::m_iMsgLangOff]  // "Nerasta programa skirta atverti šio tipo failus"
#define KP_MSG_SE_ERR_OOM               KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_OOM_IX             ][KpCommonApp::m_iMsgLangOff]  // "Nepakanka atminties atlikti operacijai"
#define KP_MSG_SE_ERR_PNF               KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_PNF_IX             ][KpCommonApp::m_iMsgLangOff]  // "Nurodytas kelias nerastas"
#define KP_MSG_SE_ERR_SHARE             KpErrorClass::m_pszaKpMessages[KP_MSG_SE_ERR_SHARE_IX           ][KpCommonApp::m_iMsgLangOff]  // "Dalijimosi klaida"

#define KP_MSG_FIRST_TIME_ADMIN         KpErrorClass::m_pszaKpMessages[KP_MSG_FIRST_TIME_ADMIN_IX       ][KpCommonApp::m_iMsgLangOff]  // "Programą paleidžiant pirmą kartą, reikalingos\n administratoriaus teisės. Paleiskite programą iš naujo administratoriaus teisėmis."
#define KP_MSG_NOW_NOT_ADMIN            KpErrorClass::m_pszaKpMessages[KP_MSG_NOW_NOT_ADMIN_IX          ][KpCommonApp::m_iMsgLangOff]  // KP_MSG_NOT_ADMIN
#define KP_MSG_NOT_ADMIN                KpErrorClass::m_pszaKpMessages[KP_MSG_NOT_ADMIN_IX              ][KpCommonApp::m_iMsgLangOff]  // "Programą paleiskite iš naujo paprasto vartotojo teisėmis"
#define KP_MSG_COPY_FILE_ACCESS_DENIED  KpErrorClass::m_pszaKpMessages[KP_MSG_COPY_FILE_ACCESS_DENIED_IX][KpCommonApp::m_iMsgLangOff]  // "Failo nukopijuoti nepavyko, programą paleiskite iš naujo administratoriaus teisėmis"

#define KP_PROGRESS_TITLE               KpErrorClass::m_pszaKpMessages[KP_PROGRESS_TITLE_IX             ][KpCommonApp::m_iMsgLangOff]  // "Palaukite..."
#define KP_MSG_DELETING_FILE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_DELETING_FILE_IX      ][KpCommonApp::m_iMsgLangOff]) // "Naikinamas failas %s.%s..."
#define KP_MSG_COPYING                  KpErrorClass::m_pszaKpMessages[KP_MSG_COPYING_IX                ][KpCommonApp::m_iMsgLangOff]  // "Kopijuojamas failas..."
#define KP_MSG_COPYING_DIR ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_COPYING_DIR_IX          ][KpCommonApp::m_iMsgLangOff]) // "Kopijuojamas aplankas %s.%s..."
#define KP_MSG_COPYING_FILE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_COPYING_FILE_IX        ][KpCommonApp::m_iMsgLangOff]) // "Kopijuojamas failas %s.%s..."

#define KP_MSG_NEG_ANSW                 KpErrorClass::m_pszaKpMessages[KP_MSG_NEG_ANSW_IX               ][KpCommonApp::m_iMsgLangOff]  // "Neigiamas atsakymas"

#define KP_MSG_UNABLE_TO_EXECUTE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_UNABLE_TO_EXECUTE_IX][KpCommonApp::m_iMsgLangOff]) // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL     KpErrorClass::m_pszaKpMessages[KP_MSG_FLASH_PLAYER_INSTALL_IX   ][KpCommonApp::m_iMsgLangOff]  // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED             KpErrorClass::m_pszaKpMessages[KP_MSG_FILE_CHANGED_IX           ][KpCommonApp::m_iMsgLangOff]  // "Failas pasikeitė"

#define KP_MSG_ALL_FILES                KpErrorClass::m_pszaKpMessages[KP_MSG_ALL_FILES_IX              ][KpCommonApp::m_iMsgLangOff]  // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS                  KpErrorClass::m_pszaKpMessages[KP_MSG_SAVE_AS_IX                ][KpCommonApp::m_iMsgLangOff]  // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_FILE_EXISTS_IX          ][KpCommonApp::m_iMsgLangOff]) // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG                 KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_IX               ][KpCommonApp::m_iMsgLangOff]  // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE           KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_TITLE_IX         ][KpCommonApp::m_iMsgLangOff]  // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL            KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_EXPL_IX          ][KpCommonApp::m_iMsgLangOff]  // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt"
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT    KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_EMAIL_PROMPT_IX  ][KpCommonApp::m_iMsgLangOff]  // "Jūsų e-pašto adresas:"
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_COMMENTS_PROMPT_IX][KpCommonApp::m_iMsgLangOff] // "Komentarai apie klaidos atsiradimo aplinkybes:"
#define KP_MSG_DIAG_MSG_FILE_PROMPT     KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_FILE_PROMPT_IX   ][KpCommonApp::m_iMsgLangOff]  // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):"

#define KP_MSG_BAD_EMAIL_ADDRESS        KpErrorClass::m_pszaKpMessages[KP_MSG_BAD_EMAIL_ADDRESS_IX      ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE        KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_SEL_FILE_IX      ][KpCommonApp::m_iMsgLangOff]  // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED       KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_SUCCEEDED_IX     ][KpCommonApp::m_iMsgLangOff]  // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1           KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_EXPL1_IX         ][KpCommonApp::m_iMsgLangOff]  // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI                   KpErrorClass::m_pszaKpMessages[KP_MSG_SIUSTI_IX                 ][KpCommonApp::m_iMsgLangOff]  // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2           KpErrorClass::m_pszaKpMessages[KP_MSG_DIAG_MSG_EXPL2_IX         ][KpCommonApp::m_iMsgLangOff]  // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING              KpErrorClass::m_pszaKpMessages[KP_MSG_DOWNLOADING_IX            ][KpCommonApp::m_iMsgLangOff]  // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_DOWNLOADING_FILE_IX][KpCommonApp::m_iMsgLangOff]) // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL                 KpErrorClass::m_pszaKpMessages[KP_MSG_FIREWALL_IX               ][KpCommonApp::m_iMsgLangOff]  // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER                  KpErrorClass::m_pszaKpMessages[KP_MSG_POINTER_IX                ][KpCommonApp::m_iMsgLangOff]  // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_LOG_STARTED_IX          ][KpCommonApp::m_iMsgLangOff]) // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE ((const char *)KpErrorClass::m_pszaKpMessages[KP_MSG_CONS_TITLE_IX            ][KpCommonApp::m_iMsgLangOff]) // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION      KpErrorClass::m_pszaKpMessages[KP_MSG_UNHANDLED_EXCEPTION_IX    ][KpCommonApp::m_iMsgLangOff]  // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT              KpErrorClass::m_pszaKpMessages[KP_MSG_DATA_FORMAT_IX            ][KpCommonApp::m_iMsgLangOff]  // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR                  KpErrorClass::m_pszaKpMessages[KP_MSG_DBERROR_IX                ][KpCommonApp::m_iMsgLangOff]  // "Duomenų bazės klaida"


// --------------------------------
#if FALSE // ((MsgLang != KpLangNo_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangEn_p))

#define KP_MSG_TITLE_EN             ((const unsigned char *)"") // "Message")
#define KP_INPUT_TITLE_EN           ((const unsigned char *)"") // "Input"

#define KP_MSG_YES_EN               ((const unsigned char *)"") // "Yes")
#define KP_MSG_TAIP_EN              KP_MSG_YES
#define KP_MSG_NO_EN                ((const unsigned char *)"") // "No")
#define KP_MSG_NE_EN                KP_MSG_NO
#define KP_MSG_OK_EN                ((const unsigned char *)"") // "OK")
#define KP_MSG_GERAI_EN             KP_MSG_OK
#define KP_MSG_CANCEL_EN            ((const unsigned char *)"") // "Cancel")
#define KP_MSG_ATSAUKTI_EN          KP_MSG_CANCEL
#define KP_MSG_TESTI_EN             ((const unsigned char *)"") // "Continue")
#define KP_MSG_BAIGTI_EN            ((const unsigned char *)"") // "Finish")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_EN ((const unsigned char *)"") // "Forgot password")

#define KP_MSG_ERROR_EN             ((const unsigned char *)"") // "Error")
#define KP_MSG_WARNING_EN           ((const unsigned char *)"") // "Warning")
#define KP_MSG_FILE_LINE_EN         ((const unsigned char *)"") // ", file:%s, line:%d")
#define KP_MSG_ENTRY_ID_EN          ((const unsigned char *)"") // ", Entry Id:%ld")
#define KP_MSG_ENTRY_EN             ((const unsigned char *)"") // ", Entry: %s")

#define KP_MSG_NO_STANDARD_PROG_EN  ((const unsigned char *)"") // "Standard program not set to open given file type")
#define KP_MSG_WND_NOT_FOUND_EN     ((const unsigned char *)"") // "Window not found")
#define KP_MSG_PID_NOT_FOUND_EN     ((const unsigned char *)"") // "PID not found")
#define KP_MSG_NO_SOCKET_EN         ((const unsigned char *)"") // "Socket not created yet")
#define KP_MSG_SOCK_UNRESOLVED_EN   ((const unsigned char *)"") // "Server address not resolved yet")

#define KP_MSG_ERR_OK_EN            ((const unsigned char *)"") // "Operation ended successfully")
#define KP_MSG_INVALIDARG_EN        ((const unsigned char *)"") // "Invalid parameter")
#define KP_MSG_NOTIMPL_EN           ((const unsigned char *)"") // "Feature not implemented yet")
#define KP_MSG_UNEXPECTED_EN        ((const unsigned char *)"") // "Unexpected interface call") // Interface call result: Unexpected error
#define KP_MSG_FERROR_EN            ((const unsigned char *)"") // "File I/O error")
#define KP_MSG_SYSTEM_ERROR_EN      ((const unsigned char *)"") // "Internal error")
#define KP_MSG_EOF_EN               ((const unsigned char *)"") // "Unexpected end of input file")
#define KP_MSG_FILE_FORMAT_EN       ((const unsigned char *)"") // "Unexpected input file format")
#define KP_MSG_FILE_NOT_FOUND_EN    ((const unsigned char *)"") // "File not found")
#define KP_MSG_DIR_ERROR_EN         ((const unsigned char *)"") // "Unable to create file")
#define KP_MSG_OUTOFMEM_EN          ((const unsigned char *)"") // "Out of memory")
#define KP_MSG_NO_FILE_EN           ((const unsigned char *)"") // "No file open")
#define KP_MSG_DOUBLE_UNGET_EN      ((const unsigned char *)"") // "Double unget")
#define KP_MSG_UNKN_CHR_EN          ((const unsigned char *)"") // "Unknown character")
#define KP_MSG_COMMAND_ERROR_EN     ((const unsigned char *)"") // "External error")
#define KP_MSG_BUFFER_OVERFLOW_EN   ((const unsigned char *)"") // "Buffer overflow")
#define KP_MSG_FONT_UNDEF_EN        ((const unsigned char *)"") // "Font undefined")
#define KP_MSG_KWD_NOT_FOUND_EN     ((const unsigned char *)"") // "Keyword not found")
#define KP_MSG_UNKNOWN_SYSTEM_EN    ((const unsigned char *)"") // "Unknown OS version")
#define KP_MSG_ILL_CODE_EN          ((const unsigned char *)"") // "Illegal registration code")
#define KP_MSG_CANCELLED_EN         ((const unsigned char *)"") // "Job cancelled")
#define KP_MSG_DOUBLE_CALL_EN       ((const unsigned char *)"") // "Double call")
#define KP_MSG_TIMEOUT_EN           ((const unsigned char *)"") // "Timeout")
#define KP_MSG_OBJ_NOT_FOUND_EN     ((const unsigned char *)"") // "Object not found")
#define KP_MSG_NO_CONN_EN           ((const unsigned char *)"") // "No connection")

#define KP_MSG_TRANS_ERR_EN         ((const unsigned char *)"") // "Transfer error")
#define KP_MSG_TRANS_ERR_1_EN       ((const unsigned char *)"") // "Transfer error, repeat the download procedure, please"

#define KP_MSG_REFUSED_EN           ((const unsigned char *)"") // "Registration refused")
#define KP_MSG_ACCESS_DENIED_EN     ((const unsigned char *)"") // "Access denied")
#define KP_MSG_ILLEGAL_CHARACTER_EN ((const unsigned char *)"") // "Unexpected character")
#define KP_MSG_DIV_ZERO_EN          ((const unsigned char *)"") // "Division by zero")
#define KP_MSG_ILLMATHARG_EN        ((const unsigned char *)"") // "Illegal math argument")
#define KP_MSG_ILLFUNC_EN           ((const unsigned char *)"") // "Illegal function call")

#define KP_MSG_NOTINST_EN           ((const unsigned char *)"") // "Program not yet installed or installation is damaged, repeat the installation procedure again, please")
#define KP_MSG_NOTINST_S_EN         ((const unsigned char *)"") // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE_EN    ((const unsigned char *)"") // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT_EN        ((const unsigned char *)"") // "Illegal message format")
#define KP_MSG_OBSOLETE_EN          ((const unsigned char *)"") // "Obsolete function call")

#define KP_MSG_ERROR_HELP_EN        ((const unsigned char *)"") // ".  Technical support by e-mail tech@tev.lt")
#define KP_MSG_ERROR_HELP_REST_EN   ((const unsigned char *)"") // "   For further information look file %s")

#define KP_MSG_WSAEACCES_EN               ((const unsigned char *)"") // "Permission denied")
#define KP_MSG_WSAEADDRINUSE_EN           ((const unsigned char *)"") // "Address already in use")
#define KP_MSG_WSAEADDRNOTAVAIL_EN        ((const unsigned char *)"") // "Cannot assign requested address")
#define KP_MSG_WSAEAFNOSUPPORT_EN         ((const unsigned char *)"") // "Address family not supported by protocol family")
#define KP_MSG_WSAEALREADY_EN             ((const unsigned char *)"") // "Operation already in progress")
#define KP_MSG_WSAECONNABORTED_EN         ((const unsigned char *)"") // "Software caused connection abort")
#define KP_MSG_WSAECONNREFUSED_EN         ((const unsigned char *)"") // "Connection refused")
#define KP_MSG_WSAECONNRESET_EN           ((const unsigned char *)"") // "Connection reset by peer")
#define KP_MSG_WSAEDESTADDRREQ_EN         ((const unsigned char *)"") // "Destination address required")
#define KP_MSG_WSAEFAULT_EN               ((const unsigned char *)"") // "Bad address")
#define KP_MSG_WSAEHOSTDOWN_EN            ((const unsigned char *)"") // "Host is down")
#define KP_MSG_WSAEHOSTUNREACH_EN         ((const unsigned char *)"") // "No route to host")
#define KP_MSG_WSAEINPROGRESS_EN          ((const unsigned char *)"") // "Operation now in progress")
#define KP_MSG_WSAEINTR_EN                ((const unsigned char *)"") // "Interrupted function call")
#define KP_MSG_WSAEINVAL_EN               ((const unsigned char *)"") // "Invalid argument")
#define KP_MSG_WSAEISCONN_EN              ((const unsigned char *)"") // "Socket is already connected")
#define KP_MSG_WSAEMFILE_EN               ((const unsigned char *)"") // "Too many open files")
#define KP_MSG_WSAEMSGSIZE_EN             ((const unsigned char *)"") // "Message too long")
#define KP_MSG_WSAENETDOWN_EN             ((const unsigned char *)"") // "Network is down")
#define KP_MSG_WSAENETRESET_EN            ((const unsigned char *)"") // "Network dropped connection on reset")
#define KP_MSG_WSAENETUNREACH_EN          ((const unsigned char *)"") // "Network is unreachable")
#define KP_MSG_WSAENOBUFS_EN              ((const unsigned char *)"") // "No buffer space available")
#define KP_MSG_WSAENOPROTOOPT_EN          ((const unsigned char *)"") // "Bad protocol option")
#define KP_MSG_WSAENOTCONN_EN             ((const unsigned char *)"") // "Socket is not connected")
#define KP_MSG_WSAENOTSOCK_EN             ((const unsigned char *)"") // "Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_EN           ((const unsigned char *)"") // "Operation not supported")
#define KP_MSG_WSAEPFNOSUPPORT_EN         ((const unsigned char *)"") // "Protocol family not supported")
#define KP_MSG_WSAEPROCLIM_EN             ((const unsigned char *)"") // "Too many processes")
#define KP_MSG_WSAEPROTONOSUPPORT_EN      ((const unsigned char *)"") // "Protocol not supported")
#define KP_MSG_WSAEPROTOTYPE_EN           ((const unsigned char *)"") // "Protocol wrong type for socket")
#define KP_MSG_WSAESHUTDOWN_EN            ((const unsigned char *)"") // "Cannot send after socket shutdown")
#define KP_MSG_WSAESOCKTNOSUPPORT_EN      ((const unsigned char *)"") // "Socket type not supported")
#define KP_MSG_WSAETIMEDOUT_EN            ((const unsigned char *)"") // "Connection timed out")
#define KP_MSG_WSATYPE_NOT_FOUND_EN       ((const unsigned char *)"") // "class type not found")
#define KP_MSG_WSAEWOULDBLOCK_EN          ((const unsigned char *)"") // "Resource temporarily unavailable")
#define KP_MSG_WSAHOST_NOT_FOUND_EN       ((const unsigned char *)"") // "Host not found")
#define KP_MSG_WSA_INVALID_HANDLE_EN      ((const unsigned char *)"") // "Specified event object handle is invalid")
#define KP_MSG_WSA_INVALID_PARAMETER_EN   ((const unsigned char *)"") // "One or more parameters are invalid")
#define KP_MSG_WSAINVALIDPROCTABLE_EN     ((const unsigned char *)"") // "Invalid procedure table from service provider")
#define KP_MSG_WSAINVALIDPROVIDER_EN      ((const unsigned char *)"") // "Invalid service provider version number")
#define KP_MSG_WSA_IO_INCOMPLETE_EN       ((const unsigned char *)"") // "Overlapped I/O event object not in signaled state")
#define KP_MSG_WSA_IO_PENDING_EN          ((const unsigned char *)"") // "Overlapped operations will complete later")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_EN   ((const unsigned char *)"") // "Insufficient memory available")
#define KP_MSG_WSANOTINITIALISED_EN       ((const unsigned char *)"") // "Successful WSAStartup not yet performed")
#define KP_MSG_WSANO_DATA_EN              ((const unsigned char *)"") // "Valid name, no data record of requested type")
#define KP_MSG_WSANO_RECOVERY_EN          ((const unsigned char *)"") // "this is a non-recoverable error")
#define KP_MSG_WSAPROVIDERFAILEDINIT_EN   ((const unsigned char *)"") // "Unable to initialize a service provider")
#define KP_MSG_WSASYSCALLFAILURE_EN       ((const unsigned char *)"") // "System call failure")
#define KP_MSG_WSASYSNOTREADY_EN          ((const unsigned char *)"") // "Network subsystem is unavailable")
#define KP_MSG_WSATRY_AGAIN_EN            ((const unsigned char *)"") // "Non-authoritative host not found")
#define KP_MSG_WSAVERNOTSUPPORTED_EN      ((const unsigned char *)"") // "WINSOCK.DLL version out of range")
#define KP_MSG_WSAEDISCON_EN              ((const unsigned char *)"") // "Graceful shutdown in progress")
#define KP_MSG_WSA_OPERATION_ABORTED_EN   ((const unsigned char *)"") // "Overlapped operation aborted")

#define KP_MSG_OUT_OF_MEM_RES_EN          ((const unsigned char *)"") // "The operating system is out of memory or resources")
#define KP_MSG_ERROR_FILE_NOT_FOUND_EN    ((const unsigned char *)"") // "The file specified was not found")
#define KP_MSG_ERROR_PATH_NOT_FOUND_EN    ((const unsigned char *)"") // "The path specified was not found")
#define KP_MSG_ERROR_BAD_FORMAT_EN        ((const unsigned char *)"") // "The .exe file is invalid (non-Win32(r) .exe or error in .exe image)")
#define KP_MSG_SE_ERR_ACCESSDENIED_EN     ((const unsigned char *)"") // "The operating system denied access to the specified file")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_EN  ((const unsigned char *)"") // "The file name association is incomplete or invalid")
#define KP_MSG_SE_ERR_DDEBUSY_EN          ((const unsigned char *)"") // "The DDE transaction could not be completed because other DDE transactions were being processed")
#define KP_MSG_SE_ERR_DDEFAIL_EN          ((const unsigned char *)"") // "The DDE transaction failed")
#define KP_MSG_SE_ERR_DDETIMEOUT_EN       ((const unsigned char *)"") // "The DDE transaction could not be completed because the request timed out")
#define KP_MSG_SE_ERR_DLLNOTFOUND_EN      ((const unsigned char *)"") // "The specified dynamic-link library was not found")
#define KP_MSG_SE_ERR_FNF_EN              ((const unsigned char *)"") // "The specified file was not found")
#define KP_MSG_SE_ERR_NOASSOC_EN          ((const unsigned char *)"") // "There is no application associated with the given file name extension")
#define KP_MSG_SE_ERR_OOM_EN              ((const unsigned char *)"") // "There was not enough memory to complete the operation")
#define KP_MSG_SE_ERR_PNF_EN              ((const unsigned char *)"") // "The specified path was not found")
#define KP_MSG_SE_ERR_SHARE_EN            ((const unsigned char *)"") // "A sharing violation occurred")

#define KP_MSG_FIRST_TIME_ADMIN_EN        ((const unsigned char *)"") // "Starting the program first time administrator\n rights are necessary. Run the program again as privileged user.")
#define KP_MSG_NOW_NOT_ADMIN_EN           KP_MSG_NOT_ADMIN
#define KP_MSG_NOT_ADMIN_EN               ((const unsigned char *)"") // "Run the program again as ordinary user")
#define KP_MSG_COPY_FILE_ACCESS_DENIED_EN ((const unsigned char *)"") // "Unsuccessfull file copy operation, run the program again as privileged user")

#define KP_PROGRESS_TITLE_EN              ((const unsigned char *)"") // "Wait...")
#define KP_MSG_DELETING_FILE_EN           ((const unsigned char *)"") // "Deleting file %s.%s...")
#define KP_MSG_COPYING_EN                 ((const unsigned char *)"") // "Copying file...")
#define KP_MSG_COPYING_FILE_EN            ((const unsigned char *)"") // "Copying file %s.%s...")
#define KP_MSG_COPYING_DIR_EN             ((const unsigned char *)"") // "Copying folder %s.%s...")

#define KP_MSG_UNABLE_TO_EXECUTE_EN       ((const unsigned char *)"") // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL_EN    ((const unsigned char *)"") // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED_EN            ((const unsigned char *)"") // "Failas pasikeitė"

#define KP_MSG_ALL_FILES_EN               ((const unsigned char *)"") // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS_EN                 ((const unsigned char *)"") // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS_EN             ((const unsigned char *)"") // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG_EN                ((const unsigned char *)"") // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE_EN          ((const unsigned char *)"") // "Diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL_EN           ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_EN   ((const unsigned char *)"") // "Jūsų e-pašto adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_EN ((const unsigned char *)"") // "Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_EN    ((const unsigned char *)"") // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_EN       ((const unsigned char *)"") // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE_EN       ((const unsigned char *)"") // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED_EN      ((const unsigned char *)"") // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1_EN          ((const unsigned char *)"") // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI_EN                  ((const unsigned char *)"") // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2_EN          ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING_EN             ((const unsigned char *)"") // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE_EN        ((const unsigned char *)"") // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL_EN                ((const unsigned char *)"") // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER_EN                 ((const unsigned char *)"") // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED_EN             ((const unsigned char *)"") // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE_EN              ((const unsigned char *)"") // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION_EN     ((const unsigned char *)"") // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT_EN,            ((const unsigned char *)"") // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR_EN,                ((const unsigned char *)"") // "Duomenų bazės klaida"

#endif // #if ((MsgLang != KpLangNo_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangEn_p))


// --------------------------------
#if ((MsgLang != KpLangSel_p) && (MsgLang != KpLangLt_p))

#define KP_MSG_TITLE_LT             ((const unsigned char *)"") // "Pranešimas"
#define KP_INPUT_TITLE_LT           ((const unsigned char *)"") // "Įvedimas"

#define KP_MSG_TAIP_LT              ((const unsigned char *)"") // "Taip")
#define KP_MSG_YES_LT               KP_MSG_TAIP
#define KP_MSG_NE_LT                ((const unsigned char *)"") // "Ne")
#define KP_MSG_NO_LT                KP_MSG_NE
#define KP_MSG_GERAI_LT             ((const unsigned char *)"") // "Gerai")
#define KP_MSG_OK_LT                KP_MSG_GERAI
#define KP_MSG_ATSAUKTI_LT          ((const unsigned char *)"") // "Atšaukti")
#define KP_MSG_CANCEL_LT            KP_MSG_ATSAUKTI
#define KP_MSG_TESTI_LT             ((const unsigned char *)"") // "Toliau")
#define KP_MSG_BAIGTI_LT            ((const unsigned char *)"") // "Baigti")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_LT ((const unsigned char *)"") // "Pamiršau slaptažodį")

#define KP_MSG_ERROR_LT             ((const unsigned char *)"") // "Klaida")
#define KP_MSG_WARNING_LT           ((const unsigned char *)"") // "Perspėjimas")
#define KP_MSG_FILE_LINE_LT         ((const unsigned char *)"") // ", failas:%s, eilutė:%d")
#define KP_MSG_ENTRY_ID_LT          ((const unsigned char *)"") // ", Įrašo nr.:%ld")
#define KP_MSG_ENTRY_LT             ((const unsigned char *)"") // ", Įrašas: %s")

#define KP_MSG_NO_STANDARD_PROG_LT  ((const unsigned char *)"") // "Nerasta programa skirta atverti šio tipo failus")
#define KP_MSG_WND_NOT_FOUND_LT     ((const unsigned char *)"") // "Langas nerastas")
#define KP_MSG_PID_NOT_FOUND_LT     ((const unsigned char *)"") // "Nerastas proceso identifikatorius")
#define KP_MSG_NO_SOCKET_LT         ((const unsigned char *)"") // "Jungtis dar nesukurta")
#define KP_MSG_SOCK_UNRESOLVED_LT   ((const unsigned char *)"") // "Tarnybinės stoties adresas dar nesurastas")

#define KP_MSG_ERR_OK_LT            ((const unsigned char *)"") // "Operacija atlikta sėkmingai") // !!!
#define KP_MSG_INVALIDARG_LT        ((const unsigned char *)"") // "Neteisingi parametrai")
#define KP_MSG_NOTIMPL_LT           ((const unsigned char *)"") // "Funkcija dar nerealizuota")
#define KP_MSG_UNEXPECTED_LT        ((const unsigned char *)"") // "Netikėtas kreipinys į sąsają")
#define KP_MSG_FERROR_LT            ((const unsigned char *)"") // "Failo skaitymo/rašymo klaida")
#define KP_MSG_SYSTEM_ERROR_LT      ((const unsigned char *)"") // "Klaida sistemoje")
#define KP_MSG_EOF_LT               ((const unsigned char *)"") // "Neteisinga failo pabaiga")
#define KP_MSG_FILE_FORMAT_LT       ((const unsigned char *)"") // "Neteisingas failo formatas")
#define KP_MSG_FILE_NOT_FOUND_LT    ((const unsigned char *)"") // "Failas nerastas")
#define KP_MSG_DIR_ERROR_LT         ((const unsigned char *)"") // "Nepavyko atverti/sukurti failo")
#define KP_MSG_OUTOFMEM_LT          ((const unsigned char *)"") // "Trūksta atminties")
#define KP_MSG_NO_FILE_LT           ((const unsigned char *)"") // "Failas neatvertas")
#define KP_MSG_DOUBLE_UNGET_LT      ((const unsigned char *)"") // "Dvigubas įvedimo grąžinimas")
#define KP_MSG_UNKN_CHR_LT          ((const unsigned char *)"") // "Neatpažintas simbolis")
#define KP_MSG_COMMAND_ERROR_LT     ((const unsigned char *)"") // "Išorinė klaida")
#define KP_MSG_BUFFER_OVERFLOW_LT   ((const unsigned char *)"") // "Persipildė buferis")
#define KP_MSG_FONT_UNDEF_LT        ((const unsigned char *)"") // "Neapibrėžtas šriftas")
#define KP_MSG_KWD_NOT_FOUND_LT     ((const unsigned char *)"") // "Raktinis žodis nerastas")
#define KP_MSG_UNKNOWN_SYSTEM_LT    ((const unsigned char *)"") // "Operacinė sistema neatpažinta")
#define KP_MSG_ILL_CODE_LT          ((const unsigned char *)"") // "Klaidingas registracijos kodas")
#define KP_MSG_CANCELLED_LT         ((const unsigned char *)"") // "Operacija nutraukta")
#define KP_MSG_DOUBLE_CALL_LT       ((const unsigned char *)"") // "Dvigubas iškvietimas")
#define KP_MSG_TIMEOUT_LT           ((const unsigned char *)"") // "Viršytas laukimo laikas")
#define KP_MSG_OBJ_NOT_FOUND_LT     ((const unsigned char *)"") // "Objektas nerastas")
#define KP_MSG_NO_CONN_LT           ((const unsigned char *)"") // "Nėra ryšio")

#define KP_MSG_TRANS_ERR_LT         ((const unsigned char *)"") // "Perdavimo klaida")
#define KP_MSG_TRANS_ERR_1_LT       ((const unsigned char *)"") // "Ryšio klaida, pakartokite siuntimo procedūrą"

#define KP_MSG_REFUSED_LT           ((const unsigned char *)"") // "Registracija atmesta")
#define KP_MSG_ACCESS_DENIED_LT     ((const unsigned char *)"") // "Neleista prisijungti")
#define KP_MSG_ILLEGAL_CHARACTER_LT ((const unsigned char *)"") // "Neleistinas simbolis")
#define KP_MSG_DIV_ZERO_LT          ((const unsigned char *)"") // "Dalyba iš nulio")
#define KP_MSG_ILLMATHARG_LT        ((const unsigned char *)"") // "Neleistinas matematinės funkcijos argumentas") // "Šaknis iš neigiamo skaičiaus"
#define KP_MSG_ILLFUNC_LT           ((const unsigned char *)"") // "Neleistina operacija") // illegal function call (at the moment)

#define KP_MSG_NOTINST_LT           ((const unsigned char *)"") // "Programa neįdiegta arba diegimas sugedo, pakartokite diegimo procedūrą")
#define KP_MSG_NOTINST_S_LT         ((const unsigned char *)"") // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE_LT    ((const unsigned char *)"") // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT_LT        ((const unsigned char *)"") // "Neteisingas pranešimo formatas")
#define KP_MSG_OBSOLETE_LT          ((const unsigned char *)"") // "Pasenusi funkcija")

#define KP_MSG_ERROR_HELP_LT        ((const unsigned char *)"") // ".  Dėl techninės pagalbos kreipkitės elektroniniu paštu, adresu tech@tev.lt")
#define KP_MSG_ERROR_HELP_REST_LT   ((const unsigned char *)"") // "   Prie laiško prikabinkite failą %s")

#define KP_MSG_WSAEACCES_LT               ((const unsigned char *)"") // "Teisės nesuteiktos")
#define KP_MSG_WSAEADDRINUSE_LT           ((const unsigned char *)"") // "Adresas jau naudojamas")
#define KP_MSG_WSAEADDRNOTAVAIL_LT        ((const unsigned char *)"") // "Prašomas adresas negali būti priskirtas")
#define KP_MSG_WSAEAFNOSUPPORT_LT         ((const unsigned char *)"") // "Adresų šeimos grupė nepalaikoma protokolo")
#define KP_MSG_WSAEALREADY_LT             ((const unsigned char *)"") // "Operacija jau vykdoma")
#define KP_MSG_WSAECONNABORTED_LT         ((const unsigned char *)"") // "Programa iššaukė ryšio nutraukimą")
#define KP_MSG_WSAECONNREFUSED_LT         ((const unsigned char *)"") // "Susijungimas atmestas")
#define KP_MSG_WSAECONNRESET_LT           ((const unsigned char *)"") // "Sujungimas nutrauktas")
#define KP_MSG_WSAEDESTADDRREQ_LT         ((const unsigned char *)"") // "Būtinas kreities adresas")
#define KP_MSG_WSAEFAULT_LT               ((const unsigned char *)"") // "Neteisingas adresas")
#define KP_MSG_WSAEHOSTDOWN_LT            ((const unsigned char *)"") // "Serveris laikinai neveikia")
#define KP_MSG_WSAEHOSTUNREACH_LT         ((const unsigned char *)"") // "Serveris nepasiekiamas")
#define KP_MSG_WSAEINPROGRESS_LT          ((const unsigned char *)"") // "Operacija vykdoma")
#define KP_MSG_WSAEINTR_LT                ((const unsigned char *)"") // "Funkcija nutraukta")
#define KP_MSG_WSAEINVAL_LT               ((const unsigned char *)"") // "Neteisingi parametrai")
#define KP_MSG_WSAEISCONN_LT              ((const unsigned char *)"") // "Susijungimas jau įvykęs")
#define KP_MSG_WSAEMFILE_LT               ((const unsigned char *)"") // "Perdaug atvertų failų")
#define KP_MSG_WSAEMSGSIZE_LT             ((const unsigned char *)"") // "Perdaug ilgas pranešimas")
#define KP_MSG_WSAENETDOWN_LT             ((const unsigned char *)"") // "Tinklas neveikia")
#define KP_MSG_WSAENETRESET_LT            ((const unsigned char *)"") // "Atsijungė nuo tinklo")
#define KP_MSG_WSAENETUNREACH_LT          ((const unsigned char *)"") // "Tinklas nepasiekiamas")
#define KP_MSG_WSAENOBUFS_LT              ((const unsigned char *)"") // "Trūksta vietos buferyje")
#define KP_MSG_WSAENOPROTOOPT_LT          ((const unsigned char *)"") // "Neteisinga protokolo parinktis")
#define KP_MSG_WSAENOTCONN_LT             ((const unsigned char *)"") // "Sujungimas nepavyko")
#define KP_MSG_WSAENOTSOCK_LT             ((const unsigned char *)"") // "Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_LT           ((const unsigned char *)"") // "Operacija negali būti atlikta")
#define KP_MSG_WSAEPFNOSUPPORT_LT         ((const unsigned char *)"") // "Protokolo šeima nepalaikoma")
#define KP_MSG_WSAEPROCLIM_LT             ((const unsigned char *)"") // "Perdaug procesų")
#define KP_MSG_WSAEPROTONOSUPPORT_LT      ((const unsigned char *)"") // "Protokolas nepalaikomas")
#define KP_MSG_WSAEPROTOTYPE_LT           ((const unsigned char *)"") // "Neteisingas protokolo sujungimo tipas")
#define KP_MSG_WSAESHUTDOWN_LT            ((const unsigned char *)"") // "Siuntimas nebegalimas, sujungimas nutrauktas")
#define KP_MSG_WSAESOCKTNOSUPPORT_LT      ((const unsigned char *)"") // "Sujungimo tipas nepalaikomas")
#define KP_MSG_WSAETIMEDOUT_LT            ((const unsigned char *)"") // "Maksimalus sujungimo laukimo laikas viršytas")
#define KP_MSG_WSATYPE_NOT_FOUND_LT       ((const unsigned char *)"") // "Klasės tipas nerastas")
#define KP_MSG_WSAEWOULDBLOCK_LT          ((const unsigned char *)"") // "Šaltinis laikinai nepasiekiamas")
#define KP_MSG_WSAHOST_NOT_FOUND_LT       ((const unsigned char *)"") // "Serveris nerastas")
#define KP_MSG_WSA_INVALID_HANDLE_LT      ((const unsigned char *)"") // "Klaidingas objekto valdiklis") // "Klaidingas pasirinkto įvykio objekto valdiklis"
#define KP_MSG_WSA_INVALID_PARAMETER_LT   ((const unsigned char *)"") // "Neteisingi parametrai") // "Neteisingi vienas ar daugiau parametrų"
#define KP_MSG_WSAINVALIDPROCTABLE_LT     ((const unsigned char *)"") // "Klaidinga procedūrų lentelė")
#define KP_MSG_WSAINVALIDPROVIDER_LT      ((const unsigned char *)"") // "Neteisingas tiekėjo kodas")
#define KP_MSG_WSA_IO_INCOMPLETE_LT       ((const unsigned char *)"") // "Persikloja įvesties/išvesties įvykiai")
#define KP_MSG_WSA_IO_PENDING_LT          ((const unsigned char *)"") // "Persiklojančios operacijos bus atliktos vėliau")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_LT   ((const unsigned char *)"") // "Nepakanka atminties")
#define KP_MSG_WSANOTINITIALISED_LT       ((const unsigned char *)"") // "Tinklo posistemis neaktyvuotas")
#define KP_MSG_WSANO_DATA_LT              ((const unsigned char *)"") // "Vardas teisingas, tačiau nėra reikiamo tipo duomenų")
#define KP_MSG_WSANO_RECOVERY_LT          ((const unsigned char *)"") // "Nepataisoma klaida")
#define KP_MSG_WSAPROVIDERFAILEDINIT_LT   ((const unsigned char *)"") // "Negalima inicializuoti paslaugos tiekėjo")
#define KP_MSG_WSASYSCALLFAILURE_LT       ((const unsigned char *)"") // "Sistemos kreipinio klaida")
#define KP_MSG_WSASYSNOTREADY_LT          ((const unsigned char *)"") // "Tinklo posistemė nepasiekiama")
#define KP_MSG_WSATRY_AGAIN_LT            ((const unsigned char *)"") // "Neautorizuotas serveris nerastas")
#define KP_MSG_WSAVERNOTSUPPORTED_LT      ((const unsigned char *)"") // "Netinka WINSOCK.DLL versija")
#define KP_MSG_WSAEDISCON_LT              ((const unsigned char *)"") // "Pradėtas tvarkingas išjungimas") // ((const unsigned char *)"Pradėtas gracingas išjungimas")
#define KP_MSG_WSA_OPERATION_ABORTED_LT   ((const unsigned char *)"") // "Persiklojanti operacija nutraukta")

#define KP_MSG_OUT_OF_MEM_RES_LT          ((const unsigned char *)"") // "Operacinei sistemai trūksta atminties")
#define KP_MSG_ERROR_FILE_NOT_FOUND_LT    ((const unsigned char *)"") // "Nurodytas failas nerastas")
#define KP_MSG_ERROR_PATH_NOT_FOUND_LT    ((const unsigned char *)"") // "Nurodytas kelias iki failų nerastas")
#define KP_MSG_ERROR_BAD_FORMAT_LT        ((const unsigned char *)"") // "Pasirinktas .exe failas sugadintas")
#define KP_MSG_SE_ERR_ACCESSDENIED_LT     ((const unsigned char *)"") // "Operacinė sistema uždraudė prisijungimą prie reikiamų failų")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_LT  ((const unsigned char *)"") // "Failo sąryšis su programa nepilnas arba neteisingas")
#define KP_MSG_SE_ERR_DDEBUSY_LT          ((const unsigned char *)"") // "DDE transakcija negali būti baigta, nes kitos DDE transakcijos dar vykdomos")
#define KP_MSG_SE_ERR_DDEFAIL_LT          ((const unsigned char *)"") // "DDE transakcija nutraukta")
#define KP_MSG_SE_ERR_DDETIMEOUT_LT       ((const unsigned char *)"") // "DDE transakcija negali būti baigta, nes neužteko nurodyto laukimo laiko")
#define KP_MSG_SE_ERR_DLLNOTFOUND_LT      ((const unsigned char *)"") // "Nurodyta dinaminė biblioteka nerasta")
#define KP_MSG_SE_ERR_FNF_LT              ((const unsigned char *)"") // "Nurodytas failas nerastas")
#define KP_MSG_SE_ERR_NOASSOC_LT          ((const unsigned char *)"") // "Nerasta programa skirta atverti šio tipo failus")
#define KP_MSG_SE_ERR_OOM_LT              ((const unsigned char *)"") // "Nepakanka atminties atlikti operacijai")
#define KP_MSG_SE_ERR_PNF_LT              ((const unsigned char *)"") // "Nurodytas kelias nerastas")
#define KP_MSG_SE_ERR_SHARE_LT            ((const unsigned char *)"") // "Dalijimosi klaida")

#define KP_MSG_FIRST_TIME_ADMIN_LT        ((const unsigned char *)"") // "Programą paleidžiant pirmą kartą, reikalingos\n administratoriaus teisės. Paleiskite programą iš naujo administratoriaus teisėmis.")
#define KP_MSG_NOW_NOT_ADMIN_LT           KP_MSG_NOT_ADMIN_LT // ((const unsigned char *)"") // "Dabar programą paleiskite dar kartą paprasto vartotojo teisėmis")
#define KP_MSG_NOT_ADMIN_LT               ((const unsigned char *)"") // "Programą paleiskite iš naujo paprasto vartotojo teisėmis")
#define KP_MSG_COPY_FILE_ACCESS_DENIED_LT ((const unsigned char *)"") // "Failo nukopijuoti nepavyko, programą paleiskite iš naujo administratoriaus teisėmis")

#define KP_PROGRESS_TITLE_LT              ((const unsigned char *)"") // "Palaukite...")
#define KP_MSG_DELETING_FILE_LT           ((const unsigned char *)"") // "Naikinamas failas %s.%s...")
#define KP_MSG_COPYING_LT                 ((const unsigned char *)"") // "Kopijuojamas failas...")
#define KP_MSG_COPYING_FILE_LT            ((const unsigned char *)"") // "Kopijuojamas failas %s.%s...")
#define KP_MSG_COPYING_DIR_LT             ((const unsigned char *)"") // "Kopijuojamas aplankas %s.%s...")

#define KP_MSG_NEG_ANSW_LT                ((const unsigned char *)"") // "Neigiamas atsakymas")

#define KP_MSG_UNABLE_TO_EXECUTE_LT       ((const unsigned char *)"") // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL_LT    ((const unsigned char *)"") // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED_LT            ((const unsigned char *)"") // "Failas pasikeitė"

#define KP_MSG_ALL_FILES_LT               ((const unsigned char *)"") // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS_LT                 ((const unsigned char *)"") // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS_LT             ((const unsigned char *)"") // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG_LT                ((const unsigned char *)"") // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE_LT          ((const unsigned char *)"") // "Diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL_LT           ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_LT   ((const unsigned char *)"") // "Jūsų e-pašto adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_LT ((const unsigned char *)"") // "Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_LT    ((const unsigned char *)"") // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_LT       ((const unsigned char *)"") // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE_LT       ((const unsigned char *)"") // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED_LT      ((const unsigned char *)"") // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1_LT          ((const unsigned char *)"") // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI_LT                  ((const unsigned char *)"") // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2_LT          ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING_LT             ((const unsigned char *)"") // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE_LT        ((const unsigned char *)"") // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL_LT                ((const unsigned char *)"") // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER_LT                 ((const unsigned char *)"") // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED_LT             ((const unsigned char *)"") // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE_LT              ((const unsigned char *)"") // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION_LT     ((const unsigned char *)"") // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT_LT             ((const unsigned char *)"") // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR_LT                 ((const unsigned char *)"") // "Duomenų bazės klaida"

#endif // #if ((MsgLang != KpLangSel_p) && (MsgLang != KpLangLt_p))


// --------------------------------
#if ((MsgLang != KpLangPl_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangPl_1250_p))

#define KP_MSG_TITLE_PL_1250              ((const unsigned char *)"") // "Komunikat")
#define KP_INPUT_TITLE_PL_1250            ((const unsigned char *)"") // "Wprowadzanie"

#define KP_MSG_TAIP_PL_1250               ((const unsigned char *)"") // "Tak")
#define KP_MSG_YES_PL_1250                KP_MSG_TAIP
#define KP_MSG_NE_PL_1250                 ((const unsigned char *)"") // "Nie")
#define KP_MSG_NO_PL_1250                 KP_MSG_NE
#define KP_MSG_GERAI_PL_1250              ((const unsigned char *)"") // "Dobrze")
#define KP_MSG_OK_PL_1250                 KP_MSG_GERAI
#define KP_MSG_ATSAUKTI_PL_1250           ((const unsigned char *)"") // "Odwo³aj")
#define KP_MSG_CANCEL_PL_1250             KP_MSG_ATSAUKTI
#define KP_MSG_TESTI_PL_1250              ((const unsigned char *)"") // "Dalej")
#define KP_MSG_BAIGTI_PL_1250             ((const unsigned char *)"") // "Zakończ")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_PL_1250 ((const unsigned char *)"") // "Zapomnia³em has³o")

#define KP_MSG_ERROR_PL_1250              ((const unsigned char *)"") // "B³¹d")
#define KP_MSG_WARNING_PL_1250            ((const unsigned char *)"") // "Ostrzeæenie")
#define KP_MSG_FILE_LINE_PL_1250          ((const unsigned char *)"") // ", plik:%s, linijka:%d")
#define KP_MSG_ENTRY_ID_PL_1250           ((const unsigned char *)"") // ", Nr. wpisu:%ld")
#define KP_MSG_ENTRY_PL_1250              ((const unsigned char *)"") // ", Wpis: %s")

#define KP_MSG_NO_STANDARD_PROG_PL_1250   ((const unsigned char *)"") // "Nie znaleziono programu do otwierania plików tego typu")
#define KP_MSG_WND_NOT_FOUND_PL_1250      ((const unsigned char *)"") // "Nie znaleziono okna")
#define KP_MSG_PID_NOT_FOUND_PL_1250      ((const unsigned char *)"") // "Nie znaleziono indentyfikatora procesu")
#define KP_MSG_NO_SOCKET_PL_1250          ((const unsigned char *)"") // "Wiź jeszcze nie stworzona")
#define KP_MSG_SOCK_UNRESOLVED_PL_1250    ((const unsigned char *)"") // "Nie znaleziono adresu stacji s³uæbowej")

#define KP_MSG_ERR_OK_PL_1250             ((const unsigned char *)"") // "Operacja wykonana")
#define KP_MSG_INVALIDARG_PL_1250         ((const unsigned char *)"") // "B³źdne parametry")
#define KP_MSG_NOTIMPL_PL_1250            ((const unsigned char *)"") // "W³aciwoę jeszcze nie zrealizowana")
#define KP_MSG_UNEXPECTED_PL_1250         ((const unsigned char *)"") // "Nieoczekiwny zwrot do interfejsu")
#define KP_MSG_FERROR_PL_1250             ((const unsigned char *)"") // "B³¹d sczytywania/zapisywania pliku")
#define KP_MSG_SYSTEM_ERROR_PL_1250       ((const unsigned char *)"") // "B³¹d systemu")
#define KP_MSG_EOF_PL_1250                ((const unsigned char *)"") // "Nieprawid³owe zakończenie pliku")
#define KP_MSG_FILE_FORMAT_PL_1250        ((const unsigned char *)"") // "Nieprawid³owy format pliku")
#define KP_MSG_FILE_NOT_FOUND_PL_1250     ((const unsigned char *)"") // "Nie znaleziono pliku")
#define KP_MSG_DIR_ERROR_PL_1250          ((const unsigned char *)"") // "Nie uda³o siź otworzyę/stworzyę pliku")
#define KP_MSG_OUTOFMEM_PL_1250           ((const unsigned char *)"") // "Niewystarcza pamiźci")
#define KP_MSG_NO_FILE_PL_1250            ((const unsigned char *)"") // "Nie otworzono pliku")
#define KP_MSG_DOUBLE_UNGET_PL_1250       ((const unsigned char *)"") // "Podwójny unget")
#define KP_MSG_UNKN_CHR_PL_1250           ((const unsigned char *)"") // "Nierozpoznano symbol")
#define KP_MSG_COMMAND_ERROR_PL_1250      ((const unsigned char *)"") // "B³¹d zewnźtrzny")

#define KP_MSG_BUFFER_OVERFLOW_PL_1250    ((const unsigned char *)"") // "Przepe³niony bufor")
#define KP_MSG_FONT_UNDEF_PL_1250         ((const unsigned char *)"") // "Nieokrelono szryft")
#define KP_MSG_KWD_NOT_FOUND_PL_1250      ((const unsigned char *)"") // "Nie znaleziono kluczowego s³owa")
#define KP_MSG_UNKNOWN_SYSTEM_PL_1250     ((const unsigned char *)"") // "Nie rozpoznano systemu operacyjnego")
#define KP_MSG_ILL_CODE_PL_1250           ((const unsigned char *)"") // "B³źdny kod rejestracji")

#define KP_MSG_CANCELLED_PL_1250          ((const unsigned char *)"") // "Przerwano operacjź")
#define KP_MSG_DOUBLE_CALL_PL_1250        ((const unsigned char *)"") // "Podwójne wywo³anie")
#define KP_MSG_TIMEOUT_PL_1250            ((const unsigned char *)"") // "Przekroczono czas oczekiwania")
#define KP_MSG_OBJ_NOT_FOUND_PL_1250      ((const unsigned char *)"") // "Nie znaleziono objektu")

#define KP_MSG_NO_CONN_PL_1250            ((const unsigned char *)"") // "Nie ma ³¹cznoci")

#define KP_MSG_TRANS_ERR_PL_1250          ((const unsigned char *)"") // "B³¹d przekazu")
#define KP_MSG_TRANS_ERR_1_PL_1250        ((const unsigned char *)"") // "B³¹d przekazu. Zapuszczaj wysy³anie ponownie"

#define KP_MSG_REFUSED_PL_1250            ((const unsigned char *)"") // "Odrzucono rejestracjź")
#define KP_MSG_ACCESS_DENIED_PL_1250      ((const unsigned char *)"") // "£¹cznoę niedozwolona")
#define KP_MSG_ILLEGAL_CHARACTER_PL_1250  ((const unsigned char *)"") // "Niedopuszczalny symbol")
#define KP_MSG_DIV_ZERO_PL_1250           ((const unsigned char *)"") // "Dzielenie przez zero")
#define KP_MSG_ILLMATHARG_PL_1250         ((const unsigned char *)"") // "Niedopuszczalny argument matematycznej funkcji")
#define KP_MSG_ILLFUNC_PL_1250            ((const unsigned char *)"") // "Niedopuszczalna operacja")

#define KP_MSG_NOTINST_PL_1250            ((const unsigned char *)"") // "Program nie zainstalowany lub zepsuta instalacja. Zainstaluj ponownie")
#define KP_MSG_NOTINST_S_PL_1250          ((const unsigned char *)"") // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE_PL_1250     ((const unsigned char *)"") // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT_PL_1250         ((const unsigned char *)"") // "B³źdny format komunikatu")
#define KP_MSG_OBSOLETE_PL_1250           ((const unsigned char *)"") // "Stara funkcja")
#define KP_MSG_ERROR_HELP_PL_1250         ((const unsigned char *)"") // ".  Po pomoc techniczn¹ zwróę siź pod adres tech@tev.lt")
#define KP_MSG_ERROR_HELP_REST_PL_1250    ((const unsigned char *)"") // "   Do listu za³¹cz plik %s")
#define KP_MSG_WSAEACCES_PL_1250               ((const unsigned char *)"") // "Nie masz uprawnienia")
#define KP_MSG_WSAEADDRINUSE_PL_1250           ((const unsigned char *)"") // "Adres jest juæ wykorzystany")
#define KP_MSG_WSAEADDRNOTAVAIL_PL_1250        ((const unsigned char *)"") // "Wskazany adres nie moæe byę przy³¹czony")
#define KP_MSG_WSAEAFNOSUPPORT_PL_1250         ((const unsigned char *)"") // "Grupa adresów nie podtrzymywana przez protokó³")
#define KP_MSG_WSAEALREADY_PL_1250             ((const unsigned char *)"") // "Operacja juæ jest wykonywana")
#define KP_MSG_WSAECONNABORTED_PL_1250         ((const unsigned char *)"") // "Program wywo³a³ rozerwanie po³¹czenia")
#define KP_MSG_WSAECONNREFUSED_PL_1250         ((const unsigned char *)"") // "Po³¹czenie zosta³o odrzucone")

#define KP_MSG_WSAECONNRESET_PL_1250           ((const unsigned char *)"") // "Po³¹czenie zosta³o rozerwane")
#define KP_MSG_WSAEDESTADDRREQ_PL_1250         ((const unsigned char *)"") // "Wymagany jest adres")
#define KP_MSG_WSAEFAULT_PL_1250               ((const unsigned char *)"") // "B³źdny adres")

#define KP_MSG_WSAEHOSTDOWN_PL_1250            ((const unsigned char *)"") // "Serwer czasowo niedostźpny")
#define KP_MSG_WSAEHOSTUNREACH_PL_1250         ((const unsigned char *)"") // "Serwer jest nieosi¹galny")
#define KP_MSG_WSAEINPROGRESS_PL_1250          ((const unsigned char *)"") // "Operacja jest wykonywana")
#define KP_MSG_WSAEINTR_PL_1250                ((const unsigned char *)"") // "Funkcja zosta³a przerwana")

#define KP_MSG_WSAEINVAL_PL_1250               ((const unsigned char *)"") // "B³źdne parametry")
#define KP_MSG_WSAEISCONN_PL_1250              ((const unsigned char *)"") // "Po³¹czenie juæ jest nawi¹zane")
#define KP_MSG_WSAEMFILE_PL_1250               ((const unsigned char *)"") // "Otworzono za duæo plików")

#define KP_MSG_WSAEMSGSIZE_PL_1250             ((const unsigned char *)"") // "Zbyt d³ugi komunikat")
#define KP_MSG_WSAENETDOWN_PL_1250             ((const unsigned char *)"") // "Sieę nie dzia³a")
#define KP_MSG_WSAENETRESET_PL_1250            ((const unsigned char *)"") // "Od³¹czono siź od sieci")

#define KP_MSG_WSAENETUNREACH_PL_1250          ((const unsigned char *)"") // "Sieę nieosi¹galna")
#define KP_MSG_WSAENOBUFS_PL_1250              ((const unsigned char *)"") // "Brakuje miejsca w buforze")
#define KP_MSG_WSAENOPROTOOPT_PL_1250          ((const unsigned char *)"") // "B³źdne opcje protoko³u")

#define KP_MSG_WSAENOTCONN_PL_1250             ((const unsigned char *)"") // "Nieudane po³¹czenie")
#define KP_MSG_WSAENOTSOCK_PL_1250             ((const unsigned char *)"") // "Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_PL_1250           ((const unsigned char *)"") // "Operacja nie moæe byę wykonana")

#define KP_MSG_WSAEPFNOSUPPORT_PL_1250         ((const unsigned char *)"") // "Niepodtrzymywana rodzina protoko³ów")
#define KP_MSG_WSAEPROCLIM_PL_1250             ((const unsigned char *)"") // "Zbyt duæo procesów")
#define KP_MSG_WSAEPROTONOSUPPORT_PL_1250      ((const unsigned char *)"") // "Protokó³ nie jest podtrzymywany")

#define KP_MSG_WSAEPROTOTYPE_PL_1250           ((const unsigned char *)"") // "Nieprawid³owy typ po³¹czenia protoko³u")
#define KP_MSG_WSAESHUTDOWN_PL_1250            ((const unsigned char *)"") // "Wysy³anie niemoæliwe, po³¹czenie zerwane")
#define KP_MSG_WSAESOCKTNOSUPPORT_PL_1250      ((const unsigned char *)"") // "Typ po³¹czenia niepodtrzymywany")
#define KP_MSG_WSAETIMEDOUT_PL_1250            ((const unsigned char *)"") // "Przewyæszono maksymalny czas oczekiwania po³¹czenia")

#define KP_MSG_WSATYPE_NOT_FOUND_PL_1250       ((const unsigned char *)"") // "Nie znaleziono typ klasy")
#define KP_MSG_WSAEWOULDBLOCK_PL_1250          ((const unsigned char *)"") // "¸ród³o czasowo niedostźpne")
#define KP_MSG_WSAHOST_NOT_FOUND_PL_1250       ((const unsigned char *)"") // "Nie znaleziono serweru")
#define KP_MSG_WSA_INVALID_HANDLE_PL_1250      ((const unsigned char *)"") // "B³źdny kontroler objektu")
#define KP_MSG_WSA_INVALID_PARAMETER_PL_1250   ((const unsigned char *)"") // "B³źdne parametry")
#define KP_MSG_WSAINVALIDPROCTABLE_PL_1250     ((const unsigned char *)"") // "B³źdna tablica procedur")
#define KP_MSG_WSAINVALIDPROVIDER_PL_1250      ((const unsigned char *)"") // "B³źdny kod dostawcy")
#define KP_MSG_WSA_IO_INCOMPLETE_PL_1250       ((const unsigned char *)"") // "Nak³adaj¹ siź zdarzenia wprowdzania/wyprowadzania")
#define KP_MSG_WSA_IO_PENDING_PL_1250          ((const unsigned char *)"") // "Nak³adaj¹ce siź operacje bźd¹ wykonane póniej")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_PL_1250   ((const unsigned char *)"") // "Brak pamiźci")
#define KP_MSG_WSANOTINITIALISED_PL_1250       ((const unsigned char *)"") // "Podsystem sieci nieaktywowany")
#define KP_MSG_WSANO_DATA_PL_1250              ((const unsigned char *)"") // "Nie ma danych wymaganego typu")
#define KP_MSG_WSANO_RECOVERY_PL_1250          ((const unsigned char *)"") // "Nienaprawialny b³¹d")
#define KP_MSG_WSAPROVIDERFAILEDINIT_PL_1250   ((const unsigned char *)"") // "Nie moæliwa jest inicjacja dostawcy us³ugi")
#define KP_MSG_WSASYSCALLFAILURE_PL_1250       ((const unsigned char *)"") // "B³źdny zwrot systemu")
#define KP_MSG_WSASYSNOTREADY_PL_1250          ((const unsigned char *)"") // "Podsystem sieci nieosi¹galny")
#define KP_MSG_WSATRY_AGAIN_PL_1250            ((const unsigned char *)"") // "Nieautoryzowany serwer nie znaleziony")

#define KP_MSG_WSAVERNOTSUPPORTED_PL_1250      ((const unsigned char *)"") // "B³źdna wersja WINSOCK.DLL")
#define KP_MSG_WSAEDISCON_PL_1250              ((const unsigned char *)"") // "Rozpoczźto porz¹dne wy³¹czanie")
#define KP_MSG_WSA_OPERATION_ABORTED_PL_1250   ((const unsigned char *)"") // "Nak³adaj¹ca siź operacja przerwana")

#define KP_MSG_OUT_OF_MEM_RES_PL_1250          ((const unsigned char *)"") // "Brak pamiźci systemu operacyjnego")
#define KP_MSG_ERROR_FILE_NOT_FOUND_PL_1250    ((const unsigned char *)"") // "Nie znaleziono wskazanego pliku")
#define KP_MSG_ERROR_PATH_NOT_FOUND_PL_1250    ((const unsigned char *)"") // "Nie znaleziono wskazanej cieæki do pliku")
#define KP_MSG_ERROR_BAD_FORMAT_PL_1250        ((const unsigned char *)"") // "Wybrany plik .exe jest zepsuty")
#define KP_MSG_SE_ERR_ACCESSDENIED_PL_1250     ((const unsigned char *)"") // "System operacyjny zabroni³ ³¹cznoci z potrzebnymi plikami")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_PL_1250  ((const unsigned char *)"") // "Wiź pliku z programem jest niepe³na lub b³źdna")
#define KP_MSG_SE_ERR_DDEBUSY_PL_1250          ((const unsigned char *)"") // "DDE transakcja nie moæe byę zakończona, bo inne DDE transakcje s¹ jeszcze wykonywane")
#define KP_MSG_SE_ERR_DDEFAIL_PL_1250          ((const unsigned char *)"") // "DDE transakcja przerwana")
#define KP_MSG_SE_ERR_DDETIMEOUT_PL_1250       ((const unsigned char *)"") // "DDE transakcja nie moæe byę zakończona, bo zabrak³o wskazanego czasu oczekiwania")
#define KP_MSG_SE_ERR_DLLNOTFOUND_PL_1250      ((const unsigned char *)"") // "Nie znaleziono wskazanej biblioteki dynamicznej")
#define KP_MSG_SE_ERR_FNF_PL_1250              ((const unsigned char *)"") // "Nie znaleziono wskazanego pliku")
#define KP_MSG_SE_ERR_NOASSOC_PL_1250          ((const unsigned char *)"") // "Nie znaleziono programu do otwarcia plików danego typu")

#define KP_MSG_SE_ERR_OOM_PL_1250              ((const unsigned char *)"") // "Brak pamiźci do wykonania operacji")
#define KP_MSG_SE_ERR_PNF_PL_1250              ((const unsigned char *)"") // "Nie znaleziono wskazanej cieæki")
#define KP_MSG_SE_ERR_SHARE_PL_1250            ((const unsigned char *)"") // "B³¹d podzia³u")

#define KP_MSG_FIRST_TIME_ADMIN_PL_1250        ((const unsigned char *)"") // "Zapuszczaj¹c program poraz pierwszy wymagane s¹ uprawnienia administratora. Zapuę program ponownie z uprawnieniami administratora.")

#define KP_MSG_NOW_NOT_ADMIN_PL_1250           KP_MSG_NOT_ADMIN_PL_1250
#define KP_MSG_NOT_ADMIN_PL_1250               ((const unsigned char *)"") // "Zapuę program ponownie z uprawnieniami zwyk³ego uæytkownika")

#define KP_MSG_COPY_FILE_ACCESS_DENIED_PL_1250 ((const unsigned char *)"") // "Nie uda³o siź skopiowaę pliku. Zapuę program ponownie z uprawnieniami administratora.")


#define KP_PROGRESS_TITLE_PL_1250               ((const unsigned char *)"") // "Zaczekaj...")
#define KP_MSG_DELETING_FILE_PL_1250            ((const unsigned char *)"") // "Kasuje siź plik %s.%s...")

#define KP_MSG_COPYING_PL_1250                  ((const unsigned char *)"") // "Kopiuje siź plik...")

#define KP_MSG_COPYING_DIR_PL_1250              ((const unsigned char *)"") // "Kopiuje siź katalog %s.%s...")
#define KP_MSG_COPYING_FILE_PL_1250             ((const unsigned char *)"") // "Kopiuje siź plik %s.%s...")

#define KP_MSG_NEG_ANSW_PL_1250                 ((const unsigned char *)"") // "Neigiamas atsakymas")

#define KP_MSG_UNABLE_TO_EXECUTE_PL_1250        ((const unsigned char *)"") // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL_PL_1250     ((const unsigned char *)"") // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED_PL_1250             ((const unsigned char *)"") // "Failas pasikeitė"

#define KP_MSG_ALL_FILES_PL_1250                ((const unsigned char *)"") // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS_PL_1250                  ((const unsigned char *)"") // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS_PL_1250              ((const unsigned char *)"") // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG_PL_1250                 ((const unsigned char *)"") // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE_PL_1250           ((const unsigned char *)"") // "Diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL_PL_1250            ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_PL_1250    ((const unsigned char *)"") // "Jūsų e-pašto adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_PL_1250 ((const unsigned char *)"") // "Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_PL_1250     ((const unsigned char *)"") // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_PL_1250        ((const unsigned char *)"") // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE_PL_1250        ((const unsigned char *)"") // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED_PL_1250       ((const unsigned char *)"") // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1_PL_1250           ((const unsigned char *)"") // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI_PL_1250                   ((const unsigned char *)"") // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2_PL_1250           ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING_PL_1250              ((const unsigned char *)"") // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE_PL_1250         ((const unsigned char *)"") // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL_PL_1250                 ((const unsigned char *)"") // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER_PL_1250                  ((const unsigned char *)"") // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED_PL_1250              ((const unsigned char *)"") // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE_PL_1250               ((const unsigned char *)"") // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION_PL_1250      ((const unsigned char *)"") // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT_PL_1250              ((const unsigned char *)"") // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR_PL_1250                  ((const unsigned char *)"") // "Duomenų bazės klaida"

#endif // #if ((MsgLang != KpLangPl_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangPl_1250_p))

// --------------------------------
#if ((MsgLang != KpLangPl_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangPl_1257_p))

#define KP_MSG_TITLE_PL_1257              ((const unsigned char *)"") // "Komunikat")
#define KP_INPUT_TITLE_PL_1257            ((const unsigned char *)"") // "Wprowadzanie"

#define KP_MSG_TAIP_PL_1257               ((const unsigned char *)"") // "Tak")
#define KP_MSG_YES_PL_1257                KP_MSG_TAIP
#define KP_MSG_NE_PL_1257                 ((const unsigned char *)"") // "Nie")
#define KP_MSG_NO_PL_1257                 KP_MSG_NE
#define KP_MSG_GERAI_PL_1257              ((const unsigned char *)"") // "Dobrze")
#define KP_MSG_OK_PL_1257                 KP_MSG_GERAI
#define KP_MSG_ATSAUKTI_PL_1257           ((const unsigned char *)"") // "Odwołaj")
#define KP_MSG_CANCEL_PL_1257             KP_MSG_ATSAUKTI
#define KP_MSG_TESTI_PL_1257              ((const unsigned char *)"") // "Dalej")
#define KP_MSG_BAIGTI_PL_1257             ((const unsigned char *)"") // "Zakończ")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_PL_1257 ((const unsigned char *)"") // "Zapomniałem hasło")

#define KP_MSG_ERROR_PL_1257              ((const unsigned char *)"") // "Błąd")
#define KP_MSG_WARNING_PL_1257            ((const unsigned char *)"") // "Ostrzeżenie")
#define KP_MSG_FILE_LINE_PL_1257          ((const unsigned char *)"") // ", plik:%s, linijka:%d")
#define KP_MSG_ENTRY_ID_PL_1257           ((const unsigned char *)"") // ", Nr. wpisu:%ld")
#define KP_MSG_ENTRY_PL_1257              ((const unsigned char *)"") // ", Wpis: %s")

#define KP_MSG_NO_STANDARD_PROG_PL_1257   ((const unsigned char *)"") // "Nie znaleziono programu do otwierania plików tego typu")
#define KP_MSG_WND_NOT_FOUND_PL_1257      ((const unsigned char *)"") // "Nie znaleziono okna")
#define KP_MSG_PID_NOT_FOUND_PL_1257      ((const unsigned char *)"") // "Nie znaleziono indentyfikatora procesu")
#define KP_MSG_NO_SOCKET_PL_1257          ((const unsigned char *)"") // "Więź jeszcze nie stworzona")
#define KP_MSG_SOCK_UNRESOLVED_PL_1257    ((const unsigned char *)"") // "Nie znaleziono adresu stacji służbowej")

#define KP_MSG_ERR_OK_PL_1257             ((const unsigned char *)"") // "Operacja wykonana")
#define KP_MSG_INVALIDARG_PL_1257         ((const unsigned char *)"") // "Błędne parametry")
#define KP_MSG_NOTIMPL_PL_1257            ((const unsigned char *)"") // "Właściwość jeszcze nie zrealizowana")
#define KP_MSG_UNEXPECTED_PL_1257         ((const unsigned char *)"") // "Nieoczekiwny zwrot do interfejsu")
#define KP_MSG_FERROR_PL_1257             ((const unsigned char *)"") // "Błąd sczytywania/zapisywania pliku")
#define KP_MSG_SYSTEM_ERROR_PL_1257       ((const unsigned char *)"") // "Błąd systemu")
#define KP_MSG_EOF_PL_1257                ((const unsigned char *)"") // "Nieprawidłowe zakończenie pliku")
#define KP_MSG_FILE_FORMAT_PL_1257        ((const unsigned char *)"") // "Nieprawidłowy format pliku")
#define KP_MSG_FILE_NOT_FOUND_PL_1257     ((const unsigned char *)"") // "Nie znaleziono pliku")
#define KP_MSG_DIR_ERROR_PL_1257          ((const unsigned char *)"") // "Nie udało się otworzyć/stworzyć pliku")
#define KP_MSG_OUTOFMEM_PL_1257           ((const unsigned char *)"") // "Niewystarcza pamięci")
#define KP_MSG_NO_FILE_PL_1257            ((const unsigned char *)"") // "Nie otworzono pliku")
#define KP_MSG_DOUBLE_UNGET_PL_1257       ((const unsigned char *)"") // "Podwójny unget")
#define KP_MSG_UNKN_CHR_PL_1257           ((const unsigned char *)"") // "Nierozpoznano symbol")
#define KP_MSG_COMMAND_ERROR_PL_1257      ((const unsigned char *)"") // "Błąd zewnętrzny")

#define KP_MSG_BUFFER_OVERFLOW_PL_1257    ((const unsigned char *)"") // "Przepełniony bufor")
#define KP_MSG_FONT_UNDEF_PL_1257         ((const unsigned char *)"") // "Nieokreślono szryft")
#define KP_MSG_KWD_NOT_FOUND_PL_1257      ((const unsigned char *)"") // "Nie znaleziono kluczowego słowa")
#define KP_MSG_UNKNOWN_SYSTEM_PL_1257     ((const unsigned char *)"") // "Nie rozpoznano systemu operacyjnego")
#define KP_MSG_ILL_CODE_PL_1257           ((const unsigned char *)"") // "Błędny kod rejestracji")

#define KP_MSG_CANCELLED_PL_1257          ((const unsigned char *)"") // "Przerwano operację")
#define KP_MSG_DOUBLE_CALL_PL_1257        ((const unsigned char *)"") // "Podwójne wywołanie")
#define KP_MSG_TIMEOUT_PL_1257            ((const unsigned char *)"") // "Przekroczono czas oczekiwania")
#define KP_MSG_OBJ_NOT_FOUND_PL_1257      ((const unsigned char *)"") // "Nie znaleziono objektu")

#define KP_MSG_NO_CONN_PL_1257            ((const unsigned char *)"") // "Nie ma łączności")

#define KP_MSG_TRANS_ERR_PL_1257          ((const unsigned char *)"") // "Błąd przekazu")
#define KP_MSG_TRANS_ERR_1_PL_1257        ((const unsigned char *)"") // "Błąd przekazu. Zapuszczaj wysyłanie ponownie"

#define KP_MSG_REFUSED_PL_1257            ((const unsigned char *)"") // "Odrzucono rejestrację")
#define KP_MSG_ACCESS_DENIED_PL_1257      ((const unsigned char *)"") // "Łączność niedozwolona")
#define KP_MSG_ILLEGAL_CHARACTER_PL_1257  ((const unsigned char *)"") // "Niedopuszczalny symbol")
#define KP_MSG_DIV_ZERO_PL_1257           ((const unsigned char *)"") // "Dzielenie przez zero")
#define KP_MSG_ILLMATHARG_PL_1257         ((const unsigned char *)"") // "Niedopuszczalny argument matematycznej funkcji")
#define KP_MSG_ILLFUNC_PL_1257            ((const unsigned char *)"") // "Niedopuszczalna operacja")

#define KP_MSG_NOTINST_PL_1257            ((const unsigned char *)"") // "Program nie zainstalowany lub zepsuta instalacja. Zainstaluj ponownie")
#define KP_MSG_NOTINST_S_PL_1257          ((const unsigned char *)"") // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE_PL_1257     ((const unsigned char *)"") // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT_PL_1257         ((const unsigned char *)"") // "Błędny format komunikatu")
#define KP_MSG_OBSOLETE_PL_1257           ((const unsigned char *)"") // "Stara funkcja")
#define KP_MSG_ERROR_HELP_PL_1257         ((const unsigned char *)"") // ".  Po pomoc techniczną zwróć się pod adres tech@tev.lt")
#define KP_MSG_ERROR_HELP_REST_PL_1257    ((const unsigned char *)"") // "   Do listu załącz plik %s")
#define KP_MSG_WSAEACCES_PL_1257               ((const unsigned char *)"") // "Nie masz uprawnienia")
#define KP_MSG_WSAEADDRINUSE_PL_1257           ((const unsigned char *)"") // "Adres jest już wykorzystany")
#define KP_MSG_WSAEADDRNOTAVAIL_PL_1257        ((const unsigned char *)"") // "Wskazany adres nie może być przyłączony")
#define KP_MSG_WSAEAFNOSUPPORT_PL_1257         ((const unsigned char *)"") // "Grupa adresów nie podtrzymywana przez protokół")
#define KP_MSG_WSAEALREADY_PL_1257             ((const unsigned char *)"") // "Operacja już jest wykonywana")
#define KP_MSG_WSAECONNABORTED_PL_1257         ((const unsigned char *)"") // "Program wywołał rozerwanie połączenia")
#define KP_MSG_WSAECONNREFUSED_PL_1257         ((const unsigned char *)"") // "Połączenie zostało odrzucone")

#define KP_MSG_WSAECONNRESET_PL_1257           ((const unsigned char *)"") // "Połączenie zostało rozerwane")
#define KP_MSG_WSAEDESTADDRREQ_PL_1257         ((const unsigned char *)"") // "Wymagany jest adres")
#define KP_MSG_WSAEFAULT_PL_1257               ((const unsigned char *)"") // "Błędny adres")

#define KP_MSG_WSAEHOSTDOWN_PL_1257            ((const unsigned char *)"") // "Serwer czasowo niedostępny")
#define KP_MSG_WSAEHOSTUNREACH_PL_1257         ((const unsigned char *)"") // "Serwer jest nieosiągalny")
#define KP_MSG_WSAEINPROGRESS_PL_1257          ((const unsigned char *)"") // "Operacja jest wykonywana")
#define KP_MSG_WSAEINTR_PL_1257                ((const unsigned char *)"") // "Funkcja została przerwana")

#define KP_MSG_WSAEINVAL_PL_1257               ((const unsigned char *)"") // "Błędne parametry")
#define KP_MSG_WSAEISCONN_PL_1257              ((const unsigned char *)"") // "Połączenie już jest nawiązane")
#define KP_MSG_WSAEMFILE_PL_1257               ((const unsigned char *)"") // "Otworzono za dużo plików")

#define KP_MSG_WSAEMSGSIZE_PL_1257             ((const unsigned char *)"") // "Zbyt długi komunikat")
#define KP_MSG_WSAENETDOWN_PL_1257             ((const unsigned char *)"") // "Sieć nie działa")
#define KP_MSG_WSAENETRESET_PL_1257            ((const unsigned char *)"") // "Odłączono się od sieci")

#define KP_MSG_WSAENETUNREACH_PL_1257          ((const unsigned char *)"") // "Sieć nieosiągalna")
#define KP_MSG_WSAENOBUFS_PL_1257              ((const unsigned char *)"") // "Brakuje miejsca w buforze")
#define KP_MSG_WSAENOPROTOOPT_PL_1257          ((const unsigned char *)"") // "Błędne opcje protokołu")

#define KP_MSG_WSAENOTCONN_PL_1257             ((const unsigned char *)"") // "Nieudane połączenie")
#define KP_MSG_WSAENOTSOCK_PL_1257             ((const unsigned char *)"") // "Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_PL_1257           ((const unsigned char *)"") // "Operacja nie może być wykonana")

#define KP_MSG_WSAEPFNOSUPPORT_PL_1257         ((const unsigned char *)"") // "Niepodtrzymywana rodzina protokołów")
#define KP_MSG_WSAEPROCLIM_PL_1257             ((const unsigned char *)"") // "Zbyt dużo procesów")
#define KP_MSG_WSAEPROTONOSUPPORT_PL_1257      ((const unsigned char *)"") // "Protokół nie jest podtrzymywany")

#define KP_MSG_WSAEPROTOTYPE_PL_1257           ((const unsigned char *)"") // "Nieprawidłowy typ połączenia protokołu")
#define KP_MSG_WSAESHUTDOWN_PL_1257            ((const unsigned char *)"") // "Wysyłanie niemożliwe, połączenie zerwane")
#define KP_MSG_WSAESOCKTNOSUPPORT_PL_1257      ((const unsigned char *)"") // "Typ połączenia niepodtrzymywany")
#define KP_MSG_WSAETIMEDOUT_PL_1257            ((const unsigned char *)"") // "Przewyższono maksymalny czas oczekiwania połączenia")

#define KP_MSG_WSATYPE_NOT_FOUND_PL_1257       ((const unsigned char *)"") // "Nie znaleziono typ klasy")
#define KP_MSG_WSAEWOULDBLOCK_PL_1257          ((const unsigned char *)"") // "Źródło czasowo niedostępne")
#define KP_MSG_WSAHOST_NOT_FOUND_PL_1257       ((const unsigned char *)"") // "Nie znaleziono serweru")
#define KP_MSG_WSA_INVALID_HANDLE_PL_1257      ((const unsigned char *)"") // "Błędny kontroler objektu")
#define KP_MSG_WSA_INVALID_PARAMETER_PL_1257   ((const unsigned char *)"") // "Błędne parametry")
#define KP_MSG_WSAINVALIDPROCTABLE_PL_1257     ((const unsigned char *)"") // "Błędna tablica procedur")
#define KP_MSG_WSAINVALIDPROVIDER_PL_1257      ((const unsigned char *)"") // "Błędny kod dostawcy")
#define KP_MSG_WSA_IO_INCOMPLETE_PL_1257       ((const unsigned char *)"") // "Nakładają się zdarzenia wprowdzania/wyprowadzania")
#define KP_MSG_WSA_IO_PENDING_PL_1257          ((const unsigned char *)"") // "Nakładające się operacje będą wykonane później")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_PL_1257   ((const unsigned char *)"") // "Brak pamięci")
#define KP_MSG_WSANOTINITIALISED_PL_1257       ((const unsigned char *)"") // "Podsystem sieci nieaktywowany")
#define KP_MSG_WSANO_DATA_PL_1257              ((const unsigned char *)"") // "Nie ma danych wymaganego typu")
#define KP_MSG_WSANO_RECOVERY_PL_1257          ((const unsigned char *)"") // "Nienaprawialny błąd")
#define KP_MSG_WSAPROVIDERFAILEDINIT_PL_1257   ((const unsigned char *)"") // "Nie możliwa jest inicjacja dostawcy usługi")
#define KP_MSG_WSASYSCALLFAILURE_PL_1257       ((const unsigned char *)"") // "Błędny zwrot systemu")
#define KP_MSG_WSASYSNOTREADY_PL_1257          ((const unsigned char *)"") // "Podsystem sieci nieosiągalny")
#define KP_MSG_WSATRY_AGAIN_PL_1257            ((const unsigned char *)"") // "Nieautoryzowany serwer nie znaleziony")

#define KP_MSG_WSAVERNOTSUPPORTED_PL_1257      ((const unsigned char *)"") // "Błędna wersja WINSOCK.DLL")
#define KP_MSG_WSAEDISCON_PL_1257              ((const unsigned char *)"") // "Rozpoczęto porządne wyłączanie")
#define KP_MSG_WSA_OPERATION_ABORTED_PL_1257   ((const unsigned char *)"") // "Nakładająca się operacja przerwana")

#define KP_MSG_OUT_OF_MEM_RES_PL_1257          ((const unsigned char *)"") // "Brak pamięci systemu operacyjnego")
#define KP_MSG_ERROR_FILE_NOT_FOUND_PL_1257    ((const unsigned char *)"") // "Nie znaleziono wskazanego pliku")
#define KP_MSG_ERROR_PATH_NOT_FOUND_PL_1257    ((const unsigned char *)"") // "Nie znaleziono wskazanej ścieżki do pliku")
#define KP_MSG_ERROR_BAD_FORMAT_PL_1257        ((const unsigned char *)"") // "Wybrany plik .exe jest zepsuty")
#define KP_MSG_SE_ERR_ACCESSDENIED_PL_1257     ((const unsigned char *)"") // "System operacyjny zabronił łączności z potrzebnymi plikami")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_PL_1257  ((const unsigned char *)"") // "Więź pliku z programem jest niepełna lub błędna")
#define KP_MSG_SE_ERR_DDEBUSY_PL_1257          ((const unsigned char *)"") // "DDE transakcja nie może być zakończona, bo inne DDE transakcje są jeszcze wykonywane")
#define KP_MSG_SE_ERR_DDEFAIL_PL_1257          ((const unsigned char *)"") // "DDE transakcja przerwana")
#define KP_MSG_SE_ERR_DDETIMEOUT_PL_1257       ((const unsigned char *)"") // "DDE transakcja nie może być zakończona, bo zabrakło wskazanego czasu oczekiwania")
#define KP_MSG_SE_ERR_DLLNOTFOUND_PL_1257      ((const unsigned char *)"") // "Nie znaleziono wskazanej biblioteki dynamicznej")
#define KP_MSG_SE_ERR_FNF_PL_1257              ((const unsigned char *)"") // "Nie znaleziono wskazanego pliku")
#define KP_MSG_SE_ERR_NOASSOC_PL_1257          ((const unsigned char *)"") // "Nie znaleziono programu do otwarcia plików danego typu")

#define KP_MSG_SE_ERR_OOM_PL_1257              ((const unsigned char *)"") // "Brak pamięci do wykonania operacji")
#define KP_MSG_SE_ERR_PNF_PL_1257              ((const unsigned char *)"") // "Nie znaleziono wskazanej ścieżki")
#define KP_MSG_SE_ERR_SHARE_PL_1257            ((const unsigned char *)"") // "Błąd podziału")

#define KP_MSG_FIRST_TIME_ADMIN_PL_1257        ((const unsigned char *)"") // "Zapuszczając program poraz pierwszy wymagane są uprawnienia administratora. Zapuść program ponownie z uprawnieniami administratora.")

#define KP_MSG_NOW_NOT_ADMIN_PL_1257           KP_MSG_NOT_ADMIN_PL_1257
#define KP_MSG_NOT_ADMIN_PL_1257               ((const unsigned char *)"") // "Zapuść program ponownie z uprawnieniami zwykłego użytkownika")

#define KP_MSG_COPY_FILE_ACCESS_DENIED_PL_1257 ((const unsigned char *)"") // "Nie udało się skopiować pliku. Zapuść program ponownie z uprawnieniami administratora.")


#define KP_PROGRESS_TITLE_PL_1257               ((const unsigned char *)"") // "Zaczekaj...")
#define KP_MSG_DELETING_FILE_PL_1257            ((const unsigned char *)"") // "Kasuje się plik %s.%s...")

#define KP_MSG_COPYING_PL_1257                  ((const unsigned char *)"") // "Kopiuje się plik...")

#define KP_MSG_COPYING_DIR_PL_1257              ((const unsigned char *)"") // "Kopiuje się katalog %s.%s...")
#define KP_MSG_COPYING_FILE_PL_1257             ((const unsigned char *)"") // "Kopiuje się plik %s.%s...")

#define KP_MSG_NEG_ANSW_PL_1257                 ((const unsigned char *)"") // "Neigiamas atsakymas")

#define KP_MSG_UNABLE_TO_EXECUTE_PL_1257        ((const unsigned char *)"") // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL_PL_1257     ((const unsigned char *)"") // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED_PL_1257             ((const unsigned char *)"") // "Failas pasikeitė"

#define KP_MSG_ALL_FILES_PL_1257                ((const unsigned char *)"") // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS_PL_1257                  ((const unsigned char *)"") // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS_PL_1257              ((const unsigned char *)"") // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG_PL_1257                 ((const unsigned char *)"") // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE_PL_1257           ((const unsigned char *)"") // "Diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL_PL_1257            ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_PL_1257    ((const unsigned char *)"") // "Jūsų e-pašto adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_PL_1257 ((const unsigned char *)"") // "Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_PL_1257     ((const unsigned char *)"") // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_PL_1257        ((const unsigned char *)"") // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE_PL_1257        ((const unsigned char *)"") // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED_PL_1257       ((const unsigned char *)"") // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1_PL_1257           ((const unsigned char *)"") // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI_PL_1257                   ((const unsigned char *)"") // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2_PL_1257           ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING_PL_1257              ((const unsigned char *)"") // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE_PL_1257         ((const unsigned char *)"") // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL_PL_1257                 ((const unsigned char *)"") // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER_PL_1257                  ((const unsigned char *)"") // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED_PL_1257              ((const unsigned char *)"") // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE_PL_1257               ((const unsigned char *)"") // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION_PL_1257      ((const unsigned char *)"") // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT_PL_1257              ((const unsigned char *)"") // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR_PL_1257                  ((const unsigned char *)"") // "Duomenų bazės klaida"

#endif // #if ((MsgLang != KpLangPl_p) && (MsgLang != KpLangSel_p) && (MsgLang != KpLangPl_1257_p))

// --------------------------------------------
#if ((MsgLang != KpLangSel_p) && (MsgLang != KpLangRu_p) && (MsgLang != KpLangRu_1251_p) && (MsgLang != KpLangRu_0_p))

#define KP_MSG_TITLE_RU             ((const unsigned char *)"") // "Message")
#define KP_INPUT_TITLE_RU           ((const unsigned char *)"") // "Input"

#define KP_MSG_YES_RU               ((const unsigned char *)"") // "Yes")
#define KP_MSG_TAIP_RU              KP_MSG_YES
#define KP_MSG_NO_RU                ((const unsigned char *)"") // "No")
#define KP_MSG_NE_RU                KP_MSG_NO
#define KP_MSG_OK_RU                ((const unsigned char *)"") // "OK")
#define KP_MSG_GERAI_RU             KP_MSG_OK
#define KP_MSG_CANCEL_RU            ((const unsigned char *)"") // "Cancel")
#define KP_MSG_ATSAUKTI_RU          KP_MSG_CANCEL
#define KP_MSG_TESTI_RU             ((const unsigned char *)"") // "Continue")
#define KP_MSG_BAIGTI_RU            ((const unsigned char *)"") // "Finish")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_RU ((const unsigned char *)"") // "Forgot password")

#define KP_MSG_ERROR_RU             ((const unsigned char *)"") // "Error")
#define KP_MSG_WARNING_RU           ((const unsigned char *)"") // "Warning")
#define KP_MSG_FILE_LINE_RU         ((const unsigned char *)"") // ", file:%s, line:%d")
#define KP_MSG_ENTRY_ID_RU          ((const unsigned char *)"") // ", Entry Id:%ld")
#define KP_MSG_ENTRY_RU             ((const unsigned char *)"") // ", Entry: %s")

#define KP_MSG_NO_STANDARD_PROG_RU  ((const unsigned char *)"") // "Standard program not set to open given file type")
#define KP_MSG_WND_NOT_FOUND_RU     ((const unsigned char *)"") // "Window not found")
#define KP_MSG_PID_NOT_FOUND_RU     ((const unsigned char *)"") // "PID not found")
#define KP_MSG_NO_SOCKET_RU         ((const unsigned char *)"") // "Socket not created yet")
#define KP_MSG_SOCK_UNRESOLVED_RU   ((const unsigned char *)"") // "Server address not resolved yet")

#define KP_MSG_ERR_OK_RU            ((const unsigned char *)"") // "Operation ended successfully")
#define KP_MSG_INVALIDARG_RU        ((const unsigned char *)"") // "Invalid parameter")
#define KP_MSG_NOTIMPL_RU           ((const unsigned char *)"") // "Feature not implemented yet")
#define KP_MSG_UNEXPECTED_RU        ((const unsigned char *)"") // "Unexpected interface call") // Interface call result: Unexpected error
#define KP_MSG_FERROR_RU            ((const unsigned char *)"") // "File I/O error")
#define KP_MSG_SYSTEM_ERROR_RU      ((const unsigned char *)"") // "Internal error")
#define KP_MSG_EOF_RU               ((const unsigned char *)"") // "Unexpected end of input file")
#define KP_MSG_FILE_FORMAT_RU       ((const unsigned char *)"") // "Unexpected input file format")
#define KP_MSG_FILE_NOT_FOUND_RU    ((const unsigned char *)"") // "File not found")
#define KP_MSG_DIR_ERROR_RU         ((const unsigned char *)"") // "Unable to create file")
#define KP_MSG_OUTOFMEM_RU          ((const unsigned char *)"") // "Out of memory")
#define KP_MSG_NO_FILE_RU           ((const unsigned char *)"") // "No file open")
#define KP_MSG_DOUBLE_UNGET_RU      ((const unsigned char *)"") // "Double unget")
#define KP_MSG_UNKN_CHR_RU          ((const unsigned char *)"") // "Unknown character")
#define KP_MSG_COMMAND_ERROR_RU     ((const unsigned char *)"") // "External error")
#define KP_MSG_BUFFER_OVERFLOW_RU   ((const unsigned char *)"") // "Buffer overflow")
#define KP_MSG_FONT_UNDEF_RU        ((const unsigned char *)"") // "Font undefined")
#define KP_MSG_KWD_NOT_FOUND_RU     ((const unsigned char *)"") // "Keyword not found")
#define KP_MSG_UNKNOWN_SYSTEM_RU    ((const unsigned char *)"") // "Unknown OS version")
#define KP_MSG_ILL_CODE_RU          ((const unsigned char *)"") // "Illegal registration code")
#define KP_MSG_CANCELLED_RU         ((const unsigned char *)"") // "Job cancelled")
#define KP_MSG_DOUBLE_CALL_RU       ((const unsigned char *)"") // "Double call")
#define KP_MSG_TIMEOUT_RU           ((const unsigned char *)"") // "Timeout")
#define KP_MSG_OBJ_NOT_FOUND_RU     ((const unsigned char *)"") // "Object not found")
#define KP_MSG_NO_CONN_RU           ((const unsigned char *)"") // "No connection")

#define KP_MSG_TRANS_ERR_RU         ((const unsigned char *)"") // "Transfer error")
#define KP_MSG_TRANS_ERR_1_RU       ((const unsigned char *)"") // "Transfer error, repeat the download procedure, please"

#define KP_MSG_REFUSED_RU           ((const unsigned char *)"") // "Registration refused")
#define KP_MSG_ACCESS_DENIED_RU     ((const unsigned char *)"") // "Access denied")
#define KP_MSG_ILLEGAL_CHARACTER_RU ((const unsigned char *)"") // "Unexpected character")
#define KP_MSG_DIV_ZERO_RU          ((const unsigned char *)"") // "Division by zero")
#define KP_MSG_ILLMATHARG_RU        ((const unsigned char *)"") // "Illegal math argument")
#define KP_MSG_ILLFUNC_RU           ((const unsigned char *)"") // "Illegal function call")

#define KP_MSG_NOTINST_RU           ((const unsigned char *)"") // "Program not yet installed or installation is damaged, repeat the installation procedure again, please")
#define KP_MSG_NOTINST_S_RU         ((const unsigned char *)"") // "Produktas „%s“ neįdiegtas arba jo diegimas sugedo, pakartokite diegimo procedūrą"
#define KP_MSG_NOTINST_DELETE_RU    ((const unsigned char *)"") // "Produktas neįdiegtas arba jo diegimas sugedo, produktą panaikinkite ir pakartokite diegimo procedūrą"

#define KP_MSG_MSG_FORMAT_RU        ((const unsigned char *)"") // "Illegal message format")
#define KP_MSG_OBSOLETE_RU          ((const unsigned char *)"") // "Obsolete function call")

#define KP_MSG_ERROR_HELP_RU        ((const unsigned char *)"") // ".  Technical support by e-mail tech@tev.lt")
#define KP_MSG_ERROR_HELP_REST_RU   ((const unsigned char *)"") // "   For further information look file %s")

#define KP_MSG_WSAEACCES_RU               ((const unsigned char *)"") // "Permission denied")
#define KP_MSG_WSAEADDRINUSE_RU           ((const unsigned char *)"") // "Address already in use")
#define KP_MSG_WSAEADDRNOTAVAIL_RU        ((const unsigned char *)"") // "Cannot assign requested address")
#define KP_MSG_WSAEAFNOSUPPORT_RU         ((const unsigned char *)"") // "Address family not supported by protocol family")
#define KP_MSG_WSAEALREADY_RU             ((const unsigned char *)"") // "Operation already in progress")
#define KP_MSG_WSAECONNABORTED_RU         ((const unsigned char *)"") // "Software caused connection abort")
#define KP_MSG_WSAECONNREFUSED_RU         ((const unsigned char *)"") // "Connection refused")
#define KP_MSG_WSAECONNRESET_RU           ((const unsigned char *)"") // "Connection reset by peer")
#define KP_MSG_WSAEDESTADDRREQ_RU         ((const unsigned char *)"") // "Destination address required")
#define KP_MSG_WSAEFAULT_RU               ((const unsigned char *)"") // "Bad address")
#define KP_MSG_WSAEHOSTDOWN_RU            ((const unsigned char *)"") // "Host is down")
#define KP_MSG_WSAEHOSTUNREACH_RU         ((const unsigned char *)"") // "No route to host")
#define KP_MSG_WSAEINPROGRESS_RU          ((const unsigned char *)"") // "Operation now in progress")
#define KP_MSG_WSAEINTR_RU                ((const unsigned char *)"") // "Interrupted function call")
#define KP_MSG_WSAEINVAL_RU               ((const unsigned char *)"") // "Invalid argument")
#define KP_MSG_WSAEISCONN_RU              ((const unsigned char *)"") // "Socket is already connected")
#define KP_MSG_WSAEMFILE_RU               ((const unsigned char *)"") // "Too many open files")
#define KP_MSG_WSAEMSGSIZE_RU             ((const unsigned char *)"") // "Message too long")
#define KP_MSG_WSAENETDOWN_RU             ((const unsigned char *)"") // "Network is down")
#define KP_MSG_WSAENETRESET_RU            ((const unsigned char *)"") // "Network dropped connection on reset")
#define KP_MSG_WSAENETUNREACH_RU          ((const unsigned char *)"") // "Network is unreachable")
#define KP_MSG_WSAENOBUFS_RU              ((const unsigned char *)"") // "No buffer space available")
#define KP_MSG_WSAENOPROTOOPT_RU          ((const unsigned char *)"") // "Bad protocol option")
#define KP_MSG_WSAENOTCONN_RU             ((const unsigned char *)"") // "Socket is not connected")
#define KP_MSG_WSAENOTSOCK_RU             ((const unsigned char *)"") // "Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_RU           ((const unsigned char *)"") // "Operation not supported")
#define KP_MSG_WSAEPFNOSUPPORT_RU         ((const unsigned char *)"") // "Protocol family not supported")
#define KP_MSG_WSAEPROCLIM_RU             ((const unsigned char *)"") // "Too many processes")
#define KP_MSG_WSAEPROTONOSUPPORT_RU      ((const unsigned char *)"") // "Protocol not supported")
#define KP_MSG_WSAEPROTOTYPE_RU           ((const unsigned char *)"") // "Protocol wrong type for socket")
#define KP_MSG_WSAESHUTDOWN_RU            ((const unsigned char *)"") // "Cannot send after socket shutdown")
#define KP_MSG_WSAESOCKTNOSUPPORT_RU      ((const unsigned char *)"") // "Socket type not supported")
#define KP_MSG_WSAETIMEDOUT_RU            ((const unsigned char *)"") // "Connection timed out")
#define KP_MSG_WSATYPE_NOT_FOUND_RU       ((const unsigned char *)"") // "class type not found")
#define KP_MSG_WSAEWOULDBLOCK_RU          ((const unsigned char *)"") // "Resource temporarily unavailable")
#define KP_MSG_WSAHOST_NOT_FOUND_RU       ((const unsigned char *)"") // "Host not found")
#define KP_MSG_WSA_INVALID_HANDLE_RU      ((const unsigned char *)"") // "Specified event object handle is invalid")
#define KP_MSG_WSA_INVALID_PARAMETER_RU   ((const unsigned char *)"") // "One or more parameters are invalid")
#define KP_MSG_WSAINVALIDPROCTABLE_RU     ((const unsigned char *)"") // "Invalid procedure table from service provider")
#define KP_MSG_WSAINVALIDPROVIDER_RU      ((const unsigned char *)"") // "Invalid service provider version number")
#define KP_MSG_WSA_IO_INCOMPLETE_RU       ((const unsigned char *)"") // "Overlapped I/O event object not in signaled state")
#define KP_MSG_WSA_IO_PENDING_RU          ((const unsigned char *)"") // "Overlapped operations will complete later")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_RU   ((const unsigned char *)"") // "Insufficient memory available")
#define KP_MSG_WSANOTINITIALISED_RU       ((const unsigned char *)"") // "Successful WSAStartup not yet performed")
#define KP_MSG_WSANO_DATA_RU              ((const unsigned char *)"") // "Valid name, no data record of requested type")
#define KP_MSG_WSANO_RECOVERY_RU          ((const unsigned char *)"") // "this is a non-recoverable error")
#define KP_MSG_WSAPROVIDERFAILEDINIT_RU   ((const unsigned char *)"") // "Unable to initialize a service provider")
#define KP_MSG_WSASYSCALLFAILURE_RU       ((const unsigned char *)"") // "System call failure")
#define KP_MSG_WSASYSNOTREADY_RU          ((const unsigned char *)"") // "Network subsystem is unavailable")
#define KP_MSG_WSATRY_AGAIN_RU            ((const unsigned char *)"") // "Non-authoritative host not found")
#define KP_MSG_WSAVERNOTSUPPORTED_RU      ((const unsigned char *)"") // "WINSOCK.DLL version out of range")
#define KP_MSG_WSAEDISCON_RU              ((const unsigned char *)"") // "Graceful shutdown in progress")
#define KP_MSG_WSA_OPERATION_ABORTED_RU   ((const unsigned char *)"") // "Overlapped operation aborted")

#define KP_MSG_OUT_OF_MEM_RES_RU          ((const unsigned char *)"") // "The operating system is out of memory or resources")
#define KP_MSG_ERROR_FILE_NOT_FOUND_RU    ((const unsigned char *)"") // "The file specified was not found")
#define KP_MSG_ERROR_PATH_NOT_FOUND_RU    ((const unsigned char *)"") // "The path specified was not found")
#define KP_MSG_ERROR_BAD_FORMAT_RU        ((const unsigned char *)"") // "The .exe file is invalid (non-Win32(r) .exe or error in .exe image)")
#define KP_MSG_SE_ERR_ACCESSDENIED_RU     ((const unsigned char *)"") // "The operating system denied access to the specified file")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_RU  ((const unsigned char *)"") // "The file name association is incomplete or invalid")
#define KP_MSG_SE_ERR_DDEBUSY_RU          ((const unsigned char *)"") // "The DDE transaction could not be completed because other DDE transactions were being processed")
#define KP_MSG_SE_ERR_DDEFAIL_RU          ((const unsigned char *)"") // "The DDE transaction failed")
#define KP_MSG_SE_ERR_DDETIMEOUT_RU       ((const unsigned char *)"") // "The DDE transaction could not be completed because the request timed out")
#define KP_MSG_SE_ERR_DLLNOTFOUND_RU      ((const unsigned char *)"") // "The specified dynamic-link library was not found")
#define KP_MSG_SE_ERR_FNF_RU              ((const unsigned char *)"") // "The specified file was not found")
#define KP_MSG_SE_ERR_NOASSOC_RU          ((const unsigned char *)"") // "There is no application associated with the given file name extension")
#define KP_MSG_SE_ERR_OOM_RU              ((const unsigned char *)"") // "There was not enough memory to complete the operation")
#define KP_MSG_SE_ERR_PNF_RU              ((const unsigned char *)"") // "The specified path was not found")
#define KP_MSG_SE_ERR_SHARE_RU            ((const unsigned char *)"") // "A sharing violation occurred")

#define KP_MSG_FIRST_TIME_ADMIN_RU        ((const unsigned char *)"") // "Starting the program first time administrator\n rights are necessary. Run the program again as privileged user.")
#define KP_MSG_NOW_NOT_ADMIN_RU           KP_MSG_NOT_ADMIN
#define KP_MSG_NOT_ADMIN_RU               ((const unsigned char *)"") // "Run the program again as ordinary user")
#define KP_MSG_COPY_FILE_ACCESS_DENIED_RU ((const unsigned char *)"") // "Unsuccessfull file copy operation, run the program again as privileged user")

#define KP_PROGRESS_TITLE_RU              ((const unsigned char *)"") // "Wait...")
#define KP_MSG_DELETING_FILE_RU           ((const unsigned char *)"") // "Deleting file %s.%s...")
#define KP_MSG_COPYING_RU                 ((const unsigned char *)"") // "Copying file...")
#define KP_MSG_COPYING_FILE_RU            ((const unsigned char *)"") // "Copying file %s.%s...")
#define KP_MSG_COPYING_DIR_RU             ((const unsigned char *)"") // "Copying folder %s.%s...")

#define KP_MSG_NEG_ANSW_RU                ((const unsigned char *)"") // "Neigiamas atsakymas")

#define KP_MSG_UNABLE_TO_EXECUTE_RU       ((const unsigned char *)"") // "Komandos %s įvykdyti negaliu – patikrinkite, ar teisingai įdiegėte visus sistemos komponentus"

#define KP_MSG_FLASH_PLAYER_INSTALL_RU    ((const unsigned char *)"") // "Dabar bus įdiegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus."

#define KP_MSG_FILE_CHANGED_RU            ((const unsigned char *)"") // "Failas pasikeitė"

#define KP_MSG_ALL_FILES_RU               ((const unsigned char *)"") // "Visi failai (*.*)"
#define KP_MSG_SAVE_AS_RU                 ((const unsigned char *)"") // "Įrašyti kaip"

#define KP_MSG_FILE_EXISTS_RU             ((const unsigned char *)"") // "Failas %s jau yra, perrašyti?"

#define KP_MSG_DIAG_MSG_RU                ((const unsigned char *)"") // "Formuojamas diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_TITLE_RU          ((const unsigned char *)"") // "Diagnostinis pranešimas"
#define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite pateiktus laukus. Pranešimas apie kompiuterio konfigūraciją, produktą bei klaidos pobūdį bus išsiųstas internetu į produkto gamintojo tarnybinę stotį. Jei po kurio laiko su Jumis nebus susisiekta Jūsų nurodytu pašto adresu, kreipkitės adresu pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_RU   ((const unsigned char *)"") // "Jūsų e-pašto adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_RU ((const unsigned char *)"") // "Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_RU    ((const unsigned char *)"") // "Papildomas failas, kurį norėtumėte nusiųsti (pvz., ekrano kopijos paveikslėlis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_RU       ((const unsigned char *)"") // "Neteisingas e-pašto adresas"

#define KP_MSG_DIAG_MSG_SEL_FILE_RU       ((const unsigned char *)"") // "Pasirinkite siunčiamą failą"

#define KP_MSG_DIAG_MSG_SUCCEEDED_RU      ((const unsigned char *)"") // "Diagnostinis pranešimas nusiųstas sėkmingai"

#define KP_MSG_DIAG_MSG_EXPL1_RU          ((const unsigned char *)"") // "Jei norite siųsti diagnostinį pranešimą, spragtelėkite „Siųsti“, jei ne – „Atšaukti“."
#define KP_MSG_SIUSTI_RU                  ((const unsigned char *)"") // "Siųsti"
#define KP_MSG_DIAG_MSG_EXPL2_RU          ((const unsigned char *)"") // "Jei norite nusiųsti diagnostinį pranešimą gamintojui, užpildykite Jūsų e-pašto adreso lauką ir spragtelėkite mygtuką „Siųsti“."

#define KP_MSG_DOWNLOADING_RU             ((const unsigned char *)"") // "Siunčiamas failas..."
#define KP_MSG_DOWNLOADING_FILE_RU        ((const unsigned char *)"") // "Siunčiamas failas %s.%s..."

#define KP_MSG_FIREWALL_RU                ((const unsigned char *)"") // "Neleista prisijungti prie interneto. Patikrinkite Jūsų ugniasienės parinktis – pabandykite įtraukti %s į sąrašą programų, kurioms leidžiama kreiptis į internetą."

#define KP_MSG_POINTER_RU                 ((const unsigned char *)"") // "Bloga rodyklė"

#define KP_MSG_LOG_STARTED_RU             ((const unsigned char *)"") // "Žurnalas išvedamas ir į failą %s"
#define KP_MSG_CONS_TITLE_RU              ((const unsigned char *)"") // "%s: Pranešimų žurnalas"

#define KP_MSG_UNHANDLED_EXCEPTION_RU     ((const unsigned char *)"") // "Neapdorojamas trūkis"

#define KP_MSG_DATA_FORMAT_RU             ((const unsigned char *)"") // "Neteisingas duomenų formatas"
#define KP_MSG_DBERROR_RU                 ((const unsigned char *)"") // "Duomenų bazės klaida"

#endif // #if ((MsgLang != KpLangSel_p) && (MsgLang != KpLangRu_p) && (MsgLang != KpLangRu_1251_p) && (MsgLang != KpLangRu_0_p))

#endif // #ifndef KPMSG_INCLUDED
