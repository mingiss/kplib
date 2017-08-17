// -----------------------------------------
// kpmsg_lt.h
// programos paleidimo aplikaciju pranesimai
// liet. kalba
//

#ifndef kpmsg_lt_included
#define kpmsg_lt_included

// --------------------------------------- common kp messages

#if ((MsgLang == KpLangSel_p) || (MsgLang == KpLangLt_p))

// #define KP_MSG_TITLE_LT          ((const unsigned char *)"KpMessage")
#define KP_MSG_TITLE_LT             ((const unsigned char *)"Prane�imas")
#define KP_INPUT_TITLE_LT           ((const unsigned char *)"�vedimas")

#define KP_MSG_TAIP_LT              ((const unsigned char *)"Taip")
#define KP_MSG_YES_LT               KP_MSG_TAIP_LT
#define KP_MSG_NE_LT                ((const unsigned char *)"Ne")
#define KP_MSG_NO_LT                KP_MSG_NE_LT
#define KP_MSG_GERAI_LT             ((const unsigned char *)"Gerai")
#define KP_MSG_OK_LT                KP_MSG_GERAI_LT
#define KP_MSG_ATSAUKTI_LT          ((const unsigned char *)"At�aukti")
#define KP_MSG_CANCEL_LT            KP_MSG_ATSAUKTI_LT
#define KP_MSG_TESTI_LT             ((const unsigned char *)"Toliau")
#define KP_MSG_BAIGTI_LT            ((const unsigned char *)"Baigti")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_LT ((const unsigned char *)"Pamir�au slapta�od�")

#define KP_MSG_ERROR_LT             ((const unsigned char *)"Klaida")
#define KP_MSG_WARNING_LT           ((const unsigned char *)"Persp�jimas")
#define KP_MSG_FILE_LINE_LT         ((const unsigned char *)", klaida: %lx, failas: %s, eilut�: %d")
#define KP_MSG_ENTRY_ID_LT          ((const unsigned char *)", �ra�o nr.:%ld")
#define KP_MSG_ENTRY_LT             ((const unsigned char *)", �ra�as: %s")

#define KP_MSG_NO_STANDARD_PROG_LT  ((const unsigned char *)"Nerasta programa skirta atverti �io tipo failus")
#define KP_MSG_WND_NOT_FOUND_LT     ((const unsigned char *)"Langas nerastas")
#define KP_MSG_PID_NOT_FOUND_LT     ((const unsigned char *)"Nerastas proceso identifikatorius")
#define KP_MSG_NO_SOCKET_LT         ((const unsigned char *)"Jungtis dar nesukurta")
#define KP_MSG_SOCK_UNRESOLVED_LT   ((const unsigned char *)"Tarnybines stoties adresas dar nesurastas")

