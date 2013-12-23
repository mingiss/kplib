/*
 * kpsock.cpp
 *
 *    Win32 sockets
 *
 *  2013-12-16  mp  Initial creation
 *
 */


// ---------------------
#if 1 // #ifdef Debug
#define TRACE_HTTP
#endif


#include "envir.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <winsock2.h>
#include <time.h>

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpsort.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptree.h"
#include "kpstdio.h"
#include "kpwindow.h"
#include "kpcapp.h"
#include "kpsock.h"


// ---------------------
const uchar *KpSocket::ProtocolNames[NUM_OF_PROTS_1] =
{
    (const uchar *)"<undefined>",  //   NO_PROT

    (const uchar *)"HTTP",         //   HTTP_PROT,
    (const uchar *)"FTP",          //   FTP_PROT,
};


const uchar *KpSocket::TransferModeNames[NUM_OF_HTTP_TR_MODES_1] =
{
   (const uchar *)"<undefined>",  //   NO_MODE

   (const uchar *)"chunked",      //   HTTP_TR_CHUNK_MODE,
};


const uchar *KpSocket::KpsockMsgTypes[NUM_OF_HTTP_MSG_TYPES_1] =
{
    (const uchar *)"UNKNOWN",
    (const uchar *)"REQUEST",
    (const uchar *)"GET",
    (const uchar *)"POST",
    (const uchar *)"POST_DATA",
    (const uchar *)"POST_SUBDATA",
    (const uchar *)"REPLY",
};


const uchar *KpSocket::KpsockTagNames[KPSOCK_NUM_OF_HDTAGS_1 + 1] =
{
    (const uchar *)"Date:",                       // KPSOCK_HDTAG_Date
    (const uchar *)"Server:",                     // KPSOCK_HDTAG_Server
    (const uchar *)"Set-Cookie:",                 // KPSOCK_HDTAG_SetCookie
    (const uchar *)"Last-Modified:",              // KPSOCK_HDTAG_LastModified
    (const uchar *)"X-Powered-By:",               // KPSOCK_HDTAG_XPoweredBy
    (const uchar *)"ETag:",                       // KPSOCK_HDTAG_ETag
    (const uchar *)"Accept-Ranges:",              // KPSOCK_HDTAG_AcceptRanges
    (const uchar *)"Content-Length:",             // KPSOCK_HDTAG_ContentLength
    (const uchar *)"Transfer-Encoding:",          // KPSOCK_HDTAG_TransferEncoding
    (const uchar *)"Connection:",                 // KPSOCK_HDTAG_Connection
    (const uchar *)"Keep-Alive:",                 // KPSOCK_HDTAG_KeepAlive
    (const uchar *)"Content-Type:",               // KPSOCK_HDTAG_ContentType
    (const uchar *)"Content-Encoding:",           // KPSOCK_HDTAG_ContentEncoding
    (const uchar *)"Host:",                       // KPSOCK_HDTAG_Host
    (const uchar *)"User-Agent:",                 // KPSOCK_HDTAG_UserAgent
    (const uchar *)"Accept:",                     // KPSOCK_HDTAG_Accept
    (const uchar *)"Accept-Language:",            // KPSOCK_HDTAG_AcceptLanguage
    (const uchar *)"Accept-Encoding:",            // KPSOCK_HDTAG_AcceptEncoding
    (const uchar *)"Accept-Charset:",             // KPSOCK_HDTAG_AcceptCharset
    (const uchar *)"Pragma:",                     // KPSOCK_HDTAG_Pragma
    (const uchar *)"Cache-Control:",              // KPSOCK_HDTAG_CacheControl
    (const uchar *)"Referer:",                    // KPSOCK_HDTAG_Referer
    (const uchar *)"If-Modified-Since:",          // KPSOCK_HDTAG_IfModifiedSince
    (const uchar *)"If-None-Match:",              // KPSOCK_HDTAG_IfNoneMatch
    (const uchar *)"Content-Disposition:",        // KPSOCK_HDTAG_ContentDisposition
    (const uchar *)"Content-Transfer-Encoding:",  // KPSOCK_HDTAG_ContentTransferEncoding
    (const uchar *)"TE:",                         // KPSOCK_HDTAG_TE
    (const uchar *)"UA-CPU:",                     // KPSOCK_HDTAG_UA_CPU
    (const uchar *)"Location:",                   // KPSOCK_HDTAG_Location
    (const uchar *)"Acrobat-Version:",            // KPSOCK_HDTAG_AcrobatVersion
    (const uchar *)"Expires:",                    // KPSOCK_HDTAG_Expires
    (const uchar *)"Content-Description:",        // KPSOCK_HDTAG_ContentDescription
    NULL
};

const bool KpSocket::KpsockTagOccurences[KPSOCK_NUM_OF_HDTAGS_1]
    [NUM_OF_HTTP_MSG_TYPES_1] =
{
//  HTTP_MSG_TYPE_UNKNOWN
//        HTTP_REQUEST_UNKNOWN
//              HTTP_GET_REQUEST
//                    HTTP_POST_REQUEST
//                          HTTP_POST_DATA_SEGM
//                                HTTP_POST_SUBDATA_SEGM
//                                      HTTP_REPLY

    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_Date
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_Server
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_SetCookie
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_LastModified
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_XPoweredBy
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_ETag
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_AcceptRanges
    False,False,False,True, False,False,True,  // KPSOCK_HDTAG_ContentLength
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_TransferEncoding
    False,False,True, True, False,False,True,  // KPSOCK_HDTAG_Connection
    False,False,True, True, False,False,True,  // KPSOCK_HDTAG_KeepAlive
    False,False,False,True, True, False,True,  // KPSOCK_HDTAG_ContentType
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_ContentEncoding
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_Host
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_UserAgent
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_Accept
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_AcceptLanguage
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_AcceptEncoding
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_AcceptCharset
    False,False,True, False,False,False,True,  // KPSOCK_HDTAG_Pragma
    False,False,True, True, False,False,True,  // KPSOCK_HDTAG_CacheControl
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_Referer
    False,False,True, False,False,False,False, // KPSOCK_HDTAG_IfModifiedSince
    False,False,True, False,False,False,False, // KPSOCK_HDTAG_IfNoneMatch
    False,False,False,False,True, False,True,  // KPSOCK_HDTAG_ContentDisposition
    False,False,False,False,True, False,True,  // KPSOCK_HDTAG_ContentTransferEncoding
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_TE
    False,False,True, True, False,False,False, // KPSOCK_HDTAG_UA_CPU
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_Location
    False,False,False,True, False,False,True,  // KPSOCK_HDTAG_AcrobatVersion
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_Expires
    False,False,False,False,False,False,True,  // KPSOCK_HDTAG_ContentDescription
};


// ---------------------
KpSocket::KpSocket(int p_iSockType)
{
WSADATA wsa_data;
WORD ver_requested = 0x0101; // ver 1.1

    m_hSocket = INVALID_SOCKET;
    m_hAccSock = INVALID_SOCKET;

    m_iMsgType = HTTP_MSG_TYPE_UNKNOWN;
    m_iRetCode = 0;
    m_lpszRetMsg[0] = Nul;
    m_lpszLocation[0] = Nul;
    m_lContLen = MAXLONG;
    m_iTrMode = NORMAL_HTTP_TR_MODE;
    m_lpszBoundary[0] = Nul;
    m_lpszEndBoundary[0] = Nul;
    m_lpszCtrlName[0] = Nul;

    m_PackedUrl.m_lpszServerName[0] = Nul;
    m_PackedUrl.m_lpszServerNameUnres[0] = Nul;
    m_PackedUrl.m_Addr.S_un.S_addr = INADDR_NONE;
    m_PackedUrl.m_iProtocol = NO_PROT;
    m_PackedUrl.m_iPort = 0;
    m_PackedUrl.m_lpszFileName[0] = Nul;

    m_lpszHdrBuf = null;
    KP_NEWA(m_lpszHdrBuf, uchar, MAX_HTTP_HDR_LEN + 1);

    m_lRestChunkLength = 0L;
//  m_lNextChunkLength = 0L;

    m_lpszChunkPos = m_lpszHdrBuf;
    m_lChunkRest = 0L;

// Init the sockets interface
    KP_ASSERT(WSAStartup(ver_requested, &wsa_data) == 0, KP_E_SYSTEM_ERROR,
                                                            WSAGetLastError());
// create the socket
    m_hSocket = socket(PF_INET, p_iSockType /* SOCK_STREAM */,
                            (p_iSockType == SOCK_DGRAM)?IPPROTO_UDP:0);
//  m_hSocket = socket(PF_INET, SOCK_RAW, 0);
    KP_ASSERT(m_hSocket != INVALID_SOCKET, KP_E_SYSTEM_ERROR,
                                                    WSAGetLastError());
}


// ---------------------
KpSocket::~KpSocket(void)
{
    if (m_hAccSock != INVALID_SOCKET)
        KP_ASSERT(closesocket(m_hAccSock) == 0, KP_E_SYSTEM_ERROR,
                                                        WSAGetLastError());
    m_hAccSock = INVALID_SOCKET;

    if (m_hSocket != INVALID_SOCKET)
        KP_ASSERTW0(closesocket(m_hSocket) == 0, KP_E_SYSTEM_ERROR,
            WSAGetLastError());     // gali duoti klaidą, kai uždarinėjam
                                    //      neacceptintą socketą
    m_hSocket = INVALID_SOCKET;

//  KP_ASSERT(WSACleanup() == 0 /* != SOCKET_ERROR */, KP_E_SYSTEM_ERROR,
//      WSAGetLastError()); // šitą kelt į programos pabaigą, kai visi
                            //      socketai jau uždaryti

    KP_DELETEA(m_lpszHdrBuf);
}


// ---------------------
HRESULT KpSocket::TestIP(const uchar *p_lpszIpAddr)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_lpszIpAddr, E_INVALIDARG, null);
    KP_ASSERT(strlen(p_lpszIpAddr) <= KP_MAX_FNAME_LEN, E_INVALIDARG, null);

uchar adr_buf[KP_MAX_FNAME_LEN + 1];
    strcpy(adr_buf, p_lpszIpAddr);
    KpStripAll(adr_buf);

int dot_count = 0;
/* const */ uchar *pnts = null;
uchar *pntd = null;
    pnts = pntd = adr_buf;

    while (pntd && SUCCEEDED(retc))
    {
        pntd = strchr(pnts, '.');
        if (pntd)
        {
            *pntd++ = Nul;
            dot_count++;
        }

    int ii = strlen(pnts);
        if ((ii > 3) || (ii < 1)){ retc = E_INVALIDARG; break; }
        if (!KpIsNumber(pnts)){ retc = E_INVALIDARG; break; }
        if (strchr(pnts, '-')){ retc = E_INVALIDARG; break; }
        if (sscanf((const char *)pnts, "%d", &ii) < 1)
        {
            retc = E_INVALIDARG;
            break;
        }
        if (ii > 255){ retc = E_INVALIDARG; break; }

        pnts = pntd;
    }

    if ((dot_count != 3) && SUCCEEDED(retc)) retc = E_INVALIDARG;

return (retc);
}


// ---------------------
HRESULT KpSocket::Resolve(const uchar *p_lpszUrl, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_lpszUrl, E_INVALIDARG, null);
    KP_ASSERTQ(strlen(p_lpszUrl) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW,
                                                p_lpszUrl, p_bThrowError);
uchar url_buf[KP_MAX_FNAME_LEN + 1];
uchar *pnts = null;
uchar *pntd = null;
uchar *pntdd = null;

    if (SUCCEEDED(retc))
    {
        strcpy(url_buf, p_lpszUrl);
        pnts = url_buf;
    }

// protocol
    m_PackedUrl.m_iProtocol = HTTP_PROT;
    if (SUCCEEDED(retc))
    {
        pntd = strstr(pnts, "//");
        if (pntd)
        {
            *pntd = Nul;
            if (strlen(pnts))
            {
                pntdd = strchr(pnts, ':');
                KP_ASSERTQ(pntdd, E_INVALIDARG, pnts, p_bThrowError);
                KP_ASSERTQ(strlen(pntdd) == 1, E_INVALIDARG, pnts,
                                                            p_bThrowError);
                if (SUCCEEDED(retc))
                {
                    *pntdd = Nul;
                int ix = GetKwrdIndex(pnts, ProtocolNames, NUM_OF_PROTS,
                                                                False, True);
                    KP_ASSERTQ(ix >= 0 /* != TV_TG_NoKey */,
                                KP_E_KWD_NOT_FOUND, pnts, p_bThrowError);
                    KP_ASSERTQ(ix < NUM_OF_PROTS,
                                KP_E_SYSTEM_ERROR, pnts, p_bThrowError);
                    if (SUCCEEDED(retc)) m_PackedUrl.m_iProtocol = (Protocols)ix;
                }
            }

            pnts = pntd + 2;
        }
    }

// server name & port
    if (SUCCEEDED(retc))
    {
        pntd = strchr(pnts, '/');
        if (pntd) *pntd = Nul;
    }

// port
    m_PackedUrl.m_iPort = HTTP_PORT;
    if (SUCCEEDED(retc))
    {
        pntdd = strchr(pnts, ':');
        if (pntdd)
        {
            *(pntdd++) = Nul;
            sscanf((const char *)pntdd, "%d", &m_PackedUrl.m_iPort);
        }
    }

// server name
    m_PackedUrl.m_lpszServerName[0] = Nul;
    m_PackedUrl.m_lpszServerNameUnres[0] = Nul;
    KP_ASSERTQ(strlen(pnts) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, pnts,
                                                            p_bThrowError);
    if (SUCCEEDED(retc))
    {
        strncpy(m_PackedUrl.m_lpszServerName, pnts, KP_MAX_FNAME_LEN);
        m_PackedUrl.m_lpszServerName[KP_MAX_FNAME_LEN] = Nul;
        strcpy(m_PackedUrl.m_lpszServerNameUnres,
                                m_PackedUrl.m_lpszServerName);
    }

// file name & query
    strcpy(m_PackedUrl.m_lpszFileName, "/");
    if (pntd)
    {
        *pntd = '/';
        KP_ASSERTQ(strlen(pntd) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW,
            pntd, p_bThrowError);

        if (SUCCEEDED(retc)) strcpy(m_PackedUrl.m_lpszFileName, pntd);
    }

