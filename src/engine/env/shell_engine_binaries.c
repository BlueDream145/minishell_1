/*
** EPITECH PROJECT, 2018
** shell_engine_binaries.c
** File description:
**
*/

#include "shell.h"

char *search_binary(struct request *request, char *path)
{
	const char *slash = "//";
	char *real_path = NULL;

	if (request->env_len == 0 || get_env(request, "PATH") == NULL)
		return (real_path);
	for (int i = 0; request->path[i]; i++) {
		if (!real_path && isindir(request->path[i], path))
		{
			real_path = malloc(sizeof(char) *
				(my_strlen(request->path[i]) +
					my_strlen(path) + 3));
			if (real_path == NULL)
				report_malloc();
			my_strcpy(real_path, request->path[i]);
			my_strcat(real_path, slash);
			my_strcat(real_path, path);
		}
	}
	if (real_path == NULL && search_binary_cwd(request, path) != NULL)
		return (search_binary_cwd(request, path));
	return (real_path);
}

char *search_binary_cwd(struct request *request, char *path)
{
	char *real_path = NULL;
	char *file = NULL;

	if (my_strlen(path) > 2 && path[0] == '.' && path[1] == '/') {
		file = malloc(sizeof(char) * (my_strlen(path)));
		if (file == NULL)
			report_malloc();
		my_strncpy(file, path, 2, (my_strlen(path) - 1));
	}
	else
		file = path;
	if (isindir(request->current_directory, file)) {
		real_path = malloc(sizeof(char) *
		(my_strlen(request->current_directory) + my_strlen(file) + 3));
		if (real_path == NULL)
			report_malloc();
		my_strcpy(real_path, request->current_directory);
		my_strcat(real_path, "//");
		my_strcat(real_path, file);
	}
	return (real_path);
}

int isindir(const char *directory, const char *file)
{
	const int true = 1;
	const int false = 0;
	DIR *dir;
	struct dirent *dp;
	int found = false;

	if ((dir = opendir(directory)) == NULL)
		return (false);
	while ((dp = readdir(dir)) != NULL && !found)
		if (!my_strcmp(dp->d_name, file))
			found = true;
	closedir(dir);
	return (found);
}