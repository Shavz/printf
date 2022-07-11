#include "main.h"

/**
 * ctox - print character as hexadecimal
 * @c: character to print
 * Return: hex of char
 */

char *ctox(char c)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 2);
	buffer[1] = c % 16;
	c /= 16;
	c %= 16;
	if (c > 9)
		buffer[0] = (c % 10) + 'A';
	else
		buffer[0] = c + '0';
	if (buffer[1] > 9)
		buffer[1] = (buffer[1] % 10) + 'A';
	else
		buffer[1] = buffer[1] + '0';
	return (buffer);
}
