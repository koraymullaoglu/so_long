NAME = so_long
SRC =  loaded_map_control.c check_elements.c map_control.c map.c movement.c flood_fill.c free_map.c main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
MLX_INC = -I$(MLX_DIR)

LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C ft_printf
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(FTPRINTF) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
