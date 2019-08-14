# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/14 22:18:40 by kirill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=out

BIN_DIR=bin

BIN=$(addprefix $(BIN_DIR)/,$(NAME))

CC=gcc

LIB = denis_printf

CFLAGS=-Wall -Wextra -Werror

HEADER = -I./$(LIB) -I./$(LIB)/libft

.PHONY: all clean fclean re build

all: $(NAME)

$(NAME): main.c
	@make -C $(LIB) re
	@echo "compiling binary with main.c to /bin/out"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(FLAGS) $(HEADER) main.c -L./$(LIB) -lftprintf -o $(BIN)

fclean:
	@make -C $(LIB) fclean
	@rm -rf $(BIN_DIR)
