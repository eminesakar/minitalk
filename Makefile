NAME = minitalk.a
FLAG = -Wall -Wextra -Werror
SRC = server.c client.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) server.o client.o

clean:
	/bin/rm -f server.o client.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
