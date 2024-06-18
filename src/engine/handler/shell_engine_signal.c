/*
** EPITECH PROJECT, 2018
** shell_engine_signal.c
** File description:
**
*/

#include "shell.h"

void check_process_signal(struct request *request)
{
	const char *exception_segfault = "Segmentation fault\n";
	const char *exception_floating = "Floating exception\n";

	if (request->status && WIFSIGNALED(request->status)) {
		if (WTERMSIG(request->status) == SIGSEGV)
			my_put_str(exception_segfault);
		if (WTERMSIG(request->status) == SIGFPE)
			my_put_str(exception_floating);
	}
}