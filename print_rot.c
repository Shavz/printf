#include "main.h"
/**
 * _isalpha - checks if character is alpha
 * @c: char
 * Return: 1
 */

int _isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * print_rot - encodes a string into rot13
 * @list: va_list
 * @modif:struct modifier
 * Return: count of string
 */

char *print_rot(modifier_t *modif, va_list list)
{
int index, length;
	unsigned char temp_c;
	char is_upper;
	char *str, *ret;

	if (!list || !modif)
		return (0);
	str = va_arg(list, char *);
	length = _strlen(str);
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);
	index = 0;
	while (str[index])
	{
		temp_c = (unsigned char)str[index];
		if (_isalpha(temp_c))
		{
			is_upper = (temp_c >= 'A' && temp_c <= 'Z');
			temp_c += 13;
			if (is_upper)
			{
				if (temp_c > 'Z')
					temp_c -= 26;
			}
			else
			{
				if (temp_c > 'z')
					temp_c -= 26;
			}
		}
		ret[index] = (char)temp_c;
		index++;
	}
	ret[length] = '\0';
	return (ret);
}
