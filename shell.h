#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

void get_user_command(char *command);
void tokens_input(char *command);
int check_command(char *command);
void execute_command(char *command);

#endif
