/* #define _GNU_SOURCE
#include <stdio.h> */
#include "main2.h"

/**
* main - Entry Point
* Return: 0 on success
*/

int main(int argc, char **argv)
{

    char *buffer, *buffer_copy, *token;
    const char *delimiter = " \t\n";
    int token_count = 0, i, fd = STDIN_FILENO, code;
    size_t size = 0;
    ssize_t chars_printed;

    (void)argc;
    /* (void)argv; */
    
    while(1)
    {
        if (isatty(fd)) {
            PROMPT;
        }
        chars_printed = getline(&buffer, &size, stdin);

        if (chars_printed == 1 && (buffer[0] == '\n' || buffer[0] == '\r'))
			continue;
        if (chars_printed == -1) /* || strcmp(&buffer, "exit") == 0) */
        {
            /* printf(" Exiting...\n"); Don't forget to remove this! */
            _putchar('\n');
            return (0);
        }
        if (_strspn(buffer, " \t\n") == _strlen(buffer))
            continue;
        /* printf("About to trim %ld\n", chars_printed); */

        trim_lead_space(buffer, chars_printed);


        buffer_copy = malloc(sizeof(char) * chars_printed);
        if (buffer_copy== NULL){
            perror("tsh: malloc error");
            return (-1);
        }

        _strcpy(buffer_copy, buffer);
        /* printf("Tokenize\n"); Tokenize here */
        token = strtok(buffer, delimiter);
        while (token != NULL){
            token_count++;
            token = strtok(NULL, delimiter);
        }
        
        token_count++;
        argv = malloc(sizeof(char *) * token_count);

        token = strtok(buffer_copy, delimiter);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * _strlen(token));
            _strcpy(argv[i], token);
            token = strtok(NULL, delimiter);
        }
        argv[i] = NULL;
        /* printf("Strlen arg: %ld", strlen(argv[0])); */
        /* for (i = 0; argv[i] != NULL; i++) {  Testing the argument vector (tokens)
            printf("\n%s", argv[i]);
        }
        printf("\n"); */
        /* printf("%s", buffer); */

        code = child_process(argv);

        if (code >= 0) {
			/*exit(code);*/
            /* printf("Reached.\n"); */
            continue;
        }
    }
    free (argv);
    free (buffer);
    free (buffer_copy);
    
    return (0);
}
