/* ----------------------------------------------------
 *
 * kptree.cpp
 *  
 *    realization of KpTreeEntry 
 *
 */   


// ======================================= definitions
#include "envir.h"

#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptree.h"



// ========================================
// ----------------------
KpTreeEntry::KpTreeEntry(void)
{
   Constructor("", 1, NULL);
}


// ----------------------
KpTreeEntry::KpTreeEntry(KpTreeEntry *pFath)
{
   Constructor("", 1, pFath);
}


// ----------------------
KpTreeEntry::KpTreeEntry(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType)
{
   Constructor(lpRecord, iSize, pFath, iRecType);
}


// ----------------------
KpTreeEntry::KpTreeEntry(const unsigned char *lpszString, KpTreeEntry *pFath)
{
   KP_ASSERT(lpszString != null, E_INVALIDARG, null);
   Constructor(lpszString, strlen(lpszString) + 1, pFath, KpRecType_Text);
}


// ----------------------
KpTreeEntry::KpTreeEntry(const char *lpszString, KpTreeEntry *pFath)
{
   KP_ASSERT(lpszString != NULL, E_INVALIDARG, null);
   Constructor(lpszString, strlen(lpszString) + 1, pFath, KpRecType_Text);
}


// ----------------------
KpTreeEntry::KpTreeEntry(const KpChStr *pKpStr, KpTreeEntry *pFath)
{
   KP_ASSERT(pKpStr != NULL, E_INVALIDARG, null);
   Constructor(pKpStr, (pKpStr->Len() + 1) * sizeof(*pKpStr), pFath, KpRecType_KpText);
}


// ----------------------
void KpTreeEntry::Constructor(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType)
{
   m_lpRecord = NULL;
   m_iRecSize = 0;
   m_iRecType = iRecType;

   m_pFirstChild = NULL;
   m_pPrevBrother = NULL;
   m_pNextBrother = NULL;
   m_pFather = pFath;

   m_iStatus = KpNodeVisible | KpNodeHasChildren | KpNodeExpanded; // KpHighChildlessNode;

   KP_ASSERT(lpRecord != NULL, E_INVALIDARG, null);

   m_iRecSize = iSize + 1;
   KP_NEWA(m_lpRecord, unsigned char, m_iRecSize);
   memcpy(m_lpRecord, lpRecord, m_iRecSize - 1);
   m_lpRecord[m_iRecSize - 1] = Nul;
}


// ----------------------
KpTreeEntry::~KpTreeEntry()
{
KpTreeEntry *next_br = NULL;

    while (m_pNextBrother != NULL)
    {
        next_br = NULL;
        next_br = m_pNextBrother->GetNextBrother();
        m_pNextBrother->SetNextBrother(NULL);
        m_pNextBrother->SetPrevBrother(NULL);

        KP_DELETE(m_pNextBrother);
        if (next_br != NULL) next_br->SetPrevBrother(this);
        SetNextBrother(next_br);
    }

    KP_DELETE(m_pFirstChild);

	KP_DELETEA(m_lpRecord);
}


// ----------------------
void KpTreeEntry::PutToEnd(const void *lpRecord, int iSize, KpRecType iRecType)
{
KpTreeEntry *cur_entry=this;
KpTreeEntry *next_entry;

    do
    {
        next_entry = cur_entry->GetFirstChild();
        if (next_entry != NULL) cur_entry = next_entry;
    } while (next_entry!=NULL);

    KP_NEW(next_entry, KpTreeEntry(lpRecord, iSize, cur_entry, iRecType));

    cur_entry->SetFirstChild(next_entry);
}


// ----------------------
void KpTreeEntry::PutToEnd(const unsigned char *lpszString)
{
    KP_ASSERT(lpszString != NULL, E_INVALIDARG, null);
    PutToEnd(lpszString, strlen(lpszString) + 1, KpRecType_Text);
}


// ----------------------
void KpTreeEntry::PutToEnd(const char *lpszString)
{
    KP_ASSERT(lpszString != NULL, E_INVALIDARG, null);
    PutToEnd(lpszString, strlen(lpszString) + 1, KpRecType_Text);
}


// ----------------------
void KpTreeEntry::PutToEnd(const KpChStr *pKpStr)
{
    KP_ASSERT(pKpStr != NULL, E_INVALIDARG, null);
    PutToEnd(pKpStr, (pKpStr->Len() + 1) * sizeof(*pKpStr), KpRecType_KpText);
}


