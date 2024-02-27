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
	char *argv[MAX_CMD_LEN];
	char *token;
	int i = 0;
	int status;
	pid_t pid;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL; /*Last element should be NULL for execve*/

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}

	if (pid == 0)
	{
		/*Child process*/
		execve(argv[0], argv, NULL);

		/*If execve returns, it must have failed*/
		perror(argv[0]);
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
