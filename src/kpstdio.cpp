/* ---------------------------------------------------
 *
 * kpstdio.cpp
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

// --------------------------------------
#include "envir.h"

#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptree.h"
#include "kpstdio.h"


void FnameSplit
(
    uchar *lpszDiskBuf,
    uchar *lpszPathBuf,
    uchar *lpszFNameBuf,
    uchar *lpszFTypeBuf,
    const uchar *lpszFullName
)
{
    KpStdIo::TvFnameSplit(lpszDiskBuf, lpszPathBuf, lpszFNameBuf, lpszFTypeBuf, lpszFullName);
}


void KpStdIo::TvFnameSplit
(
uchar *lpszDiskBuf,
uchar *lpszPathBuf,
uchar *lpszFNameBuf,
uchar *lpszFTypeBuf,
const uchar *lpszFullName
)
{
   KP_ASSERT(lpszDiskBuf && lpszPathBuf && lpszFNameBuf &&
      lpszFTypeBuf && lpszFullName, E_INVALIDARG, null);

   KP_ASSERT(strlen(lpszFullName) < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, lpszFullName);

uchar str_buf[KP_MAX_FNAME_LEN + 1];
   strcpy(str_buf, lpszFullName);

uchar *disk_ptr;
uchar *path_ptr;
uchar *fnam_ptr;
uchar *typ_ptr;
uchar *pnts;
   disk_ptr = pnts = path_ptr = fnam_ptr = typ_ptr = str_buf;

   do
   {
      if (*pnts == ':') path_ptr = pnts + 1;
      if ((*pnts == '\\') || (*pnts == '/')) fnam_ptr = pnts + 1;
      if (*pnts == '.') typ_ptr = pnts;
      pnts++;
   } while (*pnts);

// type
   if (typ_ptr <= fnam_ptr) typ_ptr=(uchar *)"";
   else *(typ_ptr++) = Nul;
   
   KP_ASSERT(strlen(typ_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszFTypeBuf, typ_ptr);

// fname
   if (fnam_ptr < path_ptr) fnam_ptr = path_ptr;
   KP_ASSERT(strlen(fnam_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszFNameBuf, fnam_ptr);

// path
   if (fnam_ptr == path_ptr) strcpy(lpszPathBuf, KP_CUR_DIR_STR);
   else /* if (fnam_ptr > path_ptr) */
   {
      *fnam_ptr-- = Nul;
      if ((*fnam_ptr=='\\') || (*fnam_ptr=='/')) *fnam_ptr = Nul;
      else KP_THROW(KP_E_SYSTEM_ERROR, null);

      KP_ASSERT(strlen(path_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
      strcpy(lpszPathBuf, path_ptr);
   }

// disk
   *path_ptr = Nul;
   KP_ASSERT(strlen(disk_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszDiskBuf, disk_ptr);
}


// -----------------------------------------
void KpFileDesc::InitMembers(void)
{
#ifdef Debug
printf("KpFileDesc::InitMembers(%x)\n", this);
#endif

    m_pFile = NULL;
    m_lpszFileName[0] = Nul;
#ifdef KPSTDIO_FULL_LOG
    m_lpszLogFileName[0] = Nul;
#endif
}


KpFileDesc::KpFileDesc(void)
{
    InitMembers();
}


KpFileDesc::KpFileDesc(const FILE *pFile, const uchar *lpszFileName)
{
    InitMembers();

    KP_ASSERT((pFile != NULL) && (lpszFileName != null), E_INVALIDARG, null);
    
    m_pFile = pFile;
    
    KP_ASSERT(strlen(lpszFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(m_lpszFileName, lpszFileName);
    
    strlwr(m_lpszFileName);

#ifdef KPSTDIO_FULL_LOG
uchar disk[KP_MAX_FNAME_LEN + 1];
uchar path[KP_MAX_FNAME_LEN + 1];
uchar fname[KP_MAX_FNAME_LEN + 1];
uchar ftype[KP_MAX_FNAME_LEN + 1];
    KpStdIo::TvFnameSplit(disk, path, fname, ftype, m_lpszFileName); 
    
    KP_ASSERT(strlen(fname) + 1 + strlen(ftype) + strlen(KPTRC_LOG_SUFF) + strlen(KP_LOG_EXT) <= 
        KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(m_lpszLogFileName, fname);
    strcat(m_lpszLogFileName, ".");
    strcat(m_lpszLogFileName, ftype);
    strcat(m_lpszLogFileName, KPTRC_LOG_SUFF);
    strcat(m_lpszLogFileName, KP_LOG_EXT);
    
    remove((const char *)m_lpszLogFileName);
#endif
}


// -----------------------------------------
void KpFileDesc::PullData(const KpFileDesc *pDescObj)
{
    KP_ASSERT(pDescObj != NULL, E_INVALIDARG, null);

    m_pFile = pDescObj->m_pFile;
    strcpy(m_lpszFileName, pDescObj->m_lpszFileName);
#ifdef KPSTDIO_FULL_LOG
    strcpy(m_lpszLogFileName, pDescObj->m_lpszLogFileName);
#endif
}


// -----------------------------------------
#ifdef KPSTDIO_FULL_LOG
void KpFileDesc::PutLogMessage(const uchar *lpszFmt, va_list Args)
{
uchar *out_str = null;   
    KP_NEWA(out_str, uchar, KP_MAX_FILE_LIN_LEN + strlen(lpszFmt) * 10 + 1);
    vsprintf((char *)out_str, (const char *)lpszFmt, Args);
    strcat(out_str, "\n");

FILE *log_file = fopen((const char *)m_lpszLogFileName, "a");
    KP_ASSERT(log_file != NULL, KP_E_DIR_ERROR, m_lpszLogFileName);
     
    fputs((const char *)out_str, log_file);
    
    fclose(log_file);
    
    KP_DELETEA(out_str);
}
#endif



// -----------------------------------------
KpFileDescList::KpFileDescList(void)
{
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::KpFileDescList()");
#endif
    m_pFileList = NULL;
}


KpFileDescList::~KpFileDescList()
{
// ----------------
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::~KpFileDescList()");
#endif

KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
#ifdef Debug
        KpError.PutLogMessage("KpFileDescList::~KpFileDescList(): deleting object: %s", desc_ptr->m_lpszFileName);
#endif
        desc_ptr->LogLastCh();

        cur_entry = cur_entry->GetFirstChild();
    }

// ----------------
    KP_DELETE(m_pFileList);
}


// -----------------------------------------
KpFileDesc *KpFileDescList::KpFileDescFactory(const FILE *pFile, const uchar *lpszFileName)
{
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::KpFileDescFactory()");
#endif

KpFileDesc *desc_obj_ptr = NULL;
    KP_NEW(desc_obj_ptr, KpFileDesc(pFile, lpszFileName));

return(desc_obj_ptr);
}


// -----------------------------------------
void KpFileDescList::RegNewFile(const FILE *pFile, const uchar *lpszFileName)
{
HRESULT retc = S_OK;
KpFileDesc *desc_obj_ptr = FindFile(pFile);
    KP_ASSERTW(desc_obj_ptr == NULL, KP_E_DOUBLE_CALL, lpszFileName);
    if(FAILED(retc))
    { 
        KpError.PutLogMessage("KpFileDescList::RegNewFile(): failas jau yra: %lx %s", (DWORD)pFile, desc_obj_ptr->m_lpszFileName);  
        DelFile(pFile);
    }

    desc_obj_ptr = KpFileDescFactory(pFile, lpszFileName);

KpTreeEntry<KpFileDesc> *new_node = NULL;
    KP_NEW(new_node, KpTreeEntry<KpFileDesc>(desc_obj_ptr, NULL));    

    if (m_pFileList == NULL) m_pFileList = new_node;
    else m_pFileList->PutToEnd(new_node);
    new_node = NULL;
}


// -----------------------------------------
void KpFileDescList::DelFile(const FILE *pFile)
{
uchar out_str[MAX_LONG_HEX_DIGITS + 10];
    sprintf((char *)out_str, "%lx", (DWORD)pFile);

HRESULT retc = S_OK;
KpTreeEntry<KpFileDesc> **node_ptr_ptr = NULL;
KpFileDesc *desc_obj_ptr = FindFile(pFile, &node_ptr_ptr);
    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, out_str);
    if (SUCCEEDED(retc))
    {
        desc_obj_ptr->LogLastCh();

        KP_ASSERT(node_ptr_ptr != NULL, KP_E_NO_FILE, out_str);
        KP_ASSERT(*node_ptr_ptr != NULL, KP_E_NO_FILE, out_str);

KpTreeEntry<KpFileDesc> tmp_obj(NULL, NULL);
        tmp_obj.DeleteKpTreeNode(node_ptr_ptr);
//      KpTreeEntry<TeXtrcFileDesc>::DeleteKpTreeNode(node_ptr_ptr);
    } 
}


// -----------------------------------------
KpFileDesc *KpFileDescList::FindFile(const FILE *pFile, KpTreeEntry<KpFileDesc> ***pppNodePtr)
{
KpFileDesc *desc_obj_ptr = NULL;

    if (pppNodePtr != NULL) *pppNodePtr = &m_pFileList;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
        if (desc_ptr->m_pFile == pFile)
        {
            desc_obj_ptr = desc_ptr; 
            break;
        }
        
        if (pppNodePtr != NULL) *pppNodePtr = &(cur_entry->m_pFirstChild);
        cur_entry = cur_entry->GetFirstChild();
    }

return(desc_obj_ptr);
}

// -----------------------------------------
void KpFileDescList::UpdateFile(const KpFileDesc *pDescObj)
{
HRESULT retc = S_OK;

    KP_ASSERT(pDescObj != NULL, E_INVALIDARG, null);

KpFileDesc *desc_obj_ptr = NULL;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    while (cur_entry != NULL)
    {
        desc_obj_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_obj_ptr != NULL, E_POINTER, null);
        
        if (desc_obj_ptr->m_pFile == pDescObj->m_pFile)
        {
            // radom – deskriptorių updeitinam, o desc_obj_ptr paliekam nustatytą
            desc_obj_ptr->PullData(pDescObj);
            break;
        }
        else
        {
            // neradom – valom desc_obj_ptr
            desc_obj_ptr = NULL;
        }
        
        cur_entry = cur_entry->GetFirstChild();
    }

    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, null); // neradom
}


// -----------------------------------------
#ifdef KPSTDIO_FULL_LOG
void KpFileDescList::PutLogMessage(const FILE *pFile, const uchar *lpszFmt, va_list Args)
{
HRESULT retc = S_OK;
uchar out_str[MAX_LONG_HEX_DIGITS + 10];
    sprintf((char *)out_str, "%lx", pFile);
KpFileDesc *desc_obj_ptr = FindFile(pFile);
    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, out_str);
    if (FAILED(retc)) KpError.PutLogMessage(lpszFmt, Args);
    else
        desc_obj_ptr->PutLogMessage(lpszFmt, Args);
}
#endif
