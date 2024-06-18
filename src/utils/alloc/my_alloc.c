/*
** EPITECH PROJECT, 2018
** my_alloc.c
** File description:
**
*/

#include "shell.h"

char *my_realloc(char *src, int pos)
{
	char *content = malloc(sizeof(char) * (pos + 1));
	int i = 0;

	if (content == NULL)
		report_malloc();
	for (i = 0; pos >= 0; i++) {
		if (src[i])
			content[i] = src[i];
		pos--;
	}
	return (content);
}