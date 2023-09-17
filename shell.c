#include "shell.h"
/**
 * main - fucntion that display a prompt and wait for user
 * Return: wait for user until end of file condition
 */
int main(void)
{
	char cmd[MAX_CMD_LENGTH];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		write(STDOUT_FILENO, "#cisfun$ ", strlen("#cisfun$ "));
		fflush(stdout);
		}
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
			break;
		cmd[strcspn(cmd, "\n")] = '\0';
		exec_cmd(cmd);
	}
	return (0);
}
