// -----------------------------------------
// kpmsg_pl_1257.h
// programos paleidimo aplikaciju pranesimai
// lenk� kalba Windows Baltic
//

#ifndef kpmsg_pl_1257_included
#define kpmsg_pl_1257_included

// --------------------------------------- common kp messages
#if ((MsgLang == KpLangPl_p) || (MsgLang == KpLangSel_p) || (MsgLang == KpLangPl_1257_p))

#define KP_MSG_TITLE_PL_1257              ((const unsigned char *)"Komunikat")
#define KP_INPUT_TITLE_PL_1257            ((const unsigned char *)"Wprowadzanie")

#define KP_MSG_TAIP_PL_1257               ((const unsigned char *)"Tak")
#define KP_MSG_YES_PL_1257                KP_MSG_TAIP_PL_1257
#define KP_MSG_NE_PL_1257                 ((const unsigned char *)"Nie")
#define KP_MSG_NO_PL_1257                 KP_MSG_NE_PL_1257
#define KP_MSG_GERAI_PL_1257              ((const unsigned char *)"Dobrze")
#define KP_MSG_OK_PL_1257                 KP_MSG_GERAI_PL_1257
#define KP_MSG_ATSAUKTI_PL_1257           ((const unsigned char *)"Odwo�aj")
#define KP_MSG_CANCEL_PL_1257             KP_MSG_ATSAUKTI_PL_1257
#define KP_MSG_TESTI_PL_1257              ((const unsigned char *)"Dalej")
#define KP_MSG_BAIGTI_PL_1257             ((const unsigned char *)"Zako�cz")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_PL_1257 ((const unsigned char *)"Zapomnia�em has�o")

#define KP_MSG_ERROR_PL_1257              ((const unsigned char *)"B��d")
#define KP_MSG_WARNING_PL_1257            ((const unsigned char *)"Ostrze�enie")
#define KP_MSG_FILE_LINE_PL_1257          ((const unsigned char *)", b��d: %lx, plik: %s, linijka: %d")
#define KP_MSG_ENTRY_ID_PL_1257           ((const unsigned char *)", Nr. wpisu:%ld")
#define KP_MSG_ENTRY_PL_1257              ((const unsigned char *)", Wpis: %s")

#define KP_MSG_NO_STANDARD_PROG_PL_1257   ((const unsigned char *)"Nie znaleziono programu do otwierania plik�w tego typu")
#define KP_MSG_WND_NOT_FOUND_PL_1257      ((const unsigned char *)"Nie znaleziono okna")
#define KP_MSG_PID_NOT_FOUND_PL_1257      ((const unsigned char *)"Nie znaleziono indentyfikatora procesu")
#define KP_MSG_NO_SOCKET_PL_1257          ((const unsigned char *)"Wi�� jeszcze nie stworzona")
#define KP_MSG_SOCK_UNRESOLVED_PL_1257    ((const unsigned char *)"Nie znaleziono adresu stacji s�u�bowej")

#define KP_MSG_ERR_OK_PL_1257             ((const unsigned char *)"Operacja wykonana")
#define KP_MSG_INVALIDARG_PL_1257         ((const unsigned char *)"B��dne parametry")
#define KP_MSG_NOTIMPL_PL_1257            ((const unsigned char *)"W�a�ciwo�� jeszcze nie zrealizowana")
#define KP_MSG_UNEXPECTED_PL_1257         ((const unsigned char *)"Nieoczekiwny zwrot do interfejsu")
#define KP_MSG_FERROR_PL_1257             ((const unsigned char *)"B��d sczytywania/zapisywania pliku")
#define KP_MSG_SYSTEM_ERROR_PL_1257       ((const unsigned char *)"B��d systemu")
#define KP_MSG_EOF_PL_1257                ((const unsigned char *)"Nieprawid�owe zako�czenie pliku")
#define KP_MSG_FILE_FORMAT_PL_1257        ((const unsigned char *)"Nieprawid�owy format pliku")
#define KP_MSG_FILE_NOT_FOUND_PL_1257     ((const unsigned char *)"Nie znaleziono pliku")
#define KP_MSG_DIR_ERROR_PL_1257          ((const unsigned char *)"Nie uda�o si� otworzy�/stworzy� pliku")
#define KP_MSG_OUTOFMEM_PL_1257           ((const unsigned char *)"Niewystarcza pami�ci")
#define KP_MSG_NO_FILE_PL_1257            ((const unsigned char *)"Nie otworzono pliku")
#define KP_MSG_DOUBLE_UNGET_PL_1257       ((const unsigned char *)"Podw�jny unget")
#define KP_MSG_UNKN_CHR_PL_1257           ((const unsigned char *)"Nierozpoznano symbol")
#define KP_MSG_COMMAND_ERROR_PL_1257      ((const unsigned char *)"B��d zewn�trzny")
                                             
