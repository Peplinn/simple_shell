#include "main.h"

/**
* trim_lead_space - Trims leading whitespace
* @buff: Contains input string
* @chars_printed: Number of characters
* Return: Nothing
*/

void trim_lead_space(char *buff, int chars_printed)
{
int i = 0;
int j = 0;
if (buff[0] != ' ')
{
return;
}
else
{
while (buff[i] == ' ')
{
i++;
}
while (i < chars_printed)
{
buff[j++] = buff[i++];
}
buff[j - 1] = '\0';
}
return;
}

/**
* count_tok - Counts num of tokens
* @buff: String Buffer
* @token: Token string
* @t_count: Number of tokens
* @dlimit: Delimiter
* Return: Nothing
*/

void count_tok(char *buff, char *token, int t_count, const char *dlimit)
{
token = strtok(buff, dlimit);
while (token != NULL)
{
t_count++;
token = strtok(NULL, dlimit);
}

t_count++;
}


/**
* tokenize - Converts input strings to tokens
* @dlimit: String of delimiters
* @token: Token from string
* @argv: Token Array
* Return: Nothing
*/

void tokenize(const char *dlimit, char *token, char **argv)
{
int i;
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * _strlen(token));
_strcpy(argv[i], token);
token = strtok(NULL, dlimit);
}
argv[i] = NULL;
}


/**
* input_edge - Handles some input cases for skip
* @chars_printed: Char count of input string
* @buff: Array of tokens
* Return: 1 if skippable
* ELSE, 0 if unskippable
*/

int input_edge(ssize_t chars_printed, char *buff)
{
if (chars_printed == 1 && (buff[0] == '\n' || buff[0] == '\r'))
return (1);

else if (_strspn(buff, " \t\n") == _strlen(buff))
return (1);
return (0);
}
