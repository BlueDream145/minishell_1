/*
** EPITECH PROJECT, 2018
** my_report.c
** File description:
**
*/

#include "shell.h"

void report_malloc(void)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";

	report_error(error_malloc);
}

void report_error(const char *str)
{
	const int exit_error = 84;
	const int output_error = 2;
	int len = 0;

	for (len = 0; str[len]; len++);
	write(output_error, str, len);
	exit(exit_error);
}