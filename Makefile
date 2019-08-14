# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/14 22:05:18 by kirill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=out

BIN_DIR=bin

BIN=$(addprefix $(BIN_DIR)/,$(NAME))

CC=gcc

LIB = denis_printf

CFLAGS=-Wall -Wextra -Werror

HEADER = -I./$(LIB) -I./$(LIB)/libft

SOURCES = 	main.c

OBJS = $(SOURCES:.c=.o)

.PHONY: all clean fclean re build

all: $(NAME)

$(NAME): main.c
	@echo "compiling binary with main.c to /bin/out"
	@mkdir -p bin
	@$(CC) $(FLAGS) $(HEADER) main.c -L./$(LIB) -lftprintf -o $(BIN)
