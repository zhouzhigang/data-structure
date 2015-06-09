/**
 * ispunct.
 * Checks if the given character is a punctuation in the current C locale.
 * The default C locale classifies the characters !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ as punctuation.
 *  33-47, 0x21-0x2F: !"#$%&()*+,-./
 *  58-64, 0x3A-0x40: :;<=>?@
 *  91-96, 0x5B-0x60: [\]^_`
 *  123-126, 0x7B-0x7E: {\}~
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * int ispunct(int ch);
 * @param  ch character to classify.
 * @return No-zero value if the character is a punctuation character, zero otherwise.
 *
 *
 * 
 */
#include <stdio.h>

int ispunct1(int ch) {
	return (('!' <= ch && ch <= '/')
		|| (':' <= ch && ch <= '@')
		|| ('[' <= ch && ch <= '`')
		|| ('{' <= ch && ch <= '~'));
}
int main(int argc, char const *argv[]) {
	return 0;
}
