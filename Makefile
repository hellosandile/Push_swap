# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samkhize <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 14:20:19 by samkhize          #+#    #+#              #
#    Updated: 2019/09/05 10:02:50 by samkhize         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC = checker.c ft_swap.c ft_push.c ft_rotate.c \
	  ft_reverse.c ft_list.c ft_errors.c ft_handle_errors.c \
	  get_next_line/get_next_line.c ft_follow_instr.c ft_sorted.c

PUSH = ft_functions.c ft_algorithm.c

SWAP_OBJ = $(PUSH:.c=.o)

OBJ = $(SRC:.c=.o)

SRC_OBJ = ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
		  ft_list.c ft_errors.c ft_handle_errors.c \
		  ft_follow_instr.c ft_sorted.c

OBJ_SRC = $(SRC_OBJ:.c=.o)

FLAGS = -g -Wall -Werror -Wextra

$(CHECKER) : 
		gcc $(FLAGS) -c $(SRC)
		make -C get_next_line/ fclean && make -C get_next_line/
		make -C get_next_line/libft/ fclean && make -C get_next_line/libft/
		clang $(FLAGS) -I get_next_line/libft/ -c $(SRC)
	   	clang -o $(CHECKER) $(OBJ) -I get_next_line/libft/ -L get_next_line/libft/ -lft -L get_next_line/
	
$(PUSH_SWAP) : 
		gcc $(FLAGS) -c $(PUSH) -g
		clang -o $(PUSH_SWAP) $(OBJ_SRC) $(SWAP_OBJ) -I get_next_line/libft -L get_next_line/libft/ -lft -L get_next_line/

all : $(CHECKER) $(PUSH_SWAP)

clean :
		/bin/rm -f $(OBJ) $(SWAP_OBJ)

fclean : clean
		/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re : fclean all

.PHONY : all clean fclean re
