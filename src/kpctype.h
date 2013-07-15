/* ----------------------------------------------------
 *
 * kpctype.h
 *  
 *    type conversations & character processing for KP C++ projects 
 *
 */   

#ifndef kpctype_included
#define kpctype_included


// ================================================== predefined spec. character strings
// TODO: kelt į KpCtype klasę
extern uchar lpszSpaces[];
extern uchar lpszEols[];
extern uchar lpszSpcEol[];
extern uchar lpszSpcEolNotNBSP[];
extern uchar lpszSpcEolNotTabNotFF[];

extern unsigned char lpszSpCharsSpcEol[]; // "/.,- \t\r\n"  // characters ignored by sorting/searching
                                                            //    former lpszSpChars

#endif // #ifndef kpctype_included

