/*
** EPITECH PROJECT, 2018
** cd_command.c
** File description:
**
*/

#include "shell.h"

void command_cd(struct request *request)
{
	char *path;
	int ret = -1;

	if (request->args[1] == NULL) {
		if (get_env(request, "HOME") == NULL)
			return;
		define_env(request, "OLDPWD", request->current_directory, 1);
		request->current_directory = get_env(request, "HOME");
		chdir(request->current_directory);
		request->folder = get_folder_name(request,
			request->current_directory);
		define_env(request, "PWD", request->current_directory, 1);
		return;
	} else {
		if (get_env(request, "HOME") != NULL)
			request->args[1] = str_replace(request->args[1],
				"~", get_env(request, "HOME"));
		path = process_cd(request);
		ret = chdir(path);
	}
	result_cd(request, path, ret);
}

void result_cd(struct request *request, char *path, int ret)
{
	if (ret)
		error_cd(request, path);
	else {
		define_env(request, "OLDPWD", request->current_directory, 1);
		request->current_directory = path;
		request->folder = get_folder_name(request,
			request->current_directory);
		define_env(request, "PWD", path, 1);
	}
}

void error_cd(struct request *request, char *path)
{
	const char *error_start_chdir = "shell: cd: ";
	const char *error_end_chdir = ": No such file or directory\n";
	const char *error_directory = ": Not a directory.\n";
	const char *error_access = ": Permission denied\n";

	if (access(path, F_OK) == 0 && access(path, X_OK) != 0) {
		my_put_str(request->args[1]);
		my_put_str(error_access);
		return;
	}
	if (access(path, F_OK) == 0 && is_regular_file(path) == 1) {
		my_put_str(request->args[1]);
		my_put_str(error_directory);
		return;
	}
	my_put_error(error_start_chdir);
	my_put_error(request->args[1]);
	my_put_error(error_end_chdir);
}

char *process_cd(struct request *request)
{
	const char *error_pwd = "shell: cd: OLDPWD not set.\n";
	const char *back_keyword = "..";

	if (my_strlen(request->args[1]) == 1 && request->args[1][0] == '-') {
		if (get_env(request, "OLDPWD") == NULL) {
			my_put_error(error_pwd);
			return (request->current_directory);
		}
		else {
			return (get_env(request, "OLDPWD"));
		}
	}
	if (request->args[1][0] == '/')
		return (exceed_slash(request->args[1]));
	else if (my_strncmp(request->args[1], back_keyword,
		my_strlen(request->args[1])) == 0)
		return (back_path(request->current_directory));
	else
		return (cat_path(request, request->args[1]));
}