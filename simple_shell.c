#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#define MAX 1024
/**
 * main - Entry point
 *
 * Return: Integer
 */
int main(void)
{
	char *command;
	size_t bufsize;
	int input_length;
	char *args[MAX];

	command = NULL;
	bufsize = 0;
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		input_length = getline(&command, &bufsize, stdin);
		if (input_length == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		if (command[input_length - 1] == '\n')
			command[input_length - 1] = '\0';
		tokenize_command(command, args);
		execute_command(args);
	}
	free(command);
	return (0);
}
