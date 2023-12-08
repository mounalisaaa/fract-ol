CC= cc

CFLAGS= -Wall -Wextra -Werror


NAME= fractol

SRCS= fractol.c

OBJ= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I /usr/local/include -L /usr/local/lib -lmlx -framework AppKit -framework OpenGl -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
