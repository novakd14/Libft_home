CC = cc
# CFLAGS = -Wall -Wextra -Werror -g

NAME = test.exe
SRCS = unity.c test_libft.c
LIBS = ../libft.a
OBJS = $(SRCS:.c=.o)
OBJSREF = $(SRCSREF:.c=.o)

.PHONY: all clean fclean re lib test memleak

all: $(NAME) $(NAMEREF)

$(NAME): $(OBJS) $(LIBS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

$(NAMEREF): $(OBJSREF) $(LIBS)
	$(CC) -o $(NAMEREF) $(OBJSREF) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBS):
	make -C ../

test: $(NAME)
	clear
	./$(NAME)

test_ref: $(NAMEREF)
	clear
	./$(NAMEREF)

memleak: $(NAME)
	valgrind -s --leak-check=full ./$(NAME)
# valgrind --leak-check=full ./$(NAME)
