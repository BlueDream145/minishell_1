/*
** EPITECH PROJECT, 2018
** shell_engine.c
** File description:
**
*/

#include "shell.h"

void loop(char **env)
{
	char *line;
	struct request *request = get_request();

	set_env_struct(request, env);
	set_env(request);
	prepare_dictionary(request);
	chdir(request->current_directory);
	signal(SIGINT, print_prompt_signal);
	while (request->exit == 1) {
		print_prompt(request);
		line = read_line();
		if (my_strlen(line) == 0)
			continue;
		request = parse_command(request, line);
		handle_request(request);
		free(line);
	}
	free(request);
}

void print_prompt(struct request *request)
{
	const char *header = "[";
	const char *prompt = "] > ";
	const char *separator = "@localhost ";

	my_put_str(header);
	if (get_env(request, "USER") != NULL)
		my_put_str(get_env(request, "USER"));
	else
		my_put_str("Unknown");
	my_put_str(separator);
	my_put_str(request->folder);
	my_put_str(prompt);
}

void print_prompt_signal(int i)
{
	const char *prompt = "\n> ";

	i = i;
	my_put_str(prompt);
}

int is_regular_file(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}