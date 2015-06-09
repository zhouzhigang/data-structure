/**
 * toupper.
 * Defined in header <ctype.h>
 *
 * int toupper( int ch );
 * @param  ch character to be converted.
 *            If the value of ch is not representable as unsigned char and does not equal EOF, the behavior is undefined.
 * @return Uppercase version of ch or unmodified ch if no uppercase version is listed in the current C locale.
 *
 * Converts the given character to uppercase according to the character conversion rules defined by the currently installed C locale.
 * In the default "C" locale, the following lowercase letters abcdefghijklmnopqrstuvwxyz are replaced with respective uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
 *
 * http://en.cppreference.com/w/c/string/byte/toupper
 */
#include <stdio.h>

int toupper1(int ch) {
	if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 'A';
	}
	return ch;
}

void test_toupper(int (*toupperMethod)(int)) {
	/* In the default locale: */
    unsigned char u;
    for (unsigned char l=0; l<255; l++) {
        u = toupperMethod(l);
        if (l!=u) printf("%c%c ", l,u);
    }
}

int main(int argc, char const *argv[])
{
 	test_toupper(toupper1);
 	return 0;
}