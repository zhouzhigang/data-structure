/**
 * tolower.
 * Defined in header <ctype.h>
 *
 * int tolower( int ch );
 * @param  ch character to be converted.
 *            If the value of ch is not representable as unsigned char and does not equal EOF, the behavior is undefined.
 * @return Lowercase version of ch or unmodified ch if no lowercase version is listed in the current C locale.
 *
 * Converts the given character to lowercase according to the character conversion rules defined by the currently installed C locale.
 * In the default "C" locale, the following uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ are replaced with respective lowercase letters abcdefghijklmnopqrstuvwxyz.
 *
 * http://en.cppreference.com/w/c/string/byte/tolower
 */
#include <stdio.h>

int tolower1(int ch) {
	if(ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 'a';
	}
	return ch;
}

void test_tolower(int (*tolowerMethod)(int)) {
	int l;
	for (int u=0; u<255; u++) {
		l = tolowerMethod(u);
		if (l!=u) {
			printf("%c%c ", u,l);
		}
	}
	printf("\n\n");
}

int main(int argc, char const *argv[])
{
	test_tolower(tolower1);
	return 0;
}