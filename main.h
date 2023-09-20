#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define UNUSED __attribute__((unused))


/* environ var */
extern char **environ;

/* Main Functions */
int unknow_cmd(char **argv, char **args);
int ctrl_d(ssize_t input_length, int intact_mode);
int tok_count(char *input, ssize_t input_length,
	char *command, char **args, const char *delimit);
void exiter(char **cmd, char *input);
char *_strtok(char *str, const char *delim);
unsigned int check_delim(char c, const char *str);
void pid_check(ssize_t child_pid, char **args);
void print_env(void);
int ext_env(char **args);

/* Helper Functions */
size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _putchar(char c);
int _atoi(char *s);
int _isalpha(int c);
int _strcmp(char *s1, char *s2);
char **parse_cmd(char *input);

#endif /* MAIN_H */
