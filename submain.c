#include "main.h"

/**
* exiter - Exits on 'exit'
* @cmd: Array of tokens
* @input: String Buffer
* Return: Nothing
*/

void exiter(char **cmd, char *input)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

/**
* print_env - Display Enviroment Variable
* Return: Nothing
*/

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		size_t len = _strlen(*env);

		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
* ext_env - Exit or env
* @args: Token array
* Return: 1 if success
* ELSE, 0
*/

int ext_env(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
		return (1);
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (2);
	}
	return (0);
}

