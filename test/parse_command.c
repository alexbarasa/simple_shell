#include "main.h"

/**
 * parse_command - Parse the command into an array of arguments
 * @cmd: The command to parse
 * @argv: An array of arguments
 * Return: Nothing
 */
void parse_command(char *cmd, char **argv)
{
	int i = 0;

	argv[i] = strtok(cmd, " ");
	while (argv[i] != NULL)
	{
		argv[++i] = strtok(NULL, " ");
	}
}
