#include "shell.h"
#include <stddef.h>
#include <errno.h>

/**
 * exec_cmd - Function that executes a command with arguments.
 * @cmd: Command to execute.
 * Return: 0 on success.
 */
int exec_cmd(char *cmd)
{
	int status;
	pid_t child_pid;

	char *argv[MAX_CMD_LENGTH / 2];
	int i = 0;

	char *token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (strcmp(argv[0], "/bin/ls") == 0 || strcmp(argv[0], "ls") == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execvp(argv[0], argv) == -1)
			{
				perror("execvp");
				return (1);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	else
	{
		char *path = getenv("PATH");
		char *directories[10];
		int num_directories = 0;

		if (!path)
		{
			fprintf(stderr, "Error: PATH environment variable not set.\n");
			return (1);
		}

		char *path_token;
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			directories[num_directories] = path_token;
			num_directories++;
			path_token = strtok(NULL, ":");
		}

		int cmd_exists = 0;
		char full_path[200];
		for (i = 0; i < num_directories; i++)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", directories[i], argv[0]);

			if (access(full_path, X_OK) == 0)
			{
				cmd_exists = 1;
				break;
			}
		}

		if (!cmd_exists)
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
			return (1);
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execve(full_path, argv, NULL) == -1)
			{
				perror("execve");
				return (1);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
