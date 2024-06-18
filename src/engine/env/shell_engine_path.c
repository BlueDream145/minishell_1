/*
** EPITECH PROJECT, 2018
** shell_engine_path.c
** File description:
**
*/

#include "shell.h"

char *get_folder_name(struct request *request, char *path)
{
	int start = 0;
	int len = 0;
	char *home_dir = get_env(request, "HOME");
	char *folder = NULL;

	if (home_dir != NULL && my_strncmp(path, home_dir,
		my_strlen(path)) == 0)
		return ("~");
	for (int i = 0; path[i]; i++)
		if (path[i] == '/')
			start = i + 1;
	len = my_strlen(path) - start + 1;
	folder = malloc(sizeof(char) * len);
	if (folder == NULL)
		report_malloc();
	my_strncpy(folder, path, start, len);

	return (folder);
}

char *exceed_slash(char *path)
{
	char *new_path = malloc(sizeof(char) * (my_strlen(path) + 1));
	int i;
	int j = 0;

	if (new_path == NULL)
		report_malloc();
	for (i = 0; path[i]; i++) {
		if (path[i] == '/' && path[i + 1] == '/')
			continue;
		new_path[j] = path[i];
		j++;
	}
	new_path[i++] = '\0';
	return (new_path);
}

char *cat_path(struct request *request, char *path)
{
	char *result;

	result = malloc(sizeof(char) *
		(my_strlen(request->current_directory) + my_strlen(path) + 2));
	if (result == NULL)
		report_malloc();
	if (my_strlen(request->current_directory) == 1 &&
		request->current_directory[0] == '/') {
		my_strcpy(result, "/");
		my_strcat(result, path);
		result[my_strlen(path) + 1] = '\0';
	}
	else {
		my_strcpy(result, request->current_directory);
		my_strcat(result, "/");
		my_strcat(result, path);
	}
	return (result);
}

char *back_path(char *path)
{
	int path_len = 0;
	int slash_len = 0;
	char *new_path;
	int i;

	for (i = 0; path[i]; i++)
		if (path[i] == '/' && path[i + 1] != '/') {
			path_len = i;
			slash_len++;
		}
	new_path = malloc(sizeof(char) * (path_len + 1));
	if (new_path == NULL)
		report_malloc();
	if (slash_len < 2)
		return (path);
	for (i = 0; path[i] && i < path_len; i++)
		new_path[i] = path[i];
	new_path[i++] = '\0';
	return (new_path);
}