#define KP_MSG_ERR_OK_LT            ((const unsigned char *)"Operacija atlikta s�kmingai") // !!!
#define KP_MSG_INVALIDARG_LT        ((const unsigned char *)"Neteisingi parametrai")
// #define KP_MSG_NOTIMPL_LT        ((const unsigned char *)"Priedas ne�diegtas")
#define KP_MSG_NOTIMPL_LT           ((const unsigned char *)"Funkcija dar nerealizuota")
#define KP_MSG_UNEXPECTED_LT        ((const unsigned char *)"Netik�tas kreipinys � s�saj�")
#define KP_MSG_FERROR_LT            ((const unsigned char *)"Failo skaitymo/ra�ymo klaida")
#define KP_MSG_SYSTEM_ERROR_LT      ((const unsigned char *)"Klaida sistemoje")
#define KP_MSG_EOF_LT               ((const unsigned char *)"Neteisinga failo pabaiga")
#define KP_MSG_FILE_FORMAT_LT       ((const unsigned char *)"Neteisingas failo formatas")
#define KP_MSG_FILE_NOT_FOUND_LT    ((const unsigned char *)"Failas nerastas")
#define KP_MSG_DIR_ERROR_LT         ((const unsigned char *)"Nepavyko atverti/sukurti failo")
#define KP_MSG_OUTOFMEM_LT          ((const unsigned char *)"Tr�ksta atminties")
#define KP_MSG_NO_FILE_LT           ((const unsigned char *)"Failas neatvertas")
#define KP_MSG_DOUBLE_UNGET_LT      ((const unsigned char *)"Dvigubas �vedimo gr��inimas")
#define KP_MSG_UNKN_CHR_LT          ((const unsigned char *)"Neatpa�intas simbolis")
#define KP_MSG_COMMAND_ERROR_LT     ((const unsigned char *)"I�orin� klaida")
#define KP_MSG_BUFFER_OVERFLOW_LT   ((const unsigned char *)"Persipild� buferis")
#define KP_MSG_FONT_UNDEF_LT        ((const unsigned char *)"Neapibr��tas �riftas")
#define KP_MSG_KWD_NOT_FOUND_LT     ((const unsigned char *)"Raktinis �odis nerastas")
#define KP_MSG_UNKNOWN_SYSTEM_LT    ((const unsigned char *)"Operacin� sistema neatpa�inta")
// #define KP_MSG_ILL_CODE_LT          ((const unsigned char *)"Klaidingas registracijos kodas")
#define KP_MSG_ILL_CODE_LT          ((const unsigned char *)"Klaidingas aktyvacijos kodas")
#define KP_MSG_CANCELLED_LT         ((const unsigned char *)"Operacija nutraukta")
#define KP_MSG_DOUBLE_CALL_LT       ((const unsigned char *)"Dvigubas i�kvietimas")
#define KP_MSG_TIMEOUT_LT           ((const unsigned char *)"Vir�ytas laukimo laikas")
#define KP_MSG_OBJ_NOT_FOUND_LT     ((const unsigned char *)"Objektas nerastas")
#define KP_MSG_NO_CONN_LT           ((const unsigned char *)"Tinklas neprijungtas") // "N�ra ry�io")

#define KP_MSG_TRANS_ERR_LT         ((const unsigned char *)"Perdavimo klaida")
#define KP_MSG_TRANS_ERR_1_LT       ((const unsigned char *)"Ry�io klaida, pakartokite siuntimo proced�r�")

// #define KP_MSG_REFUSED_LT           ((const unsigned char *)"Registracija atmesta")
#define KP_MSG_REFUSED_LT           ((const unsigned char *)"Aktyvacija atmesta")
#define KP_MSG_ACCESS_DENIED_LT     ((const unsigned char *)"Neleista prisijungti")
#define KP_MSG_ILLEGAL_CHARACTER_LT ((const unsigned char *)"Neleistinas simbolis")
#define KP_MSG_DIV_ZERO_LT          ((const unsigned char *)"Dalyba i� nulio")
#define KP_MSG_ILLMATHARG_LT        ((const unsigned char *)"Neleistinas matematin�s funkcijos argumentas") // "�aknis i� neigiamo skai�iaus"
#define KP_MSG_ILLFUNC_LT           ((const unsigned char *)"Neleistina operacija") // illegal function call (at the moment)
                                      
// #define KP_MSG_NOTINST_LT        ((const unsigned char *)"Programa ne�diegta arba diegimas sugedo, pakartokite diegimo proced�r�")
#define KP_MSG_NOTINST_LT           ((const unsigned char *)"Produktas ne�diegtas arba jo diegimas sugedo, pakartokite diegimo proced�r�")
#define KP_MSG_NOTINST_S_LT         ((const unsigned char *)"Produktas �%s� ne�diegtas arba jo diegimas sugedo, pakartokite diegimo proced�r�")
#define KP_MSG_NOTINST_DELETE_LT    ((const unsigned char *)"Produktas ne�diegtas arba jo diegimas sugedo. Produkt� panaikinkite ir pakartokite diegimo proced�r�.")
                                      
#define KP_MSG_MSG_FORMAT_LT        ((const unsigned char *)"Neteisingas prane�imo formatas")
#define KP_MSG_OBSOLETE_LT          ((const unsigned char *)"Pasenusi funkcija")

// #define KP_MSG_ERROR_HELP_LT     ((const unsigned char *)".  D�l technin�s pagalbos kreipkit�s elektroniniu pa�tu %s   Smulkesn� informacija faile %s")
// #define KP_MSG_ERROR_HELP_LT     ((const unsigned char *)".  D�l technin�s pagalbos kreipkit�s elektroniniu pa�tu %s, prie lai�ko prikabinkite fail� %s")
// #define KP_MSG_ERROR_HELP_LT     ((const unsigned char *)".  D�l technin�s pagalbos kreipkit�s elektroniniu pa�tu, adresu %s, prie lai�ko prikabinkite fail� %s")
#define KP_MSG_ERROR_HELP_LT        ((const unsigned char *)".  D�l technin�s pagalbos kreipkit�s elektroniniu pa�tu, adresu %s")
#define KP_MSG_ERROR_HELP_REST_LT   ((const unsigned char *)"   Prie lai�ko prikabinkite J�s� darbalaukyje atsiradus� fail� %s.")

