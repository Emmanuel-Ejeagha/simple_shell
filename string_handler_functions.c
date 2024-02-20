#include "main.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	if (c == '\n')
	{
		char newline = '\n';

		return (write(1, &newline, 1));
	}
	else
		return (write(1, &c, 1));
}
/**
 * _strcpy - copy a string from on location to another
 * @dest: the destination to copy to
 * @src: the string to be copied
 * Return: a pointer to the destination or null
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * tokenize_str -convert a string to an array of tokens separated by a space
 * @str: the string to be tokenized
 * @str_arr: an array holding the tokens produced
 * @max: the size of the resultant array
 * Return: nothing
*/
void tokenize_str(const char *str, char *str_arr[], int max)
{
	char *str_copy = _strcpy((char *)malloc(strlen(str) + 1), str);
	char delim[] = " ", *token;
	int i, token_count;

	if (str_copy == NULL)
	{
		perror("malloc");
		return;
	}

	token = strtok(str_copy, delim);
	token_count = 0;

	while (token != NULL && token_count < max)
	{
		str_arr[token_count] = _strcpy((char *)malloc(strlen(token) + 1), token);
		if (str_arr[token_count] == NULL)
		{
			perror("malloc");
			break;
		}

		token = strtok(NULL, delim);
		token_count++;
	}

	for (i = token_count; i < max; i++)
		str_arr[i] = NULL;

	free(str_copy);

}
/**
* _print_str - function that calls the _putchar
* _putchar - writes the character c to stdout
* @string: characters passed
* Return: On success 1.
*/
void _print_str(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}
/**
 * strdup_static - duplicate a line with dynamic memory allocation
 * @str: the string to be duplicated
 * Return: pointer to the duplicate string
*/

char *strdup_static(const char *str)
{
	static char buffer[BUFF_SIZE];

	strncpy(buffer, str, sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';

	return (buffer);
}
