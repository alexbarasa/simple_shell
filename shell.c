#include "shell.h"

/**
 * main - simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *cmd = malloc(MAX_CMD_LEN);
	ssize_t nread;
	size_t len = MAX_CMD_LEN;

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell> ", 14);

		nread = getline(&cmd, &len, stdin);
		if (nread == -1)
		{
			/*End of file (Ctrl+D) condition*/
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		/* Remove trailing newline character*/
		cmd[strcspn(cmd, "\n")] = 0;

		handle_command(cmd);
	}

	free(cmd);
	return (0);
}
