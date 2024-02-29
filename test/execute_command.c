#include "shell.h"
/**
 * execute_command - execute a command
 * @full_path: the full path to the command
 * @argv: the arguments to the command
 */
void execute_command(char *full_path, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}

	if (pid == 0)
	{
		/*Child process*/
		execve(full_path, argv, NULL);

		/*If execve returns, it must have failed*/
		perror(full_path);
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
