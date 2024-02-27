#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

/**
 * handle_command - execute a command
 * @cmd: the command to execute
 */
void handle_command(char *cmd)
{
	char *argv[2];
	int status;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}

	if (pid == 0)
	{
		/*Child process*/
		argv[0] = cmd;
		argv[1] = NULL;

		execve(cmd, argv, NULL);

		/*If execve returns, it must have failed*/
		perror(cmd);
		exit(0);
	}
	else
	{
		/*Parent process*/
		if (waitpid(pid, &status, 0) != pid)
		{
			perror("waitpid failed");
		}
	}
}
/**
 * main - simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf("simple_shell> ");

		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			/*End of file (Ctrl+D) condition*/
			printf("\n");
			exit(0);
		}

		/* Remove trailing newline character*/
		cmd[strcspn(cmd, "\n")] = 0;

		handle_command(cmd);
	}

	return (0);
}
