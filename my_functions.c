#include "main.h"

/**
 * my_execvp - our customized execvp
 *	runner
 * @file: the argument size
 * @argv: the argument vector
 *
 * Return: (0)
 */
int my_execvp(const char *file, char *const argv[])
{
	char *path;
	char *path_copy;
	char *token;

	if (my_strchr(file, '/') != NULL)
	{
		return (execve(file, argv, environ));
	}

	path = my_getenv("PATH");

	if (path == NULL)
	{
		display_chars("PATH environment variable is not set.\n");
		return (-1);
	}

	path_copy = my_strdup(path);

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char executable_path[1024];

		my_snprintf(executable_path, sizeof(executable_path), "%s/%s", token, file);

		execve(executable_path, argv, environ);

		token = strtok(NULL, ":");
	}

	display_chars("command not found\n");

	free(path_copy);
	return (-1);
}

/**
 * my_vsnprintf_init - initailizes and passes
 *	data to the my_vsnprintf function
 * @str: passed in string
 * @size: the argument size
 * @format: the pattern
 * @args: additional argument
 *
 * Return: (0)
 */

int my_vsnprintf_init(char *str, size_t size, const char *format, va_list args)
{
	size_t count = 0;
	size_t index = 0;
	char *input = NULL;

	my_vsnprintf(str, size, format, args, count, index, input);

	return (0);
}

/**
 * my_snprintf - our customized snprintf
 * @str: passed in string
 * @size: the argument size
 * @format: the pattern
 *
 * Return: (0)
 */
int my_snprintf(char *str, size_t size, const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	count = my_vsnprintf_init(str, size, format, args);
	va_end(args);

	return (count);
}

