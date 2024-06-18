/*
** EPITECH PROJECT, 2018
** my_get.c
** File description:
**
*/

#include "shell.h"

struct request *get_request(void)
{
	struct request *request = malloc(sizeof(struct request));

	if (request == NULL)
		report_malloc();
	request->env_len = 0;
	request->exit = 1;
	return (request);
}