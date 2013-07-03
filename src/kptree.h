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

template <class KpTreeRecType> 
class KpTreeEntry
{
public:
    KpTreeRecType *m_lpRecord;

    KpTreeEntry<KpTreeRecType> *m_pFirstChild; // TeXtrcClass::FindFile() naudoja tiesiogini pointeri, po to trina listo elementa
private:
    KpTreeEntry<KpTreeRecType> *m_pPrevBrother;
    KpTreeEntry<KpTreeRecType> *m_pNextBrother;
    KpTreeEntry<KpTreeRecType> *m_pFather;


public:
    //-----------------------------------
    // create new record entry
    // stores allocated object pointer lpRecord to m_lpRecord
    // don't delete it after return
    KpTreeEntry(KpTreeRecType *lpRecord, KpTreeEntry<KpTreeRecType> *pFath)
    {
     // KP_ASSERT(lpRecord != NULL, E_INVALIDARG, null);
        m_lpRecord = lpRecord;

        m_pFather = pFath;
        m_pFirstChild = NULL;
        m_pPrevBrother = NULL;
        m_pNextBrother = NULL;
    }


    //-----------------------------------
    virtual ~KpTreeEntry()
    {
    KpTreeEntry<KpTreeRecType> *next_br = NULL;

        while (m_pNextBrother != NULL)
        {
            next_br = m_pNextBrother->GetNextBrother();
            m_pNextBrother->SetNextBrother(NULL);
//          m_pNextBrother->SetPrevBrother(NULL);

            KP_DELETE(m_pNextBrother);
            if (next_br != NULL) next_br->SetPrevBrother(this);
            SetNextBrother(next_br);
        }

        KP_DELETE(m_pFirstChild);

        KP_DELETE(m_lpRecord);
    }


    //-----------------------------------
    // get record object pointer m_lpRecord
    KpTreeRecType *GetValue(void){ return(m_lpRecord); } 

    
// ------------------------------
// simply linear list methods


    //-----------------------------------
    // sets value of pointer to the next entry (child) m_pFirstChild
    // sets next chain member in case of linear list
    // pChild cannot be deleted after successfull SetFirstChild()
    // pChild->m_pFather turi sutapti su this
    // pChild->m_pPrevBrother turi buti NULL
    void SetFirstChild(KpTreeEntry<KpTreeRecType> *pChild)
    {
    KpTreeEntry<KpTreeRecType> *father = NULL;
    KpTreeEntry<KpTreeRecType> *prev_brother = NULL;
    
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
    // gets value of m_pFirstChild
    // gets pointer to next entry of the linear list
    // NULL - last entry
    KpTreeEntry<KpTreeRecType> *GetFirstChild(void) const { return(m_pFirstChild); }


    //-----------------------------------
    // uses the object *lpNode itself, don't delete it after return 
    void PutToEnd(KpTreeEntry<KpTreeRecType> *lpNode)
    {
    KpTreeEntry<KpTreeRecType> *cur_entry = this;
    KpTreeEntry<KpTreeRecType> *next_entry = NULL;

        KP_ASSERT(lpNode != NULL, E_INVALIDARG, null);

        do
        {
            next_entry = cur_entry->GetFirstChild();
            if (next_entry != NULL) cur_entry = next_entry;
        } while (next_entry != NULL);

        lpNode->SetFather(cur_entry);
        cur_entry->SetFirstChild(lpNode);
    }
    

// ------------------------------
// tree management methods


    //-----------------------------------
    KpTreeEntry<KpTreeRecType> *GetFather(void) const { return(m_pFather); };

    // nustato teva ir visiems tolimesniems broliams
    // pPrevBrother turi buti NULL
    // pFath cannnot be deleted after successfull SetFather()
    void SetFather0(KpTreeEntry<KpTreeRecType> *pFath) // recursive entry
    {
        m_pFather = pFath;

        // recursion
        if (m_pNextBrother != NULL) m_pNextBrother->SetFather0(pFath);
    }

    void SetFather(KpTreeEntry<KpTreeRecType> *pFath)  // main entry
    {
        KP_ASSERT(m_pPrevBrother == NULL, KP_E_SYSTEM_ERROR, null);
        SetFather0(pFath);
    }


    //-----------------------------------
    KpTreeEntry<KpTreeRecType> *GetPrevBrother(void) const { return(m_pPrevBrother); }


    //-----------------------------------
    // pPrevBr cannnot be deleted after successfull SetPrevBrother()
    // pPrevBr->pFather turi sutapti su this->pFather
    void SetPrevBrother(KpTreeEntry<KpTreeRecType> *pPrevBr)
    {
    KpTreeEntry<KpTreeRecType> *father = NULL;

        if (pPrevBr != NULL)
        {
            father = pPrevBr->GetFather();
            KP_ASSERT(father == m_pFather, KP_E_SYSTEM_ERROR, null);
        }

        m_pPrevBrother = pPrevBr;
    }


    //-----------------------------------
    KpTreeEntry<KpTreeRecType> *GetNextBrother(void) const { return(m_pNextBrother); }
    

    //-----------------------------------
    // nustato sekantá brolá ðiam mazgui (this)
    // pNextBr cannnot be deleted after successfull SetNextBrother()
    // pNextBr->pFather turi sutapti su this->pFather
    void SetNextBrother(KpTreeEntry<KpTreeRecType> *pNextBr)
    {
    KpTreeEntry<KpTreeRecType> *father = NULL;

        if (pNextBr != NULL)
        {
            father = pNextBr->GetFather();
            KP_ASSERT(father == m_pFather, KP_E_SYSTEM_ERROR, null);
        }

        m_pNextBrother = pNextBr;
    }


    //-----------------------------------
    // TODO: panaðiai, kaip ir DeleteKpTreeEntry, tik elementà trina, vietoj jo atkeldamas vaikus
    // TODO: elementà trina su visais broliais
    // tinka paprasto listo tvarkymui  
    // DeleteChild() papildymas
    static void DeleteKpTreeNode(KpTreeEntry<KpTreeRecType> **ppEntryPtr)
    {
        KP_ASSERT(ppEntryPtr != NULL, E_POINTER, null);
        KP_ASSERT(*ppEntryPtr != NULL, E_POINTER, null);

    KpTreeEntry<KpTreeRecType> *first_child = NULL;
        first_child = (*ppEntryPtr)->GetFirstChild();

    KpTreeEntry<KpTreeRecType> *prev_brother = NULL;
        prev_brother = (*ppEntryPtr)->GetPrevBrother();

    KpTreeEntry<KpTreeRecType> *father = NULL;
        father = (*ppEntryPtr)->GetFather();

        if (first_child != NULL) 
        {
            first_child->SetPrevBrother(prev_brother);
            first_child->SetFather0(father);
        }
        if (prev_brother != NULL) prev_brother->SetNextBrother(first_child);

        (*ppEntryPtr)->SetFirstChild(NULL);
     // (*ppEntryPtr)->SetPrevBrother(NULL);
        KP_DELETE(*ppEntryPtr);
   
        *ppEntryPtr = first_child;

        // pirmas vaikas  nustatom naujà tëvo pirmà vaikà
        if ((prev_brother == NULL) && (father != NULL)) father->SetFirstChild(first_child);
    }
};

#endif // #ifndef kptree_included

