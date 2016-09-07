// -----------------------------------------
// kpmsg_ru.h
// programos paleidimo aplikaciju pranesimai
// rus� kalba
//

#ifndef kpmsg_ru_included
#define kpmsg_ru_included

// --------------------------------------- common kp messages

#if ((MsgLang == KpLangSel_p) || (MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))

#define KP_MSG_TITLE_RU             ((const unsigned char *)"���������")
#define KP_INPUT_TITLE_RU           ((const unsigned char *)"����")

#define KP_MSG_YES_RU               ((const unsigned char *)"��")
#define KP_MSG_TAIP_RU              KP_MSG_YES_RU
#define KP_MSG_NO_RU                ((const unsigned char *)"���")
#define KP_MSG_NE_RU                KP_MSG_NO_RU
#define KP_MSG_OK_RU                KP_MSG_TESTI_RU // KP_MSG_YES_RU // ((const unsigned char *)"������")
#define KP_MSG_GERAI_RU             KP_MSG_TESTI_RU // KP_MSG_OK_RU
#define KP_MSG_CANCEL_RU            ((const unsigned char *)"��������")
#define KP_MSG_ATSAUKTI_RU          KP_MSG_CANCEL_RU
#define KP_MSG_TESTI_RU             ((const unsigned char *)"����������") // "����������")
#define KP_MSG_BAIGTI_RU            ((const unsigned char *)"���������")
#define KP_MSG_PAMIRSAU_SLAPTAZODI_RU ((const unsigned char *)"������ ������")

#define KP_MSG_ERROR_RU             ((const unsigned char *)"������")
#define KP_MSG_WARNING_RU           ((const unsigned char *)"��������������")
#define KP_MSG_FILE_LINE_RU         ((const unsigned char *)", ������: %lx, ����: %s, ������: %d")
#define KP_MSG_ENTRY_ID_RU          ((const unsigned char *)", ������������� ������:%ld")
#define KP_MSG_ENTRY_RU             ((const unsigned char *)", ������: %s")

#define KP_MSG_NO_STANDARD_PROG_RU  ((const unsigned char *)"��� ����������� ��������� ��� ������� ���� ������")
#define KP_MSG_WND_NOT_FOUND_RU     ((const unsigned char *)"���� �� �������")
#define KP_MSG_PID_NOT_FOUND_RU     ((const unsigned char *)"�� ������ ������������� ��������")
#define KP_MSG_NO_SOCKET_RU         ((const unsigned char *)"����� ��� �� ������")
#define KP_MSG_SOCK_UNRESOLVED_RU   ((const unsigned char *)"����� ������� ��� �� ������")