// ------------------------------
struct hostent *p_host = NULL;

    if (SUCCEEDED(retc))
    {
        if (strcmp(m_PackedUrl.m_lpszServerName, KP_IPADDR_BROADCAST) == 0)
        {
        // ------------------------------
        // broadcast
            m_PackedUrl.m_Addr.S_un.S_addr = INADDR_BROADCAST; // INADDR_ANY;
int on = 1;
            KP_ASSERTQ(setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST,
                (const char *)&on, sizeof(on)) != SOCKET_ERROR,
                KP_E_SYSTEM_ERROR, WSAGetLastError(), p_bThrowError);

            KP_ASSERTQ(setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR,
                (const char *)&on, sizeof(on)) != SOCKET_ERROR,
                KP_E_SYSTEM_ERROR, WSAGetLastError(), p_bThrowError);
        }
        else // if (strcmp(m_PackedUrl.m_lpszServerName, KP_IPADDR_BROADCAST)...
        {
        // ------------------------------
        // lookup the address for the server name
            m_PackedUrl.m_Addr.S_un.S_addr =
                inet_addr((const char *)m_PackedUrl.m_lpszServerName);
            if (m_PackedUrl.m_Addr.S_un.S_addr == INADDR_NONE)
            {

            // ------------------
                p_host =
                    gethostbyname((const char *)m_PackedUrl.m_lpszServerName);
                if (p_host == NULL)
                {
                uchar *msg_buf = null;
                    KP_NEWA(msg_buf, uchar,
                        KP_MAX_FNAME_LEN + KP_MAX_FILE_LIN_LEN + 100);

                    strcpy(msg_buf, m_PackedUrl.m_lpszServerName);
                    strcat(msg_buf, ": ");

                long retw = WSAGetLastError();
                    KpErrorClass::FormatSystemErrorMessage(retw,
                                            msg_buf + strlen(msg_buf), True);
                    retc = KP_E_NO_CONN;
                    if (p_bThrowError && (retw == WSANO_DATA /* WSAEACCES */))
                        PutMsgFirewall(KP_MSG_FIREWALL);
                    else KP_ASSERTQ(False, retc, msg_buf, p_bThrowError);

                    KP_DELETEA(msg_buf);

                } // if (p_host == NULL)

            } // if (m_PackedUrl.m_Addr.S_un.S_addr == INADDR_NONE)

            if (SUCCEEDED(retc))
            {
                memcpy((char *)&(m_PackedUrl.m_Addr.S_un.S_addr),
                    p_host->h_addr,
                    sizeof(unsigned long) /* p_host->h_length */);
//              m_PackedUrl.m_Addr.S_un.S_addr = (*p_host->h_addr);
            }

        } // else if (strcmp(m_PackedUrl.m_lpszServerName, KP_IPADDR_BROADCAST)

    } // if (SUCCEEDED(retc))

return (retc);
}


// ---------------------
HRESULT KpSocket::Connect(bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED, KP_MSG_NO_SOCKET,
                                                                p_bThrowError);
    KP_ASSERTQ(m_PackedUrl.m_Addr.S_un.S_addr != INADDR_NONE,
                        E_UNEXPECTED, KP_MSG_SOCK_UNRESOLVED, p_bThrowError);

// connect to the remote endpoint
SOCKADDR_IN sin;
    if (SUCCEEDED(retc))
    {
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = m_PackedUrl.m_Addr.S_un.S_addr;
        sin.sin_port = htons(m_PackedUrl.m_iPort /* HTTP_PORT */);

        if (connect(m_hSocket, (LPSOCKADDR)&sin, sizeof (sin)))
        {
            retc = KP_E_NO_CONN;
        long retw = WSAGetLastError();

            if (p_bThrowError && (retw == WSAEACCES))
                PutMsgFirewall(KP_MSG_FIREWALL);
            else KP_ASSERTQ(False, retc, retw, p_bThrowError);
        }
    }

return (retc);
}


// ---------------------
void KpSocket::PutMsgFirewall(const uchar *p_lpszMsgFmt)
{
uchar ap_name[2 * KP_MAX_FNAME_LEN + 100];
uchar disk[KP_MAX_FNAME_LEN + 1];
uchar path[KP_MAX_FNAME_LEN + 1];
uchar name[KP_MAX_FNAME_LEN + 1];
uchar type[KP_MAX_FNAME_LEN + 1];

    KP_ASSERT(p_lpszMsgFmt, E_INVALIDARG, null);
    KP_ASSERT(KpApp, E_POINTER, null);

uchar *str_buf = null;
    KP_NEWA(str_buf, uchar, KP_MAX_FNAME_LEN + strlen(p_lpszMsgFmt) + 100);

    KpApp->GetAppName(ap_name);
    KpStdIo::TvFnameSplit(disk, path, name, type, ap_name);
    strcpy(ap_name, name);
    strcat(ap_name, ".");
    strcat(ap_name, type);

    sprintf((char *)str_buf, (const char *)p_lpszMsgFmt, ap_name);
    KpMsgOut(str_buf, IDI_WARNING /* IDI_ERROR */, KP_MB_TESTI); // KP_MB_BAIGTI);

    KP_DELETEA(str_buf);
}


// ---------------------
HRESULT KpSocket::Bind(int p_iPort, unsigned long p_lAddr, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED, KP_MSG_NO_SOCKET,
                                                            p_bThrowError);
SOCKADDR_IN sin;
const uchar *ip_addr = null;
    if (SUCCEEDED(retc))
    {
        memset(&sin, 0, sizeof(sin));
        ((SOCKADDR_IN *)&sin)->sin_family = AF_INET;
        ((SOCKADDR_IN *)&sin)->sin_addr.s_addr = p_lAddr; // ADDR_ANY;
        ((SOCKADDR_IN *)&sin)->sin_port = htons(p_iPort);

        m_PackedUrl.m_Addr.S_un.S_addr = p_lAddr;

        ip_addr = (const uchar *)inet_ntoa(sin.sin_addr);
        if (ip_addr == null)
        {
            KP_WARNING(KP_E_NO_CONN, null);
            ip_addr = KP_IPADDR_LOCAL_HOST;
        }
        strncpy(m_PackedUrl.m_lpszServerName, ip_addr, KP_MAX_FNAME_LEN);
        m_PackedUrl.m_lpszServerName[KP_MAX_FNAME_LEN] = Nul;
        strcpy(m_PackedUrl.m_lpszServerNameUnres, m_PackedUrl.m_lpszServerName);

        m_PackedUrl.m_iPort = p_iPort;
    }

    // connect to local listenning port
    KP_ASSERTQ(bind(m_hSocket, (LPSOCKADDR)&sin, sizeof (sin)) == 0,
        KP_E_NO_CONN, WSAGetLastError(), p_bThrowError);

return (retc);
}


// ---------------------
HRESULT KpSocket::Listen(bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED,
                                        KP_MSG_NO_SOCKET, p_bThrowError);
    if (SUCCEEDED(retc))
    {
        if (m_hAccSock != INVALID_SOCKET)
            KP_ASSERTQ(closesocket(m_hAccSock) == 0,
                KP_E_SYSTEM_ERROR, WSAGetLastError(), p_bThrowError);
        m_hAccSock = INVALID_SOCKET;
    }

    KP_ASSERTQ(listen(m_hSocket, 1 /* SOMAXCONN */) == 0,
                    KP_E_NO_CONN, WSAGetLastError(), p_bThrowError);

return (retc);
}


// ---------------------
HRESULT KpSocket::Accept(bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED,
                                        KP_MSG_NO_SOCKET, p_bThrowError);
    if (SUCCEEDED(retc))
    {
        if (m_hAccSock != INVALID_SOCKET)
            KP_ASSERTQ(closesocket(m_hAccSock) == 0,
                KP_E_SYSTEM_ERROR, WSAGetLastError(), p_bThrowError);
        m_hAccSock = INVALID_SOCKET;
    }

SOCKADDR_IN sin;
int addrlen;
    if (SUCCEEDED(retc))
    {
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = 0;
        sin.sin_port=htons(m_PackedUrl.m_iPort /* HTTP_PORT */);

        addrlen = sizeof(sin);

        m_hAccSock = accept(m_hSocket, (LPSOCKADDR)&sin, &addrlen);
        if (m_hAccSock == INVALID_SOCKET)
        {
        // pranešimo nereikia, kai klaida atsiranda programos pabaigoje stabdant threadą
        long retw = WSAGetLastError();
            if (retw != WSAEINTR) // 10004) // A blocking operation was
                // interrupted by a call to WSACancelBlockingCall
                    KP_ASSERTQ(False, KP_E_NO_CONN, retw, p_bThrowError);
        }
    }

const uchar *ip_addr = null;
    if (SUCCEEDED(retc))
    {
        ip_addr = (const uchar *)inet_ntoa(sin.sin_addr);
        if (ip_addr == null)
        {
            KP_WARNING(KP_E_NO_CONN, null);
            ip_addr = KP_IPADDR_LOCAL_HOST;
        }

        strncpy(m_PackedUrl.m_lpszServerName, ip_addr, KP_MAX_FNAME_LEN);
        m_PackedUrl.m_lpszServerName[KP_MAX_FNAME_LEN] = Nul;
        strcpy(m_PackedUrl.m_lpszServerNameUnres, m_PackedUrl.m_lpszServerName);
        m_PackedUrl.m_Addr.S_un.S_addr = sin.sin_addr.S_un.S_addr;
        m_PackedUrl.m_iProtocol = HTTP_PROT;
        m_PackedUrl.m_iPort = sin.sin_port;
        m_PackedUrl.m_lpszFileName[0] = Nul;
    }

return (retc);
}


// ---------------------
HRESULT KpSocket::SendTo(const uchar *p_pBuf, long p_lBufLen,
                                                bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED,
                                        KP_MSG_NO_SOCKET, p_bThrowError);
SOCKADDR_IN sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = m_PackedUrl.m_Addr.S_un.S_addr;
    sin.sin_port = htons(m_PackedUrl.m_iPort);

int retv = 0;
    retv = sendto(m_hSocket, (const char *)p_pBuf, p_lBufLen, 0,
                                        (SOCKADDR *)&sin, sizeof(sin));
    KP_ASSERTQ(retv != SOCKET_ERROR, KP_E_TRANS_ERR, WSAGetLastError(),
                                                            p_bThrowError);
return (retc);
}


// -------------------------------------
HRESULT KpSocket::RecvFrom(uchar *p_pBuf, long *p_plBufLen, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_plBufLen, E_INVALIDARG, null);

    KP_ASSERTQ(m_hSocket != INVALID_SOCKET, E_UNEXPECTED,
                                        KP_MSG_NO_SOCKET, p_bThrowError);
long ll;
    ll = *p_plBufLen;

SOCKADDR_IN sin;
int sin_len = sizeof(SOCKADDR_IN);
    ll = recvfrom(m_hSocket, (char *)p_pBuf, ll, 0 /* MSG_PEEK */,
                                            (PSOCKADDR)&sin, &sin_len);
    KP_ASSERTQ(ll != SOCKET_ERROR, KP_E_TRANS_ERR, WSAGetLastError(),
                                                        p_bThrowError);
    if (SUCCEEDED(retc))
    {
        *p_plBufLen = ll;

        m_PackedUrl.m_Addr.S_un.S_addr = sin.sin_addr.s_addr;

    const uchar *ip_addr;
        ip_addr = (const uchar *)inet_ntoa(sin.sin_addr);
        if (ip_addr == NULL)
        {
            KP_WARNING(KP_E_NO_CONN, null);
            ip_addr = KP_IPADDR_LOCAL_HOST;
        }
        strncpy(m_PackedUrl.m_lpszServerName, ip_addr, KP_MAX_FNAME_LEN);
        m_PackedUrl.m_lpszServerName[KP_MAX_FNAME_LEN] = Nul;
        strcpy(m_PackedUrl.m_lpszServerNameUnres, m_PackedUrl.m_lpszServerName);
    }

return (retc);
}


DWORD WINAPI RecvFromProc(LPVOID lpParameter)
{
HRESULT retc = S_OK;
RecvFromProcPars *pars_ptr = (RecvFromProcPars *)lpParameter;

    KP_ASSERT(pars_ptr, E_INVALIDARG, null);
    KP_ASSERT(pars_ptr->m_This, E_INVALIDARG, null);
    KP_ASSERT(pars_ptr->m_pBuf, E_INVALIDARG, null);
    KP_ASSERT(pars_ptr->m_plBufLen, E_INVALIDARG, null);

    if (SUCCEEDED(retc))
        retc = pars_ptr->m_This->RecvFrom(pars_ptr->m_pBuf,
                            pars_ptr->m_plBufLen, pars_ptr->m_bThrowError);
// send notification
    if (SUCCEEDED(retc))
        PostThreadMessage(pars_ptr->m_iCallersThreadId,
                                KP_BLOCKED_SOCK_RELEASED, 0, 0L);
return (retc);
}


HRESULT KpSocket::RecvFromAsynch(uchar *p_pBuf, long *p_plBufLen,
                                                            bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_plBufLen, E_INVALIDARG, null);

RecvFromProcPars pars;
    pars.m_This = this;
    pars.m_pBuf = p_pBuf;
    pars.m_plBufLen = p_plBufLen;
    pars.m_bThrowError = p_bThrowError;
    pars.m_iCallersThreadId = GetCurrentThreadId();

HANDLE rcv_thread = NULL;
    rcv_thread = CreateThread
    (
        NULL,           // LPSECURITY_ATTRIBUTES lpThreadAttributes,
            // pointer to security attributes
        0L,             // DWORD dwStackSize,
            // initial thread stack size
        RecvFromProc,   // LPTHREAD_START_ROUTINE lpStartAddress,
            // pointer to thread function
        (LPVOID)&pars,  // LPVOID lpParameter,
            // argument for new thread
        0L,             // DWORD dwCreationFlags,
            // creation flags
        NULL            // LPDWORD lpThreadId
            // pointer to receive thread ID
    );
    KP_ASSERTQ(rcv_thread, KP_E_SYSTEM_ERROR, GetLastError(), p_bThrowError);

UINT rcv_timer = 0;
    if (SUCCEEDED(retc))
        rcv_timer = SetTimer(HWND_DESKTOP, KP_TIMEOUT_TIMER,
                                    KPSOCK_BLOCK_TIMEOUT * 1000, NULL);
    KP_ASSERTQ(rcv_timer, KP_E_SYSTEM_ERROR, GetLastError(), p_bThrowError);

