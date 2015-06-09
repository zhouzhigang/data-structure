/**
 * isxdigit.
 * Defined in header <ctype.h>
 *
 * int isxdigit( int ch );
 * @param  character to classify
 * @return Non-zero value if the character is an hexadecimal numeric character, zero otherwise.
 *
 * Checks if the given character is a hexadecimal numeric character (0123456789abcdefABCDEF)
 * or is classified as a hexadecimal character.
 *
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * http://en.cppreference.com/w/c/string/byte/isxdigit
 */
#include <stdio.h>

int isxdigit1(int ch) {
	return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'));
}

/**
 *
 * use existing isdigit method and marked as static inline.
 *
 * thinking: why static inline?
 *
 * http://lxr.linux.no/linux+v3.19.1/arch/x86/boot/ctype.h#L10
 */
static inline int isdigit2(int ch) {
	return (ch >= '0') && (ch <= '9');
}
static inline int isxdigit2(int ch) {
	if (isdigit2(ch))
		return true;
	if (ch >= 'a' && ch <= 'f')
		return true;
	return (ch >= 'A') && (ch <= 'F');
}

/**
 * another implementation in linux: use macro.
 *
 * #define _D      0x04    // digit
 * #define _X      0x40    // hex digit
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define isxdigit(c)     ((__ismask(c)&(_D|_X)) != 0)
 *
 * const unsigned char _ctype[] = {} // an 256 array indicate _D(digit), _X(xdigit) etc.
 *
 * http://lxr.linux.no/linux+v3.19.1/include/linux/ctype.h#L33
 */

void test_isxdigit() {

}

void print_isxdigit(int (*isxdigitMethod)(int)) {
	for (int ndx=0; ndx<=255; ndx++)
		if (isxdigitMethod(ndx)) printf("%c", ndx);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	print_isxdigit(isxdigit1);
	return 0;
}