/* -----------------------------
 * fmtf.cpp
 *      formatted I/O file implementation
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


// ---------------------------
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

#include "tinyxml.h"

#include "rti.h"
#include "fmtf.h"


// ---------------------------
FmtFile::FmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
    m_lpszFileName[0] = Nul;
    m_lpszFileMode[0] = Nul;
    m_pFileObj = NULL;
//  m_pXmlDoc = NULL;

    m_bOutputEmpty = True; 
    m_iIndent = 0;

    strcpy(m_lpszFileMode, "r");
    
    if(p_lpszFileMode != null)
    {
        KP_ASSERT(strlen(p_lpszFileMode) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileMode, p_lpszFileMode);
    }

    if(strchr(m_lpszFileMode, 'b') == null)
    {
        if(strchr(m_lpszFileMode, 'w') != null) m_pFileObj = stdout;
        if(strchr(m_lpszFileMode, 'r') != null) m_pFileObj = stdin;
    }
    
    if(p_lpszFileName != null) if (p_lpszFileName[0] != Nul)
    {
        KP_ASSERT(strlen(p_lpszFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileName, p_lpszFileName);
        
        m_pFileObj = fopen((const CHAR *)m_lpszFileName, (const CHAR *)m_lpszFileMode);
        KP_ASSERT(m_pFileObj != NULL, KP_E_DIR_ERROR, p_lpszFileName);
    }
}


FmtFile::~FmtFile()
{
    CloseOutFile();
}


// ------------------------------------  
void FmtFile::CloseOutFile(void)
{
    if(m_pFileObj != NULL)
    {
        KP_ASSERT(!m_bOutputEmpty, KP_E_FILE_FORMAT, "Nothing found to print...\n");
        PrintOutputTail();
    
        if(m_pFileObj == stdout)
            KP_ASSERT(fflush(m_pFileObj) != EOF, KP_E_FERROR, null)
        else
            KP_ASSERT(fclose(m_pFileObj) != EOF, KP_E_FERROR, m_lpszFileName);
        
        m_pFileObj = NULL;
    } 
}


// ---------------------------------
void FmtFile::PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
bool *p_output_empty = p_pbOutputEmpty;
    if (p_pbOutputEmpty == NULL) p_output_empty = &m_bOutputEmpty;
    
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    PrintOutputLow(p_pRti, p_output_empty, p_lpszGrpTagName);

    m_bOutputEmpty = False; // Do not print OUPUT_HEAD
    *p_output_empty = False; // no more output of parent group tag p_lpszGrpTagName
}


// ---------------------------------
const unsigned int NUM_INDENTS_PER_SPACE=2;

const char * getIndent( unsigned int numIndents )
{
	static const char * pINDENT="                                      + ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;

	return &pINDENT[ LENGTH-n ];
}

// same as getIndent but no "+" at the end
const char * getIndentAlt( unsigned int numIndents )
{
	static const char * pINDENT="                                        ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;

	return &pINDENT[ LENGTH-n ];
}

int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent)
{
	if ( !pElement ) return 0;

	TiXmlAttribute* pAttrib=pElement->FirstAttribute();
	int i=0;
	int ival;
	double dval;
	const char* pIndent=getIndent(indent);
	printf("\n");
	while (pAttrib)
	{
		printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());

		if (pAttrib->QueryIntValue(&ival)==TIXML_SUCCESS)    printf( " int=%d", ival);
		if (pAttrib->QueryDoubleValue(&dval)==TIXML_SUCCESS) printf( " d=%1.1f", dval);
		printf( "\n" );
		i++;
		pAttrib=pAttrib->Next();
	}
	return i;	
}

void dump_to_stdout( TiXmlNode* pParent, unsigned int indent = 0 )
{
	if ( !pParent ) return;

	TiXmlNode* pChild;
	TiXmlText* pText;
	int t = pParent->Type();
	printf( "%s", getIndent(indent));
	int num;

	switch ( t )
	{
	case TiXmlNode::TINYXML_DOCUMENT:
		printf( "Document" );
		break;

	case TiXmlNode::TINYXML_ELEMENT:
		printf( "Element [%s]", pParent->Value() );
		num=dump_attribs_to_stdout(pParent->ToElement(), indent+1);
		switch(num)
		{
			case 0:  printf( " (No attributes)"); break;
			case 1:  printf( "%s1 attribute", getIndentAlt(indent)); break;
			default: printf( "%s%d attributes", getIndentAlt(indent), num); break;
		}
		break;

	case TiXmlNode::TINYXML_COMMENT:
		printf( "Comment: [%s]", pParent->Value());
		break;

	case TiXmlNode::TINYXML_UNKNOWN:
		printf( "Unknown" );
		break;

	case TiXmlNode::TINYXML_TEXT:
		pText = pParent->ToText();
		printf( "Text: [%s]", pText->Value() );
		break;

	case TiXmlNode::TINYXML_DECLARATION:
		printf( "Declaration" );
		break;
	default:
		break;
	}
	printf( "\n" );
	for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
	{
		dump_to_stdout( pChild, indent+1 );
	}
}
        
