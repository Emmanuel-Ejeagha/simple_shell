#include "main.h"

/**
 * my_strcmp - compares two strings
 * @strx: string to comppare
 * @stry: string to be compared with
 * Return: (EXIT_SUCCESS)
 */
int my_strcmp(const char *strx, const char *stry)
{
	while (*strx && *stry)
	{
		if (*strx != *stry)
		{
			break;
		}
		strx++;
		stry++;
	}

	return (*strx - *stry);
}

/**
 * my_strcmp2 - compares two strings
 * @strx: string to comppare
 * @stry: string to be compared with
 * Return: (0)
 */
int my_strcmp2(const char *strx, const char *stry)
{
	while (*strx && *stry)
	{
		if (*strx != *stry)
		{
			break;
		}
		strx++;
		stry++;
	}

	if (*strx == *stry)
	{
		return (0);
	}
	else
	{
		return (*strx - *stry);
	}
}

/**
 * my_strdup - customized strdup
 * @src: reading from
 * Return: (char)
 */
char *my_strdup(const char *src)
{
	size_t len;
	char *dest;

	if (src == NULL)
	{
		return (NULL);
	}

	len = my_strlen(src);
	dest = malloc(len + 1);

	if (dest == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	my_strcpy(dest, src);
	return (dest);
}

/**
 * my_strlen - custom strlen
 *	runner
 * @str: reading from
 *
 * Return: (NULL)
 */
size_t my_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

