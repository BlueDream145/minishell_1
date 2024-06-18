/*
** EPITECH PROJECT, 2018
** env_command.c
** File description:
**
*/

#include "shell.h"

void command_env(struct request *request)
{
	for (int i = 0; i < request->env_len; i++) {
		if (request->env[i]->value == NULL ||
			request->env[i]->key == NULL)
			continue;
		my_put_str(request->env[i]->key);
		my_put_char('=');
		my_put_str(request->env[i]->value);
		my_put_char('\n');
	}
}

void command_setenv(struct request *request)
{
	const int true = 1;

	if (check_args_setenv(request) == true)
		return;
	define_env(request, request->args[1], request->args[2], 0);
	if (my_strcmp(request->args[1], "PATH") == 0)
		serialize_env(request, get_env(request, "PATH"));
}

int check_args_setenv(struct request *request)
{
	int args_len;

	for (args_len = 0; request->args[args_len]; args_len++);
	if (args_len != 3)
		return (1);
	if (my_str_isalpha(request->args[1]) == 0)
		return (1);
	if (my_str_isprintable(request->args[2]) == 0)
		return (1);
	return (0);
}

void command_unsetenv(struct request *request)
{
	const int true = 1;
	const int false = 0;
	int i;

	if (request->env_len == 0)
		return;
	if (check_args_unsetenv(request) == true || request == NULL)
		return;
	for (i = 0; i < request->env_len; i++) {
		if (my_strncmp(request->env[i]->key, request->args[1],
			my_strlen(request->env[i]->key)) == false) {
			request->env[i]->value = NULL;
			return;
		}
	}
}

int check_args_unsetenv(struct request *request)
{
	const int true = 1;
	const int false = 0;
	int args_len;

	for (args_len = 0; request->args[args_len]; args_len++);
	if (args_len != 2)
		return (true);
	if (my_str_isalpha(request->args[1]) == false)
		return (true);
	return (false);
}