#define KP_MSG_ERR_OK_RU            ((const unsigned char *)"�������� ������ �������")
#define KP_MSG_INVALIDARG_RU        ((const unsigned char *)"��������� ��������")
#define KP_MSG_NOTIMPL_RU           ((const unsigned char *)"������� ��� �� �������������")
#define KP_MSG_UNEXPECTED_RU        ((const unsigned char *)"����������� ����� �������")
#define KP_MSG_FERROR_RU            ((const unsigned char *)"������ ������/������ �����")
#define KP_MSG_SYSTEM_ERROR_RU      ((const unsigned char *)"���������� ������")
#define KP_MSG_EOF_RU               ((const unsigned char *)"����������� ����� �����")
#define KP_MSG_FILE_FORMAT_RU       ((const unsigned char *)"������������ ������ �����")
#define KP_MSG_FILE_NOT_FOUND_RU    ((const unsigned char *)"���� �� ������")
#define KP_MSG_DIR_ERROR_RU         ((const unsigned char *)"��������� ������� �������� �����")
#define KP_MSG_OUTOFMEM_RU          ((const unsigned char *)"������������ ������")
#define KP_MSG_NO_FILE_RU           ((const unsigned char *)"���� ��������")
#define KP_MSG_DOUBLE_UNGET_RU      ((const unsigned char *)"������� ������� �����")
#define KP_MSG_UNKN_CHR_RU          ((const unsigned char *)"������������ ������")
#define KP_MSG_COMMAND_ERROR_RU     ((const unsigned char *)"������� ������")
#define KP_MSG_BUFFER_OVERFLOW_RU   ((const unsigned char *)"������������ ������")
#define KP_MSG_FONT_UNDEF_RU        ((const unsigned char *)"����� ���������")
#define KP_MSG_KWD_NOT_FOUND_RU     ((const unsigned char *)"�������� ����� �� �������")
#define KP_MSG_UNKNOWN_SYSTEM_RU    ((const unsigned char *)"������������ ������ ��")
// #define KP_MSG_ILL_CODE_RU          ((const unsigned char *)"��������� ��� �����������")
#define KP_MSG_ILL_CODE_RU          ((const unsigned char *)"��������� ��� ���������")
#define KP_MSG_CANCELLED_RU         ((const unsigned char *)"�������� ����������")
#define KP_MSG_DOUBLE_CALL_RU       ((const unsigned char *)"������� �����")
#define KP_MSG_TIMEOUT_RU           ((const unsigned char *)"�������")
#define KP_MSG_OBJ_NOT_FOUND_RU     ((const unsigned char *)"������ ��������")
#define KP_MSG_NO_CONN_RU           ((const unsigned char *)"��� �����")

#define KP_MSG_TRANS_ERR_RU         ((const unsigned char *)"������ ��������")
#define KP_MSG_TRANS_ERR_1_RU       ((const unsigned char *)"������ ��������, ��������� ���������� ��� ���")

// #define KP_MSG_REFUSED_RU           ((const unsigned char *)"����� �������������� �����������")
#define KP_MSG_REFUSED_RU           ((const unsigned char *)"����� �������������� ���������")
#define KP_MSG_ACCESS_DENIED_RU     ((const unsigned char *)"��� �������")
#define KP_MSG_ILLEGAL_CHARACTER_RU ((const unsigned char *)"����������� ������")
#define KP_MSG_DIV_ZERO_RU          ((const unsigned char *)"������� �� ����")
#define KP_MSG_ILLMATHARG_RU        ((const unsigned char *)"��������� �������� �������������� ��������")
#define KP_MSG_ILLFUNC_RU           ((const unsigned char *)"��������� ����� �������")

#define KP_MSG_NOTINST_RU           ((const unsigned char *)"��������� ��� �� ����������� ��� � ��������� ����������, ��������� ��������� �����������")
#define KP_MSG_NOTINST_S_RU         ((const unsigned char *)"��������� �%s� ��� �� ����������� ��� � ��������� ����������, ��������� ��������� �����������")
#define KP_MSG_NOTINST_DELETE_RU    ((const unsigned char *)"��������� ��� �� ����������� ��� � ��������� ����������. ������� ��������� � ��������� ��������� �����������.")

#define KP_MSG_MSG_FORMAT_RU        ((const unsigned char *)"��������� ������ ���������")
#define KP_MSG_OBSOLETE_RU          ((const unsigned char *)"���������� ����� �������")

//#define KP_MSG_ERROR_HELP_RU      ((const unsigned char *)".  �� ����������� ������� ����������� �� ������ tech@tev.lt   ��� ����� ��������� ���������� ��. ���� %s")
//#define KP_MSG_ERROR_HELP_RU      ((const unsigned char *)".  �� ����������� ������� ����������� �� ����������� �����, ����� tech@tev.lt   � ��������� ������������ ���� %s")
#define KP_MSG_ERROR_HELP_RU        ((const unsigned char *)".  �� ����������� ������� ����������� �� ����������� �����, ����� pagalba@tev.lt")
#define KP_MSG_ERROR_HELP_REST_RU   ((const unsigned char *)"   � ��������� ������������ ���� %s � ������ �������� �����.")

