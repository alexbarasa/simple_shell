#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"
#define MAX_CMD_LEN 1024
/**
 * main - simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	size_t bufsize = 0;
	ssize_t nread;
	char *cmd = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell> ", 14);

		nread = getline(&cmd, &bufsize, stdin);
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
