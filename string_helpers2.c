#include "main.h"

/**
* _strcmp - Compares Two String
* @s1: String 1
* @s2: String 2
* Return: 0 if same
* ELSE, Disparity
*/

int _strcmp(char *s1, char *s2)
{
int cmp = 0, i, len1, len2;
len1 = _strlen(s1);
len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
* _isalpha - Check if cchar is letter
* @c: Character
* Return: 1 if letter
* ELSE, 0
*/

int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
	return (0);
	}
}

/**
* check_delim - Checks for char match
* @c: char to check
* @str: str
* Return: 1 if Success
* ELSE 0 if Failure
*/
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
* _strtok - Tokenize str
* @str: String
* @delim: Delimiter
* Return: Pointer to next tok
* ELSE NULL
*/

char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nxt;
	unsigned int i;

	if (str != NULL)
		nxt = str;
	ts = nxt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delim(ts[i], delim) == 0)
			break;
	}
	if (nxt[i] == '\0' || nxt[i] == '#')
	{
		nxt = NULL;
		return (NULL);
	}
	ts = nxt + i;
	nxt = ts;
	for (i = 0; nxt[i] != '\0'; i++)
	{
		if (check_delim(nxt[i], delim) == 1)
			break;
	}
	if (nxt[i] == '\0')
		nxt = NULL;
	else
	{
		nxt[i] = '\0';
		nxt = nxt + i + 1;
		if (*nxt == '\0')
			nxt = NULL;
	}
	return (ts);
}

/**
* parse_cmd - parse input
* @input: Iinput
* Return: String array
*/

char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = MAX_INPUT;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