#define KP_MSG_WSAEACCES_RU               KP_MSG_ACCESS_DENIED_RU
#define KP_MSG_WSAEADDRINUSE_RU           ((const unsigned char *)"����� �����")
#define KP_MSG_WSAEADDRNOTAVAIL_RU        ((const unsigned char *)"��������� ������� ��������� �����")
#define KP_MSG_WSAEAFNOSUPPORT_RU         ((const unsigned char *)"�������� ������ ���������� �� ��������������")
#define KP_MSG_WSAEALREADY_RU             ((const unsigned char *)"�������� ��� �����������")
#define KP_MSG_WSAECONNABORTED_RU         ((const unsigned char *)"����������� ����������� �����")
#define KP_MSG_WSAECONNREFUSED_RU         ((const unsigned char *)"����� �������������� ����������")
#define KP_MSG_WSAECONNRESET_RU           ((const unsigned char *)"����������� ����������")
#define KP_MSG_WSAEDESTADDRREQ_RU         ((const unsigned char *)"��������� ����� ����������")
#define KP_MSG_WSAEFAULT_RU               ((const unsigned char *)"��������� �����")
#define KP_MSG_WSAEHOSTDOWN_RU            ((const unsigned char *)"������ ��������")
#define KP_MSG_WSAEHOSTUNREACH_RU         ((const unsigned char *)"������ ����������")
#define KP_MSG_WSAEINPROGRESS_RU          ((const unsigned char *)"�������� �����������")
#define KP_MSG_WSAEINTR_RU                ((const unsigned char *)"����� ������� ����������")
#define KP_MSG_WSAEINVAL_RU               ((const unsigned char *)"��������� ��������")
#define KP_MSG_WSAEISCONN_RU              ((const unsigned char *)"����� �����")
#define KP_MSG_WSAEMFILE_RU               ((const unsigned char *)"������������ ����� �������� ������") // "������� ����� �������� ������")
#define KP_MSG_WSAEMSGSIZE_RU             ((const unsigned char *)"������������ ����� ���������") // "��������� ������� �������")
#define KP_MSG_WSAENETDOWN_RU             ((const unsigned char *)"���� �� ��������")
#define KP_MSG_WSAENETRESET_RU            ((const unsigned char *)"���� �����������")
#define KP_MSG_WSAENETUNREACH_RU          ((const unsigned char *)"���� ����������")
#define KP_MSG_WSAENOBUFS_RU              ((const unsigned char *)"���������� ����� � ������")
#define KP_MSG_WSAENOPROTOOPT_RU          ((const unsigned char *)"��������� ����� ���������")
#define KP_MSG_WSAENOTCONN_RU             ((const unsigned char *)"����� �����������")
#define KP_MSG_WSAENOTSOCK_RU             ((const unsigned char *)"�������� ������ �� ��� ������")
#define KP_MSG_WSAEOPNOTSUPP_RU           ((const unsigned char *)"�������� �� ��������������")
#define KP_MSG_WSAEPFNOSUPPORT_RU         ((const unsigned char *)"������ ���������� �� ��������������")
#define KP_MSG_WSAEPROCLIM_RU             ((const unsigned char *)"������������ ����� ���������") // "������� ����� ���������")
#define KP_MSG_WSAEPROTONOSUPPORT_RU      ((const unsigned char *)"�������� �� ��������������")
#define KP_MSG_WSAEPROTOTYPE_RU           ((const unsigned char *)"��������� ��� ������ ��� ������� ���������")
#define KP_MSG_WSAESHUTDOWN_RU            ((const unsigned char *)"����� �������� ������ �������� ����������")
#define KP_MSG_WSAESOCKTNOSUPPORT_RU      ((const unsigned char *)"��� ������ �� ��������������")
#define KP_MSG_WSAETIMEDOUT_RU            ((const unsigned char *)"������� � ����������")
#define KP_MSG_WSATYPE_NOT_FOUND_RU       ((const unsigned char *)"��� ������ ��������")
#define KP_MSG_WSAEWOULDBLOCK_RU          ((const unsigned char *)"������ �������� �� ��������")
#define KP_MSG_WSAHOST_NOT_FOUND_RU       ((const unsigned char *)"������ ��������")
#define KP_MSG_WSA_INVALID_HANDLE_RU      ((const unsigned char *)"��������� ��������� �������") // "Specified event object handle is invalid")
#define KP_MSG_WSA_INVALID_PARAMETER_RU   ((const unsigned char *)"��������� ���������") // "One or more parameters are invalid")
#define KP_MSG_WSAINVALIDPROCTABLE_RU     ((const unsigned char *)"��������� ������� ��������") // "Invalid procedure table from service provider")
#define KP_MSG_WSAINVALIDPROVIDER_RU      ((const unsigned char *)"��������� ��� ����������") // "Invalid service provider version number")
#define KP_MSG_WSA_IO_INCOMPLETE_RU       ((const unsigned char *)"������� ��������������� ������� ��� �������") // "Overlapped I/O event object not in signaled state")
#define KP_MSG_WSA_IO_PENDING_RU          ((const unsigned char *)"��������������� �������� ����� ��������� �����") // Overlapped operations will complete later")

