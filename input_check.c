#include "main.h"

/**
* trim_lead_space - Trims leading whitespace
* @buffer: Contains input string
* @chars_printed: Number of characters
* Return: Nothing
*/

void trim_lead_space(char *buffer, int chars_printed) {
    int i = 0;
    int j = 0;
    if (buffer[0] != ' ') {
        return;
    } else {
        while (buffer[i] == ' ') {
            i++;
        }
        while (i < chars_printed) {
            buffer[j++] = buffer[i++];
        }
        buffer[j-1] = '\0';
    }
    return;
}
