NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = valid.c ft_error.c ft_read_file.c ft_strnew.c ft_bzero.c

OBJ = $(SRC:
.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -c $(FLAGS) $(SRC)
	@$(CC) -o $(NAME) main.c $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