//-----------------------------------
void KpTreeEntry::SetFather0(KpTreeEntry *pFath)
{
   m_pFather = pFath;

// recursion
   if (m_pNextBrother != NULL) m_pNextBrother->SetFather0(pFath);
}


//-----------------------------------
void KpTreeEntry::SetFather(KpTreeEntry *pFath)
{
    KP_ASSERT(m_pPrevBrother == NULL, KP_E_SYSTEM_ERROR, null);
    SetFather0(pFath);
}


//-----------------------------------
void KpTreeEntry::SetFirstChild(KpTreeEntry *pChild)
{
KpTreeEntry *father = NULL;
KpTreeEntry *prev_brother = NULL;
    
    if (pChild != NULL)
    {
        father = pChild->GetFather();
        KP_ASSERT(father == this, KP_E_SYSTEM_ERROR, null);

        prev_brother = pChild->GetPrevBrother();
        KP_ASSERT(prev_brother == NULL, KP_E_SYSTEM_ERROR, null);
    }

    m_pFirstChild = pChild;
}


//-----------------------------------
void KpTreeEntry::ConnectChild(KpTreeEntry *pChild)
{
    if (pChild != NULL)
    {
        pChild->SetPrevBrother(NULL);
        pChild->SetFather(this);
    }

    SetFirstChild(pChild);
}


//-----------------------------------
void KpTreeEntry::SetPrevBrother(KpTreeEntry *pPrevBr)
{
KpTreeEntry *father = NULL;

    if (pPrevBr != NULL)
    {
        father = pPrevBr->GetFather();
        KP_ASSERT(father == m_pFather, KP_E_SYSTEM_ERROR, null);
    }

    m_pPrevBrother = pPrevBr;
}


//-----------------------------------
void KpTreeEntry::SetNextBrother(KpTreeEntry *pNextBr)
{
KpTreeEntry *father = NULL;

    if (pNextBr != NULL)
    {
        father = pNextBr->GetFather();
        KP_ASSERT(father == m_pFather, KP_E_SYSTEM_ERROR, null);
    }

    m_pNextBrother = pNextBr;
}


//-----------------------------------
void KpTreeEntry::ConnectBrother(KpTreeEntry *pNextBr)
{
    if (pNextBr != NULL)
    {
        pNextBr->SetPrevBrother(NULL);
        pNextBr->SetFather(m_pFather);
        pNextBr->SetPrevBrother(this);
    }

    SetNextBrother(pNextBr);
}


//-----------------------------------
void KpTreeEntry::InsertChild(KpTreeEntry *pChild)
{
KpTreeEntry *prev_brother = NULL;
KpTreeEntry *next_brother = NULL;

    KP_ASSERT(pChild != NULL, E_INVALIDARG, null);
    pChild->SetFather(this);
    prev_brother = pChild->GetPrevBrother();
    next_brother = pChild->GetNextBrother();
    KP_ASSERT((prev_brother == NULL) && (next_brother == NULL), E_INVALIDARG, null);

    pChild->ConnectBrother(m_pFirstChild);
    ConnectChild(pChild);
}


//-----------------------------------
void KpTreeEntry::AppendChild(KpTreeEntry *pChild)
{
KpTreeEntry *prev_brother = NULL;
KpTreeEntry *cur_brother = NULL;
KpTreeEntry *next_brother = NULL;

    KP_ASSERT(pChild != NULL, E_INVALIDARG, null);

    pChild->SetFather(this);

    prev_brother = pChild->GetPrevBrother();
    next_brother = pChild->GetNextBrother();
    KP_ASSERT((prev_brother == NULL) && (next_brother == NULL), E_INVALIDARG, null);

    if (m_pFirstChild == NULL) ConnectChild(pChild);
    else
    {
        next_brother = m_pFirstChild;
        do
        {
            cur_brother = next_brother;
            next_brother = cur_brother->GetNextBrother();
        } while (next_brother != NULL);

        cur_brother->ConnectBrother(pChild);
    }
}


