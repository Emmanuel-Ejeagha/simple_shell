#include "main.h"

/**
 * display_chars - Displays passedin chars
 * @format: The passed in char
 *
 * Return: (NULL)
 */

void display_chars(const char *format, ...)
{
	va_list args;
	const char *ptr;

	va_start(args, format);

	ptr = format;

	while (*ptr)
	{
		if (*ptr != '%')
		{
			my_putchar(*ptr);
		}
		else
		{
			char ch = (char)va_arg(args, int);

			my_putchar(ch);
		}
		++ptr;
	}

	va_end(args);
}

/**
 * my_putchar - Writes to the standard output
 * @c: Take in character
 *
 * Return: (Void)
 */
void my_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * my_strcspn -  gets length of the initial portion of stra
 * @stra: character to compared
 * @strb: charcter to be compared with
 *
 * Return: (Void)
 */
size_t my_strcspn(const char *stra, const char *strb)
{
	size_t length = 0;
	char *ptr;

	while (stra[length] != '\0')
	{
		ptr = my_strchr(strb, stra[length]);
		if (ptr != NULL)
		{
			break;
		}
		length++;
	}

	return (length);
}

/**
 * my_strchr -  Works just like strchr
 * @str: passed in character
 * @c: passed in integer value
 *
 * Return: (Void)
 */
char *my_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}