MSG msg;
int retp;
bool endfl = False;

    if (SUCCEEDED(retc)) do
    {
        KP_ASSERTQ(GetMessage(&msg, NULL, 0, 0) >= 0, KP_E_SYSTEM_ERROR,
                                            GetLastError(), p_bThrowError);
        if (SUCCEEDED(retc))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            retp = LOWORD(msg.wParam);

            switch(msg.message)
            {
            case KP_BLOCKED_SOCK_RELEASED:
                endfl = True;
                break;

            case WM_TIMER:
                if (retp == rcv_timer)
                {
                    KP_ASSERTW0(TerminateThread(rcv_thread, KP_E_TIMEOUT),
                        KP_E_SYSTEM_ERROR, GetLastError());
                    rcv_thread = NULL;
                    retc = KP_E_NO_CONN; // KP_E_TIMEOUT;
                }
                break;

            case WM_COMMAND:
                switch(retp)
                {
                case IDCANCEL: retc = KP_E_CANCEL; break;
                }
                break;

            case WM_QUIT:
                switch(retp)
                {
                case IDCANCEL: retc = KP_E_CANCEL; break;
                case IDABORT: retc = KP_E_SYSTEM_ERROR; break;
                }
                endfl = True;
                break;

            } // switch(msg.message)

        } // if (SUCCEEDED(retc))

    } while ((!endfl) && SUCCEEDED(retc));

    if (FAILED(retc)){ KP_ASSERTQ(False, retc, null, p_bThrowError); }

    if (rcv_timer) KillTimer(HWND_DESKTOP, rcv_timer);
    rcv_timer = 0;

return (retc);
}


// ---------------------
HRESULT KpSocket::SendMsg(const uchar *p_pBuf, long p_lBufLen,
                                                    bool p_bThrowError)
{
HRESULT retc = S_OK;
const uchar *p_temp = p_pBuf;
int cb_sent;
int cb_remaining = p_lBufLen;
SOCKET socket = INVALID_SOCKET;

    if (p_lBufLen != 0)
    {
        KP_ASSERT(p_pBuf, E_INVALIDARG, null);

        socket = m_hSocket;
        if (m_hAccSock != INVALID_SOCKET) socket = m_hAccSock;

        KP_ASSERTQ(socket != INVALID_SOCKET, E_UNEXPECTED,
                                        KP_MSG_NO_SOCKET, p_bThrowError);

        while ((cb_remaining > 0) && SUCCEEDED(retc))
        {
            cb_sent = send(socket, (const char *)p_temp, cb_remaining, 0);
            if (cb_sent == SOCKET_ERROR)
            {
            uchar *msg_buf = null;
                KP_NEWA(msg_buf, uchar,
                        KP_MAX_FNAME_LEN + KP_MAX_FILE_LIN_LEN + 100);

                strcpy(msg_buf, m_PackedUrl.m_lpszServerName);
                strcat(msg_buf, ": ");

            long retw = WSAGetLastError();
                KpErrorClass::FormatSystemErrorMessage(retw,
                                        msg_buf + strlen(msg_buf), True);
                KP_ASSERTQ(False, KP_E_TRANS_ERR, msg_buf, p_bThrowError);

                KP_DELETEA(msg_buf);
            }

            if (SUCCEEDED(retc))
            {
                p_temp += cb_sent;
                cb_remaining -= cb_sent;
            }

        } // while ((cb_remaining > 0) && SUCCEEDED(retc))

    } // if (p_lBufLen != 0)

return (retc);
}


// ---------------------
HRESULT KpSocket::SendStr(const uchar *p_lpszBuf, bool p_bThrowError)
{
    KP_ASSERT(p_lpszBuf, E_INVALIDARG, null);

return (SendMsg(p_lpszBuf, strlen(p_lpszBuf), p_bThrowError));
}


// ---------------------
HRESULT KpSocket::SendStr(const char *p_lpszBuf, bool p_bThrowError)
{
    KP_ASSERT(p_lpszBuf, E_INVALIDARG, null);

return (SendMsg((const uchar *)p_lpszBuf, strlen(p_lpszBuf), p_bThrowError));
}


// ---------------------
HRESULT KpSocket::ReceiveMsg(uchar *p_pBuf, long *p_plRead, bool p_bSingleMsg,
                                                            bool p_bThrowError)
{
HRESULT retc = S_OK;
uchar *p_temp = p_pBuf;
long cb_read;
long cb_remaining;
long buf_len;
SOCKET socket = INVALID_SOCKET;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_plRead, E_INVALIDARG, null);

    buf_len = cb_remaining = *p_plRead;

    socket = m_hSocket;
    if (m_hAccSock != INVALID_SOCKET) socket = m_hAccSock;

    KP_ASSERTQ(socket != INVALID_SOCKET, E_UNEXPECTED, KP_MSG_NO_SOCKET,
                                                            p_bThrowError);
    while ((cb_remaining > 0) && SUCCEEDED(retc))
    {
        cb_read = recv(socket, (char *)p_temp, cb_remaining, 0);

        if (cb_read == SOCKET_ERROR)
        {
            uchar *msg_buf = null;
                KP_NEWA(msg_buf, uchar,
                        KP_MAX_FNAME_LEN + KP_MAX_FILE_LIN_LEN + 100);

                strcpy(msg_buf, m_PackedUrl.m_lpszServerName);
                strcat(msg_buf, ": ");

            long retw = WSAGetLastError();
                KpErrorClass::FormatSystemErrorMessage(retw,
                                        msg_buf + strlen(msg_buf), True);
                KP_ASSERTQ(False, KP_E_TRANS_ERR, msg_buf, p_bThrowError);

                KP_DELETEA(msg_buf);
        }

        if (SUCCEEDED(retc))
        {
            cb_remaining -= cb_read;
            p_temp += cb_read;
        }

        if (cb_read == 0) break;

        if (p_bSingleMsg) break;

    } // while ((cb_remaining > 0) && SUCCEEDED(retc))

    if (SUCCEEDED(retc)) *p_plRead = buf_len - cb_remaining;

return (retc);
}


// ---------------------
HRESULT KpSocket::GetChar(uchar *p_pcInChar, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pcInChar, E_INVALIDARG, null);

long read = 1L;
    retc = ReceiveMsg(p_pcInChar, &read, True, p_bThrowError);

    KP_ASSERTW0(read >= 1L, KP_E_EOF, null);

return (retc);
}


// ---------------------
HRESULT KpSocket::GetCharD(uchar *p_pcInChar, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pcInChar, E_INVALIDARG, null);

    m_lContLen--;
    if (m_lContLen < 0L)
    {
        m_lContLen = 0L;
        KP_ASSERTW(False, KP_E_EOF, null);
    }

    if (SUCCEEDED(retc)) retc = GetChar(p_pcInChar, p_bThrowError);

return (retc);
}


// ---------------------
HRESULT KpSocket::GetLine(uchar *p_lpszStrBuf, int p_iBufLen,
                                                        bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_lpszStrBuf, E_INVALIDARG, null);
    KP_ASSERT(p_iBufLen >= 1, E_INVALIDARG, null);

uchar *pntd = p_lpszStrBuf;
uchar in_ch;

    do
    {
        retc = GetCharD(&in_ch, p_bThrowError);

        if (retc == KP_E_EOF)
        {
            if (pntd > p_lpszStrBuf) // paskutinė eilutė be Lf
            {
                retc = S_OK;
                in_ch = Lf;
                *pntd = Nul;
            }
        }
        else if ((in_ch != Cr) && SUCCEEDED(retc))
        {
            if (in_ch == Lf) *pntd = Nul;
            else
            {
                if (pntd - p_lpszStrBuf >= p_iBufLen - 1)
                {
                    *pntd = Nul;
                    KP_ASSERTQ(False, KP_E_BUFFER_OVERFLOW, null, p_bThrowError);
                }
                else (*pntd++) = in_ch;
            }
        }

    } while ((in_ch != Lf) && SUCCEEDED(retc));

return (retc);
}


// ---------------------
HRESULT KpSocket::GetByte(uchar *p_pcInCh, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pcInCh, E_INVALIDARG, null);

    if (m_lChunkRest == 0L)
    {
        m_lpszChunkPos = m_lpszHdrBuf;
        m_lChunkRest = MAX_HTTP_HDR_LEN;

        retc = ReceiveMsg(m_lpszHdrBuf, &m_lChunkRest, True, p_bThrowError);

        KP_ASSERTQ((m_lChunkRest >= 0L) && (m_lChunkRest <= MAX_HTTP_HDR_LEN),
                KP_E_TRANS_ERR, null, p_bThrowError);
    }

    if (SUCCEEDED(retc))
    {
        if (m_lChunkRest > 0L)
        {
            *p_pcInCh = (*(m_lpszChunkPos++));
            m_lChunkRest--;
        }
        else
        {
            *p_pcInCh = Nul;
            retc = KP_E_EOF;
        }
    }

return (retc);
}


//---------------------
HRESULT KpSocket::UnGetByte(uchar p_cInCh, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERTQ(m_lpszChunkPos > m_lpszHdrBuf, KP_E_DOUBLE_UNGET, null,
                                                            p_bThrowError);
    if (SUCCEEDED(retc))
    {
        (*(--m_lpszChunkPos)) = p_cInCh;
        m_lChunkRest++;
    }

return (retc);
}


//---------------------
HRESULT KpSocket::GetChunk(long p_lChunkLength, uchar **p_ppOutBufPtr,
    uchar *p_pBuf, long p_lBufLen, bool p_bFullChunk, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_ppOutBufPtr, E_INVALIDARG, null);
    KP_ASSERT(*p_ppOutBufPtr, E_INVALIDARG, null);

    for (long ll = 0; (ll < p_lChunkLength) && SUCCEEDED(retc); ll++)
    {
        KP_ASSERTQ(*p_ppOutBufPtr - p_pBuf < p_lBufLen - 1,
                            KP_E_BUFFER_OVERFLOW, null, p_bThrowError);
        if (SUCCEEDED(retc)) retc = GetByte((*p_ppOutBufPtr)++, p_bThrowError);
    }

    if (SUCCEEDED(retc)) **p_ppOutBufPtr = Nul;

    // skip EOL
    if (p_bFullChunk && SUCCEEDED(retc))
    {
    uchar ch;

        if (SUCCEEDED(retc)) retc = GetByte(&ch, p_bThrowError);
        KP_ASSERTQ(strchr(lpszEols, ch), KP_E_FILE_FORMAT, null,
                                                        p_bThrowError);
        if ((ch == Cr) && SUCCEEDED(retc))
        {
            retc = GetByte(&ch, p_bThrowError);
            if ((ch != Lf) && SUCCEEDED(retc))
                retc = UnGetByte(ch, p_bThrowError);
        }
    }

return (retc);
}


//---------------------
HRESULT KpSocket::GetChunkLength(long *p_plChunkLength, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_plChunkLength, E_INVALIDARG, null);

uchar len_buf[MAX_LONG_DIGITS + 1];
uchar *pntd = len_buf;
uchar ch;
    do
    {
        retc = GetByte(&ch, p_bThrowError);
        if ((strchr(lpszEols, ch) == NULL) && SUCCEEDED(retc))
        {
            KP_ASSERTQ(pntd - len_buf <= MAX_LONG_DIGITS,
                            KP_E_BUFFER_OVERFLOW, null, p_bThrowError);

            if (SUCCEEDED(retc)) *(pntd++) = ch;
        }
        else break;

    } while (SUCCEEDED(retc));

    if ((ch == Cr) && SUCCEEDED(retc))
    {
        retc = GetByte(&ch, p_bThrowError);
        if ((ch != Lf) && SUCCEEDED(retc))
            retc = UnGetByte(ch, p_bThrowError);
    }

    *pntd = Nul;

    if (SUCCEEDED(retc))
    {
        KpStrip(len_buf);

        KP_ASSERTQ(KpIsHexNum(len_buf), KP_E_FILE_FORMAT, len_buf,
                                                            p_bThrowError);
    }

    if (SUCCEEDED(retc)) sscanf((const char *)len_buf, "%lx", p_plChunkLength);

return (retc);
}


// ---------------------
bool KpSocket::IsHTTPdataMsg(int p_iHTTP_RetCode)
{
return (p_iHTTP_RetCode / 100 == 2);
}

bool KpSocket::IsHTTPcontinueMsg(int p_iHTTP_RetCode)
{
return (p_iHTTP_RetCode / 100 == 1);
}

bool KpSocket::IsHTTPerrorMsg(int p_iHTTP_RetCode)
{
return (p_iHTTP_RetCode / 100 == 4);
}


//---------------------
HRESULT KpSocket::SendHttpRequest(const uchar *p_lpszRequest,
    const uchar *p_lpszArg, long p_lSimplyPostMsgLen, bool p_bAcroPostMsg,
    const uchar *p_lpszPostBoundary, const uchar *p_lpszHTTP_Template,
    bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_lpszRequest, E_INVALIDARG, null);
    KP_ASSERT(p_lpszHTTP_Template, E_INVALIDARG, null);
    KP_ASSERT(p_lSimplyPostMsgLen >= 0L, E_INVALIDARG, null);

    KP_ASSERTQ(m_PackedUrl.m_iProtocol == HTTP_PROT, KP_E_SYSTEM_ERROR,
                                                    null, p_bThrowError);

const uchar *http_fname = m_PackedUrl.m_lpszFileName;
    if (p_lpszArg) http_fname = p_lpszArg;

const uchar *http_tpl = (const uchar *)"";

    // --------- GET
    if (SUCCEEDED(retc)) if (strcmp(p_lpszRequest, HTTP_GET_REQUEST_CMD) == 0)
    {
        KP_ASSERTQ(p_lSimplyPostMsgLen == 0L, E_INVALIDARG,
                                                null, p_bThrowError);
        if (SUCCEEDED(retc)) http_tpl = p_lpszHTTP_Template;
    }

    // --------- POST
    if (SUCCEEDED(retc)) if (strcmp(p_lpszRequest, HTTP_POST_REQUEST_CMD) == 0)
    {
        KP_ASSERTQ(p_lSimplyPostMsgLen, E_NOTIMPL, null, p_bThrowError);

        if (SUCCEEDED(retc)) http_tpl =
            p_bAcroPostMsg?HTTP_POST_REQ_TPL_ACRO:HTTP_POST_REQ_TPL;
    }

    // -----------
