#include "main.h"

/**
 * my_getenv - function to get customized getenv
 * @name: The passed in args
 *
 * Return: (char)
 */
char *my_getenv(const char *name)
{
	char **env;

	if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL)
	return (NULL);

	env = environ;

	while (*env != NULL)
	{
		char *equalSignPos = my_strchr(*env, '=');

		if (equalSignPos != NULL &&
		(size_t)(equalSignPos - *env) == my_strlen(name) &&
		my_strncmp(*env, name, equalSignPos - *env) == 0)
		return (equalSignPos + 1);

		++env;
	}

	return (NULL);
}
