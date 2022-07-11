#include "main.h"
/**
 * print_char - prints a char
 * @list: va_list pointer
 * @modif: struct modifier
 * Return: char
 */

char *print_char (modifier_t *modif, va_list list)
{
	char *ch;
	char c;

	if (!list || !modif)
		return (0);
	c = va_arg(list, int);
	ch = malloc(2);
	if (!ch)
	{
		return (NULL);
	}
	if (c)
	{
		ch[0] = c;
	}
	else
	{
		ch[0] = '\0';
	}
	ch[1] = '\0';
	return (ch);
}
