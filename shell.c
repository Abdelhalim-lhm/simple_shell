#include "shell.h"

/**
 * main - Function that displays a prompt and waits for user input.
 * Return: Waits for user input until end of file condition.
 */
int main(void)
{
	char cmd[MAX_CMD_LENGTH];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print("#cisfun$ ");
			fflush(stdout);
		}
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
			break;
		cmd[strcspn(cmd, "\n")] = '\0';

		if (strcmp(cmd, "exit") == 0)
		{
			print("Exiting the shell...\n");
			exit(0);
		}
		if (strcmp(cmd, "env") == 0)
		{
			env();
		}

		if (path(cmd) != 0)
		{
			print("Command execution failed for: %s\n", cmd);
		}
	}

	return (0);
}
