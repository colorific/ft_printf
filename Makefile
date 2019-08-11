# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/11 11:39:13 by kirill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

LIBFT = denis_printf/libft

DIR_O = temporary

HEADER = -I./$(LIBFT)

SOURCES = 	ft_printf.c		\
			parser.c		\
			table.c			\
			type_chr.c		\
			type_handlers.c	\
			type_hex.c		\
			type_oct.c		\
			type_str.c		\
			bonus.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling libft and libftprintf"
	@make -sC $(LIBFT)
	@echo "Done"
	@cp -p $(LIBFT)/libft.a ./$(NAME)
	@ar r $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: %.c
	@mkdir -p temporary
	@$(CC) $(HEADER) $(FLAGS) -o $@ -c $<

clean:
	@echo "Removing objects"
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -sC $(LIBFT)
	@echo "Done"

fclean: clean
	@echo "Removing library"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT)
	@echo "Done"

re: fclean all