#define KP_MSG_WSAEACCES_LT               ((const unsigned char *)"Teis�s nesuteiktos")
#define KP_MSG_WSAEADDRINUSE_LT           ((const unsigned char *)"Adresas jau naudojamas")
#define KP_MSG_WSAEADDRNOTAVAIL_LT        ((const unsigned char *)"Pra�omas adresas negali b�ti priskirtas")
#define KP_MSG_WSAEAFNOSUPPORT_LT         ((const unsigned char *)"Adres� �eimos grup� nepalaikoma protokolo")
#define KP_MSG_WSAEALREADY_LT             ((const unsigned char *)"Operacija jau vykdoma")
#define KP_MSG_WSAECONNABORTED_LT         ((const unsigned char *)"Programinis ry�io tr�kis") // "Programa i��auk� ry�io nutraukim�")
#define KP_MSG_WSAECONNREFUSED_LT         ((const unsigned char *)"Susijungimas atmestas")
#define KP_MSG_WSAECONNRESET_LT           ((const unsigned char *)"Sujungimas nutrauktas")
#define KP_MSG_WSAEDESTADDRREQ_LT         ((const unsigned char *)"B�tinas kreipties adresas")
#define KP_MSG_WSAEFAULT_LT               ((const unsigned char *)"Neteisingas adresas")
#define KP_MSG_WSAEHOSTDOWN_LT            ((const unsigned char *)"Tarnybin� stotis laikinai neveikia") // "Serveris laikinai neveikia")
#define KP_MSG_WSAEHOSTUNREACH_LT         ((const unsigned char *)"Tarnybin� stotis nepasiekiama") // "Serveris nepasiekiamas")
#define KP_MSG_WSAEINPROGRESS_LT          ((const unsigned char *)"Operacija vykdoma")
#define KP_MSG_WSAEINTR_LT                ((const unsigned char *)"Funkcija nutraukta")
#define KP_MSG_WSAEINVAL_LT               ((const unsigned char *)"Neteisingi parametrai")
#define KP_MSG_WSAEISCONN_LT              ((const unsigned char *)"Jungtis u�imta") // "Susijungimas jau �vyk�s")
#define KP_MSG_WSAEMFILE_LT               ((const unsigned char *)"Perdaug atvert� fail�")
#define KP_MSG_WSAEMSGSIZE_LT             ((const unsigned char *)"Perdaug ilgas prane�imas")
#define KP_MSG_WSAENETDOWN_LT             ((const unsigned char *)"Tinklas neveikia")
#define KP_MSG_WSAENETRESET_LT            ((const unsigned char *)"Tinklas atsijung�") // "Atsijung� nuo tinklo")
#define KP_MSG_WSAENETUNREACH_LT          ((const unsigned char *)"Tinklas nepasiekiamas")
#define KP_MSG_WSAENOBUFS_LT              ((const unsigned char *)"Tr�ksta vietos buferyje")
#define KP_MSG_WSAENOPROTOOPT_LT          ((const unsigned char *)"Neteisinga protokolo parinktis")
#define KP_MSG_WSAENOTCONN_LT             ((const unsigned char *)"Sujungimas nepavyko")
#define KP_MSG_WSAENOTSOCK_LT             ((const unsigned char *)"Jungties operacija ne jung�iai")
#define KP_MSG_WSAEOPNOTSUPP_LT           ((const unsigned char *)"Operacija negali b�ti atlikta")
#define KP_MSG_WSAEPFNOSUPPORT_LT         ((const unsigned char *)"Protokolo �eima nepalaikoma")
#define KP_MSG_WSAEPROCLIM_LT             ((const unsigned char *)"Per daug proces�")
#define KP_MSG_WSAEPROTONOSUPPORT_LT      ((const unsigned char *)"Protokolas nepalaikomas")
#define KP_MSG_WSAEPROTOTYPE_LT           ((const unsigned char *)"Neteisingas protokolo sujungimo tipas")
#define KP_MSG_WSAESHUTDOWN_LT            ((const unsigned char *)"Siuntimas nebegalimas, jungtis nutraukta") // "Siuntimas nebegalimas, sujungimas nutrauktas")
#define KP_MSG_WSAESOCKTNOSUPPORT_LT      ((const unsigned char *)"Sujungimo tipas nepalaikomas")
#define KP_MSG_WSAETIMEDOUT_LT            ((const unsigned char *)"Maksimalus sujungimo laukimo laikas vir�ytas")
#define KP_MSG_WSATYPE_NOT_FOUND_LT       ((const unsigned char *)"Klas�s tipas nerastas")
#define KP_MSG_WSAEWOULDBLOCK_LT          ((const unsigned char *)"�altinis laikinai nepasiekiamas")
#define KP_MSG_WSAHOST_NOT_FOUND_LT       ((const unsigned char *)"Tarnybin� stotis nerasta") // "Serveris nerastas")
#define KP_MSG_WSA_INVALID_HANDLE_LT      ((const unsigned char *)"Klaidingas objekto valdiklis") // "Klaidingas pasirinkto �vykio objekto valdiklis"
#define KP_MSG_WSA_INVALID_PARAMETER_LT   ((const unsigned char *)"Neteisingi parametrai") // "Neteisingi vienas ar daugiau parametr�"
#define KP_MSG_WSAINVALIDPROCTABLE_LT     ((const unsigned char *)"Klaidinga proced�r� lentel�")
#define KP_MSG_WSAINVALIDPROVIDER_LT      ((const unsigned char *)"Neteisingas tiek�jo kodas")
#define KP_MSG_WSA_IO_INCOMPLETE_LT       ((const unsigned char *)"Persiklojan�ios �vesties/i�vesties �vykiai dar nepasibaig�") // "Persiklojan�ios �vesties/i�vesties �vykiai neaktyv�s") // "Persikloja �vesties/i�vesties �vykiai")
#define KP_MSG_WSA_IO_PENDING_LT          ((const unsigned char *)"Persiklojan�ios operacijos bus atliktos v�liau")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_LT   ((const unsigned char *)"Nepakanka atminties")
#define KP_MSG_WSANOTINITIALISED_LT       ((const unsigned char *)"Tinklo posistemis neaktyvuotas")
#define KP_MSG_WSANO_DATA_LT              ((const unsigned char *)"Vardas teisingas, ta�iau n�ra reikiamo tipo duomen�")
#define KP_MSG_WSANO_RECOVERY_LT          ((const unsigned char *)"Nepataisoma klaida")
#define KP_MSG_WSAPROVIDERFAILEDINIT_LT   ((const unsigned char *)"Negalima inicializuoti paslaugos tiek�jo")
#define KP_MSG_WSASYSCALLFAILURE_LT       ((const unsigned char *)"Sistemos kreipinio klaida")
#define KP_MSG_WSASYSNOTREADY_LT          ((const unsigned char *)"Tinklo posistem� nepasiekiama")
#define KP_MSG_WSATRY_AGAIN_LT            ((const unsigned char *)"Nerasta neautorizuota tarnybin� stotis") // "Neautorizuotas serveris nerastas")
#define KP_MSG_WSAVERNOTSUPPORTED_LT      ((const unsigned char *)"Netinka WINSOCK.DLL versija")
#define KP_MSG_WSAEDISCON_LT              ((const unsigned char *)"Prad�tas tvarkingas i�jungimas") // ((const unsigned char *)"Prad�tas gracingas i�jungimas")
#define KP_MSG_WSA_OPERATION_ABORTED_LT   ((const unsigned char *)"Persiklojanti operacija nutraukta")

