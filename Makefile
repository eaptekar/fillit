NAME = fillit

CC = gcc
FLAGS = -Wall -Wextra -Werror


SRC = main.c valid.c ft_error.c ft_read_file.c ft_strnew.c ft_bzero.c

OBJ = $(SRC:.c=.o)





all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

