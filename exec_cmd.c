#include "shell.h"
/**
 * exec_cmd - fucntion that execute commande with arguments
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
		char *argv[50];

		argv[i] = strtok(cmd, " ");
		while (argv[i] != NULL)
		{
			i++;
			argv[i] = strtok(NULL, " ");
		}
		argv[i + 1] = NULL;
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