//-----------------------------------
void KpTreeEntry::AppendBrother(KpTreeEntry *pBrother)
{
KpTreeEntry *prev_brother = NULL;
KpTreeEntry *cur_brother = NULL;
KpTreeEntry *next_brother = NULL;

    KP_ASSERT(pBrother != NULL, E_INVALIDARG, null);

    prev_brother = pBrother->GetPrevBrother();
    next_brother = pBrother->GetNextBrother();
    KP_ASSERT((prev_brother == NULL) && (next_brother == NULL), E_INVALIDARG, null);

    next_brother = this;
    do
    {
        cur_brother = next_brother;
        next_brother = cur_brother->GetNextBrother();
    } while (next_brother != NULL);

    cur_brother->ConnectBrother(pBrother);
}


// ----------------------
void KpTreeEntry::SearchTreeEntry(const void *pPattern, CompareFuncPtr pfCompare, KpTreeEntry **ppEntryPtr, KpTreeEntry **ppFatherPtr)
{
KpTreeEntry *list_ptr = NULL;

    KP_ASSERT(ppEntryPtr != NULL, E_INVALIDARG, null);

    if (ppFatherPtr != NULL) *ppFatherPtr = NULL;

    *ppEntryPtr = NULL;
    list_ptr = this;
    while (list_ptr != NULL)
    {
        if (pfCompare(list_ptr->GetValue(), pPattern) == 0)
        {
            *ppEntryPtr = list_ptr;
            break;
        }
        if (ppFatherPtr) *ppFatherPtr = list_ptr;

        if (list_ptr->m_pFirstChild != NULL) 
            list_ptr->m_pFirstChild->SearchTreeEntry(pPattern, pfCompare, ppEntryPtr, ppFatherPtr);
        if (*ppEntryPtr != NULL) break;

        list_ptr = list_ptr->m_pNextBrother;
    }
}


// ----------------------
void KpTreeEntry::GetEntryPtr(int *piSel, KpTreeEntry **ppEntryPtr, int iLevel, const KpTreeEntry *pCurGrandFather)
{
KpTreeEntry *loop_brother = NULL;
KpTreeEntry *first_child = NULL;
int status = 0;

    KP_ASSERT((ppEntryPtr != NULL) && (piSel != NULL) && 
        (iLevel >= 0) && (iLevel < KpNodeNumOfLevels), E_INVALIDARG, null);

    *ppEntryPtr = NULL;

    loop_brother = this;
    if (loop_brother != NULL) do
    {
        status = loop_brother->m_iStatus >> (KpNodeLevelShift * iLevel);

        if ((status & KpNodeVisible) != 0) (*piSel)--;

        if (*piSel == (-1))
        {
            *ppEntryPtr = loop_brother;
            break;
        }
        else
        {
// recursion through children of children
            if (
                (status & KpNodeExpanded) &&
                (((status & KpNodeVisible) != 0) || (loop_brother==pCurGrandFather))
              )
            {
                first_child = loop_brother->GetFirstChild();
                if (first_child != NULL) first_child->GetEntryPtr(piSel, ppEntryPtr, iLevel, pCurGrandFather);
            }
        }

        if (loop_brother == pCurGrandFather) loop_brother = NULL;
        else loop_brother = loop_brother->GetNextBrother();

   } while (loop_brother && (*piSel >= 0));

// recursion on brothers
// if (pNextBrother != NULL) pNextBrother->GetEntryPtr(piSel, ppEntryPtr, iLevel, pCurGrandFather);
}


// ----------------------
void KpTreeEntry::DeleteChild(void)
{
KpTreeEntry *child_child_ptr = NULL;

    if (m_pFirstChild != NULL)
    {
        child_child_ptr = m_pFirstChild->GetFirstChild();

        m_pFirstChild->SetFirstChild(NULL);
        KP_DELETE(m_pFirstChild);
        m_pFirstChild = child_child_ptr;
        if (m_pFirstChild != NULL) m_pFirstChild->SetFather(this);
    }
}


// ----------------------
void DeleteKpTreeEntry(KpTreeEntry *pEntryPtr)
{
    KP_ASSERT(pEntryPtr != NULL, E_POINTER, null);

KpTreeEntry *next_brother = NULL;
    next_brother = pEntryPtr->GetNextBrother();

KpTreeEntry *prev_brother = NULL;
    prev_brother = pEntryPtr->GetPrevBrother();

KpTreeEntry *father = NULL;
    father = pEntryPtr->GetFather();

    if (next_brother != NULL) next_brother->SetPrevBrother(prev_brother);
    if (prev_brother != NULL) prev_brother->SetNextBrother(next_brother);

// pirmas vaikas – nustatom naujà tëvo pirmà vaikà
   if ((prev_brother == NULL) && (father != NULL)) father->SetFirstChild(next_brother);

   pEntryPtr->SetNextBrother(NULL);
   pEntryPtr->SetPrevBrother(NULL);
   KP_DELETE(pEntryPtr);
}


