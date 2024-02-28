#include "shell.h"

/**
 * search_path - search for a command in the PATH
 * @cmd: the command to search for
 *
 * Return: the full path to the command, or NULL if not found
 */
char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *directory;
	char *full_path = malloc(MAX_CMD_LEN);
	struct stat st;

	directory = strtok(path, ":");

	while (directory != NULL)
	{
		snprintf(full_path, MAX_CMD_LEN, "%s/%s", directory, cmd);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			return (full_path);
		}

		directory = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}
