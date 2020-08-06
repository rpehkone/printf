# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 20:09:24 by rpehkone          #+#    #+#              #
#    Updated: 2020/08/06 14:12:56 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
FOLDERS = libft src
FILES = ft_printf
C_FILES = $(addprefix $(FILES), .c)
O_FILES = $(addprefix $(FILES), .o)
.PHONY: all lean fclean re

all: $(NAME)

$(NAME):
	@make re -C libft
	gcc -Wall -Wextra -Werror -O3 $(addprefix src/, $(C_FILES)) $(LIB) $(addprefix -I , $(FOLDERS)) -o $(NAME)
	ar rc $(O_FILES)
clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean
	make all