#define KP_MSG_WSA_NOT_ENOUGH_MEMORY_RU   ((const unsigned char *)"������������ ������")
#define KP_MSG_WSANOTINITIALISED_RU       ((const unsigned char *)"������� ���������� ��� �� ������������") // "Successful WSAStartup not yet performed")
#define KP_MSG_WSANO_DATA_RU              ((const unsigned char *)"��� ����������, �� ����������� ������ ������ ������������ ����")
#define KP_MSG_WSANO_RECOVERY_RU          ((const unsigned char *)"������������ ������")
#define KP_MSG_WSAPROVIDERFAILEDINIT_RU   ((const unsigned char *)"��������� ������� ���������������� ���������� ������")
#define KP_MSG_WSASYSCALLFAILURE_RU       ((const unsigned char *)"������ ���������� ������")
#define KP_MSG_WSASYSNOTREADY_RU          ((const unsigned char *)"������� ������� ����������")
#define KP_MSG_WSATRY_AGAIN_RU            ((const unsigned char *)"�������� ������������������ ������") // "Non-authoritative host not found")
#define KP_MSG_WSAVERNOTSUPPORTED_RU      ((const unsigned char *)"������������ ������ WINSOCK.DLL")
#define KP_MSG_WSAEDISCON_RU              ((const unsigned char *)"������ ��������� ���������� �������")
#define KP_MSG_WSA_OPERATION_ABORTED_RU   ((const unsigned char *)"��������������� �������� ����������")

#define KP_MSG_OUT_OF_MEM_RES_RU          ((const unsigned char *)"������������ ������ ��� �������� ������������ �������")
#define KP_MSG_ERROR_FILE_NOT_FOUND_RU    ((const unsigned char *)"��������� ���� �� ������")
#define KP_MSG_ERROR_PATH_NOT_FOUND_RU    ((const unsigned char *)"��������� ���� �� ������")
#define KP_MSG_ERROR_BAD_FORMAT_RU        ((const unsigned char *)"�������� ��� ��������� ���� .exe")
#define KP_MSG_SE_ERR_ACCESSDENIED_RU     ((const unsigned char *)"������������ ������� �������� � ������� � ���������� �����")
#define KP_MSG_SE_ERR_ASSOCINCOMPLETE_RU  ((const unsigned char *)"���������� ����� ����� �������� ��� ��������")
#define KP_MSG_SE_ERR_DDEBUSY_RU          ((const unsigned char *)"���������� DDE �� ����� ���� ���������, ��� ��� ������� ������ �������� ���������� DDE")
#define KP_MSG_SE_ERR_DDEFAIL_RU          ((const unsigned char *)"���������� DDE ����������")
#define KP_MSG_SE_ERR_DDETIMEOUT_RU       ((const unsigned char *)"������� � ���������� DDE")
#define KP_MSG_SE_ERR_DLLNOTFOUND_RU      ((const unsigned char *)"��������� ������������ ���������� �� �������")
#define KP_MSG_SE_ERR_FNF_RU              ((const unsigned char *)"��������� ���� �� ������")
#define KP_MSG_SE_ERR_NOASSOC_RU          ((const unsigned char *)"��������� ��� ����� �� ����� ��������������� ���������")
#define KP_MSG_SE_ERR_OOM_RU              ((const unsigned char *)"������������� ����� ������ ��� ���������� ��������")
#define KP_MSG_SE_ERR_PNF_RU              ((const unsigned char *)"��������� ���� �� ������")
#define KP_MSG_SE_ERR_SHARE_RU            ((const unsigned char *)"������ ����������� �������������") // "��������� ...") // "A sharing violation occurred")

