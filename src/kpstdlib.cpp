/* ===============================================
 *
 * kpstdlib.cpp
 *
 *    common tools for all Kp C++ projects
 *
 * 2013-02-22  mp  initial creation
 *
 */

// -----------------------------
#include "envir.h"

#include <stdio.h>
#include <string.h>
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
#include "kpcapp.h"

using namespace std;


// ========================================= KpLib 
KpErrorClass KpError((const UCHAR *)"kplib");
KpCommonApp *KpApp = NULL;
KpCommonApp *KpAppAlloc = NULL; // pointer to locally here allocated KpApp 

void KpInit(const UCHAR *ProdName, const void *pStackTop)
{
    try
    {
        if (KpApp == NULL) // allocate just in case when not allocated in the main application
        {
            KP_NEW(KpAppAlloc, KpCommonApp(ProdName, 0));
            KpApp = KpAppAlloc;
        }
        KpApp->Init(
#ifdef __WIN32__
            GetModuleHandle(NULL), (const UCHAR *)GetCommandLine(),
#else
// TODO Linux: get cmd line
            0, ProdName,
#endif             
            pStackTop);
    }
    catch(const KpException *e)
    {
        KP_CATCH(*e);
    }
    catch(const exception &e)
    {
        KP_CATCH(e);
    }
    catch(...)
    {
        KP_ERROR(KP_E_UNHANDLED_EXCEPTION, null);
    }
}


void KpClose(void)
{
    try
    {
        KP_ASSERT(KpApp != NULL, E_POINTER, null);
        KpApp->Close();
        if(KpAppAlloc != NULL)
        {
            KP_DELETE(KpAppAlloc /* KpApp */); // delete just in case when allocated not in the main application
            KpApp = KpAppAlloc;
        }
    }
    catch(const KpException *e)
    {
        KP_CATCH(*e);
    }
    catch(const exception &e)
    {
        KP_CATCH(e);
    }
    catch(...)
    {
        KP_ERROR(KP_E_UNHANDLED_EXCEPTION, null);
    }
}


// ========================================= malloc

// -----------------------------
// memory allocation control
#ifdef KP_ALLOC_SAFE
KpHeapClass KpHeap;

int KpHeapClass::SearchHeapEntry(const void *pPtr) // -1 – did not find
{
int ret_val = -1;

   for(int ii = 0; ii < m_iCurKpHeapIx; ii++)
      if(m_KpHeapArray[ii].m_pAddress == pPtr)
      {
         ret_val = ii;
         break;
      }

return(ret_val);
}


void KpHeapClass::InsertHeapPtr(const void *pNewPtr, bool bArrayFl)
{
HRESULT retc = S_OK;

UCHAR msg_out[MAX_LONG_HEX_DIGITS + 5];
   sprintf((CHAR *)msg_out, "%lx", (unsigned long)pNewPtr);

int ix = SearchHeapEntry(pNewPtr);
   KP_ASSERTW(ix < 0, KP_E_DOUBLE_CALL, null);

   KP_ASSERTW(m_iCurKpHeapIx < KP_HEAP_SIZE - 1, KP_E_BUFFER_OVERFLOW, msg_out);
   if(SUCCEEDED(retc))
   {
      m_KpHeapArray[m_iCurKpHeapIx].m_pAddress = pNewPtr;
      m_KpHeapArray[m_iCurKpHeapIx].m_bArrayFl = bArrayFl;
      m_iCurKpHeapIx++;
   }
}


HRESULT KpHeapClass::RemoveHeapPtr(const void *pDelPtr, bool bArrayFl)
{
HRESULT retc = S_OK;

UCHAR msg_out[MAX_LONG_HEX_DIGITS + 5];
   sprintf((CHAR *)msg_out, "%lx", (DWORD)pDelPtr);

int ix = SearchHeapEntry(pDelPtr);
   KP_ASSERTW(ix >= 0, KP_E_SYSTEM_ERROR, msg_out);
   KP_ASSERTW(m_KpHeapArray[ix].m_bArrayFl == bArrayFl, KP_E_SYSTEM_ERROR, msg_out);
// if(FAILED(retc)) KpError.StackDump();

   if((ix >= 0) /* SUCCEEDED(retc) */)
   {
      memmove(&(m_KpHeapArray[ix]), &(m_KpHeapArray[ix + 1]), (m_iCurKpHeapIx - ix - 1) * sizeof(KpHeapEntry));
      m_iCurKpHeapIx--;
   }

return(retc);
}
#endif // #ifdef KP_ALLOC_SAFE
