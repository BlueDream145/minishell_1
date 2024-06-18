##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

ENGINE	=	src/engine

UTILS	=	src/utils

SRC	=	$(ENGINE)/shell_engine.c \
		$(ENGINE)/commands/cd_command.c \
		$(ENGINE)/commands/env_command.c \
		$(ENGINE)/env/shell_engine_binaries.c \
		$(ENGINE)/env/shell_engine_environment.c \
		$(ENGINE)/env/shell_engine_path.c \
		$(ENGINE)/handler/shell_engine_commands.c \
		$(ENGINE)/handler/shell_engine_handler.c \
		$(ENGINE)/handler/shell_engine_signal.c \
		$(ENGINE)/parser/shell_engine_parser.c \
		$(ENGINE)/reader/shell_engine_reader.c \
		$(UTILS)/alloc/my_alloc.c \
		$(UTILS)/error/my_report.c \
		$(UTILS)/instances/my_get.c \
		$(UTILS)/output/my_put.c \
		$(UTILS)/string/my_string_extra.c \
		$(UTILS)/string/my_string_extension.c \
		$(UTILS)/string/my_string.c \
		src/main.c

CFLAGS	=	-Wall -Wextra -pedantic -std=c99 -g3

INCLUDE =	-I include

LIB	=	-g -lm

NAME	=	mysh

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(INCLUDE) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
