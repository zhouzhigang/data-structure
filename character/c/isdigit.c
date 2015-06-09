/**
 * isdigit.
 * Checks if the given character is a numeric character ('0'-'9', 48-57, 0x30-0x39).
 *
 * int isdigit( int ch );
 * @param  ch character to classify
 * @return Non-zero value if the character is a numeric character, zero otherwise.
 *
 * Reference
 * http://en.cppreference.com/w/c/string/byte/isdigit
 * http://lxr.singlinkelectronics.com/linux/arch/x86/boot/ctype.h#L5
 */
#include <stdio.h>
#include <ctype.h>

/**
 * compare with the ascii code.
 */
int isdigit1( int ch ) {
	if (48 <= ch && ch <= 57) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * get the ascii code of the digit.
 * thinking: why minus '0' isn't work?
 */
void get_digit_ascii() {
	int ch = 5;
	printf("%d %d\n", '0', '9');
	// if we want get the ascii code of a digit, we can add '0' to it.
	printf("%d %d\n", ch + '0', ch - '0');
}

/**
 * use the digit char style directly(use ascii code is not easy to understand).
 * thinking: why the parameter is int, not char?
 */
int isdigit2( int ch ) {
	if ('0' <= ch && ch <= '9') {
		return 1;
	} else {
		return 0;
	}
}

/**
 * a more compact version, just retrun compare the result.
 */
int isdigit3(int ch) {
	return '0' <= ch && ch <= '9';
}

/**
 * use inline to optimize it.
 * thinking: will modern compiler do that?
 * simular implementation
 * http://lxr.linux.no/linux+v3.19.1/arch/x86/boot/ctype.h#L5
 */
int static inline isdigit4(int ch) {
	return '0' <= ch && ch <= '9';
}
/**
 * other implementation: use macro instead.
 * http://lxr.linux.no/linux+v3.19.1/arch/powerpc/kernel/prom_init.c#L528
 */
#define isdigit5(c)      ('0' <= (c) && (c) <= '9')

/**
 * implementation in linux: use macro instead.
 *
 * #define _D      0x04    // digit
 * extern const unsigned char _ctype[];
 * #define __ismask(x) (_ctype[(int)(unsigned char)(x)])
 * #define isdigit(c)      ((__ismask(c)&(_D)) != 0)
 *
 * const unsigned char _ctype[] = {}; // an 256 array indicate _D(digit) etc.
 *
 * http://lxr.linux.no/linux+v3.19.1/include/linux/ctype.h#L25
 * http://lxr.linux.no/linux+v3.19.1/lib/ctype.c#L11
 */

void test_isdigit(int (*isdigitMethod)(int)) {
	char valid_char[] = {'0', '5', '9'};
	char failed_char[] = {'a', 'z', 'A', 'Z', '+', '*', '!', '&'};
	int failed_int[] = {0, 5, 9};
}

void print_all_digits(int (*isdigitMethod)(int)) {
	for (int ndx=0; ndx<=255; ndx++)
		if (isdigitMethod(ndx)) printf("%c ", ndx);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	get_digit_ascii();

	printf("%d %d %d %d\n", isdigit(0), isdigit(9), isdigit('0'), isdigit('9'));

	printf("%d %d %d %d\n", isdigit2(0), isdigit2(9), isdigit2('0'), isdigit2('9'));
	printf("%d %d %d %d\n", isdigit3(0), isdigit3(9), isdigit3('0'), isdigit3('9'));
	printf("%d %d %d %d\n", isdigit4(0), isdigit4(9), isdigit4('0'), isdigit4('9'));
	printf("%d %d %d %d\n", isdigit5(0), isdigit5(9), isdigit5('0'), isdigit5('9'));
	print_all_digits(isdigit4);
	return 0;
}


/**
 * compare the efference ot these methods.
 *
 * in fact, the assembly code is almost the same.
 * gcc -S
 *   movl	%ecx, 16(%rbp)
 *   cmpl	$47, 16(%rbp)
 *   jle	.failed
 *   cmpl	$57, 16(%rbp)
 *   jg	.failed
 *   movl	$1, %eax
 *   jmp	.success
 */
void time_isdigit() {

}
