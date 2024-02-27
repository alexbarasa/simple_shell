#include "main.h"


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
