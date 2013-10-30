/* ------------------------------------------
 *
 * kpstrapp.h
 *  
 *    Safe strcat() 
 *
 *  2013-10-28  mp  initial creation
 *   
 */   

#ifndef KPSTRAPP_INCLUDED
#define KPSTRAPP_INCLUDED

#ifndef KPSTDLIB_INCLUDED
typedef unsigned char uchar;
#endif

/* -----------------------
 * Macros to call kp_append_...()
 * ret_buf and cur_buf_len should be locally defined using KP_DEF_BUF   
 */
#define KP_DEF_BUF int cur_buf_len = 1000; uchar *ret_buf = malloc(cur_buf_len + 1); assert(ret_buf); ret_buf[0] = 0;
#define KP_APPEND_STR(out_str) kp_append_str((const uchar *)out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_STR_AND_FREE(out_str) kp_append_str_and_free(out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_CHR(out_chr) kp_append_chr(out_chr, &ret_buf, &cur_buf_len)
   
/* safe strcat() – appends out_str to the string buffer *str_buf_ptr */ 
extern void kp_append_str(const uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr);

/* appends out_str to *str_buf_ptr and free()'s */
extern void kp_append_str_and_free(const uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr);

/* safely appends byte out_chr to the string buffer *str_buf_ptr */
extern void kp_append_chr(const uchar out_chr, uchar **str_buf_ptr, int *buf_len_ptr);

#endif /* #ifndef KPSTRAPP_INCLUDED */
