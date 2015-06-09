# Character

## Overview

### Why we need characrter functions?
* character handling is important and used frenquently
* more easy to use and standarad for different character set(ASCII etc.)

## Character class

`digit`: `0`-`9`

`hexadcimal digit`: a digit or `a`-`f` or `A`-`f`

`lowercase letter`: `a`-`z`, plus possibly others when outside of "c" locale.

`uppercase letter`: `A`-`Z`, plus possibly others when outside of "c" locale.

`letter`: lowercase or upppercase letter, plus possibly others when outside of "c" locale.

`alphanumeric`: letter or digit.

`graphic`: occupies one print position and visible when wrritten to a display device.

`punctuation`: a graphic character that is not an alphanumeric, including at least the 29 such characters used to represent C source text.

`printable`: a graphic character or the space character `' '`

`space`: the space character `' '`, one of five standara motion control characters(form feed `FF`, newline `NL`, carriage return `CR`, horizontal tab `HT`, vertical tab `VT`)

`control`: one of the five standard motion control characters, backspace `BS`, alert `BEL`, plus possibly others.

## Character handling
Defined in header `<ctype.h>`

[`isalnum`](isalnum.c) test for any character for which `isalpha` or `isdigit` is true.

[`isalpha`](isalpha.c) test for any character for which `issuper` or `islower` is true or any character that is one of an implementation-defined set of characters for which none of `iscntrl`, `isdigit`, `ispunct`, `isspace` is true.

[`islower`](islower.c) test for any character that is a lowercase letter or any character that is one of an implementation-defined set of characters for which none of `iscntrl`, `isdigit`, `ispunct`, `isspace` is true.

[`isupper`](isupper.c) test for any character that is a supercase letter or any character that is one of an implementation-defined set of characters for which none of `iscntrl`, `isdigit`, `ispunct`, `isspace` is true.

[`isdigit`](isdigit.c) test for any decimal-digit character.

[`isxdigit`](isxdigit.c) test for any hexadecimal-digit character.

[`iscntrl`](iscntrl.c) test for any control character.

[`isspace`](isspace.c) test for any character that is a standard white-space or is one of an implementaion-defined set of characters for which `isalnum` is false.

[`isblank`](isblank.c)(C99) test for any blank character.

[`isgraph`](isgraph.c) test for any priting character except space(`' '`).

[`isprint`](isprint.c) test for any priting character including space(`' '`).

[`ispunct`](ispunct.c) test for any printing character that is neither space(`' '`) nor a character for which `isalnum` is true.


## Character case mapping
[`tolower`](tolower.c) converts a character to corresponding lowercase.

[`toupper`](toupper.c) converts a character to corresponding uppercase.

**Note**: additional functions whose names begin with either to or is, followed by a lowercase letter, may be added to the header ctype.h in future and should not be defined by programs that include that header.

## Reference
* [C character classification - Wikipedia](http://en.wikipedia.org/wiki/C_character_classfication)
* [The Standard C Library by P. J. Plauger - Chapter 2 ctype.h](http://plauger.com/books.html) [Pdf](http://read.pudn.com/downloads149/ebook/643972/The%20SStandard%20C%20Library.pdf)
* [Cpp Reference - String](http://en.cppreference.com/w/c/string/byte)
* [The GNU C library - Character Handling](http://www.gnu.org/software/libc/manual/html_node/Character-Handling.html)
* [The C Library Reference Guide by Eric Huss - ctype.h](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.2.html)
* [Linux Cross Reference - ctype.h](https://lxr.missinglinkelectronics.com/linux/include/linux/ctype.h)
