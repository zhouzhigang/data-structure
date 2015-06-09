#include <stdio.h>

int isalnum1(int ch) {
	return (('0' <= ch && ch <= '9')
		|| ('a' <= ch && ch <= 'z')
		|| ('A' <= ch && ch <= 'Z'));
}
int main(int argc, char const *argv[]) {
	return 0;
}
