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
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kperrno.h"
#include "kpstdlib.h"
#include "kpmsg.h"
#include "kperr.h"

// ----------------------------------------- malloc

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
   sprintf((CHAR *)msg_out, "%x", pDelPtr);

int ix = SearchHeapEntry(pDelPtr);
   KP_ASSERTW(ix >= 0, KP_E_SYSTEM_ERROR, msg_out);
   KP_ASSERTW(m_KpHeapArray[ix].m_bArrayFl == bArrayFl, KP_E_SYSTEM_ERROR, msg_out);
   if(FAILED(retc)) KpError.StackDump();

   if((ix >= 0) /* SUCCEEDED(retc) */)
   {
      memmove(&(m_KpHeapArray[ix]), &(m_KpHeapArray[ix + 1]), (m_iCurKpHeapIx - ix - 1) * sizeof(KpHeapEntry));
      m_iCurKpHeapIx--;
   }

return(retc);
}
#endif // #ifdef KP_ALLOC_SAFE
