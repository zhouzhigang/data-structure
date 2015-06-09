/**
 * isalpha.
 * Defined in header <ctype.h>
 *
 * int isalpha( int ch );
 * @param  ch character to classify
 * @return Non-zero value if the character is an alphabetic character, zero otherwise.
 *
 * Checks if the given character is an alphabetic character,
 * i.e. either an uppercase letter (ABCDEFGHIJKLMNOPQRSTUVWXYZ),
 * or a lowercase letter (abcdefghijklmnopqrstuvwxyz).
 *
 * In locales other than "C", an alphabetic character is a character for which isupper() or islower() returns true
 * or any other character considered alphabetic by the locale.
 * In any case, iscntrl(), isdigit(), ispunct() and isspace() will return false for this character.
 *
 * Reference
 * http://en.cppreference.com/w/c/string/byte/isalpha
 */
#include <stdio.h>
#include <locale.h>

/**
 * wrong implementation.
 */
int isalpha1(int ch) {
	// printf("%d %d %d %d\n", 'A', 'Z', 'a', 'z');
	return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

/**
 * implementatio in linux: : use macro.
 *
 * #define _U      0x01    // upper
 * #define _L      0x02    // lower
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define isalpha(c)      ((__ismask(c)&(_U|_L)) != 0)
 *
 * const unsigned char _ctype[] = {}; // an 256 array indicate _U(upper), _L(lower) etc.
 *
 * http://lxr.missinglinkelectronics.com/linux/include/linux/ctype.h#L23
 *
 */

void test_isalpha(int (*isalphaMethod)(int)) {
	unsigned char c = '\xdf'; // German letter ß in ISO-8859-1
	printf("isalpha('\\xdf') in default C locale returned %d\n", !!isalphaMethod(c));

	setlocale(LC_CTYPE, "de_DE.iso88591");
	printf("isalpha('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalphaMethod(c));
}

int main(int argc, char const *argv[])
{
	test_isalpha(isalpha1);
	return 0;
}
