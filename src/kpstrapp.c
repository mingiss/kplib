/* ------------------------------------------
 *
 * kpstrapp.c
 *  
 *    Safe strcat() 
 *
 *  2013-10-28  mp  initial creation
 *   
 */   


/* ----------------------- */
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "kpstdlib.h"
#include "kpstring.h"


/* ----------------------- */
void kp_append_str(const uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr)
{
    if (out_str && buf_len_ptr && str_buf_ptr) if (*str_buf_ptr)
    {
    int new_str_len = strlen((const char *)*str_buf_ptr) +
                                    strlen((const char *)out_str);
        if (new_str_len >= *buf_len_ptr)
        {
            *buf_len_ptr = new_str_len + 1000;
            *str_buf_ptr = realloc (*str_buf_ptr, *buf_len_ptr + 1);
            assert(*str_buf_ptr);
        }
        
        if (*str_buf_ptr) strcat(*str_buf_ptr, out_str);            
    } 
}


void kp_append_str_and_free(uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr)
{
    if (out_str)
    {
        kp_append_str(out_str, str_buf_ptr, buf_len_ptr);
        free(out_str);
    }
}


void kp_append_chr(const uchar out_chr, uchar **str_buf_ptr, int *buf_len_ptr)
{
uchar out_str[2] = {out_chr, 0};
    kp_append_str(out_str, str_buf_ptr, buf_len_ptr);
}
