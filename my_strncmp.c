#include "main.h"

/**
 * custom_strncmp - customize strncmp
 * @str1: char pointer
 * @str2: strings
 * @n: variable
 * Return: 0
 */

int custom_strncmp(const char *str1, const char *str2, size_t n) 
{
    while (n > 0 && *str1 && *str2) 
    {
        if (*str1 != *str2) 
	{
            return (*str1 - *str2);
        }
        	str1++;
        	str2++;
        	n--;
    }

    return (0);
}
