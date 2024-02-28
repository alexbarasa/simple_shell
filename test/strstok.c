#include <string.h>
/**
 * tokenize_command - Splits a given line of strings into words
 *
 * @command: Pointer to string
 * @args: Double pointer to arguments
 */
void tokenize_command(char *command, char **args)
{
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
