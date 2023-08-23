#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);

#define PROMPT \
do {
_putchar('$');
_putchar(' ')
} while (1);

 /* Replace this with putchar */
#define UNUSED __attribute__((unused))
/* Main Functions */
int child_process(char **argv, int pid);


void freer(char **argv, char *buff, char *buff_cpy);

/* String Helper Functions */
char *_strcpy(char *dest, char *src);
size_t _strlen(char *s);
void _puts(char *str);
unsigned int _strspn(char *s, char *accept);
void trim_lead_space(char *buff, int chars_printed);
void count_tok(char *buff, char *token, int t_count, const char *dlimit);
void tokenize(const char *dlimit, char *token, char **argv);
int input_edge(ssize_t chars_printed, char *buff);


/* Int Helper Functions */
int _atoi(char *s);

#endif /* MAIN_H */
