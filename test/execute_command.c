#include "main.h"

/**
 * execute_command - Execute the command
 * @argv: An array of arguments
 * Return: Nothing
 */
void execute_command(char **argv)
{
	char *cmd_path;
	int status;
	pid_t pid;

	cmd_path = search_path(argv[0]);
	if (cmd_path == NULL)
	{
		printf("%s: command not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(cmd_path, argv, NULL);

		perror("execve error");
		exit(1);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
}