#define KP_MSG_BUFFER_OVERFLOW_PL_1257    ((const unsigned char *)"Przepe�niony bufor")
#define KP_MSG_FONT_UNDEF_PL_1257         ((const unsigned char *)"Nieokre�lono szryft")
#define KP_MSG_KWD_NOT_FOUND_PL_1257      ((const unsigned char *)"Nie znaleziono kluczowego s�owa")
#define KP_MSG_UNKNOWN_SYSTEM_PL_1257     ((const unsigned char *)"Nie rozpoznano systemu operacyjnego")
// #define KP_MSG_ILL_CODE_PL_1257           ((const unsigned char *)"B��dny kod rejestracji")
#define KP_MSG_ILL_CODE_PL_1257           ((const unsigned char *)"B��dny kod aktywacji")
                                            
#define KP_MSG_CANCELLED_PL_1257          ((const unsigned char *)"Przerwano operacj�")
#define KP_MSG_DOUBLE_CALL_PL_1257        ((const unsigned char *)"Podw�jne wywo�anie")
#define KP_MSG_TIMEOUT_PL_1257            ((const unsigned char *)"Przekroczono czas oczekiwania")
#define KP_MSG_OBJ_NOT_FOUND_PL_1257      ((const unsigned char *)"Nie znaleziono objektu")
                                            
#define KP_MSG_NO_CONN_PL_1257            ((const unsigned char *)"Nie ma ��czno�ci")

#define KP_MSG_TRANS_ERR_PL_1257          ((const unsigned char *)"B��d przekazu")
#define KP_MSG_TRANS_ERR_1_PL_1257        ((const unsigned char *)"B��d przekazu. Zapuszczaj wysy�anie ponownie")

// #define KP_MSG_REFUSED_PL_1257            ((const unsigned char *)"Odrzucono rejestracj�")
#define KP_MSG_REFUSED_PL_1257            ((const unsigned char *)"Odrzucono aktywacj�")
#define KP_MSG_ACCESS_DENIED_PL_1257      ((const unsigned char *)"��czno�� niedozwolona")
#define KP_MSG_ILLEGAL_CHARACTER_PL_1257  ((const unsigned char *)"Niedopuszczalny symbol")
#define KP_MSG_DIV_ZERO_PL_1257           ((const unsigned char *)"Dzielenie przez zero")
#define KP_MSG_ILLMATHARG_PL_1257         ((const unsigned char *)"Niedopuszczalny argument matematycznej funkcji")
#define KP_MSG_ILLFUNC_PL_1257            ((const unsigned char *)"Niedopuszczalna operacja")

#define KP_MSG_NOTINST_PL_1257            ((const unsigned char *)"Program nie zainstalowany lub zepsuta instalacja. Zainstaluj ponownie.")
#define KP_MSG_NOTINST_S_PL_1257          ((const unsigned char *)"Program �%s� nie zainstalowany lub zepsuta instalacja. Zainstaluj ponownie.")
#define KP_MSG_NOTINST_DELETE_PL_1257     ((const unsigned char *)"Program nie zainstalowany lub zepsuta instalacja. Odinstaluj i zainstaluj produkt ponownie.")

#define KP_MSG_MSG_FORMAT_PL_1257         ((const unsigned char *)"B��dny format komunikatu")
#define KP_MSG_OBSOLETE_PL_1257           ((const unsigned char *)"Stara funkcja")
                                            
