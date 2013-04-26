/* ----------------------------------------------------
 *
 * kptree.h
 *  
 *    definitions of KpTreeEntry 
 *
 */   


// ===============================================
#ifndef kptree_included
#define kptree_included


// ===============================================
#define XL_ND_MaxNumOfNodes 3000 // 30000 // max number of nodes in node tree
#define KP_MAX_TREE_DEPTH 50 // max level of descendants


typedef struct
{
   UCHAR m_lpszText[KP_MAX_FILE_LIN_LEN + 1];
   HBITMAP m_hBmp;
} KpTextBmp;

typedef struct
{
   HBITMAP m_hBmp;
   HBITMAP m_hTextBmp;
} KpBmpBmp;

class KpTextChk
{
public:
   UCHAR m_lpszText[KP_MAX_FILE_LIN_LEN + 1];
   KpChStr m_KpStr;
   bool m_bChecked;

   KpTextChk(void);
};

typedef enum
{
   KpRecType_Unknown,   // void * record
   KpRecType_Text,      // UCHAR * - lpsz character array, any length
   KpRecType_TextBmp,   // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_BmpBmp,    // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_TextChk,   // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_KpText,    // KpChStr - wide character array, any length

} KpRecType; 


// node display types for KP_LISTBOX
// flags for KpTreeEntry::m_iStatus
#define KpNodeVisible      1  // if 0 - node does not belong to current level tree
#define KpNodeHasChildren  2  // not empty node - KpNodeExpanded is applicable
#define KpNodeExpanded     4  // expanded node - children visible, node marked as [-] in KP_LISTBOX; applicable only if KpNodeHasChildren
                              // if KpNodeHasChildren and not KpNodeExpanded - collapsed node - children invisible, node marked as [+] in KP_LISTBOX
#define KpNodeLevelShift   8  // 8 bits for each level flags
#define KpNodeLevelFactor  256

#define KpNodeNumOfLevels  2


// ================================================== tree of objects, class for tree node
class KpTreeEntry
{
// The object itself, any class.
// First member - usually lpsz character string -
//    simply text representation of contents - for sorting and listing purposes
//    (KpCreateListBox()
public:
   UCHAR /* void */ *m_lpRecord; // should be allocated as an array – destructor deletes it with delete []

   int m_iRecSize; // size of m_lpRecord in bytes

// int iNumOfNodes;
// XmlNode_tag **iaNodesArray;

public:
    KpRecType m_iRecType;

    // paprastas listas per ðitas rodykles, broliø tada nëra
    KpTreeEntry *m_pFirstChild; 
    KpTreeEntry *m_pFather;

    // o èia jau medþio ðakos 
    KpTreeEntry *m_pPrevBrother;
    KpTreeEntry *m_pNextBrother;

    int m_iStatus;
        // flag of node with hidden children (for output to KP_LISTBOX)
        // levels in XmlNode_tag:  1 - group tags (nodes)
        //                         0 - simply tags

// constructors
   KpTreeEntry(void);

   KpTreeEntry(KpTreeEntry *pFath);

   KpTreeEntry(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType = KpRecType_Unknown); 
    // create new record entry, iSize - size in bytes of the record
    // *lpRecord could be deleted after return (value of *lpRecord is copied to new created CHAR array m_lpRecord[])
   KpTreeEntry(const UCHAR *lpszString, KpTreeEntry *pFath); // lpszString - text string to initialize
   KpTreeEntry(const CHAR *lpszString, KpTreeEntry *pFath); // lpszString - text string to initialize
   KpTreeEntry(const KpChStr *pKpStr, KpTreeEntry *pFath); // iazKpStr - wide text string to initialize
   void Constructor(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType = KpRecType_Unknown); // *lpRecord po gráþimo galima sunaikinti

   virtual ~KpTreeEntry();


// ------------------------------
// simply linear list methods

   void SetFirstChild(KpTreeEntry *pChild);  // sets value of pointer to next entry (child) m_pFirstChild
                                             // sets next chain member in case of linear list
                                             // pChild cannot be deleted after successfull SetFirstChild()
                                             // pChild->m_pFather turi sutapti su this
                                             // pChild->m_pPrevBrother turi buti NULL
   KpTreeEntry *GetFirstChild(void) const { return(m_pFirstChild); }
                                             // gets value of m_pFirstChild
                                             // gets pointer to next entry of the linear list
                                             // NULL - last entry

