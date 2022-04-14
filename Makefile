NAME = get_next_line

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re