uchar *buf_ptr = null;
    if (SUCCEEDED(retc))
    {
        KP_NEWA(buf_ptr, uchar, strlen(http_tpl) + strlen(p_lpszRequest) +
            strlen(http_fname) + strlen(m_PackedUrl.m_lpszServerName) + 1000);

        sprintf((char *)buf_ptr, (const char *)http_tpl, p_lpszRequest, http_fname,
            m_PackedUrl.m_lpszServerName, m_PackedUrl.m_iPort,
            KpError.m_lpszProdName, p_lSimplyPostMsgLen);

#ifdef TRACE_HTTP
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, buf_ptr, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::SendHttpRequest() post:\n%s\n", str_buf_1);
}
#endif

        retc = SendMsg(buf_ptr, strlen(buf_ptr), p_bThrowError);
    }

    if ((!p_bAcroPostMsg) && SUCCEEDED(retc))
        if (strcmp(p_lpszRequest, HTTP_POST_REQUEST_CMD) == 0)
        {
            sprintf((char *)buf_ptr, (const char *)HTTP_POST_REQ_TAIL_TPL,
                m_PackedUrl.m_lpszServerName, http_fname, p_lpszPostBoundary);

#ifdef TRACE_HTTP
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, buf_ptr, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::SendHttpRequest() tail:\n%s\n", str_buf_1);
}
#endif
            retc = SendMsg(buf_ptr, strlen(buf_ptr), p_bThrowError);
        }

    KP_DELETEA(buf_ptr);

return (retc);
}


//---------------------
HRESULT KpSocket::ReceiveHdr(HttpMsgTypes p_iMsgType, long *p_plRead,
                                                        bool p_bThrowError)
{
HRESULT retc = S_OK;
uchar *pntd = m_lpszHdrBuf;
bool endfl = False;

    while ((!endfl) && SUCCEEDED(retc))
    {
        KP_ASSERTQ(pntd - m_lpszHdrBuf <= MAX_HTTP_HDR_LEN - 1,
            KP_E_BUFFER_OVERFLOW, null, p_bThrowError);

        if (SUCCEEDED(retc))
        {
            if (p_iMsgType == HTTP_POST_DATA_SEGM)
                retc = GetCharD(pntd, p_bThrowError);
            else retc = GetChar(pntd, p_bThrowError);

            if (SUCCEEDED(retc)) pntd++;
            else if (retc == KP_E_EOF)
            {
                retc = S_OK;
                endfl = True;
            }
        }
        if (SUCCEEDED(retc)) *pntd = Nul;

        if (SUCCEEDED(retc)) if (pntd - m_lpszHdrBuf > 2)
            if (strcmp(pntd - 2, "\n\n") == 0) endfl = True;
        if (SUCCEEDED(retc)) if (pntd - m_lpszHdrBuf > 3)
            if (strcmp(pntd - 3, "\n\r\n") == 0) endfl = True;
    }

    if ((p_plRead) && SUCCEEDED(retc)) *p_plRead = pntd - m_lpszHdrBuf;

    KP_ASSERTW0(pntd - m_lpszHdrBuf, KP_E_TRANS_ERR, null);
    KP_ASSERTW0(pntd - m_lpszHdrBuf <= MAX_HTTP_HDR_LEN, KP_E_TRANS_ERR, null);
    KP_ASSERTW0((pntd - m_lpszHdrBuf >= MIN_HTTP_HDR_LEN) || \
                (p_iMsgType == HTTP_POST_DATA_SEGM), KP_E_TRANS_ERR, null);

return (retc);
}


// ======================================================
// HTTP_REPLY:

// HTTP/1.1 200 OK
// Date: Mon, 19 Jul 2004 06:43:58 GMT
// Server: Apache/1.3.26 (Unix) mod_gzip/1.3.19.1a mod_throttle/3.1.2
// Last-Modified: Thu, 15 Jul 2004 16:29:04 GMT
// ETag: "23-40f6b0d0"
// Accept-Ranges: bytes
// Content-Length: 35
// Connection: close
// Content-Type: text/plain
//
// KpReg-Error: Licenzija jau u_imta

// HTTP/1.1 200 OK
// Date: Mon, 28 Aug 2006 12:48:24 GMT
// Server: Apache
// Keep-Alive: timeout=1, max=100
// Connection: Keep-Alive
// Transfer-Encoding: chunked
// Content-Type: text/html
// Content-Encoding: gzip
//
// 31
// ŗ<<<
// <...>

// HTTP/1.1 200 OK
// Date: Mon, 28 Aug 2006 12:54:21 GMT
// Server: Apache
// Content-Encoding: none
// Keep-Alive: timeout=1, max=100
// Connection: Keep-Alive
// Transfer-Encoding: chunked
// Content-Type: text/html
//
// 1d
// KpReg-Ok: AA2L-3U81-21A7-GG4R
// 0
// <...> - dar pora baitu, atrodo



// atsakymas iš http://new.tev.lt/content.php

// HTTP/1.1 200 OK
// Date: Wed, 07 Sep 2011 15:29:11 GMT
// Server: Apache
// Set-Cookie: PHPSESSID=1e64d5b45db8cbb16a618dd6ec621c88; path=/
// Expires: Thu, 19 Nov 1981 08:52:00 GMT
// Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
// Pragma: no-cache
// Keep-Alive: timeout=1, max=100
// Connection: Keep-Alive
// Transfer-Encoding: chunked
// Content-Type: text/html
// Content-Encoding: gzip
//


// atsakymas iš http://mindep.puslapiai.lt/pr/MaTau-9v_diegimas.exe

// HTTP/1.1 404 Not Found
// Date: Wed, 07 Sep 2011 15:38:39 GMT
// Server: Apache
// Last-Modified: Sat, 13 Sep 2008 11:41:48 GMT
// ETag: "780890-69a-48cba6fc;4be2fc45"
// Accept-Ranges: bytes
// Content-Length: 1690
// Connection: close
// Content-Type: text/html
//


// atsakymas rezultatai.pdf failui i at'post'intus duomenis

// HTTP/1.1 200 OK
// Date: Mon, 19 Jul 2004 06:43:58 GMT             // ????
// Server: kpstlsvr
// Last-Modified: Thu, 15 Jul 2004 16:29:04 GMT    // ????
// ETag: "23-40f6b0d0"                             // ????
// Accept-Ranges: bytes                            // ????
// Content-Length: 35
// Connection: close
// Content-type: application/vnd.fdf
//
// <...> (xxx.fdf failas)


// --------------------------------------
// Gintaro atsakymas į Tado klausimą apie update

// kai POST /

// HTTP/1.1 302 Found
// Date: Wed, 27 Feb 2008 11:45:02 GMT
// Server: Apache
// Location: http://new.tev.lt/inc/rlink.php?sector=update&kalba=LT
// Transfer-Encoding: chunked
// Content-Type: text/html
//
// 0

// kai POST /versija.php

// HTTP/1.1 302 Found
// Date: Wed, 27 Feb 2008 13:35:53 GMT
// Server: Apache
// Location: http://new.tev.lt/
// Transfer-Encoding: chunked
// Content-Type: text/html
//
// 0

// kai Gintaras pataise, kad priimtu is User-Agent: lzdsh

// HTTP/1.1 200 OK
// Date: Wed, 27 Feb 2008 13:53:38 GMT
// Server: Apache
// Transfer-Encoding: chunked
// Content-Type: application/vnd.fdf

// ======================================================
// HTTP_REQUEST_UNKNOWN:

// ======================================================
// HTTP_GET_REQUEST:

// GET /favicon.ico HTTP/1.1
// Host: 127.0.0.1:49494
// User-Agent: Mozilla/5.0 (Windows; U; Win98; en-US; rv:1.4) Gecko/20030624 Netscape/7.1 (ax)
// Accept: video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive

// GET /abcd HTTP/1.1
// Host: 127.0.0.1:49494
// User-Agent: Mozilla/5.0 (Windows; U; Win98; en-US; rv:1.4) Gecko/20030624 Netscape/7.1 (ax)
// Accept: application/x-shockwave-flash,text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
// Cache-Control: max-age=0
//

// GET /prodreg.php?instcode=12JJ-GA96-E5UR-4EJ1 HTTP/1.1
// Host: www.tev.lt
// User-Agent: Mozilla/5.0 (Windows; U; Win98; en-US; rv:1.4) Gecko/20030624 Netscape/7.1 (ax)
// Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
//

// Firefox 3.6.21:

// GET /links.htm HTTP/1.1
// Host: 127.0.0.1:14006
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; lt; rv:1.9.2.21) Gecko/20110830 Firefox/3.6.21
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
// Accept-Language: lt,en-us;q=0.8,en;q=0.6,ru;q=0.4,pl;q=0.2
// Accept-Encoding: gzip,deflate
// Accept-Charset: windows-1257,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 115
// Connection: keep-alive
// Referer: http://127.0.0.1:14006/
// If-Modified-Since: 2009.04.24
// If-None-Match: "1315402634"
//

// GET /rrr.exe HTTP/1.1
// Host: 127.0.0.1:14006
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; lt; rv:1.9.2.21) Gecko/20110830 Firefox/3.6.21
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
// Accept-Language: lt,en-us;q=0.8,en;q=0.6,ru;q=0.4,pl;q=0.2
// Accept-Encoding: gzip,deflate
// Accept-Charset: windows-1257,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 115
// Connection: keep-alive
// If-Modified-Since: 2011.09.07
// If-None-Match: "1315404252"
// Cache-Control: max-age=0
//


// --------------------------------------
// HTTP_GET_REQUEST, "reload current page":

// GET /friends.htm HTTP/1.1
// Host: 127.0.0.1:3010
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.0; en-US; rv:1.8.0.6) Gecko/20060728 Firefox/1.5.0.6
// Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
// Referer: http://127.0.0.1:3010/
// If-Modified-Since: 2006-08-23
// If-None-Match: "1156338348"
// Cache-Control: max-age=0
//


// --------------------------------------
// HTTP_GET_REQUEST, <meta http-equiv="refresh" content="5">:

// GET /status.htm HTTP/1.1
// Host: 127.0.0.1:3010
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.0; en-US; rv:1.8.0.6) Gecko/20060728 Firefox/1.5.0.6
// Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
// Pragma: no-cache
// Cache-Control: no-cache


// --------------------------------------
// HTTP_GET_REQUEST, Opera:

// GET / HTTP/1.1
// User-Agent: Opera/9.02 (Windows NT 5.0; U; en)
// Host: 127.0.0.1:13008
// Accept: text/html, application/xml;q=0.9, application/xhtml+xml, image/png, image/jpeg, image/gif, image/x-xbitmap, */*;q=0.1
// Accept-Language: lt-LT,lt;q=0.9,en;q=0.8
// Accept-Charset: iso-8859-1, utf-8, utf-16, *;q=0.1
// Accept-Encoding: deflate, gzip, x-gzip, identity, *;q=0
// Connection: Keep-Alive


// GET /friends.htm HTTP/1.1
// User-Agent: Opera/9.02 (Windows NT 5.0; U; en)
// Host: 127.0.0.1:13008
// Accept: text/html, application/xml;q=0.9, application/xhtml+xml, image/png, image/jpeg, image/gif, image/x-xbitmap, */*;q=0.1
// Accept-Language: lt-LT,lt;q=0.9,en;q=0.8
// Accept-Charset: iso-8859-1, utf-8, utf-16, *;q=0.1
// Accept-Encoding: deflate, gzip, x-gzip, identity, *;q=0
// Connection: Keep-Alive, TE
// TE: deflate, gzip, chunked, identity, trailers


// --------------------------------------
// HTTP_GET_REQUEST, IE 7:

// GET /results.htm HTTP/1.1
// Accept: */*
// Accept-Language: lt
// UA-CPU: x86
// Accept-Encoding: gzip, deflate
// If-Modified-Since: Sun, 03 Sep 2000 08:46:12 GMT
// If-None-Match: "1173429969"
// User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)
// Host: 10.2.0.24:13006
// Connection: Keep-Alive
//

// GET /results.htm HTTP/1.1
// Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*
// Accept-Language: lt
// UA-CPU: x86
// Accept-Encoding: gzip, deflate
// If-Modified-Since: Sun, 03 Sep 2000 08:18:38 GMT
// If-None-Match: "1173428315"
// User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)
// Host: 10.2.0.24:13006
// Connection: Keep-Alive
//


// --------------------------------------
// HTTP_GET_REQUEST, lynx:

// GET /admins.htm HTTP/1.1
// Host: 10.2.0.24:13006
// User-Agent: Links (1.00pre12; Linux 2.6.8-2-386 i686; 80x24) (Debian pkg 0.99+1.00pre12-1sarge1)
// Accept: */*
// Accept-Charset: us-ascii, ISO-8859-1, ISO-8859-2, ISO-8859-4, ISO-8895-5, ISO-8859-7, ISO-8895-9, ISO-8859-13, ISO-8859-15, ISO-8859-16, windows-1250, windows-1251, windows-1257, cp437, cp737, cp850, cp852, cp866, x-cp866-u, x-mac, x-mac-ce, x-kam-cs, koi8-r, koi8-u, TCVN-5712, VISCII, utf-8
// Connection: Keep-Alive
//


// ======================================================
// HTTP_POST_REQUEST


// --------------------------------------
// HTTP_POST_REQUEST, Firefox:
// paskutines dvi eilutes ateina kitu paketu
// is kpstlsvr.exe IP adresu ivedimo formos bandymu

// POST /friends.htm HTTP/1.1
// Host: 127.0.0.1:3010
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.0; en-US; rv:1.8.0.6) Gecko/20060728 Firefox/1.5.0.6
// Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
// Referer: http://127.0.0.1:3010/friends.htm
// Content-Type: multipart/form-data; boundary=---------------------------31673223865021
// Content-Length: 142
//


// --------------------------------------
// HTTP_POST_REQUEST, IE 7:

// POST /admins.htm HTTP/1.1
// Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*
// Referer: http://10.2.0.24:13006/admins.htm
// Accept-Language: lt
// Content-Type: multipart/form-data; boundary=---------------------------7d73089100ca
// UA-CPU: x86
// Accept-Encoding: gzip, deflate
// User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)
// Host: 10.2.0.24:13006
// Content-Length: 239
// Connection: Keep-Alive
// Cache-Control: no-cache
//
// -----------------------------7d73089100ca
// Content-Disposition: form-data; name="ButNum"
//
// 2
// -----------------------------7d73089100ca
// Content-Disposition: form-data; name="IP"
//
// 10.2.0.54
// -----------------------------7d73089100ca--


// --------------------------------------
// HTTP_POST_REQUEST, lynx:

