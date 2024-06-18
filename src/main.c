/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main(int ac, char **as, char **env)
{
	const int exit_success = 0;

	if (ac != 0 && as != NULL)
		loop(env);
	return (exit_success);
}