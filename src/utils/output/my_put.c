/*
** EPITECH PROJECT, 2018
** my_put.c
** File description:
**
*/

#include "shell.h"

void my_put_char(char c)
{
	const int output_gen = 1;
	const int read_len = 1;

	write(output_gen, &c, read_len);
}

void my_put_char_error(char c)
{
	const int output_error = 2;
	const int read_len = 1;

	write(output_error, &c, read_len);
}

void my_put_str(char const *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char(str[length]);
		length++;
	}
}

void my_put_error(char const *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char_error(str[length]);
		length++;
	}
}