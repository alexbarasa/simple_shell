<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024
/**
 * execute_command - Executes the tokenized commands using execve function
 *
 * @command: Pointer to the tokenized command
 * @args: Double pointer to the arguments
 */
void execute_command(char **args)
=======
#include "main.h"
/**
 * execute_command - execute a command
 * @full_path: the full path to the command
 * @argv: the arguments to the command
 */
void execute_command(char *full_path, char **argv)
>>>>>>> e3f87f10bd4bcf1f8f63f69611fc77d01bcce0ec
{
	pid_t pid;
	int status;

	pid = fork();
<<<<<<< HEAD
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
=======

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
>>>>>>> e3f87f10bd4bcf1f8f63f69611fc77d01bcce0ec
	}
}
