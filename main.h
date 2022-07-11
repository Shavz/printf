#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

/**
 * struct modifier - modifier fields
 * @flags: flags field
 * @width: width field
 * @precision: precision field
 * @length: length field string
 * @specifier: specifier character
 */

typedef struct modifier
{
	char *flags;
	int width;
	int precision;
	char *length;
	char specifier;
} modifier_t;

void *_realloc(void *ptr, unsigned int, unsigned int);
int _putchar(char c);
char *print_binary(modifier_t *, va_list);
char *print_unsigned_int(modifier_t *, va_list);
char *print_octal(modifier_t *, va_list);
char *print_hex(modifier_t *, va_list);
char *print_char(modifier_t *, va_list list);
char *print_int(modifier_t *, va_list list);
char *print_string(modifier_t *modif, va_list list);
char *print_rev(modifier_t *, va_list list);
char *print_big_s(modifier_t *, va_list);
char *print_pointer(modifier_t *, va_list);
char *rot13(char *s);
int _strlen(char *s);
char *print_rot(modifier_t *, va_list list);

void free_modifier(modifier_t *);
char *get_flags(const char *, unsigned int *);
int get_width(const char *, unsigned int *);
int get_precision(const char *, unsigned int *);
char *get_length(const char *, unsigned int *);
char get_specifier(const char *, unsigned int *);
modifier_t *get_modifier(const char *, unsigned int *);
char *treat_format(const char *, unsigned int *, va_list);
int _printf(const char *format, ...);
char *_strcpy(char *dest, char *src);
void array_rev(char *arr, int len);
int int_len(int num);
char *ito(int n);
char *reverse(char *s);

/**
 * struct print - multiple choice print
 * @f: char
 * @func: function
 */

typedef struct print
{
	char f;
	char *(*func)(modifier_t *, va_list);
} t_print;

#endif
