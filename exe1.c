#include "main.h"

/**
* child_process - Creates child process
* @argv: Array containing tokenized string (command)
* @pid: PID of the process
* Return: Status
* ELSE, 0 if FAILURE
*/

int child_process(char **argv, int pid)
{
int status;
if (pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
perror("error in new_process: child process");
return (status);
}
else if (pid < 0)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);

if (WIFEXITED(status))
return (status);
else
{
printf("3.5");
perror("child process terminated abnormally");
return (-1);
}
}
return (-1);
}

/**
* freer - Frees entities
* @argv: Token array
* @buff: String Buffer
* @buff_cpy: Buffer copy
* Return: Nothing
*/

void freer(char **argv, char *buff, char *buff_cpy)
{
free(argv);
free(buff);
free(buff_cpy);
}
