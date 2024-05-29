CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = test.exe
SRCS = main_test.c print_fnc.c visual_fnc.c ft_isalpha_test.c ft_isdigit_test.c ft_isalnum_test.c ft_isascii_test.c ft_isprint_test.c \
	ft_strlen_test.c ft_memset_test.c ft_bzero_test.c ft_memcpy_test.c ft_memmove_test.c \
	ft_strlcpy_test.c ft_strlcat_test.c ft_toupper_test.c ft_tolower_test.c ft_strchr_test.c \
	ft_strrchr_test.c ft_strncmp_test.c ft_memchr_test.c ft_memcmp_test.c ft_strnstr_test.c \
	ft_atoi_test.c ft_calloc_test.c ft_strdup_test.c ft_substr_test.c ft_strjoin_test.c \
	ft_strtrim_test.c ft_split_test.c ft_itoa_test.c ft_strmapi_test.c ft_striteri_test.c \
	ft_putchar_fd_test.c ft_putstr_fd_test.c ft_putendl_fd_test.c ft_putnbr_fd_test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft.a
	$(CC) -o $(NAME) $(OBJS) ../libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

libft.a:
	make -C ../

test: $(NAME)
	clear
	./$(NAME)

ftest: $(NAME)
	clear
	./$(NAME) full

memleak: $(NAME)
	valgrind --leak-check=full ./$(NAME)
