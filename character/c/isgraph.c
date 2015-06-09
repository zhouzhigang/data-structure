/**
 * isgraph.
 * checks if the given character has a graphical representation, i.e. 
 *  it is either a number, or a uppercase letter, a lowercase letter,
 *  or a punctuation character, or any graphical character specific to the current C locale.
 *
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * int isgraph(in ch);
 * @param  ch character to classify.
 * @return Non-zero value if the character has a graphical representation character, zero otherwise.
 *
 *
 */
#include <stdio.h>

int isgraph1(int ch) {
	// char between '!'(33, 0x21) and '~'(126, 0x7E) has a graphical representation.
	return '!' <= ch && ch <= '~';
}

int main(int argc, char const *argv) {
	return 0;
}
