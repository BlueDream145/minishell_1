/*
** EPITECH PROJECT, 2018
** shell_engine_handler.c
** File description:
**
*/

#include "shell.h"

void handle_request(struct request *request)
{
	set_gen(request);
	if (search_binary(request, request->command) != NULL
		&& request->gen_id == -1) {
		if ((request->pid = fork()) == -1)
			return;
	}
	else {
		dispatch_request(request);
		return;
	}
	if (request->pid != 0)
		wait(&request->status);
	else
		dispatch_request(request);
	check_process_signal(request);
}

void dispatch_request(struct request *request)
{
	const char *error_command_end = ": Command not found.\n";
	char *real_path = NULL;

	if (request->gen_id == -1) {
		if ((real_path = search_binary(request, request->command))
			!= NULL) {
			if (request->env_len != 0)
				execve(real_path, request->args,
					get_string_env(request));
			else
				execve(real_path, request->args, NULL);
			return;
		}
		my_put_error(request->command);
		my_put_error(error_command_end);
	}
	else if (request->handlers[request->gen_id] != NULL)
		request->handlers[request->gen_id](request);
	free(real_path);
}

char **get_string_env(struct request *request)
{
	char **str = malloc(sizeof(char*) * (request->env_len + 1));
	int i;
	int j = 0;

	if (str == NULL)
		report_malloc();
	for (i = 0; i < request->env_len; i++) {
		if (request->env[i]->value == NULL)
			continue;
		str[j] = malloc(sizeof(char) *
		(my_strlen(request->env[i]->key) +
		my_strlen(request->env[i]->value) + 2));
		if (str[j] == NULL)
			report_malloc();
		my_strcpy(str[j], request->env[i]->key);
		my_strcat(str[j], "=\0");
		my_strcat(str[j], request->env[i]->value);
		j++;
	}
	str[j] = NULL;
	return (str);
}

void set_gen(struct request *request)
{
	const int false = 0;
	char *commands[6] =
		{ "cd", "setenv", "unsetenv", "env", "exit", "\0" };
	int gen_id = -1;

	for (int i = 0; commands[i][0] != '\0'; i++) {
		if (my_strncmp(request->command, commands[i],
			my_strlen(request->command)) == false)
			gen_id = i;
	}
	request->gen_id = gen_id;
}

void prepare_dictionary(struct request *request)
{
	request->handlers[0] = command_cd;
	request->handlers[1] = command_setenv;
	request->handlers[2] = command_unsetenv;
	request->handlers[3] = command_env;
	request->handlers[4] = command_exit;
}