// POST /admins.htm HTTP/1.1
// Host: 10.2.0.24:13006
// User-Agent: Links (1.00pre12; Linux 2.6.8-2-386 i686; 80x24) (Debian pkg 0.99+1.00pre12-1sarge1)
// Accept: */*
// Accept-Charset: us-ascii, ISO-8859-1, ISO-8859-2, ISO-8859-4, ISO-8895-5, ISO-8859-7, ISO-8895-9, ISO-8859-13, ISO-8859-15, ISO-8859-16, windows-1250, windows-1251, windows-1257, cp437, cp737, cp850, cp852, cp866, x-cp866-u, x-mac, x-mac-ce, x-kam-cs, koi8-r, koi8-u, TCVN-5712, VISCII, utf-8
// Connection: Keep-Alive
// Content-Type: multipart/form-data; boundary=00000000000000000000000000000000
// Content-Length: 217
//
// --00000000000000000000000000000000
// Content-Disposition: form-data; name="ButNum"
//
//
// --00000000000000000000000000000000
// Content-Disposition: form-data; name="IP"
//
// 10.2.0.13
// --00000000000000000000000000000000--


// --------------------------------------
// is Tado rezultatai.pdf

// POST / HTTP/1.1
// Accept: */*
// Content-Type: application/x-www-form-urlencoded
// Content-Length: 92
// User-Agent: AcroForms
// Host: 127.0.0.1:18008
// Cache-Control: no-cache
//


// ======================================================
// HTTP_POST_DATA_SEGM:


// --------------------------------------
// is kpstlsvr.exe IP adresu ivedimo formos bandymu

// -----------------------------31673223865021
// Content-Disposition: form-data; name="IP"
//
// 987
// -----------------------------31673223865021--


// --------------------------------------
// HTTP_POST_DATA_SEGM:
// HTTP_POST_REQUEST galas:
// is kpstlsvr.exe IP adresu ivedimo formos bandymu

// Content-Type: multipart/form-data; boundary=---------------------------31673223865021
// Content-Length: 142
//

// -----------------------------287452692419072
// Content-Disposition: form-data; name="IP"
//
// 123
// -----------------------------287452692419072
// Content-Disposition: form-data; name="Band"
//
// 456
// -----------------------------287452692419072--


// --------------------------------------
// HTTP_POST_DATA_SEGM:
// is kpstlsvr.exe IP adresu ivedimo formos
// nepazymeti checkboxai neperduodami

// -----------------------------265001916915724
// Content-Disposition: form-data; name="ButNum"
//
// 1
// -----------------------------265001916915724
// Content-Disposition: form-data; name="check[1]"
//
// on
// -----------------------------265001916915724
// Content-Disposition: form-data; name="check[2]"
//
// on
// -----------------------------265001916915724
// Content-Disposition: form-data; name="IP"
//
//
// -----------------------------265001916915724--


// --------------------------------------
// HTTP_POST_DATA_SEGM:
// is kpstlsvr.exe IP adresu ivedimo formos per Opera
// galas jau apdorotas, like tik kepures

// POST /friends.htm HTTP/1.1
// User-Agent: Opera/9.02 (Windows NT 5.0; U; en)
// Host: 127.0.0.1:13008
// Accept: text/html, application/xml;q=0.9, application/xhtml+xml, image/png, image/jpeg, image/gif, image/x-xbitmap, */*;q=0.1
// Accept-Language: lt-LT,lt;q=0.9,en;q=0.8
// Accept-Charset: iso-8859-1, utf-8, utf-16, *;q=0.1
// Accept-Encoding: deflate, gzip, x-gzip, identity, *;q=0
// Referer: http://127.0.0.1:13008/friends.htm
// Connection: Keep-Alive, TE
// TE: deflate, gzip, chunked, identity, trailers
// Content-Length: 224
// Content-Type: multipart/form-data; boundary=----------MewvlxgnyxIqwnyLYofnOt
//

// Content-Disposition: form-data; name="ButNum"
//

// Content-Disposition: form-data; name="IP"
//


// --------------------------------------
// is pavyzdzio apie POST: http://www.w3.org/TR/html4/interact/forms.html
// sitokie duomenys netinka - duomenys ilgesni nei viena eilute,
// be to keli duomenu strukturos lygiai:

// Content-Type: multipart/form-data; boundary=AaB03x
//
// --AaB03x
// Content-Disposition: form-data; name="submit-name"
//
// Larry
// --AaB03x
// Content-Disposition: form-data; name="files"
// Content-Type: multipart/mixed; boundary=BbC04y
//
// --BbC04y
// Content-Disposition: file; filename="file1.txt"
// Content-Type: text/plain
//
// ... contents of file1.txt ...
// --BbC04y
// Content-Disposition: file; filename="file2.gif"
// Content-Type: image/gif
// Content-Transfer-Encoding: binary
//
// ...contents of file2.gif...
// --BbC04y--
// --AaB03x--


// --------------------------------------
// AcroRead 6 iš Tado matau5e/cd/cd5_3.pdf

// POST /?&File_Name=cd5_3.pdf&Start_Time=&Lygis=1%20lygis&Pasirinktas_rezimas=Mokausi&Pasirinkta_uzd_sk=5&Pasirinktas_laikas_sk=2 HTTP/1.1
// Accept: */*
// Content-Type: application/vnd.fdf
// Content-Length: 1841
// User-Agent: AcroForms
// Host: 127.0.0.1:13010
// Cache-Control: no-cache

// POST /?&File_Name=cd5_3.pdf&Stop_Time=2006.09.25%2014:07:22&Pateikta_uzd_sk=1&Teisingai_sk=&Neteisingai_sk=1 HTTP/1.1
// Accept: */*
// Content-Type: application/vnd.fdf
// Content-Length: 1862
// User-Agent: AcroForms
// Host: 127.0.0.1:13010
// Cache-Control: no-cache


// --------------------------------------
// AcroRead 7 iš Tado PP11-12 kreipinys į kpstisvr.exe dėl ArkSh.exe paleidimo

// POST / HTTP/1.1
// Accept: */*
// Content-Type: application/x-www-form-urlencoded
// Content-Length: 42
// Acrobat-Version: 7.0.8
// User-Agent: AcroForms
// Host: 127.0.0.1:49494
// Connection: Keep-Alive
// Cache-Control: no-cache

// POST / HTTP/1.1
// Accept: */*
// Content-Type: application/x-www-form-urlencoded
// Content-Length: 44
// User-Agent: AcroForms
// Host: 127.0.0.1:49494
// Cache-Control: no-cache
//
// EXT_f1010101=failai%2ff1010101.doc&f1010101=
//


// --------------------------------------
// AcroRead iš iš Raimio EV9-10 klaidingas kreipinys į kpstisvr.exe dėl .doc atvėrimo

// POST / HTTP/1.1
// Accept: */*
// Content-Type: multipart/form-data; boundary=---------------------------703890824533759
// Content-Length: 162
// User-Agent: AcroForms
// Host: 127.0.0.1:49494
// Cache-Control: no-cache
//
// -----------------------------703890824533759
// Content-Disposition: form-data; name="EXT_failas"; filename=""
//
//
// -----------------------------703890824533759
// Content-Disposition: form-data; name="aktyvus_1sk_0"
//
//
// -----------------------------703890824533759--


// ----------------------------------------------------
// HTTP/1.1 200 OK
// Date: Thu, 03 May 2012 14:50:55 GMT
// Server: Apache
// Set-Cookie: PHPSESSID=5f15743c7c898d147cabe8385cc4afaa; path=/
// Content-Description: File Transfer
// Content-Disposition: attachment; filename=ekov910_lt_setup.exe
// Content-Transfer-Encoding: binary
// Expires: 0
// Cache-Control: must-revalidate, post-check=0, pre-check=0
// Pragma: public
// Content-Length: 23959329
// Keep-Alive: timeout=1, max=100
// Connection: Keep-Alive
// Content-Type: application/octet-stream
//
// ...
//


HRESULT KpSocket::ScanHdrFileName(uchar **p_plpszHdrPtrPtr, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_plpszHdrPtrPtr, E_INVALIDARG, null);
    KP_ASSERT(*p_plpszHdrPtrPtr, E_INVALIDARG, null);

    while (**p_plpszHdrPtrPtr && strchr(lpszSpaces, **p_plpszHdrPtrPtr))
        (*p_plpszHdrPtrPtr)++;

    KP_ASSERTQ(strstr(*p_plpszHdrPtrPtr, KPSOCK_POST_FNAME_TAG) == // "filename="
        *p_plpszHdrPtrPtr, KP_E_KWD_NOT_FOUND, *p_plpszHdrPtrPtr, p_bThrowError);

    if (SUCCEEDED(retc)) *p_plpszHdrPtrPtr += strlen(KPSOCK_POST_FNAME_TAG);

    KP_ASSERTQ(strlen(*p_plpszHdrPtrPtr) <= KP_KWD_LEN, KP_E_BUFFER_OVERFLOW,
        null, p_bThrowError);

int ii = -1;
    if (SUCCEEDED(retc))
    {
        if (**p_plpszHdrPtrPtr == '\"') (*p_plpszHdrPtrPtr)++;
        strcpy(m_lpszCtrlName, *p_plpszHdrPtrPtr);
        ii = strlen(*p_plpszHdrPtrPtr) - 1;
    }
    KP_ASSERTQ(ii >= 0, KP_E_MSG_FORMAT, null, p_bThrowError);
    if (SUCCEEDED(retc))
        if (m_lpszCtrlName[ii] == '\"') m_lpszCtrlName[ii] = Nul;

return (retc);
}


