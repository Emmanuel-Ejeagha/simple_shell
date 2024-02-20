#include "shell.h"

/**
 * vec - it prints environment
 */
void vec(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
