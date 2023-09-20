#include "shell.h"

/**
 * main - Function that displays a prompt and waits for user input.
 * Return: Waits for user input until end of file condition.
 */
int main(void)
{
	char *cmd = NULL;

	while (1)
	{
		cmd = get_linecmd();
		if (cmd == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
			print("\n");
			}
			free(cmd);
			return (0);
		}
		cmd[strcspn(cmd, "\n")] = '\0';

		if (_strcmp(cmd, "exit") == 0)
		{
			exit(0);
		}
		if (_strcmp(cmd, "env") == 0)
		{
			env();
		}
		if (path(cmd) == 100)
		{
			continue;
		}
	}
	return (0);
}