// #define KP_MSG_ERROR_HELP_PL_1257      ((const unsigned char *)".  Po pomoc techniczn� zwr�� si� pod adres %s. Do listu za��cz plik %s")
#define KP_MSG_ERROR_HELP_PL_1257         ((const unsigned char *)".  Po pomoc techniczn� zwr�� si� pod adres %s")
#define KP_MSG_ERROR_HELP_REST_PL_1257    ((const unsigned char *)"   Do listu za��cz plik %s z Twego pulpitu.")
                                             
#define KP_MSG_WSAEACCES_PL_1257               ((const unsigned char *)"Nie masz uprawnienia")
#define KP_MSG_WSAEADDRINUSE_PL_1257           ((const unsigned char *)"Adres jest ju� wykorzystany")
#define KP_MSG_WSAEADDRNOTAVAIL_PL_1257        ((const unsigned char *)"Wskazany adres nie mo�e by� przy��czony")
#define KP_MSG_WSAEAFNOSUPPORT_PL_1257         ((const unsigned char *)"Grupa adres�w nie podtrzymywana przez protok��")
#define KP_MSG_WSAEALREADY_PL_1257             ((const unsigned char *)"Operacja ju� jest wykonywana")
#define KP_MSG_WSAECONNABORTED_PL_1257         ((const unsigned char *)"Program wywo�a� rozerwanie po��czenia")
#define KP_MSG_WSAECONNREFUSED_PL_1257         ((const unsigned char *)"Po��czenie zosta�o odrzucone")

#define KP_MSG_WSAECONNRESET_PL_1257           ((const unsigned char *)"Po��czenie zosta�o rozerwane")
#define KP_MSG_WSAEDESTADDRREQ_PL_1257         ((const unsigned char *)"Wymagany jest adres")
#define KP_MSG_WSAEFAULT_PL_1257               ((const unsigned char *)"B��dny adres")

#define KP_MSG_WSAEHOSTDOWN_PL_1257            ((const unsigned char *)"Serwer czasowo niedost�pny")
#define KP_MSG_WSAEHOSTUNREACH_PL_1257         ((const unsigned char *)"Serwer jest nieosi�galny")
#define KP_MSG_WSAEINPROGRESS_PL_1257          ((const unsigned char *)"Operacja jest wykonywana")
#define KP_MSG_WSAEINTR_PL_1257                ((const unsigned char *)"Funkcja zosta�a przerwana")

#define KP_MSG_WSAEINVAL_PL_1257               ((const unsigned char *)"B��dne parametry")
#define KP_MSG_WSAEISCONN_PL_1257              ((const unsigned char *)"Po��czenie ju� jest nawi�zane")
#define KP_MSG_WSAEMFILE_PL_1257               ((const unsigned char *)"Otworzono za du�o plik�w")

#define KP_MSG_WSAEMSGSIZE_PL_1257             ((const unsigned char *)"Zbyt d�ugi komunikat")
#define KP_MSG_WSAENETDOWN_PL_1257             ((const unsigned char *)"Sie� nie dzia�a")
#define KP_MSG_WSAENETRESET_PL_1257            ((const unsigned char *)"Od��czono si� od sieci")

#define KP_MSG_WSAENETUNREACH_PL_1257          ((const unsigned char *)"Sie� nieosi�galna")
#define KP_MSG_WSAENOBUFS_PL_1257              ((const unsigned char *)"Brakuje miejsca w buforze")
#define KP_MSG_WSAENOPROTOOPT_PL_1257          ((const unsigned char *)"B��dne opcje protoko�u")

#define KP_MSG_WSAENOTCONN_PL_1257             ((const unsigned char *)"Nieudane po��czenie")
#define KP_MSG_WSAENOTSOCK_PL_1257             ((const unsigned char *)"Socket operation on non-socket")
#define KP_MSG_WSAEOPNOTSUPP_PL_1257           ((const unsigned char *)"Operacja nie mo�e by� wykonana")

#define KP_MSG_WSAEPFNOSUPPORT_PL_1257         ((const unsigned char *)"Niepodtrzymywana rodzina protoko��w")
#define KP_MSG_WSAEPROCLIM_PL_1257             ((const unsigned char *)"Zbyt du�o proces�w")
#define KP_MSG_WSAEPROTONOSUPPORT_PL_1257      ((const unsigned char *)"Protok�� nie jest podtrzymywany")

