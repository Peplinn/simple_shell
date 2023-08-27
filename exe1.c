#include "main.h"

/**
* ctrl_d - Handles Ctrl+D
* @input_length: Length of gotten input
* @intact_mode: Interactive mode check
* Return: Nothing
*/

int ctrl_d(ssize_t input_length, int intact_mode)
{
	if (input_length == -1)
	{
		if (intact_mode)
			write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}

/**
 * unknow_cmd - Handles unknown command error output
 * @argv: Argument vector
 * @args: Token array
 * Return: Error status code
*/

int unknow_cmd(char **argv, char **args)
{
	char *first_args2 = malloc(sizeof(args[0]));
	const char *first_args1 = first_args2;
	size_t argv_len = _strlen(argv[0]);
	size_t args_len = _strlen(args[0]);
	const char *suffix = ": 1: ";
	const char *not_found = ": not found\n";
	size_t err_sze = argv_len + _strlen(suffix) +
		args_len + _strlen(not_found) + 1;
	char *msg = "malloc error";
	char *err_str = (char *) malloc(sizeof(char) * err_sze);

	if (_strcmp(args[0], "exit") == 0)
		return (0);
	else if (err_str == NULL)
		perror(msg);

	first_args1 = args[0];

	_strcpy(err_str, argv[0]);
	_strcat(err_str, suffix);
	_strcat(err_str, first_args1);
	_strcat(err_str, not_found);

	write(STDERR_FILENO, err_str, err_sze - 1);
	free(err_str);
	free(first_args2);
	return (127);
}

/**
* tok_count - Counts tokens
* @input: Input Buffer
* @input_length: Length of gotten input
* @command: Entered command
* @args: Token array
* @delimit: Delimiter string
* Return: Nothing
*/

int tok_count(char *input, ssize_t input_length,
	char *command, char **args, const char *delimit)
{
	input[input_length - 1] = '\0';
	command = input;
	while (*command == ' ')
		command++;
	args[0] = strtok(command, delimit);
	if (args[0] == NULL)
		return (1);
	return (0);
}