HRESULT KpSocket::ScanHdr(HttpMsgTypes p_iInitMsgType, bool p_bThrowError)
{
HRESULT retc = S_OK;
HRESULT retv = S_OK;

    KP_ASSERTQ((p_iInitMsgType >= 0) && (p_iInitMsgType <
        NUM_OF_HTTP_MSG_TYPES), E_INVALIDARG, null, p_bThrowError);

    if (SUCCEEDED(retc))
    {
        m_iMsgType = p_iInitMsgType;

        if (p_iInitMsgType != HTTP_POST_DATA_SEGM)
        {
            // HTTP_POST_DATA_SEGM atveju šitie globalūs parametrai jau
            // priimti su pagrindine POST pranešimo antrašte
            m_iRetCode = 0;
            m_lpszRetMsg[0] = Nul;
            m_lpszLocation[0] = Nul;
            m_iTrMode = NORMAL_HTTP_TR_MODE;
            m_lContLen = MAXLONG;
            m_lpszBoundary[0] = Nul;
            m_lpszEndBoundary[0] = Nul;
        }
        m_lpszCtrlName[0] = Nul;
    }

    KP_ASSERTQ(strlen(m_lpszHdrBuf) <= MAX_HTTP_HDR_LEN, E_INVALIDARG, null,
                                                            p_bThrowError);
uchar *pnts = null;
uchar *pntd = null;
int str_len = 0;
uchar url[KP_MAX_FNAME_LEN+1];
    url[0] = Nul;

    if (SUCCEEDED(retc))
    {
        pnts = pntd = m_lpszHdrBuf;
        do
        {
            while (*pntd && (strchr(lpszEols, *pntd) == NULL)) pntd++;

        uchar sav_chr = (*pntd);
            *pntd = Nul;

            str_len = pntd - pnts;
            if (str_len > 0)
            {
                // pirma headerio eilutė
                if (
                    (pnts == m_lpszHdrBuf) &&
                    (
                        (m_iMsgType == HTTP_REPLY) ||
                        (m_iMsgType == HTTP_REQUEST_UNKNOWN)
                    )
                   )
                {
                int ii;
                int jj;

                    switch (m_iMsgType)
                    {
                    case HTTP_REPLY:

                        // "HTTP/1.1"
                        KP_ASSERTQ(strstr(pnts, KPSOCK_HTTP_HDR_PREFIX)
                            == pnts, KP_E_TRANS_ERR, null, p_bThrowError);

                        if (SUCCEEDED(retc))
                        {
                            pnts += strlen(KPSOCK_HTTP_HDR_PREFIX);
                            while (*pnts && (strchr(lpszSpaces, *pnts) !=
                                                                null)) pnts++;
                            m_iRetCode = 0; // 200 OK
                            sscanf((const char *)pnts, "%d", &m_iRetCode);

                            while (*pnts && KpIsDigit((KpChar)*pnts)) pnts++;
                            while (*pnts && (strchr(lpszSpaces, *pnts) !=
                                                                null)) pnts++;
                            strncpy(m_lpszRetMsg, pnts, KP_MAX_FILE_LIN_LEN);
                            m_lpszRetMsg[KP_MAX_FILE_LIN_LEN] = Nul;

                            retv = SUCCEEDED(
                                KpErrorClass::TranslFromHTTP_RetCode(
                                m_iRetCode))?S_OK:KP_E_NEG_ANSW;
                        }
                        break;

                    case HTTP_REQUEST_UNKNOWN:
                        if (strstr(pnts, HTTP_GET_REQUEST_CMD " ") == pnts)
                        {
                            pnts += strlen(HTTP_GET_REQUEST_CMD); // "GET"
                            while (*pnts && (strchr(lpszSpaces, *pnts) !=
                                                                null)) pnts++;
                            m_iMsgType = HTTP_GET_REQUEST;
                        }
                        // 
                        else if (strstr(pnts, HTTP_POST_REQUEST_CMD " ") == pnts)
                        {
                            pnts += strlen(HTTP_POST_REQUEST_CMD); // "POST"
                            while (*pnts && (strchr(lpszSpaces, *pnts) !=
                                                                null)) pnts++;

                            m_iMsgType = HTTP_POST_REQUEST;
                        }
                        else
                            KP_ASSERTQ(False, E_NOTIMPL, pnts, p_bThrowError);

                        if (SUCCEEDED(retc))
                        {
                            ii = strlen(pnts);
                            jj = strlen(" " KPSOCK_HTTP_HDR_PREFIX); // "HTTP/1.1"
                        }
                        KP_ASSERTQ(strstr(pnts, " " KPSOCK_HTTP_HDR_PREFIX) == pnts + ii - jj,
                            E_NOTIMPL, pnts, p_bThrowError);

                        if (SUCCEEDED(retc)) pnts[ii - jj] = Nul;

                        KP_ASSERTQ(strlen(url) + ii - jj < KP_MAX_FNAME_LEN,
                            KP_E_BUFFER_OVERFLOW, pnts, p_bThrowError);
                        if (SUCCEEDED(retc))
                        {
                            strcat(url, pnts);
                            pnts += ii;
                        }

                        break;

                    default:
                        KP_ASSERTQ(False, E_NOTIMPL, pnts, p_bThrowError);
                        break;

                    } // switch (m_iMsgType)

                } // if ((pnts == m_lpszHdrBuf) && ((m_iMsgType == HTTP_REPLY)
                else
                {
                    // tolesnės headerio eilutės
                uchar *pntd0 = strchr(pnts, ':');
                    KP_ASSERTQ(pntd0, KP_E_MSG_FORMAT, pnts, p_bThrowError);

                    if (SUCCEEDED(retc)) pntd0++;
                    KP_ASSERTQ(*pntd0 == Spc, KP_E_MSG_FORMAT, pnts,
                                                            p_bThrowError);
                    if (SUCCEEDED(retc))
                    {
                        *pntd0 = Nul;

                    int ix = GetKwrdIndex(pnts, KpsockTagNames,
                                        KPSOCK_NUM_OF_HDTAGS, True, True);
                        if (ix == TV_TG_NoKey)
                        {
                            // neatpažintus headerio raktus praleidžiam
                            KP_WARNING(KP_E_KWD_NOT_FOUND, pnts);
                        }
                        else
                        {
                        KpSockHdTag http_tag = (KpSockHdTag)ix;
                            KP_ASSERTQ((http_tag >= 0) &&
                                (http_tag < KPSOCK_NUM_OF_HDTAGS),
                                KP_E_SYSTEM_ERROR, pnts, p_bThrowError);
                            KP_ASSERTQ(
                                KpsockTagOccurences[http_tag][m_iMsgType],
                                KP_E_MSG_FORMAT, pnts, p_bThrowError);
                            if (SUCCEEDED(retc))
                            {
                                pnts = pntd0 + 1;
                                while (*pnts && strchr(lpszSpaces, *pnts))
                                    pnts++;

                            uchar url1[KP_MAX_FNAME_LEN + 1];
                                url1[0] = Nul;
                            int ii;

                                switch(http_tag)
                                {
                                // --------------------------------
                                // HTTP_REPLY
                                case KPSOCK_HDTAG_Location:
                                    KP_ASSERTQ(strlen(m_lpszLocation) <=
                                        KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW,
                                        pnts, p_bThrowError);
                                    if (SUCCEEDED(retc))
                                        strcpy(m_lpszLocation, pnts);
                                    break;

                                case KPSOCK_HDTAG_Date:
                                    // Date: Fri, 22 Oct 2004 07:13:17 GMT
                                    break;

                                case KPSOCK_HDTAG_Server:
                                    // Server: Apache/1.3.29 (Unix)
                                    // Server: Apache/1.3.29 (Unix) (Red-Hat/Linux) PHP/3.0.15 mod_ssl/2.8.7 OpenSSL/0.9h tomcat/1.0 mod_jk/1.2.0
                                    // Server: Apache/1.3.26 (Unix) mod_gzip/1.3.19.1a mod_throttle/3.1.2
                                    // Server: Apache
                                    break;                                          

                                case KPSOCK_HDTAG_SetCookie:
                                    // Set-Cookie: JSESSIONID=2C6444E9BE0D74D7E5FE24042673459F;Path=/services
                                    // gali ir nebuti
                                    break;

                                case KPSOCK_HDTAG_LastModified:
                                    // Last-Modified: Thu, 17 Jan 2002 12:58:44 GMT
                                    // TODO: scan file date
                                    // tik statiniams puslapiams
                                    break;

                                case KPSOCK_HDTAG_XPoweredBy:
                                    // X-Powered-By: PHP/4.3.4
                                    // dinaminiams puslapiams, gali ir nebuti
                                    break;

                                case KPSOCK_HDTAG_ETag:
                                    // ETag: cb992-26b-3c46ca84
                                    // ETag: 23-40f6b0d0
                                    // gali ir nebuti (yra tik statiniams
                                    //      puslapiams?)
                                    break;

                                case KPSOCK_HDTAG_AcceptRanges:
                                    // Accept-Ranges: bytes
                                    // gali ir nebuti (yra tik statiniams
                                    //      puslapiams?)
                                    if (strcmp(pnts, "bytes")==0){}                  
                                    else KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    break;

                                case KPSOCK_HDTAG_ContentLength:
                                    // Content-Length: 619
                                    // gali ir nebuti -
                                    //      tada "Transfer-Encoding:"
                                    // pranešimo duomenų dalies ilgis - baitų
                                    //      skaičius be headerio ir tuščios
                                    //      eilutės - atskyrėjo tarp headerio
                                    //      ir duomenų
                                    // TODO: tikrinti, kad butu tik skaičius
                                    //      ir nieko daugiau
                                    m_lContLen = MAXLONG;
                                    if (sscanf((const char *)pnts, "%ld",
                                        &m_lContLen) < 1)
                                    {
                                        m_lContLen = MAXLONG;
                                        KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    }
                                    break;

                                case KPSOCK_HDTAG_TransferEncoding:
                                    // Transfer-Encoding: chunked
                                    // gali ir nebūti - tada "Content-Length:"
                                    // žr. HTTP_TR_CHUNK_MODE
                                    ix = GetKwrdIndex(pnts, TransferModeNames,
                                        NUM_OF_HTTP_TR_MODES, True, True);
                                    KP_ASSERTQ(ix != TV_TG_NoKey,
                                        KP_E_KWD_NOT_FOUND, pnts,
                                        p_bThrowError);
                                    if (SUCCEEDED(retc))
                                        m_iTrMode = (HttpTransferModes)ix;
                                    break;

                                case KPSOCK_HDTAG_Connection:
                                    // Connection: close
                                    // Connection: keep-alive
                                    // Connection: Keep-Alive
                                    // Connection: Keep-Alive, TE
                                    // jei "keep-alive" - tada "Keep-Alive:"
                                    // jei "TE" - tada "TE:"
                                    if (strcmp(pnts, "close") == 0){}
                                    else if ((strcmp(pnts, "keep-alive") == 0)
                                        || (strstr(pnts, "Keep-Alive") ==
                                        pnts)){}
                                    else KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    break;

                                case KPSOCK_HDTAG_KeepAlive:
                                    // Keep-Alive: timeout=15, max=100
                                    // Keep-Alive: 300
                                    // tik jei "Connection: keep-alive"
                                    // TODO: tikrinti, kad būtų, tik jei
                                    //      "Connection: keep-alive",
                                    //      tik kad  "Connection: keep-alive"
                                    //      būna po "Keep-Alive:"
                                    // TODO: tikrinti, kad būtų skaičius
                                    break;

                                case KPSOCK_HDTAG_TE:
                                    // TE: deflate, gzip, chunked, identity,
                                    //      trailers
                                    // kažkas panašaus į Accept-Encoding:
                                    // po Connection: Keep-Alive, TE
                                    break;

// ------------------------------------------------------
// Content-Type := type "/" subtype *[";" parameter]
// type :=          "application"     / "audio"
//           / "image"           / "message"
//           / "multipart"  / "text"
//           / "video"           / x-token
// x-token := <The two characters "X-" followed, with no
//            intervening white space, by any token>
// subtype := token
// parameter := attribute "=" value
// attribute := token
// value := token / quoted-string
// token := 1*<any CHAR except SPACE, CTLs, or tspecials>
// tspecials :=  "(" / ")" / "<" / ">" / "@"  ; Must be in
//            /  "," / ";" / ":" / "\" / <">  ; quoted-string,
//            /  "/" / "[" / "]" / "?" / "."  ; to use within
//            /  "="                        ; parameter values
// Note that the definition of "tspecials" is the same as the RFC 822 definition of "specials" with the addition of the three characters "/", "?", and "=".
// Note also that a subtype specification is MANDATORY. There are no default subtypes.
// The type, subtype, and parameter names are not case sensitive. For example, TEXT, Text, and TeXt are all equivalent. Parameter values are normally case sensitive, but certain parameters are interpreted to be case- insensitive, depending on the intended use. (For example, multipart boundaries are case-sensitive, but the "access- type" for message/External-body is not case-sensitive.)
// Beyond this syntax, the only constraint on the definition of subtype names is the desire that their uses must not conflict. That is, it would be undesirable to have two different communities using "Content-Type: application/foobar" to mean two different things. The process of defining new content-subtypes, then, is not intended to be a mechanism for imposing restrictions, but simply a mechanism for publicizing the usages. There are, therefore, two acceptable mechanisms for defining new Content-Type subtypes:
//     Private values (starting with "X-") may be defined bilaterally between two cooperating agents without outside registration or standardization.
//     New standard values must be documented, registered with, and approved by IANA, as described in Appendix F. Where intended for public use, the formats they refer to must also be defined by a published specification, and possibly offered for standardization.
// The seven standard initial predefined Content-Types are detailed in the bulk of this document. They are:
// text – textual information. The primary subtype, "plain", indicates plain (unformatted) text. No special software is required to get the full meaning of the text, aside from support for the indicated character set. Subtypes are to be used for enriched text in forms where application software may enhance the appearance of the text, but such software must not be required in order to get the general idea of the content. Possible subtypes thus include any readable word processor format. A very simple and portable subtype, richtext, is defined in this document.
// multipart – data consisting of multiple parts of independent data types. Four initial subtypes are defined, including the primary "mixed" subtype, "alternative" for representing the same data in multiple formats, "parallel" for parts intended to be viewed simultaneously, and "digest" for multipart entities in which each part is of type "message".
// message – an encapsulated message. A body of Content-Type "message" is itself a fully formatted RFC 822 conformant message which may contain its own different Content-Type header field. The primary subtype is "rfc822". The "partial" subtype is defined for partial messages, to permit the fragmented transmission of bodies that are thought to be too large to be passed through mail transport facilities. Another subtype, "External-body", is defined for specifying large bodies by reference to an external data source.
// image – image data. Image requires a display device (such as a graphical display, a printer, or a FAX machine) to view the information. Initial subtypes are defined for two widely-used image formats, jpeg and gif.
// audio – audio data, with initial subtype "basic". Audio requires an audio output device (such as a speaker or a telephone) to "display" the contents.
// video – video data. Video requires the capability to display moving images, typically including specialized hardware and software. The initial subtype is "mpeg".
// application – some other kind of data, typically either uninterpreted binary data or information to be processed by a mail-based application. The primary subtype, "octet-stream", is to be used in the case of uninterpreted binary data, in which case the simplest recommended action is to offer to write the information into a file for the user. Two additional subtypes, "ODA" and "PostScript", are defined for transporting ODA and PostScript documents in bodies. Other expected uses for "application" include spreadsheets, data for mail-based scheduling systems, and languages for "active" (computational) email. (Note that active email entails several securityconsiderations, which are discussed later in this memo, particularly in the context of application/PostScript.)
// Default RFC 822 messages are typed by this protocol as plain text in the US-ASCII character set, which can be explicitly specified as "Content-type: text/plain; charset=us-ascii". If no Content-Type is specified, either by error or by an older user agent, this default is assumed. In the presence of a MIME-Version header field, a receiving User Agent can also assume that plain US-ASCII text was the sender's intent. In the absence of a MIME-Version specification, plain US-A
// ------------------------------------------------------
                                case KPSOCK_HDTAG_ContentType:
                                    // Content-Type: text/plain
                                    // Content-Type: text/html
                                    // Content-Type: text/html; charset=ISO-8859-1
                                    // TODO: migruoti iš content_types.py
                                    if (m_iMsgType == HTTP_REPLY)
                                    {
                                        if (strcmp(pnts, "text/plain") == 0){}
                                        else if (strcmp(pnts, "text/html") == 0){}
                                        else if (strstr(pnts, "text/html; charset=") == pnts){}
                                        else if (strcmp(pnts, "image/bmp") == 0){}
                                        else if (strcmp(pnts, "image/png") == 0){}
                                        else if (strstr(pnts, "image/jpeg") == 0){} // JPEG JFIF image
                                        else if (strstr(pnts, "image/gif") == 0){} // GIF image
                                        else if (strstr(pnts, "image/vnd.microsoft.icon") == 0){} // ICO image
                                        else if (strstr(pnts, "application/unknown") == 0){}
                                        else if (strstr(pnts, "application/octet-stream") == 0){} // common binary uninterpreted
                                        else if (strcmp(pnts, "application/x-msdownload") == 0){}
                                        else if (strstr(pnts, "application/vnd.xls") == 0){} // MS Excel
                                        else if (strstr(pnts, "application/vnd.ms-excel") == 0){} // Microsoft Excel (tm)
                                        else if (strstr(pnts, "application/ms-word") == 0){} // MS Word
                                        else if (strstr(pnts, "application/msword") == 0){} // Microsoft Word
                                        else if (strstr(pnts, "application/vnd.ms-powerpoint") == 0){} // Microsoft Powerpoint (tm)
                                        else if (strstr(pnts, "application/pdf") == 0){} // Portable Document Format
                                        else if (strcmp(pnts, "application/vnd.fdf") == 0){}
                                        else if (strstr(pnts, "application/zip") == 0){} // ZIP file
                                        else KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    }
                                    else if (m_iMsgType == HTTP_POST_REQUEST)
                                    // Content-Type: multipart/form-data; boundary=---------------------------287452692419072
                                    // Content-Type: multipart/form-data; boundary=----------MewvlxgnyxIqwnyLYofnOt
                                    // Content-Type: application/x-www-form-urlencoded
                                    {
                                        if (strstr(pnts, KPSOCK_POST_MULTIPART_TAG) == pnts) // "multipart/form-data;"
                                        // tada turi būti Content-Length:
                                        // Content-Type: application/vnd.fdf
                                        {
                                            pnts += strlen(KPSOCK_POST_MULTIPART_TAG);
                                            while (*pnts && (strchr(lpszSpaces, *pnts) != NULL)) pnts++;
                                            if (strstr(pnts, KPSOCK_POST_BOUNDARY_TAG) == pnts) // "boundary="
                                            {
                                                pnts += strlen(KPSOCK_POST_BOUNDARY_TAG);
                                                KP_ASSERTQ(strlen(pnts) <= KP_MAX_FILE_LIN_LEN,
                                                    KP_E_BUFFER_OVERFLOW, null, p_bThrowError);
                                                if (SUCCEEDED(retc))
                                                {
                                                    strcpy(m_lpszBoundary, "--");
                                                    strcat(m_lpszBoundary, pnts);

                                                    strcpy(m_lpszEndBoundary, m_lpszBoundary);
                                                    strcat(m_lpszEndBoundary, "--");
                                                }
                                                // ne – boundary naudojamas formos laukų atskyrimui, ne chunk'ų
                                                // m_iTrMode = HTTP_TR_CHUNK_MODE;
                                            }
                                            else
                                                KP_ASSERTQ(False, KP_E_MSG_FORMAT, pnts, p_bThrowError);
                                        }
                                        else if (strcmp(pnts, "application/x-www-form-urlencoded") == 0){}
                                        else if (strcmp(pnts, "application/vnd.fdf") == 0){}
                                        else
                                            KP_ASSERTQ(False, E_NOTIMPL, pnts, p_bThrowError);
                                    }
                                    else if (m_iMsgType==HTTP_POST_DATA_SEGM)
                                    // Content-Type: multipart/mixed; boundary=BbC04y
                                    // Content-Type: text/plain
                                    // Content-Type: image/gif
                                        KP_ASSERTQ(False, E_NOTIMPL, pnts, p_bThrowError);
                                    break;

                                case KPSOCK_HDTAG_ContentEncoding:
                                    // Content-Encoding: gzip
                                    // Content-Encoding: none
                                    if (strcmp(pnts, "gzip") == 0)                     
                                        KP_WARNING(E_NOTIMPL, pnts)
                                    else if (strcmp(pnts, "none") == 0){}
                                    else KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    break;

                                // --------------------------------
                                // HTTP_REQUEST_UNKNOWN
                                case KPSOCK_HDTAG_Host:
                                    // Host: 127.0.0.1:49494
                                    if (strlen(KPSOCK_URL_HTTP_PREFIX) + strlen(pnts) + strlen(url)
                                        >= KP_MAX_FNAME_LEN) KP_WARNING(KP_E_BUFFER_OVERFLOW, null)
                                    else
                                    {
                                        strcpy(url1, KPSOCK_URL_HTTP_PREFIX);
                                        strcat(url1, pnts);
                                        strcat(url1, url);
                                        strcpy(url, url1);
                                    }
                                    break;

                                case KPSOCK_HDTAG_UserAgent:
                                    // User-Agent: Mozilla/5.0 (Windows; U; Win98; en-US; rv:1.4) Gecko/20030624 Netscape/7.1 (ax)
                                    // User-Agent: AcroForms
                                    // User-Agent: Opera/9.02 (Windows NT 5.0; U; en)
                                    break;

                                case KPSOCK_HDTAG_Accept:
                                    // Accept: video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
                                    // Accept: application/x-shockwave-flash,text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
                                    // Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,video/x-mng,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
                                    // Accept: text/html, application/xml;q=0.9, application/xhtml+xml, image/png, image/jpeg, image/gif, image/x-xbitmap, */*;q=0.1
                                    // Accept: */*
                                    break;

                                case KPSOCK_HDTAG_AcceptLanguage:
                                    // Accept-Language: en-us,en;q=0.5
                                    // Accept-Language: lt-LT,lt;q=0.9,en;q=0.8
                                    break;

                                case KPSOCK_HDTAG_AcceptEncoding:
                                    // Accept-Encoding: gzip,deflate
                                    // Accept-Encoding: deflate, gzip, x-gzip, identity, *;q=0
                                    break;

                                case KPSOCK_HDTAG_AcceptCharset:
                                    // Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
                                    // Accept-Charset: iso-8859-1, utf-8, utf-16, *;q=0.1
                                    break;

                                case KPSOCK_HDTAG_Pragma:
                                    // Pragma: no-cache
                                    if (strcmp(pnts, "no-cache") == 0){}
                                    if (strcmp(pnts, "public") == 0){}
                                    else KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    break;

                                case KPSOCK_HDTAG_CacheControl:
                                    // Cache-Control: max-age=0
                                    // Cache-Control: no-cache
                                    // Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
                                    if (strstr(pnts, "max-age=") == pnts){}
                                    else if (strcmp(pnts, "no-cache") == 0){}
                                    else
                                    {
                                        // KP_WARNING(KP_E_MSG_FORMAT, pnts);
                                    }
                                    break;

                                case KPSOCK_HDTAG_Referer:
                                    // Referer: http://127.0.0.1:3010/friends.htm
                                    // Referer: http://127.0.0.1:3010/
                                    // GET requestuose tik jei "reload current page"
                                    break;

                                case KPSOCK_HDTAG_IfModifiedSince:
                                    // If-Modified-Since: 2006-08-23
                                    // tik jei "reload current page"
                                    break;

                                case KPSOCK_HDTAG_IfNoneMatch:
                                    // If-None-Match: 1156338348
                                    // tik jei "reload current page"
                                    break;

                                case KPSOCK_HDTAG_UA_CPU:
                                    // UA-CPU: x86
                                    if (strcmp(pnts, "x86") == 0){}
                                    else
                                    {
                                        // KP_WARNING(E_NOTIMPL, pnts);
                                    }
                                    break;

                                // --------------------------------
                                // HTTP_POST_DATA_SEGM
                                case KPSOCK_HDTAG_ContentDisposition:
                                    // Content-Disposition: form-data; name="IP"
                                    if (strstr(pnts, KPSOCK_POST_FORM_TAG) == pnts) // "form-data;"
                                    {
                                        pnts += strlen(KPSOCK_POST_FORM_TAG);

                                        while (*pnts && (strchr(lpszSpaces, *pnts) != NULL)) pnts++;
                                        KP_ASSERTQ(strstr(pnts, KPSOCK_POST_CTRL_NAME_TAG) == pnts, // "name="
                                            KP_E_KWD_NOT_FOUND, pnts, p_bThrowError);
                                        if (SUCCEEDED(retc)) pnts += strlen(KPSOCK_POST_CTRL_NAME_TAG);

                                        KP_ASSERTQ(strlen(pnts) <= KP_KWD_LEN,
                                            KP_E_BUFFER_OVERFLOW, null, p_bThrowError);

                                        KP_ASSERTQ(*pnts == '\"', KP_E_MSG_FORMAT,
                                            pnts, p_bThrowError);
                                        if (SUCCEEDED(retc))
                                        {
                                            pnts++;
                                            strcpy(m_lpszCtrlName, pnts);
                                            ii = strlen(pnts) - 1;
                                        }
                                        KP_ASSERTQ(ii >= 0, KP_E_MSG_FORMAT, null, p_bThrowError);
                                        KP_ASSERTQ(m_lpszCtrlName[ii] == '\"', KP_E_MSG_FORMAT, null, p_bThrowError);
                                        if (SUCCEEDED(retc)) m_lpszCtrlName[ii] = Nul;
                                    }
                                    else if (strstr(pnts, KPSOCK_POST_FILE_TAG) == pnts) // "file;"
                                    // Content-Disposition: file; filename="file1.txt"
                                    {
                                        pnts += strlen(KPSOCK_POST_FILE_TAG);
                                        retc = ScanHdrFileName(&pnts, p_bThrowError);
                                    }
                                    else if (strstr(pnts, KPSOCK_POST_ATT_TAG) == pnts) // "attachment;"
                                    // Content-Disposition: attachment; filename=ekov910_lt_setup.exe
                                    {
                                        pnts += strlen("attachment;");
                                        retc = ScanHdrFileName(&pnts, p_bThrowError);
                                    }
                                    else
                                        KP_ASSERTQ(False, E_NOTIMPL, pnts, p_bThrowError);
                                    break;

                                case KPSOCK_HDTAG_ContentTransferEncoding:
                                    // Content-Transfer-Encoding: binary
                                    if (strstr(pnts, KPSOCK_POST_BIN_TAG) == pnts) // "binary"
                                        pnts += strlen(KPSOCK_POST_BIN_TAG);
                                    else
                                        KP_ASSERTQ(False, E_NOTIMPL, null, p_bThrowError);
                                    break;

                                } // switch (http_tag)

                            } // if (SUCCEEDED(retc))

                        } // else // if (ix == TV_TG_NoKey)

                    } // if (SUCCEEDED(retc))

                } // else // if ((pnts==m_lpszHdrBuf) ...

            } // if (str_len > 0)

            *pntd = sav_chr;

            // while (*pntd && (strchr(lpszEols, *pntd) != NULL)) pntd++;
            if (*pntd == Cr) pntd++;
            if (*pntd == Lf) pntd++;

            pnts=pntd;

        } while ((*pnts) && (str_len > 0) && SUCCEEDED(retc));

    } // if (SUCCEEDED(retc))

    // gale headerio gale turi buti tuscia eilute
    KP_ASSERTW0(*pnts || (str_len == 0), KP_E_TRANS_ERR, null);

    if (
        (
            (m_iMsgType == HTTP_GET_REQUEST) ||
            (m_iMsgType == HTTP_POST_REQUEST)
        ) &&
        SUCCEEDED(retc)
       )
        retc = Resolve(url, p_bThrowError);

    if (SUCCEEDED(retc)) retc = retv; // grąžinam KP_E_NEG_ANSW

return (retc);
}


