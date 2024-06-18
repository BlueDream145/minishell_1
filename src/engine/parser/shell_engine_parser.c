/*
** EPITECH PROJECT, 2018
** shell_engine_parser.c
** File description:
**
*/

#include "shell.h"

struct request *parse_command(struct request *request, const char *str)
{
	if (my_strlen(str) == 0)
		return (NULL);
	request->args = split_command(str);
	request->command = request->args[0];
	return (request);
}

int check_char(char *content, char c, int j)
{
	const int true = 1;
	const int false = 0;
	const int min_printable = 32;
	const int max_printable = 126;

	if (((c > min_printable && c < max_printable)
		&& c != ' ' && c != '\t') || (c == '~')) {
		content[j] = c;
		content[j + 1] = '\0';
		return (true);
	}
	return (false);
}

char **split_command(const char *str)
{
	char **result = malloc(sizeof(char *) * (my_strlen(str) + 1));
	char *content = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;
	int k = 0;

	content[0] = '\0';
	if (result == NULL || content == NULL)
		report_malloc();
	for (int i = 0; i < my_strlen(str) + 1; i++) {
		if (check_char(content, str[i], j))
			j++;
		else if (my_strlen(content) > 0) {
			content[j] = '\0';
			j = 0;
			result[k] = my_strdup(content);
			content[j] = '\0';
			k++;
		}
	}
	result[k] = '\0';
	return (result);
}