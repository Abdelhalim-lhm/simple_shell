#include "shell.h"
/**
 * get_command_path - Get the full path of a command.
 * @cmd: The command to find.
 * Return: The full path of the command if found, otherwise NULL.
 */
char *get_command_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir, *saveptr, *path_copy;

	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok_r(path_copy, ":", &saveptr);
	while (dir)
	{
	char full_path[MAX_PATH_LENGTH];

	if (strncmp(cmd, "./", 2) == 0 || strncmp(cmd, "../", 3) == 0)
	{
	char *current_dir = getcwd(NULL, 0);

		if (current_dir)
		{
			_strcpy(full_path, current_dir);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			free(current_dir);
		}
	}
	else
	{
		_strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);
	}
	if (access(full_path, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(full_path));
	}
	dir = strtok_r(NULL, ":", &saveptr);
	}
	free(path_copy);
	return (NULL);
}
