#include "shell.h"
/**
 * exec_cmd - fucntion that execute commande with 1 argument
 * @cmd: command to execute
 * Return: 0 on success
 */
int exec_cmd(char *cmd)
{
	int status, i = 0;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (child_pid == 0)
	{
		char *argv[3];

		argv[2] = NULL;
		argv[i] = strtok(cmd, " ");
		while (i < 2 && argv[i] != NULL)
		{
			i++;
			argv[i] = strtok(NULL, " ");
		}
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			return (1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (0);
}
