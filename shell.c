#include "shell.h"

/**
 * main - Function that displays a prompt and waits for user input.
 * Return: Waits for user input until end of file condition.
 */
int main(void)
{
	char *cmd = NULL;
	int status = 0;

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
			return (status);
		}
		cmd[strcspn(cmd, "\n")] = '\0';

		if (_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(status);
		}
		if (_strcmp(cmd, "env") == 0)
		{
			free(cmd);
			env();
		}
		status = path(cmd);
		if (status == 100)
		{
			continue;
		}
		free(cmd);
	}
	return (0);
}
