<<<<<<< HEAD
#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#include <unistd.h>

#define MAX_CMD_LEN 1024
extern char **environ;

char *build_full_path(char *directory, char *cmd);
int command_exists(char *full_path);
void execute_command(char *full_path, char **argv);
void handle_command(char *cmd);
char *search_path(char *cmd);
void print_env();

#endif /*_SHELL_H*/
=======
#ifndef SHELL_H
#define SHELL_H
void tokenize_command(char *command, char **args);
void execute_command(char **args);
#endif
>>>>>>> cb4bfa07b144f67bf92e3bd8d1edb85ae0b85d1c
