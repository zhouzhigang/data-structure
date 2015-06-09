/**
 * isblank.
 * Checks if the given character is a blank in the current C locale.
 * In the default C locale, only space(0x20) and horizontal tab(0x09) are classified as blank.
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 *
 * int ispunct(int ch);
 * @param  ch character to classify.
 * @return No-zero value if the character is a blank character, zero otherwise.
 *
 *
 * 
 */
#include <stdio.h>

int isblank1(int ch) {
	return ch == ' ' || ch == '\t';
}
int main(int argc, char const *argv[]) {
	return 0;
}
