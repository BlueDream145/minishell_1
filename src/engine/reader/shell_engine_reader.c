/*
** EPITECH PROJECT, 2018
** shell_engine_reader.c
** File description:
**
*/

#include "shell.h"

char *read_line(void)
{
	int buff_size = 8096;
	char *buff = malloc(sizeof(char) * buff_size);
	char c = '\0';
	int pos = 0;

	if (buff == NULL)
		report_malloc();
	while (1) {
		c = my_getchar();
		if (c == '\n') {
			buff[pos] = '\0';
			return (buff);
		} else
			buff[pos] = c;
		pos++;
		if (pos >= buff_size) {
			buff_size += 8096;
			buff = my_realloc(buff, buff_size);
		}
	}
}

int my_getchar(void)
{
	const int intput_shell = 0;
	const int size = 1;
	char c;

	if (read(intput_shell, &c, size) == 1)
		return (unsigned char)c;
	else
		exit (0);
}