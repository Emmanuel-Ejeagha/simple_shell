#include "shell.h"

/**
 * cd_command - handle change directory
 * @path: regular path
 * Return: (1).
 */
int cd_command(char *path)
{
	char *token_array[100];

	printf("%s\n", path);
	str_tok(path, token_array);
	printf("%s\n", token_array[0]);
	return (1);
}
