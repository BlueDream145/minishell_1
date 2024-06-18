/*
** EPITECH PROJECT, 2018
** shell_engine_environment.c
** File description:
**
*/

#include "shell.h"

void set_env(struct request *request)
{
	if (get_env(request, "PATH") != NULL)
		serialize_env(request, get_env(request, "PATH"));
	if (get_env(request, "PWD") != NULL) {
		request->current_directory = get_env(request, "PWD");
		request->folder =
			get_folder_name(request, request->current_directory);
	}
	else {
		request->current_directory = "/";
		request->folder = "/";
	}
}

void set_env_struct(struct request *request, char **env)
{
	int index;

	for (request->env_len = 0; env[request->env_len]; request->env_len++);
	request->env = malloc(sizeof(struct entry*) * 200);
	if (request->env_len == 0)
		return;
	for (int i = 0; i < request->env_len && env[i]; i++) {
		request->env[i] = malloc(sizeof(struct entry));
		for (index = 0; env[i][index] != '='; index++);
		request->env[i]->key = malloc(sizeof(char) * (index + 2));
		request->env[i]->value = malloc(sizeof(char) *
			(my_strlen(env[i]) - index + 2));
		if (request->env[i] == NULL || request->env[i]->key == NULL
			|| request->env[i]->value == NULL)
			report_malloc();
		my_strncpy(request->env[i]->key, env[i], 0, index);
		request->env[i]->key[index] = '\0';
		my_strncpy(request->env[i]->value, env[i], index + 1,
			my_strlen(env[i]) - index);
		request->env[i]->value[my_strlen(env[i]) - index + 1] = '\0';
	}
}

char *get_env(struct request *request, char *name)
{
	for (int i = 0; i < request->env_len; i++) {
		if (my_strncmp(request->env[i]->key,
			name, my_strlen(request->env[i]->key)) == 0)
			return (request->env[i]->value);
	}
	return (NULL);
}

void define_env(struct request *request, char *key, char *value, int silent)
{
	for (int i = 0; i < request->env_len; i++) {
		if (my_strncmp(request->env[i]->key, key,
			my_strlen(request->env[i]->key)) == 0) {
			request->env[i]->value = value;
			return;
		}
	}
	request->env[request->env_len] = malloc(sizeof(struct entry));
	request->env[request->env_len]->key = my_strdup(key);
	request->env[request->env_len]->value = my_strdup(value);
	request->env_len++;
	define_env(request, key, value, silent);
}

void serialize_env(struct request *request, char *path)
{
	char *content = malloc(my_strlen(path) + 1);
	int j = 0;
	int k = 0;

	request->path = malloc(my_strlen(path) + 1);
	if (request->path == NULL || content == NULL)
		report_malloc();
	for (int i = 0; i < my_strlen(path) + 1; i++) {
		if (path[i] != ':') {
			content[j] = path[i];
			content[j + 1] = '\0';
			j++;
		} else if (my_strlen(content) > 0) {
			content[j] = '\0';
			j = 0;
			request->path[k] = my_strdup(content);
			k++;
		}
	}
	request->path[k] = '\0';
}