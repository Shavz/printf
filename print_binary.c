#include "main.h"

/**
 * print_binary - print unsigned int as binary
 * @modif: struct
 * @list: va_list pointer
 * Return: number of printed characters
 */

char *print_binary(modifier_t *modif, va_list list)
{
	unsigned int n;
	int i = 0, j = 0;
	char binary[35], *res_str;

	if (!list || !modif || modif->specifier != 'b')
		return (0);
	n = va_arg(list, unsigned int);
	if (n == 0)
	{
		j = 1;
		res_str = malloc(sizeof(char) * 2);
		res_str[0] = '0';
	}
	else
	{
		while (n)
		{
			binary[i++] = '0' + (n % 2);
			n = n / 2;
		}
		res_str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
			res_str[j++] = binary[i--];
	}
	res_str[j] = '\0';
	return (res_str);
}
