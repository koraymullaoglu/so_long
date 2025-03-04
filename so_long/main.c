/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:03:19 by femullao          #+#    #+#             */
/*   Updated: 2025/02/21 16:55:00 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"

void	start_mlx(t_win *win, int x, int y)
{
	win->hgh = win->map->h * 64;
	win->wdt = win->map->w * 64;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->wdt, win->hgh, "so_long");
	win->chr = ft_calloc(1, sizeof(t_char));
	win->chr->l_x = 0;
	win->chr->l_y = 0;
	win->chr->point = 0;
	win->chr->cr = mlx_xpm_file_to_image(win->mlx, "textures/plr.xpm", &x, &y);
	win->img_bg = mlx_xpm_file_to_image(win->mlx, "textures/bg.xpm", &x, &y);
	win->c_bg = mlx_xpm_file_to_image(win->mlx, "textures/coin.xpm", &x, &y);
	win->end_bg = mlx_xpm_file_to_image(win->mlx, "textures/exit.xpm", &x, &y);
	win->block_bg = mlx_xpm_file_to_image(win->mlx, "textures/wl.xpm", &x, &y);
}

int	stop_mlx(t_win *win)
{
	int	i;

	i = 0;
	mlx_destroy_image(win->mlx, win->chr->cr);
	mlx_destroy_image(win->mlx, win->c_bg);
	mlx_destroy_image(win->mlx, win->end_bg);
	mlx_destroy_image(win->mlx, win->block_bg);
	mlx_destroy_image(win->mlx, win->img_bg);
	free(win->chr);
	while (win->map->map_lines[i])
		free(win->map->map_lines[i++]);
	free(win->map->map_lines);
	free(win->map);
	i = 0;
	while (win->map_copy->map_lines[i])
		free(win->map_copy->map_lines[i++]);
	free(win->map_copy->map_lines);
	free(win->map_copy);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(1);
	return (0);
}

void	open_win(t_win *win, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	win->map = read_map(path);
	win->map_copy = read_map(path);
	check_map_size(win);
	check_wall(win);
	check_player(win);
	check_exit(win);
	check_coin(win);
	check_elements(win);
	start_ff(win);
	start_mlx(win, x, y);
}

int	main(int ac, char **av)
{
	t_win	win;

	if (ac == 2)
	{
		xpm_isexist();
		map_path_control(av[1]);
		map_file_exits(av[1]);
		open_win(&win, av[1]);
		load_map(&win);
		mlx_hook(win.win, 17, 0, stop_mlx, &win);
		mlx_key_hook(win.win, catch_key, &win);
		mlx_loop((&win)->mlx);
	}
	else
	{
		write(2, "ac is not correct\n", 18);
		return (1);
	}
	return (0);
}
