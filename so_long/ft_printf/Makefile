NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_putchar.c src/ft_printf_fn.c src/ft_strchr.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

all: $(NAME)

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
