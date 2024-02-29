#ifndef _MAIN_H_
#define _MAIN_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
#define MAX_CMD_LEN 256
#define MAX_ARGV_NUM 64
#define PROMPT "($) "

char *search_path(char *cmd);
void execute_command(char **argv);
void parse_command(char *cmd, char **argv);

#endif /*_MAIN_H_*/
