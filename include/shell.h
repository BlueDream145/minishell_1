/*
** EPITECH PROJECT, 2017
** shell.h
** File description:
**
*/

#ifndef shell_
#define shell_

#define _XOPEN_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

struct request {
	void (*handlers[5])(struct request *request);
	char **path;
	char **args;
	struct entry **env;
	char *current_directory;
	char *folder;
	char *command;
	int env_len;
	int bin_count;
	int gen_id;
	int pid;
	int exit;
	int status;
};

struct entry {
	char *key;
	char *value;
};

// engine/shell_engine.c
void loop(char **env);
void print_prompt(struct request *request);
int is_regular_file(const char *path);
void print_prompt_signal(int i);

// engine/commands/cd_command.c
void command_cd(struct request *request);
char *process_cd(struct request *request);
void error_cd(struct request *request, char *path);
void result_cd(struct request *request, char *path, int ret);

// engine/commands/env_command.c
void command_env(struct request *request);
void command_setenv(struct request *request);
int check_args_setenv(struct request *request);
void command_unsetenv(struct request *request);
int check_args_unsetenv(struct request *request);

// engine/env/shell_engine_binaries.c
char *search_binary(struct request *request, char *path);
char *search_binary_cwd(struct request *request, char *path);
int isindir(const char *dir, const char *file);

// engine/env/shell_engine_environment.c
void set_env_struct(struct request *request, char **env);
void serialize_env(struct request *request, char *env);
void set_env(struct request *request);
char *get_env(struct request *request, char *name);
void define_env(struct request *request, char *key, char *value, int silent);

// engine/env/shell_engine_path.c
char *get_folder_name(struct request *request, char *path);
char *cat_path(struct request *request, char *path);
char *back_path(char *path);
char *exceed_slash(char *path);

// engine/parser/shell_engine_commands.c
void command_exit(struct request *request);

// engine/parser/shell_engine_handler.c
void set_gen(struct request *request);
void handle_request(struct request *request);
void dispatch_request(struct request *request);
char **get_string_env(struct request *request);
void prepare_dictionary(struct request *request);

// engine/parser/shell_engine_signal.c
void check_process_signal(struct request *request);

// engine/parser/shell_engine_parser.c
struct request *parse_command(struct request *request, const char *str);
char **split_command(const char *str);
int check_char(char *content, char c, int j);

// engine/reader/shell_engine_reader.c
char *read_line(void);
int my_getchar(void);

// utils/alloc/my_alloc.c
char *my_realloc(char *src, int pos);

// utils/error/my_report.c
void report_malloc(void);
void report_error(const char *str);

// utils/instances/my_get.c
struct request *get_request(void);

// utils/output/my_put.c
void my_put_char(char c);
void my_put_str(const char *str);
void my_put_char_error(char c);
void my_put_error(char const *str);

// utils/string/my_string_extension.c
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
int my_str_isprintable(const char *str);
int my_str_isalpha(const char *str);

// utils/string/my_string_extra.c
char *str_replace(char *str, char *data, char *rep);
int len_occurence(char *ins, char *tmp, char *data);
char *my_strstr(const char *str, const char *to_find);
char *my_strtcpy(char *dest, char const *src, int n);

// utils/string/my_string.c
int my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int start, int n);
char *my_strdup(const char *src);
int my_strncmp(const char *s1, const char *s2, int n);

// main.c

#endif /* shell */