//---------------------
HRESULT KpSocket::RcvHdr(HttpMsgTypes p_iInitMsgType, bool p_bThrowError)
{
HRESULT retc = S_OK;

   retc = ReceiveHdr(p_iInitMsgType, NULL, p_bThrowError);

   if (SUCCEEDED(retc))
   {
#ifdef TRACE_HTTP
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, m_lpszHdrBuf, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::RcvHdr(): \n%s", str_buf_1);
}
#endif

      retc = ScanHdr(p_iInitMsgType, p_bThrowError);
   }

return (retc);
}


//---------------------
HRESULT KpSocket::RcvHttpMsg(uchar *p_pBuf, long *p_plRead,
                                        bool p_bRcvHdr, bool p_bThrowError)
{
HRESULT retc = S_OK;
HRESULT retv = S_OK;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_plRead, E_INVALIDARG, null);

    if (p_bRcvHdr)
    {
        // -------- dar kabo nepabaigtas ankstesnis pranešimas
        KP_ASSERTQ(m_lRestChunkLength == 0L, KP_E_DOUBLE_CALL, null, p_bThrowError);
//      KP_ASSERTQ(m_lNextChunkLength == 0L, KP_E_DOUBLE_CALL, null, p_bThrowError);

        // -------------------------------------------------
        if (SUCCEEDED(retc))
        {
            retc = RcvHdr(HTTP_REPLY, p_bThrowError);
            if (retc == KP_E_NEG_ANSW)
            {
            char str_buf[KP_MAX_FILE_LIN_LEN + 100];
                sprintf(str_buf, "%d %s", m_iRetCode, m_lpszRetMsg);
                // išsaugojam KP_E_NEG_ANSW
                retv = retc;
                KP_WARNING(retc, str_buf);
                retc = S_OK;
            }
        }

    } // if (p_bRcvHdr)

    // -------------------------------------------------
    // receive header tail with chunk header???
long read = MAX_HTTP_HDR_LEN;
    if (SUCCEEDED(retc))
        retc = ReceiveMsg(m_lpszHdrBuf, &read, True, p_bThrowError);
    if (SUCCEEDED(retc))
    {
        m_lpszHdrBuf[read] = Nul;

#ifdef TRACE_HTTP
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, m_lpszHdrBuf, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::RcvHttpMsg():\n%s", str_buf_1);
}
#endif
    }

    // receive data part
long buf_len = 0L;
    if (SUCCEEDED(retc))
    {
        m_lpszChunkPos = m_lpszHdrBuf;
        m_lChunkRest = read;

        // TODO: čia gal kažkaip iškviesti RcvHttpRest()?

        buf_len = *p_plRead;
        KP_ASSERTQ(buf_len > 1, E_INVALIDARG, null, p_bThrowError);
            // paliekam vietos galiniam nuliui
    }

uchar *pntd = null;
    if (SUCCEEDED(retc))
    {
        *p_plRead = 0;  // jau priimtų baitų sk.
        pntd = p_pBuf;  // pointeris priėmimo buferyje

        // ----------------------------- Transfer-Encoding: chunked
        if (m_iTrMode == HTTP_TR_CHUNK_MODE)
        {
            KP_ASSERTQ(m_lContLen == MAXLONG, KP_E_FILE_FORMAT, null, p_bThrowError);

        long chunk_length = 0L;

            if (SUCCEEDED(retc)) do
            {
                // ---------- chunk length
                chunk_length = 0L;

                if (m_lRestChunkLength == 0)
                    retc = GetChunkLength(&chunk_length, p_bThrowError);

                if ((chunk_length > 0) && SUCCEEDED(retc))
                {
                    // ---------- jei netilps į buferį – nukandam
                    m_lRestChunkLength = 0L;
                    if (chunk_length > buf_len - (pntd - p_pBuf) - 1)
                        m_lRestChunkLength = chunk_length - (buf_len -
                                                        (pntd - p_pBuf) - 1);

                    // ---------- tiek skaitysim iš dabartinio chunk
                    chunk_length -= m_lRestChunkLength;

                    // ---------- chunk
                    if (chunk_length > 0)
                        retc = GetChunk(chunk_length, &pntd, p_pBuf, buf_len,
                            m_lRestChunkLength == 0, p_bThrowError);

                } // if ((chunk_length > 0) && SUCCEEDED(retc))

            } while ((chunk_length > 0) && SUCCEEDED(retc));

            // kai paskutinis gabalas, gali likti nebent Cr/Lf (2 baitai)
            if (SUCCEEDED(retc))
                if (m_lRestChunkLength == 0L)
             // if (m_lNextChunkLength == 0L)
                    KP_ASSERTW0(m_lChunkRest <= 2L, KP_E_SYSTEM_ERROR, null);
        }
        // -----------------------------
        else // if (m_iTrMode == HTTP_TR_CHUNK_MODE)
        {
            // KP_ASSERTQ(m_lContLen != MAXLONG, E_NOTIMPL, null, p_bThrowError);
                // Content-Length: 999
                // gali būti MAXLONG, jei pranešime nebuvo ContentLength:
                //      arba pranešimas iš viso tuščias

            KP_ASSERTQ(m_lChunkRest <= m_lContLen, KP_E_TRANS_ERR, null, p_bThrowError);

            if (SUCCEEDED(retc))
            {
                read = m_lContLen;
                if (read > buf_len - 1) read = buf_len - 1;

                m_lRestChunkLength = m_lContLen - read;

                for (long ll = 0L; (ll < read) && SUCCEEDED(retc); ll++)
                    retc = GetByte(pntd++, p_bThrowError);
            }

        } // else // if (m_iTrMode == HTTP_TR_CHUNK_MODE)

    } // if (SUCCEEDED(retc))

    if (SUCCEEDED(retc))
    {
        *p_plRead = pntd - p_pBuf;
        *pntd = Nul;

        retc = retv; // grąžinam KP_E_NEG_ANSW
    }

return (retc);
}


HRESULT KpSocket::RcvHttpRest(uchar *p_pBuf, long *p_plRead, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pBuf, E_INVALIDARG, null);
    KP_ASSERT(p_plRead, E_INVALIDARG, null);

    // -----------------------------
long buf_len = *p_plRead;
    KP_ASSERTQ(buf_len > 1, E_INVALIDARG, null, p_bThrowError);
        // paliekam vietos galiniam nuliui

