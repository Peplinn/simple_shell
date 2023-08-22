#include "main2.h"

/**
* execmd - Executes the command passed
* @argv: Array containing tokenized string (command)
* Return: Nothing
*/

void execmd(char **argv){
    char *command = NULL;

    if (argv){
        command = argv[0];
        if (execve(command, argv, NULL) == -1){
            perror("Error:");
        }
    }
}

/**
* child_process - Creates child process
* @argv: Array containing tokenized string (command)
* Return: Nothing
*/

int child_process(char **argv){
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        /* printf("pid 0\n"); */
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("error in new_process: child process");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else {
        /* printf("Reached in Child.\n");*/
        /* Wait for the child process to finish and get its exit status */
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            /* printf("Exited normal\n"); */
            /* Child process exited normally */
            /* return WEXITSTATUS(status); */
            return (status);
        }
        else
        {
            perror("child process terminated abnormally");
            return (-1);
        }
    }
    /*return(-1);*/
}
