# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 15:30:10 by mtaylor           #+#    #+#              #
#    Updated: 2019/03/03 12:59:01 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

## Libraries
LIBFT = ./libft/libft.a
LIB = -I libft/ $(LIBFT)

PUSHSWAP = main_pushswap.c \
		   opps.c structs.c \
		   quick_sort.c selection_sort.c \
		   sorting_helpers.c median.c \
		   util.c errors.c

CHECKER = main_checker.c \
		  opps.c structs.c util.c errors.c

all :
	make -s -C ./libft
	gcc $(FLAGS) $(LIB) $(addprefix ./src/, $(PUSHSWAP)) -o push_swap
	gcc $(FLAGS) $(LIB) $(addprefix ./src/, $(CHECKER)) -o checker

clean :
	make -s -C ./libft clean

fclean : clean
	make -s -C ./libft fclean
	rm -f push_swap checker

re : fclean all
