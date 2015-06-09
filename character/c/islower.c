/**
 * islower.
 * Defined in header <ctype.h>
 *
 * int islower( int ch );
 * Checks if the given character is classified as a lowercase character according to the current C locale.
 * In the default "C" locale, islower returns true only for the lowercase letters('a'-'z', 97-122, 0x61-0x7A).
 *
 * If islower returns true, it is guaranteed that iscntrl, isdigit, ispunct, and isspace return false for the same character in the same C locale.
 *
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 */
#include <stdio.h>
#include <locale.h>

/**
 * wrong implementation: not take locale into consideration.
 * 'a': 97, 'z': 122
 */
int islower1(int ch) {
	// printf("%d %d\n", 'a', 'z');
	return 'a' <= ch && ch <= 'z';
}

/**
 * implementation in linux: use macro.
 *
 * #define _L      0x02    //lower
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define islower(c)      ((__ismask(c)&(_L)) != 0)
 *
 * const unsigned char _ctype[] = {} // an 256 array indicate _U(upper), _L(lower) etc.
 *
 * http://lxr.missinglinkelectronics.com/linux/include/linux/ctype.h#L27
 */

void test_islower(int (*islowerMethod)(int)) {
	unsigned char c = '\xe5'; // letter å in ISO-8859-1
	printf("In the default C locale, \\xe5 is %slowercase\n", islowerMethod(c) ? "" : "not " );
	setlocale(LC_ALL, "en_GB.iso88591");
	printf("In ISO-8859-1 locale, \\xe5 is %slowercase\n", islowerMethod(c) ? "" : "not " );
}

int main(int argc, char const *argv[])
{
	test_islower(islower1);
	return 0;
}
