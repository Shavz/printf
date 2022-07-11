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