// ----------------------
int KpTreeEntry::GetValSize(void) const
{
int size = m_iRecSize;
   
   if (size > 0) size--;
    
return(size);
}


// ----------------------
void KpTreeEntry::SetValue(const void *pValue, int iValSize)
{
   KP_ASSERT(pValue != NULL, E_INVALIDARG, null);
   KP_ASSERT(iValSize >= 0, E_INVALIDARG, null);
   
   KP_ASSERT(iValSize < m_iRecSize, KP_E_BUFFER_OVERFLOW, null); // vienas baitas gale nuliui

   memcpy(m_lpRecord, pValue, iValSize);
   m_lpRecord[iValSize] = Nul;
}


// ----------------------
void KpTreeEntry::SetNewValue(const void *pValue, int iValSize)
{
   KP_ASSERT(pValue != NULL, E_INVALIDARG, null);

   KP_DELETEA(m_lpRecord);

   m_iRecSize = iValSize + 1;
   KP_NEWA(m_lpRecord, unsigned char, m_iRecSize);

   SetValue(pValue, iValSize);
}


// ----------------------
void KpTreeEntry::SetNewValue(const unsigned char *lpszValue)
{
   KP_ASSERT(lpszValue != NULL, E_INVALIDARG, null);

   SetNewValue(lpszValue, strlen(lpszValue) + 1);
   m_iRecType = KpRecType_Text;
}


// ----------------------
void KpTreeEntry::SetNewValue(const KpTextBmp *pValue)
{
    KP_ASSERT(pValue != NULL, E_INVALIDARG, null);

    SetNewValue(pValue, sizeof(KpTextBmp));
    m_iRecType = KpRecType_TextBmp;
}


// ----------------------
void KpTreeEntry::SetNewValue(const KpBmpBmp *pValue)
{
    KP_ASSERT(pValue != NULL, E_INVALIDARG, null);

    SetNewValue(pValue, sizeof(KpTextBmp));
    m_iRecType = KpRecType_BmpBmp;
}


// ----------------------
void KpTreeEntry::CountEntries(int *piCnt,  int iLevel, KpTreeEntry *pCurGrandFather)
{
KpTreeEntry *loop_brother = NULL;
KpTreeEntry *first_child = NULL;
int status = 0;

    if ((piCnt != NULL) && (iLevel >= 0) && (iLevel < KpNodeNumOfLevels), E_INVALIDARG, null);

    loop_brother = this;
    if (loop_brother != NULL) do
    {
        status = loop_brother->m_iStatus >> (KpNodeLevelShift * iLevel);

        if ((status & KpNodeVisible) != 0)
            (*piCnt)++;

// recursion through children of children
        if (
            (status & KpNodeExpanded) &&
            (((status & KpNodeVisible) != 0) || (loop_brother==pCurGrandFather))
          )
        {
            first_child = loop_brother->GetFirstChild();
            if (first_child != NULL) first_child->CountEntries(piCnt, iLevel, pCurGrandFather);
        }

        if (loop_brother == pCurGrandFather) loop_brother = NULL;
        else loop_brother = loop_brother->GetNextBrother();

    } while (loop_brother != NULL);

// recursion on brothers
// if (pNextBrother != NULL) pNextBrother->CountEntries(piCnt, iLevel, pCurGrandFather);
}


// ----------------------
void KpTreeEntry::Sort(CompareFuncPtr pfCompare)
{
KpTreeEntry *pt1 = NULL;
KpTreeEntry *pt2 = NULL;
KpTreeEntry *next_entry = NULL;

    pt1 = this;
    while (pt1 != NULL)
    {
        pt2 = pt1->GetFirstChild();
        while (pt2 != NULL)
        {
            if ((*pfCompare)(pt1->GetValue(), pt2->GetValue()) > 0)
                ChangeKpTreeNodes(pt1, pt2);

            next_entry = pt2->GetFirstChild();
            pt2 = next_entry;
        }
        next_entry = pt1->GetFirstChild();
        pt1 = next_entry;
    }
}


