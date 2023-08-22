#include "main.h"

/**
* _strcpy - Copies a string from src to dest
* @dest: Pointer to the destination buffer
* @src: Pointer to the source string
*
* Return: Pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';

return (dest);
}

/**
* _strlen - Returns the length of a string
* @s: Pointer to the string
*
* Return: The length of the string
*/

size_t _strlen(char *s)
{
size_t length = 0;
while (*s != '\0')
{
length++;
s++;
}
return (length);
}

/**
* _puts - Prints a string followed by a new line
* @str: Pointer to the string
*/
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
_putchar('\n');
}

/**
* _strspn - gets the length of prefix substring
*
* @s: string to search
* @accept: accepted characters
* Return: number of bytes in s
* with only bytes from accept
*/

unsigned int _strspn(char *s, char *accept)
{
int i;
int count = 0;

for (i = 0; s[i] != '\0'; i++)
{
int j = 0;
while (accept[j] != '\0')
{
if (s[i] == accept[j])
{
count++;
break;
}
j++;
}
if (accept[j] == '\0')
{
break;
}
}
return (count);
}
