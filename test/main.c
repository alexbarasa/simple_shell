#include "main.h"

/**
 * main - The main function
 * Return: 0
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[MAX_ARGV_NUM];

	while (1)
	{
		printf(PROMPT);
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}

		cmd[strcspn(cmd, "\n")] = 0;

		parse_command(cmd, argv);

		if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}

		if (strcmp(argv[0], "env") == 0)
		{
			char **env;

			for (env = environ; *env; ++env)
			{
				printf("%s\n", *env);
			}
			continue;
		}

		execute_command(argv);
	}

	return (0);
}
