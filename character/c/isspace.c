/**
 * isapace.
 * Defined in header <ctype.h>
 *
 * int isspace( int ch );
 * @param  ch character to classify
 * @return Non-zero value if the character is a whitespace character, zero otherwise.
 *
 * Checks if the given character is a whitespace character, i.e. either space (0x20),
 * form feed (0x0c), line feed (0x0a), carriage return (0x0d), horizontal tab (0x09) or vertical tab (0x0b).
 *
 * Note: isspace() must return false for %NUL-terminator
 */
#include <stdio.h>

int isspace1(int ch) {
	return ch == ' ' || ch == '\t' || ch == '\r' || ch =='\n' || ch == '\v' || ch == '\f';
}


/**
 * implementation in linux.
 *
 * #define _S      0x20    // white space (space/lf/tab)
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define isspace(c)      ((__ismask(c)&(_S)) != 0)
 *
 * const unsigned char _ctype[] = {} // an 256 array indicate _S(sapce), _D(digit) etc.
 *
 * http://lxr.linux.no/linux+v3.19.1/include/linux/ctype.h#L31
 */


void printf_isspace(int (*isspaceMethod)(int)) {
	for (int ndx=0; ndx<=255; ndx++)
		if (isspaceMethod(ndx)) printf("0x%02x\n", ndx);
}

int main(int argc, char const *argv[])
{
	printf("%c", 0x0b);
	printf_isspace(isspace1);
	return 0;
}