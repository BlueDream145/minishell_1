/*
** EPITECH PROJECT, 2018
** shell_engine_commands.c
** File description:
**
*/

#include "shell.h"

void command_exit(struct request *request)
{
	if (request == NULL)
		return;
	request->exit = 0;
	exit(0);
}