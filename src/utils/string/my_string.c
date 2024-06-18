/*
** EPITECH PROJECT, 2018
** my_string.c
** File description:
**
*/

#include "shell.h"

int my_strlen(const char *str)
{
	int count = 0;

	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char *my_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *my_strncpy(char *dest, const char *src, int start, int n)
{
	int i = start;
	int j = 0;

	while (n > 0 && src[i] != '\0') {
		dest[j] = src[i];
		j++;
		i++;
		n--;
	}
	if (n > 0)
		dest[j++] = '\0';
	return (dest);
}

char *my_strdup(const char *src)
{
	char *str;
	int len = my_strlen(src) + 1;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		report_malloc();
	str = my_strcpy(str, src);
	return (str);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	if (!(s1) || !(s2))
		return (1);
	for (i = 0; s1[i] == s2[i] && s1[i] && i < n; i++);
	if (i < n || s2[i + 1] != '\0')
		return (s1[i] - s2[i]);
	return (0);
}