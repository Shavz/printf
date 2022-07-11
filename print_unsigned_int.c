include "main.h"
/**
 * print_unsigned_int - print unsigned integer
 * @modif: struct
 * @list: va_list
 * Return: number of printed characters
 */
char *print_unsigned_int(modifier_t *modif, va_list list)
{
    unsigned int n;
    int i = 0, j = 0;
    char buffer[10], *res_str;
    if (!list || !modif || modif->specifier != 'u')
        return (NULL);
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
            buffer[i++] = (n % 10) + '0';
            n = n / 10;
        }
        res_str = malloc(sizeof(char) * i);
        i--;
        while (i >= 0)
            res_str[j++] = buffer[i--];
    }
    res_str[j] = '\0';
    return (res_str);
}
