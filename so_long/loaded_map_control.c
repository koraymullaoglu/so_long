/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_map_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:44:50 by femullao          #+#    #+#             */
/*   Updated: 2025/02/21 19:51:24 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	check_player(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	win->map->p_ct = 0;
	while (win->map->map_lines[i])
	{
		while (win->map->map_lines[i][j])
		{
			if (win->map->map_lines[i][j] == 'P')
				win->map->p_ct += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (win->map->p_ct != 1)
	{
		write(2, "Player count error\n", 19);
		free_all_maps(win);
	}
}

void	check_map_size(t_win *win)
{
	int		i;
	size_t	len;
	size_t	this_len;

	i = 0;
	len = win->map->w;
	while (win->map->map_lines[i])
	{
		this_len = ft_strlen_sl(win->map->map_lines[i]) - 1;
		if (i == win->map->h - 1)
			this_len++;
		if (this_len != len)
		{
			write(2, "Invalid line\n", 13);
			free_all_maps(win);
		}
		i++;
	}
}

void	check_wall(t_win *win)
{
	int	i;
	int	lst;

	i = 0;
	while (win->map->map_lines[0][i] != '\n'
		&& win->map->map_lines[0][i] != '\0')
	{
		if (win->map->map_lines[0][i] != '1'
			|| win->map->map_lines[win->map->h - 1][i++] != '1')
		{
			write(2, "Invalid wall\n", 13);
			free_all_maps(win);
		}
	}
	i = 0;
	lst = win->map->w - 1;
	while (win->map->map_lines[i])
	{
		if (win->map->map_lines[i][0] != '1'
			|| win->map->map_lines[i++][lst] != '1')
		{
			write(2, "Invalid wall\n", 13);
			free_all_maps(win);
		}
	}
}

void	check_exit(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	win->map->end_ct = 0;
	while (win->map->map_lines[i])
	{
		j = 0;
		while (win->map->map_lines[i][j])
		{
			if (win->map->map_lines[i][j] == 'E')
				win->map->end_ct += 1;
			j++;
		}
		i++;
	}
	if (win->map->end_ct != 1)
	{
		write(2, "Invalid exit\n", 13);
		free_all_maps(win);
	}
}

void	check_coin(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	win->map->cb = 0;
	while (win->map->map_lines[i])
	{
		j = 0;
		while (win->map->map_lines[i][j])
		{
			if (win->map->map_lines[i][j++] == 'C')
				win->map->cb += 1;
		}
		i++;
	}
	if (win->map->cb <= 0)
	{
		write(2, "No any coin\n", 12);
		free_all_maps(win);
	}
}