#define KP_MSG_WSAEPROTOTYPE_PL_1257           ((const unsigned char *)"Nieprawid�owy typ po��czenia protoko�u")
#define KP_MSG_WSAESHUTDOWN_PL_1257            ((const unsigned char *)"Wysy�anie niemo�liwe, po��czenie zerwane")
#define KP_MSG_WSAESOCKTNOSUPPORT_PL_1257      ((const unsigned char *)"Typ po��czenia niepodtrzymywany")
#define KP_MSG_WSAETIMEDOUT_PL_1257            ((const unsigned char *)"Przewy�szono maksymalny czas oczekiwania po��czenia")

#define KP_MSG_WSATYPE_NOT_FOUND_PL_1257       ((const unsigned char *)"Nie znaleziono typ klasy")
#define KP_MSG_WSAEWOULDBLOCK_PL_1257          ((const unsigned char *)"�r�d�o czasowo niedost�pne")
#define KP_MSG_WSAHOST_NOT_FOUND_PL_1257       ((const unsigned char *)"Nie znaleziono serweru")
#define KP_MSG_WSA_INVALID_HANDLE_PL_1257      ((const unsigned char *)"B��dny kontroler objektu")
#define KP_MSG_WSA_INVALID_PARAMETER_PL_1257   ((const unsigned char *)"B��dne parametry")
#define KP_MSG_WSAINVALIDPROCTABLE_PL_1257     ((const unsigned char *)"B��dna tablica procedur")
#define KP_MSG_WSAINVALIDPROVIDER_PL_1257      ((const unsigned char *)"B��dny kod dostawcy")
#define KP_MSG_WSA_IO_INCOMPLETE_PL_1257       ((const unsigned char *)"Nak�adaj� si� zdarzenia wprowdzania/wyprowadzania")
#define KP_MSG_WSA_IO_PENDING_PL_1257          ((const unsigned char *)"Nak�adaj�ce si� operacje b�d� wykonane p��niej")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_PL_1257   ((const unsigned char *)"Brak pami�ci")
#define KP_MSG_WSANOTINITIALISED_PL_1257       ((const unsigned char *)"Podsystem sieci nieaktywowany")
#define KP_MSG_WSANO_DATA_PL_1257              ((const unsigned char *)"Nie ma danych wymaganego typu")
#define KP_MSG_WSANO_RECOVERY_PL_1257          ((const unsigned char *)"Nienaprawialny b��d")
#define KP_MSG_WSAPROVIDERFAILEDINIT_PL_1257   ((const unsigned char *)"Nie mo�liwa jest inicjacja dostawcy us�ugi")
#define KP_MSG_WSASYSCALLFAILURE_PL_1257       ((const unsigned char *)"B��dny zwrot systemu")
#define KP_MSG_WSASYSNOTREADY_PL_1257          ((const unsigned char *)"Podsystem sieci nieosi�galny")
#define KP_MSG_WSATRY_AGAIN_PL_1257            ((const unsigned char *)"Nieautoryzowany serwer nie znaleziony")

#define KP_MSG_WSAVERNOTSUPPORTED_PL_1257      ((const unsigned char *)"B��dna wersja WINSOCK.DLL")
#define KP_MSG_WSAEDISCON_PL_1257              ((const unsigned char *)"Rozpocz�to porz�dne wy��czanie")
#define KP_MSG_WSA_OPERATION_ABORTED_PL_1257   ((const unsigned char *)"Nak�adaj�ca si� operacja przerwana")

