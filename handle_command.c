#include "main.h"

/**
 * handle_command - handle a command
 * @cmd: the command to handle
 */
void handle_command(char *cmd)
{
	char *argv[MAX_CMD_LEN];
	char *token;
	char *full_path;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL; /*Null-terminate the argument list*/
	/*chek if the command is 'exit*/
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}

	/*check if the command is 'env*/
	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return;
	}

	full_path = search_path(argv[0]);
	if (full_path == NULL)
	{
		printf("%s: command not found\n", argv[0]);
		return;
	}

	execute_command(full_path, argv);

	free(full_path);
}
