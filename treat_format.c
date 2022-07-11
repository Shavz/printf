#include "main.h"
#include <stdio.h>

/**
 * get_print_func - gets the correct printing function
 * @c: specifier
 * Return: pointer to a function
 */

char *(*get_print_func(char c))(modifier_t *, va_list)
{
	int i;
	t_print t[] = {
	    {'c', print_char},
	    {'s', print_string},
	    {'i', print_int},
	    {'d', print_int},
	    {'u', print_unsigned_int},
	    {'o', print_octal},
	    {'x', print_hex},
	    {'X', print_hex},
	    {'b', print_binary},
	    {'S', print_big_s},
	    {'p', print_pointer},
	    {'r', print_rev},
	    {'R', print_rot},
	    {'\0', NULL}};
	for (i = 0; t[i].f; i++)
	{
		if (t[i].f == c)
			return (t[i].func);
	}
	return (NULL);
}

/**
 * treat_format - treats every case of '%' inside format given at pos
 * @format: string
 * @pos: position of '%'
 * @list: va_list
 * Return: result string
 */

char *treat_format(const char *format, unsigned int *pos, va_list list)
{
	char *(*fun_p)(modifier_t *, va_list);
	modifier_t *modif;
	unsigned int end_pos;
	char *res_str, *aux;

	if (!format || !format[(*pos) + 1])
	{
		(*pos)++;
		return (NULL);
	}
	aux = malloc(sizeof(char) * 2);
	aux[0] = '%';
	aux[1] = '\0';
	if (format[(*pos) + 1] == '%')
	{
		(*pos) += 2;
		return (aux);
	}
	end_pos = *pos;
	modif = get_modifier(format, &end_pos);
	if (modif == NULL)
	{
		(*pos)++;
		return (aux);
	}
	fun_p = get_print_func(modif->specifier);
	if (!fun_p)
	{
		free(modif);
		(*pos)++;
		return (aux);
	}
	free(aux);
	res_str = fun_p(modif, list);
	free(modif);
	*pos = end_pos + 1;
	return (res_str);
}
