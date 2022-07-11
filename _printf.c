#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * buffer_print - print buffer to stdout
 * @buffer: buffer to print
 * @nbytes: number of bytes to print
 * Return: nbytes
 */

int buffer_print(char buffer[], unsigned int nbytes)
{
	write(1, buffer, nbytes);
	return (nbytes);
}

/**
 * buffer_add - adds string to buffer
 * @buffer: buffer to fill
 * @str: str to add
 * @buffer_pos: pointer to buffer first empty position
 * Return: char
 */

int buffer_add(char buffer[], char *str, unsigned int *buffer_pos)
{
	int i = 0;
	unsigned int count = 0, pos = *buffer_pos, size = BUFFER_SIZE;

	while (str && str[i])
	{
		if (pos == size)
		{
			count += buffer_print(buffer, pos);
			pos = 0;
		}
		buffer[pos++] = str[i++];
	}
	*buffer_pos = pos;
	return (count);
}