uchar *pntd = null;
    if (SUCCEEDED(retc))
    {
        *p_plRead = 0;  // jau priimtų baitų sk.
        pntd = p_pBuf;  // pointeris priemimo buferyje

        if (m_iTrMode == HTTP_TR_CHUNK_MODE)
        {
            KP_ASSERTQ(m_lContLen == MAXLONG, KP_E_FILE_FORMAT, null, p_bThrowError);

        long chunk_length = m_lRestChunkLength; // m_lNextChunkLength;
            m_lRestChunkLength = 0L; // m_lNextChunkLength = 0L;

            while ((chunk_length > 0) && SUCCEEDED(retc))
            {
                // ---------- jei netilps į buferį – nukandam
                m_lRestChunkLength = 0L;
                if (chunk_length > buf_len - (pntd - p_pBuf) - 1)
                    m_lRestChunkLength = chunk_length - (buf_len -
                                                    (pntd - p_pBuf) - 1);
                // ---------- tiek skaitysim iš dabartinio chunk
                chunk_length -= m_lRestChunkLength;

                // ---------- chunk
                if (chunk_length > 0)
                    retc = GetChunk(chunk_length, &pntd, p_pBuf, buf_len,
                                m_lRestChunkLength == 0L, p_bThrowError);

                // ---------- next chunk length
                if (SUCCEEDED(retc))
                {
                    chunk_length = 0;
                    if (m_lRestChunkLength == 0L)
                        retc = GetChunkLength(&chunk_length, p_bThrowError);
                }

            } // while ((chunk_length > 0) && SUCCEEDED(retc))

            // kai paskutinis gabalas, gali likti nebent Cr/Lf (2 baitai)
            if (SUCCEEDED(retc))
                if (m_lRestChunkLength == 0L)
            //  if (m_lNextChunkLength == 0L)
                    KP_ASSERTW0(m_lChunkRest <= 2L, KP_E_SYSTEM_ERROR, null);

        }
        // ------------------------
        else // if (m_iTrMode == HTTP_TR_CHUNK_MODE)
        {
            KP_ASSERTQ(m_lContLen != MAXLONG, E_NOTIMPL, null, p_bThrowError);
                // Content-Length: 999

            if (SUCCEEDED(retc))
            {
            long read = m_lRestChunkLength;
                if (read > buf_len - 1) read = buf_len - 1;

                m_lRestChunkLength -= read;

                for (long ll = 0L; (ll < read) && SUCCEEDED(retc); ll++)
                    retc = GetByte(pntd++, p_bThrowError);
            }

        } // else // if (m_iTrMode == HTTP_TR_CHUNK_MODE)

    } // if (SUCCEEDED(retc))

    if (SUCCEEDED(retc))
    {
        *pntd = Nul;
        *p_plRead = pntd - p_pBuf;
    }

return (retc);
}


HRESULT KpSocket::RcvHttpMsgAlloc(uchar **p_ppBuf, long *p_plRead,
                                    bool p_bRcvHdr, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_ppBuf != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_plRead != NULL, E_INVALIDARG, null);

// ---------------------------------------
    *p_plRead = 0L;
long cur_buf_size = KPSOCK_RCVBUF_CHUNK_SIZE;
    KP_NEWA(*p_ppBuf, uchar, cur_buf_size + KPSOCK_RCVBUF_CHUNK_SIZE + 100);

long read = KPSOCK_RCVBUF_CHUNK_SIZE;
uchar *pntd = *p_ppBuf;

    retc = RcvHttpMsg(pntd, &read, p_bRcvHdr, p_bThrowError);
    KP_ASSERTQ(read <= KPSOCK_RCVBUF_CHUNK_SIZE, KP_E_BUFFER_OVERFLOW, null,
                                                                p_bThrowError);
    if (SUCCEEDED(retc))
    {
        pntd[read] = Nul;
        *p_plRead += read;
        pntd += read;

        do
        {
            read = KPSOCK_RCVBUF_CHUNK_SIZE;
            retc = RcvHttpRest(pntd, &read, p_bThrowError);
            KP_ASSERTQ(read <= KPSOCK_RCVBUF_CHUNK_SIZE, KP_E_BUFFER_OVERFLOW,
                                                        null, p_bThrowError);
            if ((read > 0) && SUCCEEDED(retc))
            {
                pntd[read] = Nul;
                *p_plRead += read;

                // realokuojam
            uchar *buf_ptr_sav = *p_ppBuf;
                *p_ppBuf = null;
                cur_buf_size += KPSOCK_RCVBUF_CHUNK_SIZE;
                KP_NEWA(*p_ppBuf, uchar, cur_buf_size + KPSOCK_RCVBUF_CHUNK_SIZE + 100);
                memcpy(*p_ppBuf, buf_ptr_sav, cur_buf_size);
                KP_DELETEA(buf_ptr_sav);

                pntd = *p_ppBuf + *p_plRead;
            }

        } while ((read > 0) && SUCCEEDED(retc));

    } // if (SUCCEEDED(retc))

return (retc);
}


//---------------------
// HTTP/1.1 200 OK
// Date: Mon, 19 Jul 2004 06:43:58 GMT
// Server: Apache/1.3.26 (Unix) mod_gzip/1.3.19.1a mod_throttle/3.1.2
// Last-Modified: Thu, 15 Jul 2004 16:29:04 GMT
// ETag: "23-40f6b0d0"
// Accept-Ranges: bytes
// Content-Length: 35
// Connection: close
// Content-Type: text/plain
//
// KpReg-Error: Licenzija jau užimta

HRESULT KpSocket::SendHttpMsg(const uchar *p_lpszMsg,
    const uchar *p_lpszFileType, int p_iHTTP_RetCode, bool p_bThrowError)
{
HRESULT retc = S_OK;

    KP_ASSERT((p_lpszMsg && p_lpszFileType) || (!IsHTTPdataMsg(p_iHTTP_RetCode)),
        E_INVALIDARG, null);

    KP_ASSERT(KpApp, E_POINTER, null);

    KP_ASSERTQ(m_PackedUrl.m_iProtocol == HTTP_PROT, KP_E_SYSTEM_ERROR,
        null, p_bThrowError);

    if (SUCCEEDED(retc))
    {
    const uchar *msg_ptr = (uchar *)"";
        if (p_lpszMsg) msg_ptr = p_lpszMsg;

    uchar *buf_ptr = NULL;
        KP_NEWA(buf_ptr, uchar, MAX_HTTP_HDR_LEN + strlen(msg_ptr) +
            strlen(m_PackedUrl.m_lpszServerName) + 100);

    time_t t_time;
        time(&t_time);
    uchar e_tag[MAX_LONG_DIGITS + 10];
        sprintf((char *)e_tag, "%ld", t_time);
    struct tm *tm_time = localtime(&t_time);
    uchar date_buf[WND_DATE_TEXT_LENGTH + 1];
        strcpy(date_buf, asctime(tm_time));
    uchar *pntd = strchr(date_buf, '\n');
        if (pntd) *pntd = Nul;

        if (IsHTTPdataMsg(p_iHTTP_RetCode) || (p_lpszMsg))
            sprintf((char *)buf_ptr, (const char *)HTTP_DATA_HDR_TPL, 1.1,
                p_iHTTP_RetCode, KpErrorClass::FormatErrorMessageHTTP(
                p_iHTTP_RetCode), date_buf, KpError.m_lpszProdName,
                KpApp->m_lpszProdDate, e_tag, "bytes", strlen(msg_ptr) + 2,
                p_lpszFileType);
        else if (IsHTTPcontinueMsg(p_iHTTP_RetCode))
            sprintf((char *)buf_ptr, (const char *)HTTP_CONT_HDR_TPL, 1.1,
                p_iHTTP_RetCode, KpErrorClass::FormatErrorMessageHTTP(
                p_iHTTP_RetCode), date_buf, KpError.m_lpszProdName,
                KpApp->m_lpszProdDate, e_tag, 300);
        else
            sprintf((char *)buf_ptr, (const char *)HTTP_NOTIF_HDR_TPL, 1.1,
                p_iHTTP_RetCode, KpErrorClass::FormatErrorMessageHTTP(
                p_iHTTP_RetCode), date_buf, KpError.m_lpszProdName,
                KpApp->m_lpszProdDate, e_tag);

        if (p_lpszMsg)
        {
            strcat(buf_ptr, p_lpszMsg);
            strcat(buf_ptr, "\r\n");
        }

        retc = SendMsg(buf_ptr, strlen(buf_ptr), p_bThrowError);

        KP_DELETEA(buf_ptr);

    } // if (SUCCEEDED(retc))

return (retc);
}


// ==================================================
// -----------------------------287452692419072
// Content-Disposition: form-data; name="IP"
//
// 123
// -----------------------------287452692419072
// Content-Disposition: form-data; name="Band"
//
// 456
// -----------------------------287452692419072--


// ==================================================
// Mozilla FireFox:

// POST /admins.htm HTTP/1.1
// Host: 127.0.0.1:13006
// User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.0; en-US; rv:1.8.0.10) Gecko/20070216 Firefox/1.5.0.10
// Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5
// Accept-Language: en-us,en;q=0.5
// Accept-Encoding: gzip,deflate
// Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
// Keep-Alive: 300
// Connection: keep-alive
// Referer: http://127.0.0.1:13006/admins.htm
// Content-Type: multipart/form-data; boundary=---------------------------305932780025036
// Content-Length: 246
//
// -----------------------------305932780025036
// Content-Disposition: form-data; name="ButNum"
//
// 2
// -----------------------------305932780025036
// Content-Disposition: form-data; name="IP"
//
// 2.2.2.2
// -----------------------------305932780025036--


// ======================================================
// IE 7:

// POST /admins.htm HTTP/1.1
// Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*
// Referer: http://10.2.0.24:13006/admins.htm
// Accept-Language: lt
// Content-Type: multipart/form-data; boundary=---------------------------7d73089100ca
// UA-CPU: x86
// Accept-Encoding: gzip, deflate
// User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)
// Host: 10.2.0.24:13006
// Content-Length: 239
// Connection: Keep-Alive
// Cache-Control: no-cache
//
// -----------------------------7d73089100ca
// Content-Disposition: form-data; name="ButNum"
//
// 2
// -----------------------------7d73089100ca
// Content-Disposition: form-data; name="IP"
//
// 10.2.0.54
// -----------------------------7d73089100ca--


// ======================================================
// lynx:

// POST /admins.htm HTTP/1.1
// Host: 10.2.0.24:13006
// User-Agent: Links (1.00pre12; Linux 2.6.8-2-386 i686; 80x24) (Debian pkg 0.99+1.00pre12-1sarge1)
// Accept: */*
// Accept-Charset: us-ascii, ISO-8859-1, ISO-8859-2, ISO-8859-4, ISO-8895-5, ISO-8859-7, ISO-8895-9, ISO-8859-13, ISO-8859-15, ISO-8859-16, windows-1250, windows-1251, windows-1257, cp437, cp737, cp850, cp852, cp866, x-cp866-u, x-mac, x-mac-ce, x-kam-cs, koi8-r, koi8-u, TCVN-5712, VISCII, utf-8
// Connection: Keep-Alive
// Content-Type: multipart/form-data; boundary=00000000000000000000000000000000
// Content-Length: 217
//
// --00000000000000000000000000000000
// Content-Disposition: form-data; name="ButNum"
//
//
// --00000000000000000000000000000000
// Content-Disposition: form-data; name="IP"
//
// 10.2.0.13
// --00000000000000000000000000000000--


HRESULT KpSocket::GetPostVars(KpTreeEntry<PostVarRec> **p_pVarList, bool p_bThrowError)
{
HRESULT retc = S_OK;
HRESULT retv = S_OK;

    KP_ASSERT(p_pVarList, E_INVALIDARG, null);

    do
    {
        // boundary
    uchar line_buf[KP_MAX_FILE_LIN_LEN + 1];
        retc = GetLine(line_buf, KP_MAX_FILE_LIN_LEN, p_bThrowError);

#ifdef TRACE_HTTP
if (SUCCEEDED(retc))
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, line_buf, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::GetPostVars() boundary:\n%s\n", str_buf_1);
}
#endif

        KP_ASSERTQ(strstr(line_buf, m_lpszBoundary) == line_buf,
            KP_E_MSG_FORMAT, line_buf, p_bThrowError);

        // end boundary
        if (SUCCEEDED(retc))
            if (strstr(line_buf, m_lpszEndBoundary) == line_buf) break;

        // data segment header
        if (SUCCEEDED(retc))
        {
            retc = RcvHdr(HTTP_POST_DATA_SEGM, p_bThrowError);
            if (retc == KP_E_NEG_ANSW)
            {
                // išsaugojam KP_E_NEG_ANSW
                retv = retc;
                retc = S_OK;
            }
        }

        KP_ASSERTQ(strlen(m_lpszCtrlName), KP_E_MSG_FORMAT, null, p_bThrowError);

        // value
        if (SUCCEEDED(retc))
            retc = GetLine(line_buf, KP_MAX_FILE_LIN_LEN, p_bThrowError);

#ifdef TRACE_HTTP
if (SUCCEEDED(retc))
{
static uchar str_buf_1[KP_MAX_FILE_LIN_LEN + 1];
strncpy(str_buf_1, line_buf, KP_MAX_FILE_LIN_LEN);
str_buf_1[KP_MAX_FILE_LIN_LEN] = Nul;
KP_TRACE("KpSocket::GetPostVars() value:\n%s\n", str_buf_1);
}
#endif

        KP_ASSERTQ(strstr(line_buf, m_lpszBoundary) != line_buf,
            KP_E_MSG_FORMAT, line_buf, p_bThrowError);
        KP_ASSERTQ(m_lpszCtrlName[0], KP_E_MSG_FORMAT, null, p_bThrowError);
        KP_ASSERTQ(strlen(line_buf) <= KP_MAX_FILE_LIN_LEN,
            KP_E_BUFFER_OVERFLOW, null, p_bThrowError);

        if (SUCCEEDED(retc))
        {
        PostVarRec *var_rec = NULL;
            KP_NEW(var_rec, PostVarRec());
            strcpy(var_rec->m_lpszVarName, m_lpszCtrlName);
            strcpy(var_rec->m_lpszVarData, line_buf);
        KpTreeEntry<PostVarRec> *var_entry = NULL;
            KP_NEW(var_entry, KpTreeEntry<PostVarRec>(var_rec));

            if (*p_pVarList) (*p_pVarList)->PutToEnd(var_entry);
            else *p_pVarList = var_entry;
        }

    } while (SUCCEEDED(retc));

    if (SUCCEEDED(retc)) retc = retv; // grąžinam KP_E_NEG_ANSW

return (retc);
}