#define KP_MSG_FIRST_TIME_ADMIN_RU        ((const unsigned char *)"��� ������� ��������� ������ ��� ����������\n ����� ��������������. ����������������� ��������������� � ��������� ��������� ��� ���.")
#define KP_MSG_NOW_NOT_ADMIN_RU           KP_MSG_NOT_ADMIN
#define KP_MSG_NOT_ADMIN_RU               ((const unsigned char *)"����������������� ������� ������������� � ��������� ��������� ��� ���")
#define KP_MSG_COPY_FILE_ACCESS_DENIED_RU ((const unsigned char *)"��������� ������� ���������� ����, ����������������� ��������������� � ��������� ��������� ��� ���")

#define KP_PROGRESS_TITLE_RU              ((const unsigned char *)"���������...")
#define KP_MSG_DELETING_FILE_RU           ((const unsigned char *)"��������� ���� %s.%s...")
#define KP_MSG_COPYING_RU                 ((const unsigned char *)"���������� ����...")
#define KP_MSG_COPYING_FILE_RU            ((const unsigned char *)"���������� ���� %s.%s...")
#define KP_MSG_COPYING_DIR_RU             ((const unsigned char *)"���������� ������� %s.%s...")

#define KP_MSG_DOWNLOADING_RU             ((const unsigned char *)"�������� �����...")
#define KP_MSG_DOWNLOADING_FILE_RU        ((const unsigned char *)"�������� ����� %s.%s...")

#define KP_MSG_NEG_ANSW_RU                ((const unsigned char *)"������������� �����")

#define KP_MSG_UNABLE_TO_EXECUTE_RU       ((const unsigned char *)"�� ���� ��������� �������� %s � ���������, ��������� �� ����������� ��� ���������� �������")

#define KP_MSG_FLASH_PLAYER_INSTALL_RU    ((const unsigned char *)"������ ����� ���������� Macromedia Flash �����. �������� ���������� ��������� ��������� ��������� ������.")

#define KP_MSG_FILE_CHANGED_RU            ((const unsigned char *)"���� ���������")

#define KP_MSG_ALL_FILES_RU               ((const unsigned char *)"��� ����� (*.*)")
#define KP_MSG_SAVE_AS_RU                 ((const unsigned char *)"�������� ���")

#define KP_MSG_FILE_EXISTS_RU             ((const unsigned char *)"���� %s ��� ����, ����������?")

#define KP_MSG_DIAG_MSG_RU                ((const unsigned char *)"���������� ���������������� ���������")
#define KP_MSG_DIAG_MSG_TITLE_RU          ((const unsigned char *)"��������������� ���������")

#if FALSE
#define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"��� ����, ����� ������� ��������������� ��������� �������������, ���������� " \
                                                                  "��������� ��������������� ����. ��������� � ������������� ����������, �������� � " \
                                                                  "��������� ����������� �� ������ ����� ������� �� ��������� � ������ ������������� " \
                                                                  "��������. ���� ����� ���������� ������� � ���� �� ����� ����������� ����� �� " \
                                                                  "���������� ������, ����������� �� ������������� �� ������ pagalba@tev.lt")
