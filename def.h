#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <stdio.h>
//convert double to string, with 7 decimal precision
#define tostr(S,f) sprintf(S,"%0.7f",f) //for short chars
//#define tostr(S,f) swprintf(S,L"%0.7f",f) //for wide chars

//char is the smallest C data type(1), so it is base type.
//used for garbage collector
#define BASE_TYPE_UNIT char

//define sizes required for commands and errors
typedef unsigned long COMMAND_TYPE;
typedef unsigned long ERROR_TYPE;

//for characters and strings
#define chr char
#define str char*
#define null '\0'

//operator definitions
#define add '+'
#define sub '-'
#define mul '*'
#define div '/'
#define mod '%'
#define pwr '^'
#define neg '`'
#define lth '<'
#define gth '>'
#define equ '='
#define fac '!'
#define _and '&'
#define _or '|'
#define _xor '#'
#define _not '~'
#define _nand '$'
#define _nor '\\'
#define g_eq '§'
#define l_eq '¶'

#define opar '('
#define cpar ')'

//important character definitions
#define ret '\n'

#define ch_a 'a'
#define ch_z 'z'
#define ch_A 'A'
#define ch_Z 'Z'

#define num0 '0'
#define num1 '1'
#define num9 '9'
#define decimal '.'

#define space ' '
#define comma ','

#define special '@'
#define text_cmd '•'
#define colon ':'

#define underscore '_'
#define quote '\"'

//Important strings
#define voidstr "\0"
#define end_line "\n\r"
#define str_end_line "\"\n\r\""
#define string_quotes "\"\""
#define string_parenths "()"

//Command strings
#define cmd_print "print"
#define cmd_2Dtext "text"
#define cmd_3Dtext "text3d"
#define cmd_WindowCaption "setWindowCaption"
#define cmd_goto "goto"
#define cmd_if "if"
#define cmd_else "else"
#define cmd_elif "elif"
#define cmd_endif "endif"
#define cmd_end_program "end"
#define cmd_gosub "gosub"   ///To do maybe
#define cmd_return "return" ///To do maybe
#define cmd_WindowColor "setWindowColor"    ///To do
#define cmd_WindowTexture "setWindowTexture"///To do
#define cmd_loadTex "loadTexture"           ///To do
#define cmd_MousePos "setMousePosition"

//function strings
#define func_RGB "rgb"
#define func_RGBA "rgba"
#define func_log "log"
#define func_floor "floor"
#define func_ceiling "ceil"
#define func_round "round"
#define func_rgba_r "red"
#define func_rgba_g "green"
#define func_rgba_b "blue"
#define func_rgba_a "alpha"
#define func_equal "equ"
#define func_rand_f "frand"
#define func_rand_i "irand"
#define func_sq_root "sqrt"
#define func_mouse_x "mousex"
#define func_mouse_y "mousey"
#define func_mouse_z "mousez"
#define func_mouse_button "mouseclick"

//string synonyms
#define syn_and "and"
#define syn_or "or"
#define syn_g_eq ">="
#define syn_l_eq "<="
#define syn_xor "xor"
#define syn_not "not"
#define syn_nand "nand"
#define syn_nor "nor"
#define syn_true "true"
#define syn_false "false"
#define syn_newline "newl"

//color definitions
#define color_white "4294967295" //0xffffffff, pure white rgba


#endif // DEF_H_INCLUDED
