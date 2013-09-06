/* -----------------------------
 * xmln.h
 *      xml file record XmlNode implementation
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


// --------------------------
XmlNodeRec::XmlNodeRec(int p_iNodeTag, XmlTagPars *p_pTagPars, uchar *p_lpszContents)
{
    m_iNodeTag = p_iNodeTag;
    m_pTagPars = p_pTagPars;
    
    m_lpszContents = null;
    if (p_lpszContents)
    {
        KP_NEWA(m_lpszContents, uchar, strlen(p_lpszContents) + 1);
        strcpy(m_lpszContents, p_lpszContents);
    }
}

XmlNodeRec::~XmlNodeRec()
{
    KP_DELETE(m_pTagPars);
    KP_DELETEA(m_lpszContents);
}


// --------------------------
XmlTree::XmlTree(void)
{
    m_pRootNode = NULL;
    
    m_plpszaTags = NULL;
    m_plpszaTags = KP_NEWA(uchar *, XL_MaxNumOfTags);
    for (int ii = 0; ii < XL_MaxNumOfTags; ii++) m_plpszaTags[ii] = null;
    
    m_iFirstTag = XM_FirstDictTagCode
    m_iNumOfTags = 0;
}


XmlTree::~XmlTree()
{
    if (m_plpszaTags)
        for (int ii = 0; ii < XL_MaxNumOfTags; ii++) KP_DELETEA(m_plpszaTags[ii]);
        
    KP_DELETEA(m_plpszaTags);
}


// --------------------------
XmlNodeRec *XmlTree::CreateTagNode(const uchar *p_lpszTagName, 
    const XmlTagPars *p_TagPars, const uchar *p_lpszTagVal)
{
    KP_ASSERT(m_plpszaTags, E_POPINTER, null);
    KP_ASSERT(p_lpszTagName, E_INVALIDARG, null);

int ix = GetKwrdIndex(p_lpszTagName, m_plpszaTags, m_iNumOfTags, True, True);
    if (ix == TV_TG_NoKey)
    {
        KP_ASSERT(m_iNumOfTags < XL_MaxNumOfTags, KP_E_BUFFER_OVERFLOW, null);
        m_plpszaTags[m_iNumOfTags] = KP_NEWA(uchar, strlen(p_lpszTagName) + 1);
        strcpy(m_plpszaTags[m_iNumOfTags], p_lpszTagName);
        ix = m_iNumOfTags++;
    }

XmlNodeRec *retv = KP_NEW(XmlNodeRec(m_iFirstTag + ix,     
return(
        
     
}