   void PutToEnd(KpTreeEntry *lpNode);
        // uses the object *lpNode itself, don't delete it after return 
   void PutToEnd(const void *lpRecord, int iSize, KpRecType iRecType = KpRecType_Unknown);
      // puts new entry after last entry (deepest child) of the list
      // *lpRecord could be deleted after return
   void PutToEnd(const UCHAR *lpszString);
      // lpszString - text string as new entry (after the deepest child)
      // could be deleted after return
   void PutToEnd(const CHAR *lpszString);
      // lpszString - text string as new entry (after the deepest child)
      // could be deleted after return
   void PutToEnd(const KpChStr *pKpStr);
      // iazKpStr - text wide string as new entry (after the deepest child)
      // could be deleted after return

   void DeleteChild(void);
      // ismeta viena vaika, anukus pastumia i vaiko vieta

   void DeleteBrother(void);
      // TODO: iðmesti pirmà brolá, tolesnius brolius pastumti vietoj jo

   KpRecType GetRecType(void) const { return(m_iRecType); } // get record type identifier m_iRecType

   void *GetValue(void) const { return(m_lpRecord); } // get record buffer pointer m_lpRecord
   int GetValSize(void) const; // get count of bytes of record value

   void SetValue(const void *pValue, int iValSize);
      // sets new contents of record buffer m_lpRecord
      // error if iValSize is greater than original
      // does not change original m_iRecSize

   void SetNewValue(const void *pValue, int iValSize);
   void SetNewValue(const UCHAR *lpszValue);

   void SetNewValue(const KpTextBmp *pValue);
   void SetNewValue(const KpBmpBmp *pValue);
      // deletes former allocation of m_lpRecord
      // allocates new buffer for m_lpRecord
      // sets new contents of record buffer m_lpRecord

   virtual void InitNodeStatus(void); // initialize value of m_iStatus

   void CountEntries(int *piCnt, int iLevel = 0, KpTreeEntry *pCurGrandFather = NULL) /* const */;
   // counts number of list entries
   // *piCnt ieinant turi buti inicializuotas i 0 - funkcija rekursine, tik inkrementuoja
   // iLevel: 0 - low level KP_LISTBOX, 1 - high
   // pCurGrandFather - top level node - for tree branches, NULL - whole tree
   // check <this> for existence before calling

   void GetEntryPtr(int *piSel, KpTreeEntry **ppEntryPtr, int iLevel, const KpTreeEntry *pCurGrandFather);
   // *piSel - áraðo numeris nuo ðaknies (pirma vaikai, po to broliai - kaip katalogø medþio ListBox'o vaizde
   // *piSel áeinant turi bûti -1; gadinamas - naudojamas kaip darbinis kintamasis
   // *ppEntryPtr==NULL - iSel exceeded real count of entries in pStartEntry
   // iLevel: 0 - low level KP_LISTBOX, 1 - high
   // pCurGrandFather - top level node - for tree branches, NULL - whole tree
   // check <this> for existence before calling

   void SearchTreeEntry
   (
      const void *pPattern,
      CompareFuncPtr pfCompare, // int (*pfCompare)(const void *, const void *),
      KpTreeEntry **ppEntryPtr,
      KpTreeEntry **ppFatherPtr // TODO: mest lauk !!!
   );
   // searches for list node corresponding to pPattern
   // NULL - node not found
   // pfCompare() - like strcmp(), TvStrCmpStrict_()
   // ppFatherPtr gali buti NULL, naudojamas, kai reikia ismetineti irasus
   // *ppFatherPtr==NULL - tevo nera (pats pirmas irasas atitiko pPattern)
   // check <this> for existence before calling

   void Sort(CompareFuncPtr pfCompare /* int (*pfCompare)(const void *lpszStr1, const void *lpszStr2) */);
   // sorts values of linked list
   // pfCompare() - like strcmp(), TvStrCmpStrict_()
   // list elements must be of equal size
   // <this> must be checked for existence before calling
   void SortPtr(ComparePtrFuncPtr pfCompare /* int (*pfCompare)(const void *plpszStr1, const void *plpszStr2) */);



// ------------------------------
// tree management methods

   KpTreeEntry *GetFather(void) const { return(m_pFather); };