#define KP_MSG_OUT_OF_MEM_RES_LT          ((const unsigned char *)"Operacinei sistemai tr�ksta atminties")
#define KP_MSG_ERROR_FILE_NOT_FOUND_LT    ((const unsigned char *)"Nurodytas failas nerastas")
#define KP_MSG_ERROR_PATH_NOT_FOUND_LT    ((const unsigned char *)"Nurodytas kelias iki fail� nerastas")
#define KP_MSG_ERROR_BAD_FORMAT_LT        ((const unsigned char *)"Pasirinktas .exe failas sugadintas")
#define KP_MSG_SE_ERR_ACCESSDENIED_LT     ((const unsigned char *)"Operacin� sistema u�draud� prisijungim� prie reikiam� fail�")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_LT  ((const unsigned char *)"Failo s�ry�is su programa nepilnas arba neteisingas")
#define KP_MSG_SE_ERR_DDEBUSY_LT          ((const unsigned char *)"DDE transakcija negali b�ti baigta, nes kitos DDE transakcijos dar vykdomos")
#define KP_MSG_SE_ERR_DDEFAIL_LT          ((const unsigned char *)"DDE transakcija nutraukta")
#define KP_MSG_SE_ERR_DDETIMEOUT_LT       ((const unsigned char *)"DDE transakcija negali b�ti baigta, nes neu�teko nurodyto laukimo laiko")
#define KP_MSG_SE_ERR_DLLNOTFOUND_LT      ((const unsigned char *)"Nurodyta dinamin� biblioteka nerasta")
#define KP_MSG_SE_ERR_FNF_LT              ((const unsigned char *)"Nurodytas failas nerastas")
#define KP_MSG_SE_ERR_NOASSOC_LT          ((const unsigned char *)"Nerasta programa skirta atverti �io tipo failus")
#define KP_MSG_SE_ERR_OOM_LT              ((const unsigned char *)"Nepakanka atminties atlikti operacijai")
#define KP_MSG_SE_ERR_PNF_LT              ((const unsigned char *)"Nurodytas kelias nerastas")
#define KP_MSG_SE_ERR_SHARE_LT            ((const unsigned char *)"Dalijimosi klaida")

