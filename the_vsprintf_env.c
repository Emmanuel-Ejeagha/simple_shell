#include "main.h"

/**
 * my_vsnprintf_child - holds path of
 *  my_vsprintf codes
 * @size: passed in string
 * @count: the argument size of count passed
 *
 * Return: (0)
 */
int my_vsnprintf_child(size_t size, size_t count)
{
	if (count >= size - 1)
	{
		return (count);
	}

	return (0);
}

/**
 * my_vsnprintf - our customized vsnprintf
 * @str: passed in string
 * @size: the argument size
 * @format: the pattern
 * @args: the argument
 * @count: the size of number of counts
 * @index: size of the index
 * @input: a pointer to the input
 *
 * Return: (0)
 */

int my_vsnprintf(char *str, size_t size, const char *format, va_list args,
		size_t count, size_t index, char *input)
{
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;

			if (format[index] == 's')
			{
				input = va_arg(args, char *);

				while (*input)
				{
					if (count >= size - 1)
					{

						return (count);
					}
					str[count++] = *input++;
				}
			}
			else if (format[index] == 'd')
			{
				display_chars("chech rhe my_functions1 , my_vsnprintf, 120");
			}

			index++;
			}
			else
			{
				my_vsnprintf_child(size, count);

				str[count++] = format[index++];
			}
	}

	str[count] = '\0';

	return (count);
}