#define KP_MSG_OUT_OF_MEM_RES_PL_1257          ((const unsigned char *)"Brak pami�ci systemu operacyjnego")
#define KP_MSG_ERROR_FILE_NOT_FOUND_PL_1257    ((const unsigned char *)"Nie znaleziono wskazanego pliku")
#define KP_MSG_ERROR_PATH_NOT_FOUND_PL_1257    ((const unsigned char *)"Nie znaleziono wskazanej �cie�ki do pliku")
#define KP_MSG_ERROR_BAD_FORMAT_PL_1257        ((const unsigned char *)"Wybrany plik .exe jest zepsuty")
#define KP_MSG_SE_ERR_ACCESSDENIED_PL_1257     ((const unsigned char *)"System operacyjny zabroni� ��czno�ci z potrzebnymi plikami")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_PL_1257  ((const unsigned char *)"Wi�� pliku z programem jest niepe�na lub b��dna")
#define KP_MSG_SE_ERR_DDEBUSY_PL_1257          ((const unsigned char *)"DDE transakcja nie mo�e by� zako�czona, bo inne DDE transakcje s� jeszcze wykonywane")
#define KP_MSG_SE_ERR_DDEFAIL_PL_1257          ((const unsigned char *)"DDE transakcja przerwana")
#define KP_MSG_SE_ERR_DDETIMEOUT_PL_1257       ((const unsigned char *)"DDE transakcja nie mo�e by� zako�czona, bo zabrak�o wskazanego czasu oczekiwania")
#define KP_MSG_SE_ERR_DLLNOTFOUND_PL_1257      ((const unsigned char *)"Nie znaleziono wskazanej biblioteki dynamicznej")
#define KP_MSG_SE_ERR_FNF_PL_1257              ((const unsigned char *)"Nie znaleziono wskazanego pliku")
#define KP_MSG_SE_ERR_NOASSOC_PL_1257          ((const unsigned char *)"Nie znaleziono programu do otwarcia plik�w danego typu")

#define KP_MSG_SE_ERR_OOM_PL_1257              ((const unsigned char *)"Brak pami�ci do wykonania operacji")
#define KP_MSG_SE_ERR_PNF_PL_1257              ((const unsigned char *)"Nie znaleziono wskazanej �cie�ki")
#define KP_MSG_SE_ERR_SHARE_PL_1257            ((const unsigned char *)"B��d podzia�u")

#define KP_MSG_FIRST_TIME_ADMIN_PL_1257        ((const unsigned char *)"Zapuszczaj�c program poraz pierwszy wymagane s� uprawnienia administratora. Zapu�� program ponownie z uprawnieniami administratora.")

#define KP_MSG_NOW_NOT_ADMIN_PL_1257           KP_MSG_NOT_ADMIN_PL_1257
#define KP_MSG_NOT_ADMIN_PL_1257               ((const unsigned char *)"Zapu�� program ponownie z uprawnieniami zwyk�ego u�ytkownika")

#define KP_MSG_COPY_FILE_ACCESS_DENIED_PL_1257 ((const unsigned char *)"Nie uda�o si� skopiowa� pliku. Zapu�� program ponownie z uprawnieniami administratora.")


#define KP_PROGRESS_TITLE_PL_1257               ((const unsigned char *)"Zaczekaj...")
#define KP_MSG_DELETING_FILE_PL_1257            ((const unsigned char *)"Kasuje si� plik %s.%s...")

#define KP_MSG_COPYING_PL_1257                  ((const unsigned char *)"Kopiuje si� plik...")

#define KP_MSG_COPYING_DIR_PL_1257              ((const unsigned char *)"Kopiuje si� katalog %s.%s...")
#define KP_MSG_COPYING_FILE_PL_1257             ((const unsigned char *)"Kopiuje si� plik %s.%s...")

// TODO: i�versti
#define KP_MSG_DOWNLOADING_PL_1257              ((const unsigned char *)"Siun�iamas failas...")
#define KP_MSG_DOWNLOADING_FILE_PL_1257         ((const unsigned char *)"Siun�iamas failas %s.%s...")

#define KP_MSG_NEG_ANSW_PL_1257                 ((const unsigned char *)"Odpowied� negatywna")

#define KP_MSG_UNABLE_TO_EXECUTE_PL_1257        ((const unsigned char *)"Polecenie %s nie mo�e by� wykonane, sprawd�, czy prawid�owo s� zainstalowane wszystkie komponenty systemowe")

#define KP_MSG_FLASH_PLAYER_INSTALL_PL_1257     ((const unsigned char *)"Nast�pnie b�dzie zainstalowany \"Macromedia Flash player\". Wykonuj dalsze polecenia instalatora.")

#define KP_MSG_FILE_CHANGED_PL_1257             ((const unsigned char *)"Plik zosta� zmieniony")

#define KP_MSG_ALL_FILES_PL_1257                ((const unsigned char *)"Wszystkie pliki (*.*)")
#define KP_MSG_SAVE_AS_PL_1257                  ((const unsigned char *)"Zapisz jako")

