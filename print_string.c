#include "main.h"
/**
 * _strcpy - copy string to another
 * @dest:dest
 * @src:source
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * print_string - print a string
 * @modif: struct
 * @list: va_list
 * Return: return pointer of the beginning of string
 */

char *print_string(modifier_t *modif, va_list list)
{
	char *str;
	char *res;

	if (!list || !modif)
		return (0);
	str = va_arg(list, char *);
	if (str == NULL)
	{
		res = malloc(sizeof(char) * 7);
		res = _strcpy(res, "(null)");
		return (res);
	}
	if (str[0] == '\0')
		return (NULL);
	res = malloc(_strlen(str) + 1);
	if (!res)
		return (NULL);
	res = _strcpy(res, str);
	return (res);
}
