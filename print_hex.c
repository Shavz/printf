#include "main.h"

/**
 * treat_flags_hex - check flags
 * @flags: string of flags
 * @buffer: to store result
 * @size: size of buffer
 * @_case: case of characters
 */

void treat_flags_hex(char *flags, char *buffer, int *size, char _case)
{
	int i;

	for (i = 0; flags && flags[i]; i++)
	{
		if (flags[i] == '#')
		{
			buffer[(*size)++] = _case + 23;
			buffer[(*size)++] = '0';
		}
	}
}
/**
 * print_hex - print decimal as hexadecimal
 * @modif: struct modifier
 * @list: va_list pointer
 * Return: number of printed characters
 */

char *print_hex(modifier_t *modif, va_list list)
{
	unsigned int n, aux;
	int i = 0, j = 0;
	char buffer[11], _case, *res_str;

	if (!list || !modif)
		return (0);
	n = va_arg(list, unsigned int);
	_case = modif->specifier == 'x' ? 'a' : 'A';
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
			aux = n % 16;
			if (aux > 9)
				buffer[i++] = (aux % 10) + _case;
			else
				buffer[i++] = aux + '0';
			n = n / 16;
		}
		treat_flags_hex(modif->flags, buffer, &i, _case);
		res_str = malloc(sizeof(char) * i);
		i--;
		while (i >= 0)
		{
			res_str[j++] = buffer[i--];
		}
	}
	res_str[j] = '\0';
	return (res_str);
}