void KpTreeEntry::SortPtr(ComparePtrFuncPtr pfCompare)
{
KpTreeEntry *pt1 = NULL;
KpTreeEntry *pt2 = NULL;
KpTreeEntry *next_entry = NULL;
void *val_ptr_1 = NULL;
void *val_ptr_2 = NULL;

    pt1 = this;
    while (pt1 != NULL)
    {
        pt2 = pt1->GetFirstChild();

        while (pt2 != NULL)
        {
            val_ptr_1 = pt1->GetValue();
            val_ptr_2 = pt2->GetValue();
            if ((*pfCompare)(&val_ptr_1, &val_ptr_2) > 0)
                ChangeKpTreeNodes(pt1, pt2);

            next_entry = pt2->GetFirstChild();
            pt2 = next_entry;
        }
        next_entry = pt1->GetFirstChild();
        pt1 = next_entry;
    }
}


// --------------------------------------------------
void KpTreeEntry::TestNodeLoop(KpTreeEntry **apNodesArray, int *piNumOfNodes)
{
KpTreeEntry *cur_node = NULL;
KpTreeEntry *loop_brother = NULL;
int ii;

    KP_ASSERT((apNodesArray != NULL) && (piNumOfNodes != NULL), E_INVALIDARG, null);

// loop on brothers
    loop_brother = this;
    while (loop_brother != NULL)
    {
        for (ii = 0; (ii < *piNumOfNodes); ii++)
            KP_ASSERT(apNodesArray[ii] != loop_brother, KP_E_SYSTEM_ERROR, null);

        KP_ASSERT(*piNumOfNodes < XL_ND_MaxNumOfNodes, KP_E_BUFFER_OVERFLOW, null);
        apNodesArray[(*piNumOfNodes)++] = loop_brother;

        cur_node = loop_brother->GetFirstChild();

// recursion through children of children first
        if (cur_node != NULL) cur_node->TestNodeLoop(apNodesArray, piNumOfNodes);

        loop_brother = loop_brother->GetNextBrother();

   } // while (loop_brother != NULL)

// recursion on brothers
// if (pNextBrother != NULL) pNextBrother->TestNodeLoop();
}


// --------------------------------------------------
void KpTreeEntry::TestNode(void)
{
int num_of_nodes = 0;
KpTreeEntry **nodes_array = NULL;

   KP_NEWA(nodes_array, KpTreeEntry *, XL_ND_MaxNumOfNodes);

   TestNodeLoop(nodes_array, &num_of_nodes);

   KP_DELETEA(nodes_array);
}


// --------------------------------------------------
void KpTreeEntry::FormListBox(HWND hListBox)
{
KpTreeEntry *loop_brother = NULL;
KpTreeEntry *first_child = NULL;
const UCHAR *cur_str = null;
int retv;

    loop_brother = this;
    while (loop_brother != NULL)
    {
        cur_str = (const UCHAR *)loop_brother->GetValue();
        if (cur_str == NULL) cur_str = (const UCHAR *)"";

        retv = SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)cur_str);
        KP_ASSERT(retv != CB_ERR, KP_E_SYSTEM_ERROR, null);
        KP_ASSERT(retv != CB_ERRSPACE, KP_E_OUTOFMEM, null); 

// recursion through children of children
        first_child = loop_brother->GetFirstChild();

        if (first_child != NULL) first_child->FormListBox(hListBox);

        loop_brother = loop_brother->GetNextBrother();

    } // while (loop_brother != NULL)

// recursion on brothers
//  if (pNextBrother != NULL) pNextBrother->FormListBox(hListBox);
}


// --------------------------------------------------
void KpTreeEntry::InitNodeStatus(void)
{
KpTreeEntry *first_child = NULL;
KpTreeEntry *loop_brother = NULL;

// loop on brothers
    loop_brother = this;
    while (loop_brother != NULL)
    {
        first_child = loop_brother->GetFirstChild();
        loop_brother->m_iStatus = 0;

        for (int ii = 0; ii < KpNodeNumOfLevels; ii++)
        {
            loop_brother->m_iStatus |= KpNodeVisible << (KpNodeLevelShift * ii);
            if (first_child != NULL) loop_brother->m_iStatus |= (KpNodeHasChildren | KpNodeExpanded) << (KpNodeLevelShift * ii);
        }

// recursion on children
        if (first_child != NULL) first_child->InitNodeStatus();
        loop_brother = loop_brother->GetNextBrother();
    }
}