#define KP_MSG_FILE_EXISTS_PL_1257              ((const unsigned char *)"Plik %s ju� istnieje, czy chcesz go zast�pi�?")

#define KP_MSG_DIAG_MSG_PL_1257                 ((const unsigned char *)"Formowanie wiadomo�ci diagnostycznej")
#define KP_MSG_DIAG_MSG_TITLE_PL_1257           ((const unsigned char *)"Wiadomo�� diagnostyczna")

#if FALSE
#define KP_MSG_DIAG_MSG_EXPL_PL_1257            ((const unsigned char *)"Je�li chcesz producentowi wys�a� wiadomo�� diagnostyczn�, wype�nij dane " \
                                                                        "pola. Wiadomo�� o konfiguracji komputera, produkcie oraz naturze b��du " \
                                                                        "b�dzie wys�ana na serwer producenta. Je�eli w kr�tkim czasie nie otrzymasz " \
                                                                        "odpowiedzi na sw�j podany e-mail, skontatuj si� z producentem pisz�c na " \
                                                                        "adres %s")
#endif
#define KP_MSG_DIAG_MSG_EXPL_PL_1257            ((const unsigned char *)"Je�li chcesz producentowi wys�a� wiadomo�� diagnostyczn�, wype�nij dane pola.")

#define KP_MSG_DIAG_MSG_EXPL1_PL_1257          ((const unsigned char *)"Je�li chcesz wys�a� wiadomo�� diagnostyczn� kliknij przycisk �Wy�lij�, je�li nie � �Odwo�aj�.")
#define KP_MSG_DIAG_MSG_EXPL2_PL_1257          ((const unsigned char *)"Je�li chcesz wys�a� wiadomo�� diagnostyczn� producentowi, wpisz sw�j adres e-mail w odpowiednie pole i kliknij przycisk �Wy�lij�.")

#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_PL_1257    ((const unsigned char *)"Tw�j e-mail:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_PL_1257 ((const unsigned char *)"Komentarze o okoliczno�ciach wyst�pienia b��du:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_PL_1257     ((const unsigned char *)"Dodatkowy plik, k�ry chcia�by� do��czy�\n(np. zrzut ekranu):")

#define KP_MSG_BAD_EMAIL_ADDRESS_PL_1257        ((const unsigned char *)"Nieprawid�owy adres e-mail")

#define KP_MSG_DIAG_MSG_SEL_FILE_PL_1257        ((const unsigned char *)"Wybierz plik do wys�ania")

// #define KP_MSG_DIAG_MSG_SUCCEEDED_PL_1257       ((const unsigned char *)"Wiadomoc diagnostyczna zosta�a wys�ana")
#define KP_MSG_DIAG_MSG_SUCCEEDED_PL_1257       ((const unsigned char *)"Wiadomo�� diagnostyczna zosta�a wys�ana")

#define KP_MSG_SIUSTI_PL_1257                   ((const unsigned char *)"Wy�lij")

#define KP_MSG_FIREWALL_PL_1257                 ((const unsigned char *)"Nie ma dost�pu do Internetu. Sprawd� ustawienia swojej zapory sieciowej � spr�buj wci�gn�� %s do listy zaufanych program�w, kt�rym dozwolone jest zwracanie si� do internetu.")

#define KP_MSG_POINTER_PL_1257                  ((const unsigned char *)"B��d wska�nika")

// TODO: i�versti
#define KP_MSG_LOG_STARTED_PL_1257             ((const unsigned char *)"�urnalas i�vedamas ir � fail� %s")
#define KP_MSG_CONS_TITLE_PL_1257              ((const unsigned char *)"%s: Prane�im� �urnalas") // ((const unsigned char *)"Pulto terminalas") // ((const unsigned char *)"Pultas")

#define KP_MSG_UNHANDLED_EXCEPTION_PL_1257     ((const unsigned char *)"Neapdorojamas tr�kis"

#endif // #if ((MsgLang == KpLangPl_p) || (MsgLang == KpLangSel_p) || (MsgLang == KpLangPl_1257_p))

#endif // #ifndef kpmsg_pl_1257_included
