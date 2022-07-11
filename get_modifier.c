#include "main.h"
#include <stdio.h>

/**
 * free_modifier - free struct modifier
 * @modif: pointer to struct modifier to free
 */

void free_modifier(modifier_t *modif)
{
	free(modif->flags);
	free(modif->length);
	free(modif);
}
/**
 * get_modifier - checks for specific mod to use
 * @s: string
 * @pos: position to start
 * Return: pointer
 */

modifier_t *get_modifier(const char *s, unsigned int *pos)
{
	modifier_t *modif;
	unsigned int i = *pos;

	if (s[i + 1] == '\0')
		return (NULL);
	modif = malloc(sizeof(modifier_t));
	if (modif == NULL)
		return (NULL);
	modif->flags = get_flags(s, &i);
	modif->width = get_width(s, &i);
	modif->precision = get_precision(s, &i);
	modif->length = get_length(s, &i);
	modif->specifier = get_specifier(s, &i);

	if (!modif->specifier)
	{
		free_modifier(modif);
		return (NULL);
	}
	(*pos) = i;
	return (modif);
}
