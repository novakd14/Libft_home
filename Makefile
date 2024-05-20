CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRSC = $(wildcard *.c)
TESTS = $(wildcard test/*.c)
OBJS = $(SRSC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) -I. -o test.exe $(SRCS) $(TESTS)
	./test.exe
	rm -f text.exe