// #define KP_MSG_FIRST_TIME_ADMIN_LT     ((const unsigned char *)"Programos paleidimui pirm� kart� reikalingos\n administratoriaus teis�s")
// #define KP_MSG_FIRST_TIME_ADMIN_LT     ((const unsigned char *)"Program� paleiskite i� naujo administratoriaus teis�mis")
#define KP_MSG_FIRST_TIME_ADMIN_LT        ((const unsigned char *)"Program� paleid�iant pirm� kart�, reikalingos\n administratoriaus teis�s. Paleiskite program� i� naujo\n administratoriaus teis�mis.")
#define KP_MSG_NOW_NOT_ADMIN_LT           KP_MSG_NOT_ADMIN_LT // ((const unsigned char *)"Dabar program� paleiskite dar kart� paprasto vartotojo teis�mis")
// #define KP_MSG_NOT_ADMIN_LT            ((const unsigned char *)"Program� paleiskite paprasto vartotojo teis�mis")
#define KP_MSG_NOT_ADMIN_LT               ((const unsigned char *)"Program� paleiskite i� naujo paprasto vartotojo teis�mis")
// #define KP_MSG_COPY_FILE_ACCESS_DENIED_LT ((const unsigned char *)"Failo nukopijuoti nepavyko, pabandykite prisijungti administratorium")
#define KP_MSG_COPY_FILE_ACCESS_DENIED_LT ((const unsigned char *)"Failo nukopijuoti nepavyko, program� paleiskite i� naujo administratoriaus teis�mis")

#define KP_PROGRESS_TITLE_LT              ((const unsigned char *)"Palaukite...")
#define KP_MSG_DELETING_FILE_LT           ((const unsigned char *)"Naikinamas failas %s.%s...")
#define KP_MSG_COPYING_LT                 ((const unsigned char *)"Kopijuojamas failas...")
#define KP_MSG_COPYING_FILE_LT            ((const unsigned char *)"Kopijuojamas failas %s.%s...")
#define KP_MSG_COPYING_DIR_LT             ((const unsigned char *)"Kopijuojamas aplankas %s.%s...")

#define KP_MSG_DOWNLOADING_LT             ((const unsigned char *)"Siun�iamas failas...")
#define KP_MSG_DOWNLOADING_FILE_LT        ((const unsigned char *)"Siun�iamas failas %s.%s...")

#define KP_MSG_NEG_ANSW_LT                ((const unsigned char *)"Neigiamas atsakymas")

#define KP_MSG_UNABLE_TO_EXECUTE_LT       ((const unsigned char *)"Komandos %s �vykdyti negaliu - patikrinkite, ar teisingai �dieg�te visus sistemos komponentus")

#define KP_MSG_FLASH_PLAYER_INSTALL_LT    ((const unsigned char *)"Dabar bus �diegtas Macromedia Flash grotuvas. Vykdykite tolesnius diegimo programos nurodymus.")

