NAME = so_long
SRC = loaded_map_control.c  map_control.c map.c movement.c flood_fill.c main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(FTPRINTF) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all