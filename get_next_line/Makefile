NAME = gnl
FLAG = -Wall -Wextra -Werror
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	make -C libft/ fclean && make -C libft/
	clang $(FLAG) -I libft/ -c $(SRC)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
