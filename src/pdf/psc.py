#!/usr/bin/env python
# coding=UTF-8

import sys

print '/* ----------------------------------------------------'
print ' *  psc.cpp'
print ' *      PostScript character names'
print ' *'
print ' *      Do not edit, file generated automatically by psc.py (psc.bat)'
print ' *'
print ' */'
print
print '#include "envir.h"'
print
print '#ifdef __WIN32__'
print '#include <windows.h>'
print '#endif'
print
print '#include "kpstdlib.h"'
print '#include "kptt.h"'
print '#include "kpctype.h"'
print '#include "kpstring.h"'
print '#include "pdf.h"'
print
print 'PsChName PsChNames[] = {'

print '{0:<47}'.format('    { ".notdef",'), '{0:<11}'.format('0xfffd },')  

in_lines = sys.stdin.readlines()
prev_in_line_tabs = ['', '', '', '', '', '', '', '']
for in_line in in_lines:
    in_line_strip = in_line.split('\n')
    in_line_tabs = in_line_strip[0].split('\t')
    if (len(in_line_tabs) <= 2):
        prev_in_line_tabs[6] = in_line_tabs[0]
        if (len(in_line_tabs) > 1): 
            prev_in_line_tabs[7] = in_line_tabs[1]
        in_line_tabs = prev_in_line_tabs  
    while (len(in_line_tabs) < 8): in_line_tabs.append('')

    hex_vals = in_line_tabs[4].split('&#')
    hex_vals = hex_vals[1].split(';')
    if (len(in_line_tabs[6]) == 0): in_line_tabs[6] = ' '
    print '{0:<47}'.format('    { "' + in_line_tabs[6] + '",'), '{0:<11}'.format('0' + hex_vals[0] + ' },'), '{0:<15}'.format('// ' + in_line_tabs[5]), '{0:<5}'.format(in_line_tabs[0]), ' ', in_line_tabs[7], '//'  
#   print '\t'.join(in_line_tabs)

    prev_in_line_tabs = in_line_tabs
    
print '{0:<47}'.format('    { "",'), '{0:<11}'.format('C_Nul  }')  
print '};'
        
