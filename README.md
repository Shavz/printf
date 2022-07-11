# printf
Creating printf function 
​
## Description
A formatted output conversion C program completed . The program is a recreation of the C standard library function
​
* Prototype: `int _printf(const char *format, ...);`
​
## Usage 
To use the `_printf` compile all `.c` files in the repository and include the header `main.h` with any main function.
​
Example `main.c`:
​
#include "main.h"
​
int main(void)
{
    _printf("Hello, World!");
​
    return (0);
}
​
​
Compilation:
$ gcc *.c -o 
​
Output:
​
$
Hello, World!
$
​
### Return Value
Upon Working successfully the `_printf` returns the number of characters printed
If an error is encountered, the function returns `-1`.
​
#### Conversion Specifiers
The conversion specifier (introduced by the character `%`) is a character that
specifies the type of conversion to be applied. The `_printf` function
supports the following conversion specifiers:
​
#### d, i
The `int` argument is converted to signed decimal notation.
​
Example:
​
    _printf("%d\n", 12);
	_printf("%i\n", -7896);
​
Output:
​
12
-7896
​
​
#### b
The `unsigned int` argument is converted to signed decimal notation.
​
Example `main.c`:
​
    _printf("%b\n", 7);
​
Output:
​
111
​
​
#### o, u, x, X
The `unsigned int` argument is converted to unsigned octal (`o`), unsigned
decimal (`u`), or unsigned hexadecimal (`x` and `X`). The letters `abcdef` are
used for `x` conversions and the letters `ABCDEF` are used for `X` conversions.
​
Example :
​
    _printf("%o\n", 77);
​
Output:
​
115
​
#### c
The argument is converted to an `unsigned char`.
​
Example
​
    _printf("%c\n", 'A');
​
Output:
​
A
​
​
#### s
The ` char *` argument  is a pointer to a character array or
pointer to a string and is printed starting from first element to the end `\0` 
excluding null byte
​
Example
​
    _printf("%s\n", "This is a printf function");
​
Output:
​
This is a printf function
​
​
#### S
Identical to the `S` conversion specifier, except any non-printable characters
in the array (ie. characters with an ASCII value < 32 or >= 127) are printed
as `\x` followed by the ASCII code value in hexadecimal
​
### r
Reverse  the `char *` argument
​
Example:
​
int main(void)
    _printf("r\n", "Hello");
​
Output:
​
olleH
​
​
#### R
 Convert the `char *` to Rot13 
Example:
​
    _printf("%R\n", "Hello, World");
​
Output:
​
Uryyb, Jbeyq
​
​
#### p
The address of the argument is written. The address is written in hexadecimal
with a leading `0x`.
​
Example:
​
    char *str = "Hello, World";
    _printf("%p\n", (void *)str);
​
Output:
​
0x561a6d7bab5d
​
​
#### %
A `%` is written. No argument is converted. The complete conversion
specification is `%%`.
​
Example:
​
    _printf("%%\n");
​
Output:
​
%
​
​
## Other Features
This function also handles :
* The flag characters for non-custom conversion specifiers (`+` `SPACE ` `#`)
* The length modifiers for non-custom conversion(`d, i, u, o, x, X`) specifiers(`l` `h`) 
​
## Contributors:
* Shavin Lillkant
* Matthew Utti
