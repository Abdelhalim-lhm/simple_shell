#include "shell.h"
/**
 * get_linecmd - Function that get the input of the user
 * Return: command line
 */
char *get_linecmd(void)
{
	char *cmd = NULL;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
	{
		print("#cisfun$ ");
	}
	if (getline(&cmd, &len, stdin) < 0)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
