#include "main.h"

/**
 * my_strcpy - customized strcpy function
 * @destination: output final stack
 * @source: where the reading is made from
 *
 * Return: (void)
 */
void my_strcpy(char *destination, const char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}

/**
 * my_strncmp - customized strncmp function
 * @strx: string to compare
 * @stry: string to compare with
 * @n: size of comparing string
 *
 * Return: (0)
 */
int my_strncmp(const char *strx, const char *stry, size_t n)
{
	while (n--)
	{
		if (*strx != *stry)
		{
			return (*strx - *stry);
		}
		strx++;
		stry++;
	}
	return (0);
}