#define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"��� ����, ����� ������� ��������������� ��������� �������������, ���������� " \
                                                                  "��������� ��������������� ����. ��������� � ������������� ����������, �������� � " \
                                                                  "��������� ����������� �� ������ ����� ������� �� ��������� � ������ ������������� " \
                                                                  "��������. ���� ����� ���������� ������� � ���� �� ����� ����������� �����, " \
                                                                  "����������� �� ������ pagalba@tev.lt")
#endif
// #define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"��� ����, ����� ������� ��������������� ��������� �������������, ���������� ��������� ��������������� ����.")
// #define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"���� ��� ������������� ������� �������� �������� ��������, ������ ������� ��������������� ��������� �������������. ��������� ��������������� ����.")
#define KP_MSG_DIAG_MSG_EXPL_RU           ((const unsigned char *)"���� ��� ������������� ������� �������� �������� ��������, ������ ������� ��������� �������������. ��������� ��������������� ����.")
#define KP_MSG_DIAG_MSG_EXPL1_RU          ((const unsigned char *)"��� ����, ����� ������� ��������������� ���������, ������� ������ ���������, � ��������� ������ � ����������.")
#define KP_MSG_DIAG_MSG_EXPL2_RU          ((const unsigned char *)"��� ����, ����� ������� ��������������� ��������� �������������, ���������� ��������� ���� ������ ����� ����������� ����� � ������ ������ ���������.")

// #define KP_MSG_DIAG_MSG_EMAIL_PROMPT_RU   ((const unsigned char *)"����� ������ ��������� ����� ����������� �����:")
#define KP_MSG_DIAG_MSG_EMAIL_PROMPT_RU   ((const unsigned char *)"��� ����� ����������� �����:")
// #define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_RU ((const unsigned char *)"���� ������� �� ������ ������������� ������������� ������:")
#define KP_MSG_DIAG_MSG_COMMENTS_PROMPT_RU ((const unsigned char *)"���� ������� ��� �������������� ������������� ������:")
#define KP_MSG_DIAG_MSG_FILE_PROMPT_RU    ((const unsigned char *)"�������������� ����, ������� �� ������ �� �������\n(��������, �������� ����� ������):")

#define KP_MSG_BAD_EMAIL_ADDRESS_RU       ((const unsigned char *)"��������� ����� ����������� �����")

#define KP_MSG_DIAG_MSG_SEL_FILE_RU       ((const unsigned char *)"�������� ���� ��� �����������")

#define KP_MSG_DIAG_MSG_SUCCEEDED_RU      ((const unsigned char *)"��������������� ��������� ������� �������")

#define KP_MSG_SIUSTI_RU                  ((const unsigned char *)"�������")

#define KP_MSG_FIREWALL_RU                ((const unsigned char *)"������ � ��������� ������������. ��������� ��������� ������ �������� ������ (firewall) � ���������� �������� %s � ������ ��������, ������� �������� ������ � ���������.")

#define KP_MSG_POINTER_RU                 ((const unsigned char *)"������������ ���������")

// TODO: i�versti
#define KP_MSG_LOG_STARTED_RU             ((const unsigned char *)"�urnalas i�vedamas ir � fail� %s")
#define KP_MSG_CONS_TITLE_RU              ((const unsigned char *)"%s: Prane�im� �urnalas") // ((const unsigned char *)"Pulto terminalas") // ((const unsigned char *)"Pultas")

#define KP_MSG_UNHANDLED_EXCEPTION_RU     ((const unsigned char *)"Neapdorojamas tr�kis"

#endif // #if ((MsgLang == KpLangSel_p) || (MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))

#endif // #ifndef kpmsg_ru_included
