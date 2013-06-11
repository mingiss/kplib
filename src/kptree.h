/* -----------------------------
 * kptree.h
 *      tree-like structure definition
 *      
 *  Changelog:
 *      2013-06-11  mp  initial creation
 *       
 */  


#ifndef kptree_included
#define kptree_included

class KpTreeRec
{
virtual ~KpTreeRec(){}
}


class KpTreeEntry
{
public:
   KpTreeRec *m_lpRecord;

   KpTreeEntry *m_pFirstChild;
   KpTreeEntry *m_pPrevBrother;
   KpTreeEntry *m_pNextBrother;
   KpTreeEntry *m_pFather;

   KpTreeEntry(const void *lpRecord, int iSize, KpTreeEntry *pFath); // create new record entry, iSize - size in bytes of the record



};

#endif // #ifndef kptree_included
