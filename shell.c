#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - fucntion that display a prompt and wait for user
 * Return: wait for user until end of file condition
 */
int main(void)
{
	char cmd[100];
	int status;
	pid_t child_pid;

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
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (child_pid == 0)
		{
			char *argv[2];

			argv[0] = cmd;
			argv[1] = NULL;

			if (execve(cmd, argv, NULL) == -1)
			{
				perror("./shell");
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
