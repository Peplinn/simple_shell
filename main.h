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
    _putchar('$'); \
    _putchar(' '); /* Replace this with puts */

/* Main Functions */
void execmd(char **argv);
int child_process(char **argv);

/* String Helper Functions */
char *_strcpy(char *dest, char *src);
size_t _strlen(char *s);
void _puts(char *str);
unsigned int _strspn(char *s, char *accept);
void trim_lead_space(char *buffer, int chars_printed);


/* Int Helper Functions */
int _atoi(char *s);

#endif /* MAIN_H */
