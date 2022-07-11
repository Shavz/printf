#include "main.h"
/**
 * print_rev - print a string in reverse
 * @list: va_list
 * @modif :struct modifier
 * Return: string
 */

char *print_rev(modifier_t *modif, va_list list)
{
	int i;
	int length;
	char *str, *ret;

	if (!list || !modif)
		return (0);
	str = va_arg(list, char *);
	length = _strlen(str);
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	for (i = 0; i < length; i++)
		ret[i] = str[length - i - 1];
	ret[i] = '\0';

	return (ret);
}
