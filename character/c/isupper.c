/**
 * isupper.
 *
 * Checks if the given character is an uppercase character according to the current C locale.
 * In the default "C" locale, isupper returns true only for the uppercase letters('A'-'Z', 65-90, 0x41-0x5A).
 *
 * If isupper returns true, it is guaranteed that iscntrl, isdigit, ispunct, and isspace return false for the same character in the same C locale.
 *
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * int isupper( int ch );
 * @param  ch character to classify
 * @return Non-zero value if the character is an uppercase letter, zero otherwise.
 *
 * Reference
 * http://en.cppreference.com/w/c/string/byte/isupper
 */
#include <stdio.h>
#include <locale.h>

/**
 * wrong implementation: not take locale into consideration.
 * 'A': 65, 'Z': 90
 */
int issuper1(int ch) {
	// printf("%d %d\n", 'A', 'Z');
	return ch >= 'A' && ch <= 'Z';
}

/**
 * implementation in linux: use macro instead.
 *
 * #define _U      0x01    //lower
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define isupper(c)      ((__ismask(c)&(_U)) != 0)
 *
 * const unsigned char _ctype[] = {} // an 256 array indicate _U(upper), _L(lower) etc.
 *
 * http://lxr.linux.no/linux+v3.19.1/include/linux/ctype.h#L27
 */

void test_issuper(int (*issuperMethod)(int)) {
	unsigned char c = '\xc6'; // letter Æ in ISO-8859-1
	printf("In the default C locale, \\xc6 is %suppercase\n", issuperMethod(c) ? "" : "not " );
	setlocale(LC_ALL, "en_GB.iso88591");
	printf("In ISO-8859-1 locale, \\xc6 is %suppercase\n", issuperMethod(c) ? "" : "not " );
}

int main(int argc, char const *argv[])
{
	test_issuper(issuper1);
	return 0;
}
