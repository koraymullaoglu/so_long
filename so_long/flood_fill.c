/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:41:10 by femullao          #+#    #+#             */
/*   Updated: 2025/02/23 13:13:42 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void	find_player(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (win->map->map_lines[i])
	{
		while (win->map->map_lines[i][j])
		{
			if (win->map->map_lines[i][j] == 'P')
			{
				win->map_copy->player_y = i;
				win->map_copy->player_x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	f_fill(t_map *mapc, int row, int col)
{
	if (row < 0 || col < 0 || row >= mapc->h || col >= mapc->w)
		return ;
	if (mapc->map_lines[row][col] == 'S' || mapc->map_lines[row][col] == '1')
		return ;
	mapc->map_lines[row][col] = 'S';
	f_fill(mapc, row - 1, col);
	f_fill(mapc, row + 1, col);
	f_fill(mapc, row, col - 1);
	f_fill(mapc, row, col + 1);
}

int	check_ff(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	start_ff(t_win *win)
{
	find_player(win);
	f_fill(win->map_copy, win->map_copy->player_y, win->map_copy->player_x);
	if (check_ff(win->map_copy->map_lines) == 1)
	{
		write(2, "Impossible Map\n", 15);
		free_all_maps(win);
	}
}
