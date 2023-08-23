#include "main.h"

/**
* main - Entry Point
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on Success
* ELSE, Failure
*/

int main(UNUSED int argc, char **argv)
{
char *buff, *buff_cpy, *token = "";
const char *dlimit = " \t\n";
int t_count = 0, fd = STDIN_FILENO;
size_t size = 0;
ssize_t chars_printed;
pid_t pid;

while (1)
{
if (isatty(fd))
{
PROMPT;
}
chars_printed = getline(&buff, &size, stdin);
if (input_edge(chars_printed, buff))
continue;
if (chars_printed == -1)
return (0);
trim_lead_space(buff, chars_printed);
buff_cpy = malloc(sizeof(char) * chars_printed);
if (buff_cpy == NULL)
{
perror("tsh: malloc error");
return (-1);
}
_strcpy(buff_cpy, buff);
count_tok(buff, token, t_count, dlimit);
argv = malloc(sizeof(char *) * t_count);
token = strtok(buff_cpy, dlimit);
tokenize(dlimit, token, argv);
pid = fork();
child_process(argv, pid);
if (chars_printed == -1)
return (0);
}
freer(argv, buff, buff_cpy);
return (0);
}
