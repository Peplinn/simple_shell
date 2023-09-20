#include "main.h"

/**
* main - Entry Point
* @argc: Argument count
* @argv: Argument vector
* Return: Status
*/

int main(UNUSED int argc, UNUSED char **argv)
{
	char *input = NULL, *args[MAX_ARGS], *command = NULL;
	const char *delimit = " \t\n";
	int intact_mode = isatty(STDIN_FILENO), arg_count, status = 0, exit_status;
	size_t input_size = 0;
	ssize_t input_length, extenv, ext_two, child_pid;

	while (1)
	{
		if (intact_mode)
			write(STDOUT_FILENO, "$ ", 2);
		input_length = getline(&input, &input_size, stdin);
		if (ctrl_d(input_length, intact_mode) == 1)
			break;
		if (tok_count(input, input_length, command, args, delimit) == 1)
			continue;
		arg_count = 1;
		while ((args[arg_count] = strtok(NULL, delimit)) != NULL)
			arg_count++;
		args[arg_count] = NULL;
		extenv = ext_env(args);
		if (extenv == 1)/* ? break : continue; */
			break;
		else if (extenv == 2)
		{
			_exit(EXIT_SUCCESS);
			continue;
		}
		child_pid = fork();
		if (child_pid != 0 && child_pid != -1)
		{
			wait(&status);
			exit_status = WEXITSTATUS(status);
			if (exit_status == 1)
				status = unknow_cmd(argv, args);
		} else
			pid_check(child_pid, args);
	}
	free(input);
	return (status);
}

/**
 * pid_check - Checks if pid is 0/-1
 * @child_pid: Child PID
 * @args: String of tokens
 * Return: Nothing
*/

void pid_check(ssize_t child_pid, char **args)
{
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		_exit(EXIT_FAILURE);
	}
}
