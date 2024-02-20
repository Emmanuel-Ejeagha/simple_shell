#include "main.h"

/**
 * ctrl_c- ctrl with c key press
 *  signal handler
 *@signum: the signal
 *
 * Return: (void)
 */

void ctrl_c(int signum)
{
	if (signum == SIGINT)
	{
		signal(SIGINT, ctrl_c);
		display_chars("\n");
		display_chars("$ ");
		fflush(stdout);
	}
}
