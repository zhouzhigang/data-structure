#String

# Null-terminated byte strings
A null-terminated byte string (NTBS) is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character). Each byte in a byte string encodes one character of some character set. For example, the character array `{'\x63','\x61','\x74','\0'}` is an NTBS holding the string `"cat"` in ASCII encoding.

## Functions

### String manipulation
Defined in header `<string.h>`
`strcpy`/`strcpy_s`(C11) copies one string to another (function)

`strncpy`/`strncpy_s`(C11) copies a certain amount of characters from one string to another (function)

`strcat`/`strcat_s`(C11) concatenates two strings (function)

`strncat`/`strncat_s`(C11) concatenates a certain amount of characters of two strings (function)

`strxfrm` transform a string so that strcmp would produce the same result as strcoll (function)

### String examination
Defined in header `<string.h>`

`strlen`/`strnlen_s`(C11) returns the length of a given string (function)

`strcmp` compares two strings  (function)

`strncmp` compares a certain amount of characters of two strings (function)

`strcoll` compares two strings in accordance to the current locale (function)

`strchr` finds the first occurrence of a character (function)

`strrchr` finds the last occurrence of a character (function)

`strspn` returns the length of the maximum initial segment that consists of only the characters found in another byte string (function)

`strcspn` returns the length of the maximum initial segment that consists of only the characters not found in another byte string (function)

`strpbrk` finds the first location of any character in one string, in another string (function)

`strstr` finds the first occurrence of a substring of characters (function)

`strtok`/`strtok_s`(C11) finds the next token in a byte string (function)

### Character array manipulation
Defined in header `<string.h>`

`memchr` searches an array for the first occurrence of a character (function)

`memcmp` compares two buffers (function)

`memset`/`memset_s`(C11) fills a buffer with a character (function)

`memcpy`/`memcpy_s`(C11) copies one buffer to another (function)

`memmove`/`memmove_s`(C11) moves one buffer to another (function)

### Miscellaneous

Defined in header `<string.h>`

`strerror`/`strerror_s`(C11)/`strerrorlen_s`(C11) returns a text version of a given error code (function)

## Reference
* [C String handling - Wikipedia](http://en.wikipedia.org/wiki/C_string_handling)
* [Cpp reference - String](http://en.cppreference.com/w/c/string/byte)
* [The Standard C Library by P. J. Plauger - Chapter 14 string.h](http://plauger.com/books.html)

