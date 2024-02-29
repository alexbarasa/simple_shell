#include "shell.h"
/**
 * build_full_path - build the full path to a command
 * @directory: the directory containing the command
 * @cmd: the command
 *
 * Return: the full path to the command
 */
char *build_full_path(char *directory, char *cmd)
{
	char *full_path = malloc(MAX_CMD_LEN);

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, cmd);
	return (full_path);
}
