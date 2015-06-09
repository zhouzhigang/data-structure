/**
 * ctype macro.
 *
 * compile in one step:
 *  gcc hello.c -o hello
 *
 * compile in mutiple steps:
 *  preprocessing(-S: generate "*.i" file)
 *    gcc -E ctype_macro.c -o ctype_macro.i
 *  compilation(-S: generate "*.s" assembly code)
 *    gcc -S ctype_macro.i -o ctype_macro.s
 *  assembly(-c: only compile, generate "*.o" file, not linking)
 *    gcc -c ctype_macro.s -o ctype_macro.o
 *  linking
 *    gcc ctype_macro.o -o ctype_macro
 */

#define _U    0x01    /* upper */
#define _L    0x02    /* lower */
#define _D    0x04    /* digit */
#define _C    0x08    /* cntrl */
#define _P    0x10    /* punct */
#define _S    0x20    /* white space (space/lf/tab) */
#define _X    0x40    /* hex digit */
#define _SP   0x80    /* hard space (0x20) */

const unsigned char _ctype[] = {
_C,_C,_C,_C,_C,_C,_C,_C,                                /* 0-7 */
_C,_C|_S,_C|_S,_C|_S,_C|_S,_C|_S,_C,_C,                 /* 8-15 */
_C,_C,_C,_C,_C,_C,_C,_C,                                /* 16-23 */
_C,_C,_C,_C,_C,_C,_C,_C,                                /* 24-31 */
_S|_SP,_P,_P,_P,_P,_P,_P,_P,                            /* 32-39 */
_P,_P,_P,_P,_P,_P,_P,_P,                                /* 40-47 */
_D,_D,_D,_D,_D,_D,_D,_D,                                /* 48-55 */
_D,_D,_P,_P,_P,_P,_P,_P,                                /* 56-63 */
_P,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U,              /* 64-71 */
_U,_U,_U,_U,_U,_U,_U,_U,                                /* 72-79 */
_U,_U,_U,_U,_U,_U,_U,_U,                                /* 80-87 */
_U,_U,_U,_P,_P,_P,_P,_P,                                /* 88-95 */
_P,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L,              /* 96-103 */
_L,_L,_L,_L,_L,_L,_L,_L,                                /* 104-111 */
_L,_L,_L,_L,_L,_L,_L,_L,                                /* 112-119 */
_L,_L,_L,_P,_P,_P,_P,_C,                                /* 120-127 */
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                        /* 128-143 */
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                        /* 144-159 */
_S|_SP,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,    /* 160-175 */
_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,        /* 176-191 */
_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,        /* 192-207 */
_U,_U,_U,_U,_U,_U,_U,_P,_U,_U,_U,_U,_U,_U,_U,_L,        /* 208-223 */
_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,        /* 224-239 */
_L,_L,_L,_L,_L,_L,_L,_P,_L,_L,_L,_L,_L,_L,_L,_L};       /* 240-255 */

#define __ismask(x) (_ctype[(int)(unsigned char)(x)])

#define isalnum(c)      ((__ismask(c)&(_U|_L|_D)) != 0)
#define isalpha(c)      ((__ismask(c)&(_U|_L)) != 0)
#define iscntrl(c)      ((__ismask(c)&(_C)) != 0)
#define isdigit(c)      ((__ismask(c)&(_D)) != 0)
#define isgraph(c)      ((__ismask(c)&(_P|_U|_L|_D)) != 0)
#define islower(c)      ((__ismask(c)&(_L)) != 0)
#define isprint(c)      ((__ismask(c)&(_P|_U|_L|_D|_SP)) != 0)
#define ispunct(c)      ((__ismask(c)&(_P)) != 0)
/* Note: isspace() must return false for %NUL-terminator */
#define isspace(c)      ((__ismask(c)&(_S)) != 0)
#define isupper(c)      ((__ismask(c)&(_U)) != 0)
#define isxdigit(c)     ((__ismask(c)&(_D|_X)) != 0)

#define isascii(c) (((unsigned char)(c))<=0x7f)
#define toascii(c) (((unsigned char)(c))&0x7f)

int main(int argc, char const *argv[])
{
	isdigit('0');
	return 0;
}