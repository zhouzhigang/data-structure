/**
 * isprint.
 * checks if the given character can be printed, i.e. 
 *  it is either a number, or a uppercase letter, a lowercase letter,
 *  or a punctuation character, or space(32, 0x20),
 *  or any graphical character specific to the current C locale.
 *
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * int isgraph(in ch);
 * @param  ch character to classify.
 * @return Non-zero value if the character can be printed, zero otherwise.
 *
 *
 */
#include <stdio.h>

int isprint1(int ch) {
	// char between space(32, 0x20) and ~(126, 0x7E) can be printed.
	return ' ' <= ch && ch <= '~';
}

int main(int argc, char const *argv) {
	return 0;
}