// --------------------------------------------------
void KpTreeEntry::Deselect(void)
{
KpTreeEntry *first_child = NULL;
KpTreeEntry *loop_brother = NULL;

// loop on brothers
// ðiaip nereikëtø – chekboxiniai listai linijiniai (StartGrp)
    loop_brother = this;
    while (loop_brother != NULL)
    {
        KP_ASSERT(m_iRecType == KpRecType_TextChk, E_UNEXPECTED, null);

// recursion on children
        first_child = loop_brother->GetFirstChild();

        if (first_child != NULL) first_child->Deselect();

KpTextChk *val_ptr = NULL;
        val_ptr = (KpTextChk *)loop_brother->GetValue();
        KP_ASSERT(val_ptr != NULL, E_POINTER, null);
        KP_ASSERT(loop_brother->GetValSize() >= sizeof(KpTextChk), KP_E_SYSTEM_ERROR, null);
        val_ptr->m_bChecked = False;

        loop_brother = loop_brother->GetNextBrother();
    }
}


// =======================================
// ----------------------
void ChangeKpTreeNodes(KpTreeEntry *pNode1, KpTreeEntry *pNode2)
{
KpTreeEntry *temp = NULL;

    KP_ASSERT((pNode1 != NULL) && (pNode2 != NULL), E_INVALIDARG, null);

    KP_NEW(temp, KpTreeEntry(pNode1->GetValue(), pNode1->GetValSize(), NULL));

    CopyKpTreeNode(pNode1, pNode2);
    CopyKpTreeNode(pNode2, temp);

    KP_DELETE(temp);
}


// ----------------------
void CopyKpTreeNode(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc)
{
int size;

    KP_ASSERT((pNodeDst != NULL) && (pNodeSrc != NULL), E_INVALIDARG, null);

    size = pNodeSrc->GetValSize();
    KP_ASSERT(size <= pNodeDst->GetValSize(), KP_E_BUFFER_OVERFLOW, null);

    pNodeDst->SetValue(pNodeSrc->GetValue(), size);

    pNodeDst->m_iRecType = pNodeSrc->m_iRecType;
    pNodeDst->m_iStatus = pNodeSrc->m_iStatus;
}


// ----------------------
void CopyKpTreeNodeAllocate(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc)
{
KpTreeEntry *father = NULL;

    KP_ASSERT((pNodeDst != NULL) && (pNodeSrc != NULL), E_INVALIDARG, null);

    KP_DELETEA(pNodeDst->m_lpRecord);

    father = pNodeDst->GetFather();
    pNodeDst->Constructor(pNodeSrc->GetValue(), pNodeSrc->GetValSize(), father);

    pNodeDst->m_iRecType = pNodeSrc->m_iRecType;
    pNodeDst->m_iStatus = pNodeSrc->m_iStatus;
}


// -----------------------------------------
KpTextChk::KpTextChk()
{
    m_lpszText[0] = Nul;
    m_bChecked = True; // varniukë paþymëta
}


// -----------------------------------------
void CountStrListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pList)
{
    KP_ASSERT(piFullContLen != NULL, E_INVALIDARG, null);
    *piFullContLen = 0;

KpTreeEntry *cur_node = pList;
    while (cur_node != NULL)
    {
unsigned char *val_buf = (unsigned char *)cur_node->GetValue();
        KP_ASSERT(val_buf != null, KP_E_SYSTEM_ERROR, null);

        *piFullContLen += strlen(val_buf);

        cur_node = cur_node->GetFirstChild();
    }
}


// -----------------------------------------
void CountKpCharListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pList)
{
    KP_ASSERT(piFullContLen != NULL, E_INVALIDARG, null);
    *piFullContLen = 0;

KpTreeEntry *cur_node = pList;
    while (cur_node != NULL)
    {
KpChStr *val_buf = (KpChStr *)cur_node->GetValue();
        KP_ASSERT(val_buf != NULL, KP_E_SYSTEM_ERROR, null);

        *piFullContLen += val_buf->Len();

        cur_node = cur_node->GetFirstChild();
    }
}