#define KP_MSG_FILE_CHANGED_LT            ((const unsigned char *)"Failas pasikeit�")

#define KP_MSG_ALL_FILES_LT               ((const unsigned char *)"Visi failai (*.*)")
#define KP_MSG_SAVE_AS_LT                 ((const unsigned char *)"�ra�yti kaip")

#define KP_MSG_FILE_EXISTS_LT             ((const unsigned char *)"Failas %s jau yra, perra�yti?")

#define KP_MSG_DIAG_MSG_LT                ((const unsigned char *)"Formuojamas diagnostinis prane�imas")
#define KP_MSG_DIAG_MSG_TITLE_LT          ((const unsigned char *)"Diagnostinis prane�imas")

#if FALSE
#define KP_MSG_DIAG_MSG_EXPL_LT           ((const unsigned char *)"Jei norite nusi�sti diagnostin� prane�im� gamintojui, u�pildykite " \
                                                                  "pateiktus laukus. Prane�imas apie kompiuterio konfig�racij�, produkt� " \
                                                                  "bei klaidos pob�d� bus i�si�stas internetu � produkto gamintojo tarnybin� " \
                                                                  "stot�. Jei po kurio laiko su Jumis nebus susisiekta J�s� nurodytu pa�to " \
                                                                  "adresu, kreipkit�s adresu %s")
#endif
// #define KP_MSG_DIAG_MSG_EXPL_LT        ((const unsigned char *)"Jei norite nusi�sti diagnostin� prane�im� gamintojui, u�pildykite pateiktus laukus.")
#define KP_MSG_DIAG_MSG_EXPL_LT           ((const unsigned char *)"Jei turite problem� naudodami �� produkt�, gamintojui galite nusi�sti diagnostin� prane�im�. U�pildykite pateiktus laukus.")
#define KP_MSG_DIAG_MSG_EXPL1_LT          ((const unsigned char *)"Jei norite si�sti diagnostin� prane�im�, spragtel�kite mygtuk� �Si�sti�, jei ne � �At�aukti�.")
#define KP_MSG_DIAG_MSG_EXPL2_LT          ((const unsigned char *)"Jei norite nusi�sti diagnostin� prane�im� gamintojui, u�pildykite J�s� el. pa�to adreso lauk� ir spragtel�kite mygtuk� �Si�sti�.")

#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_LT   ((const unsigned char *)"J�s� el. pa�to adresas:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_LT ((const unsigned char *)"Komentarai apie klaidos atsiradimo aplinkybes:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_LT    ((const unsigned char *)"Papildomas failas, kur� nor�tum�te nusi�sti\n(pvz., ekrano kopijos paveiksl�lis):")

#define KP_MSG_BAD_EMAIL_ADDRESS_LT       ((const unsigned char *)"Neteisingas el. pa�to adresas")

#define KP_MSG_DIAG_MSG_SEL_FILE_LT       ((const unsigned char *)"Pasirinkite siun�iam� fail�")

#define KP_MSG_DIAG_MSG_SUCCEEDED_LT      ((const unsigned char *)"Diagnostinis prane�imas nusi�stas s�kmingai")

#define KP_MSG_SIUSTI_LT                  ((const unsigned char *)"Si�sti")

#define KP_MSG_FIREWALL_LT                ((const unsigned char *)"Neleista prisijungti prie interneto. Patikrinkite J�s� ugniasien�s parinktis � pabandykite �traukti %s � s�ra�� program�, kurioms leid�iama kreiptis � internet�.")

#define KP_MSG_POINTER_LT                 ((const unsigned char *)"Bloga rodykl�")

#define KP_MSG_LOG_STARTED_LT             ((const unsigned char *)"�urnalas i�vedamas ir � fail� %s")
#define KP_MSG_CONS_TITLE_LT              ((const unsigned char *)"%s: Prane�im� �urnalas") // ((const unsigned char *)"Pulto terminalas") // ((const unsigned char *)"Pultas")

#define KP_MSG_UNHANDLED_EXCEPTION_LT     ((const unsigned char *)"Neapdorojamas tr�kis"

#endif // #if ((MsgLang == KpLangSel_p) || (MsgLang == KpLangLt_p))

#endif // #ifndef kpmsg_lt_included
