#include "main.h"

/**
 * search_path - Search for the command in the PATH environment variable
 * @cmd: The command to search for
 * Return: The full path to the command, or NULL if not found
 */
char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (cmd[0] == '/')
	{
		return (strdup(cmd));
	}

	while (dir != NULL)
	{
		char *cmd_path = malloc(strlen(dir) + strlen(cmd) + 2);

		strcpy(cmd_path, dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);

		if (access(cmd_path, X_OK) == 0)
		{
			free(path_copy);
			return (cmd_path);
		}

		free(cmd_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