   void SetFather0(KpTreeEntry *pFath);         // recursive entry
   void SetFather(KpTreeEntry *pFath);          // main entry
                                                   // pFath cannnot be deleted after successfull SetFather()
                                                   // nustato teva ir visiems tolimesniems broliams
                                                   // pPrevBrother turi buti NULL


   void ConnectChild(KpTreeEntry *pChild);      // pChild cannot be deleted after successfull ConnectChild()
                                                   // nustato pChild->pFather i this, pChild->pPrevBrother i NULL

   KpTreeEntry *GetPrevBrother(void) const { return(m_pPrevBrother); }
   void SetPrevBrother(KpTreeEntry *pPrevBr);   // pPrevBr cannnot be deleted after successfull SetPrevBrother()
                                                   // pPrevBr->pFather turi sutapti su this->pFather

   KpTreeEntry *GetNextBrother(void) const { return(m_pNextBrother); }
   void SetNextBrother(KpTreeEntry *pNextBr);   // nustato sekantá brolá ðiam mazgui (this)
                                                   // pNextBr cannnot be deleted after successfull SetNextBrother()
                                                   // pNextBr->pFather turi sutapti su this->pFather


   void ConnectBrother(KpTreeEntry *pNextBr);   // nustato sekantá brolá ðiam mazgui (this)
                                                   // pNextBr cannnot be deleted after successfull ConnectBrother()
                                                   // nustato pNextBr->m_pFather=this->m_pFather

   void InsertChild(KpTreeEntry *pChild);       // inserts new child BEFORE first child
                                                   //    pChild cannot be deleted after successfull InsertChild()
                                                   // nustato pChild->pFather i this
   void AppendChild(KpTreeEntry *pChild);       // appends new child AFTER the last child of this
                                                   //    pChild cannot be deleted after successfull AppendChild()
                                                   // nustato pChild->pFather i this
   void AppendBrother(KpTreeEntry *pBrother);   // appends new brother AFTER the last brother of this
                                                   //    pBrother cannot be deleted after successfull AppendBrother()
                                                   // nustato pBrother->pFather i this->pFather

// ---------------------------------
private:
   void TestNodeLoop(KpTreeEntry **iaNodesArray, int *piNumOfNodes); // internal function used in TestNode
public:                                                             
   void TestNode(void);

// ---------------------------------
   void FormListBox(HWND hListBox); // SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)m_lpRecord); recursively through all children and brothers

// ---------------------------------
// KpTextChk metodai
   void Deselect(); // visus m_lpRecord->m_bChecked numeta á False

};


// TODO: toliau viskà kelti á KpTreeEntry klasës statinius metodus

extern void DeleteKpTreeEntry(KpTreeEntry *pEntryPtr); 
    // iðtrina *pEntryPtr su visais vaikais, pastumdydamas brolius
    // TODO: negerai, jeigu èia vyriausias tëvas – pamesim medþio ðaknies rodyklæ
    // TODO: reikia perduot parametrà KpTreeEntry **ppEntryPtr ir atnaujint rodyklæ *ppEntryPtr->m_pNextBrother reikðme 
    // DeleteBrother() papildymas

extern void DeleteKpTreeNode(KpTreeEntry **ppEntryPtr); 
    // TODO: panaðiai, kaip ir DeleteKpTreeEntry, tik elementà trina, vietoj jo atkeldamas vaikus
    // TODO: elementà trina su visais broliais
    // tinka paprasto listo tvarkymui  
    // DeleteChild() papildymas

extern void ChangeKpTreeNodes(KpTreeEntry *pNode1, KpTreeEntry *pNode2);
   // changes VALUES (*m_lpRecord) of two tree entries, relationship is not changed
   // pNode1->m_lpRecord and pNode2->m_lpRecord should be allready allocated with sufficient size

extern void CopyKpTreeNode(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc);
   // copies VALUES (*m_lpRecord) of the tree node, relationship is not changed
   // pNodeDst->m_lpRecord should be allready allocated with sufficient size

extern void CopyKpTreeNodeAllocate(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc);
   // like CopyKpTreeNode(), but allocates new space for pNodeDst->m_lpRecord

// ------------------- suskaièiuoja teksto eiluèiø sàraðo bendrà ilgá
extern void CountStrListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pCharList); // *pList – CHAR[] stringø sàraðas
extern void CountKpCharListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pKpCharList); // *pList – KpChStr stringø sàraðas

#endif // #ifndef kptree_included

