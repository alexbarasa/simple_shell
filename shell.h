#ifndef SHELL_H
#define SHELL_H
void tokenize_command(char *command, char **args);
void execute_command(char **args);
#endif
