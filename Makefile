# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/01 16:27:03 by kirill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

LIBFT = denis_printf/libft

DIR_O = temporary

HEADER = -I./$(LIBFT)

SOURCES = ft_printf.c chr_type.c parser.c strings_type.c table.c type_handlers.c

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
