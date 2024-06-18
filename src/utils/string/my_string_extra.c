/*
** EPITECH PROJECT, 2018
** my_string_extra.c
** File description:
**
*/

#include "shell.h"

char *str_replace(char *str, char *data, char *rep)
{
	char *result;
	char *ins = str;
	char *tmp = NULL;
	int len_data = my_strlen(data);
	int len_rep = my_strlen(rep);
	int len_front;
	int count = len_occurence(ins, tmp, data);

	result = malloc(my_strlen(str) + (len_rep - len_data) * count + 1);
	if (result == NULL)
		report_malloc();
	tmp = result;
	while (count--) {
		ins = my_strstr(str, data);
		len_front = ins - str;
		tmp = my_strtcpy(tmp, str, len_front) + len_front;
		tmp = my_strcpy(tmp, rep) + len_rep;
		str += len_front + len_data;
	}
	my_strcpy(tmp, str);
	return (result);
}

int len_occurence(char *ins, char *tmp, char *data)
{
	int count;

	for (count = 0; (tmp = my_strstr(ins, data)); ++count)
		ins = tmp + my_strlen(data);
	return (count);
}

char *my_strstr(const char *str, const char *to_find)
{
	int i = 0;

	if (str[0] != '\0') {
		while (to_find[i] != '\0')
		{
			if (to_find[i] != str[i])
				return (my_strstr(str + 1, to_find));
			i++;
		}
		return ((char*)str);
	}
		else
	return (NULL);
}

char *my_strtcpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (n > 0 && src[i] != '\0') {
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n > 0)
		dest[i++] = '\0';
	return (dest);
}