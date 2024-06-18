/*
** EPITECH PROJECT, 2018
** my_string_extension.c
** File description:
**
*/

#include "shell.h"

char *my_strcat(char *dest, const char *src)
{
	int dest_len = my_strlen(dest);
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
		dest[dest_len + j] = src[j];
	dest[dest_len + j] = '\0';
	return (dest);
}

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++);
	return (s1[i] - s2[i]);
}

int my_str_isprintable(const char *str)
{
	const int true = 1;
	const int false = 0;
	const int min_printable = 32;
	const int max_printable = 126;
	int i = 0;
	int result = false;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= min_printable && str[i] <= max_printable)
			result = true;
		else
			return (false);
	}
	return (result);
}

int my_str_isalpha(const char *str)
{
	const int true = 1;
	const int false = 0;
	int i = 0;
	int result = false;

	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] <= 'Z' && str[i] >= 'A')
			|| (str[i] <= 'z' && str[i] >= 'a'))
			result = true;
		else
			return (false);
	}
	return (result);
}