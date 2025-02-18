/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:12:33 by femullao          #+#    #+#             */
/*   Updated: 2025/02/18 17:14:20 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "./ft_printf/inc/ft_printf.h"

void	move_player(t_win *win, int x, int y)
{
	if (win->map->cb == 0 && win->map->map_lines[y / 64][x / 64] == 'E')
	{
		ft_printf("move count: %d\n", ++win->chr->point);
		ft_printf("Win!\n");
		stop_mlx(win);
	}
	if (!(win->map->map_lines[y / 64][x / 64] == '1'))
	{
		win->chr->point++;
		if (win->map->map_lines[y / 64][x / 64] == 'C')
			win->map->cb--;
		win->map->map_lines[win->chr->l_y / 64][win->chr->l_x / 64] = '0';
		win->map->map_lines[win->map->gatey / 64][win->map->gatex / 64] = 'E';
		win->map->map_lines[y / 64][x / 64] = 'P';
	}
	ft_printf("move count: %d\n", win->chr->point);
}

int	catch_key(int keycode, void *param)
{
	t_win	*win;

	win = param;
	mlx_clear_window(win->mlx, win->win);
	if (keycode == 'd')
		move_player(win, win->chr->l_x + 64, win->chr->l_y);
	if (keycode == 'a')
		move_player(win, win->chr->l_x - 64, win->chr->l_y);
	if (keycode == 'w')
		move_player(win, win->chr->l_x, win->chr->l_y - 64);
	if (keycode == 's')
		move_player(win, win->chr->l_x, win->chr->l_y + 64);
	if (keycode == 65307)
		stop_mlx(win);
	load_map(win);
	return (keycode);
}
