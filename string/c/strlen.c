/**
 * strlen
 * Defined in header <string.h>
 *
 * size_t strlen( const char *str );
 * @param  str pointer to the null-terminated byte string to be examined
 * @return The length of the null-terminated string str.
 *
 * Returns the length of the given byte string(character array), not including null character
 * The behavior is undefined if there is no null character in the character array pointed to by str.
 *
 * Reference
 * http://en.cppreference.com/w/c/string/byte/strlen
 * http://lxr.linux.no/linux+v3.19.1/arch/x86/boot/string.c#L128
 */
#include <stdio.h>
#include <string.h>

/**
 * simple version: use a int number to count the string length.
 */
size_t strlen1(const char* str) {
    int len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

/**
 * use pointer instead of number to optimize.
 * thinking: why pointer is more efficient than normal data type?
 * note: this method has defect.
 */
size_t strlen2(const char* str) {
    char* p = (char*)str;
    while (*p++ != '\0') {
    }
    return p - str;
}
/**
 * we should not convert const char* to char*.
 * in fact, we can define the pointer as const char*.
 * note: this method is still not right.
 */
size_t strlen3(const char* str) {
    const char* p = str;
    while (*p++ != '\0') {
    }
    return p - str;
}

/**
 * we should only increase the pointer when current char is not NUL.
 * in previous version, we always increase the pointer.
 * simular with the arm version in linux.
 * http://lxr.linux.no/linux+v3.19.1/arch/arm/boot/compressed/string.c#L59
 */
size_t strlen4(const char* str) {
    const char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

/**
 * for version.
 * simular with the x86 version in linux.
 * http://lxr.linux.no/linux+v3.19.1/arch/x86/boot/string.c#L128
 * thinking: the difference between whiile and for version.
 */
size_t strlen5(const char* str) {
    const char* p;
    for(p = str; *p != '\0'; p++) {
        // do noting
    }
    return p - str;
}

int main(int argc, char const *argv[])
{
    char strArr[] = "char array";
    const char* str = "char pointer";
    int len = strlen(str);
    int len1 = strlen1(str);
    int len2 = strlen2(str);
    int len3 = strlen3(str);
    int len4 = strlen4(str);
    int len5 = strlen5(str);
    printf("%d, %d, %d, %d, %d, %d\n", len, len1, len2, len3, len4, len5);
    return 0;
}
