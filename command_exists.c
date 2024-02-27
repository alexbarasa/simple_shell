#include "main.h"

/**
 * command_exists - check if a command exists
 * @full_path: the full path to the command
 *
 * Return: 1 if the command exists, 0 otherwise
 */
int command_exists(char *full_path)
{
	struct stat st;

	return (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR));
}
