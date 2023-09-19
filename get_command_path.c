#include "shell.h"

/**
 * get_command_path - Obtenir le chemin complet d'une commande.
 * @cmd: La commande à rechercher.
 * Return: Une chaîne allouée contenant le chemin complet de la commande
 */
char *get_command_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir, *saveptr;
	char *path_copy;

	if (!path)
		return (NULL);

	path_copy = strdup(path);

	if (!path_copy)
		return (NULL);

	dir = strtok_r(path_copy, ":", &saveptr);

	while (dir)
	{
		char full_path[200];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);

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
