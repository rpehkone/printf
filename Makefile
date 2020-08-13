# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 20:09:24 by rpehkone          #+#    #+#              #
#    Updated: 2020/08/13 18:52:09 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
FOLDERS = libft/ src/
FILES = ft_printf integer float
C_FILES = $(addsuffix .c, $(FILES))
O_FILES = $(addsuffix .o, $(FILES))
FLAGS = -Wall -Wextra -Werror -O3
.PHONY: all lean fclean re

all: $(NAME)

$(NAME):
	@make re -C libft
#gcc -c $(ERROR) -O3 $(addprefix src/, $(C_FILES)) $(LIB) $(addprefix -I , $(FOLDERS))
	gcc -c $(FLAGS) $(addprefix src/, $(C_FILES)) $(addprefix -I , $(FOLDERS))
	cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)
clean:
	rm -f $(O_FILES)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean
	make all
