/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:06 by femullao          #+#    #+#             */
/*   Updated: 2025/02/18 17:01:40 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	check_elements(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map->map_lines[i])
	{
		j = 0;
		while (win->map->map_lines[i][j] && win->map->map_lines[i][j] != '\n')
		{
			if (win->map->map_lines[i][j] != '1'
				&& win->map->map_lines[i][j] != '0'
				&& win->map->map_lines[i][j] != 'P'
				&& win->map->map_lines[i][j] != 'E'
				&& win->map->map_lines[i][j] != 'C')
			{
				write(2, "Invalid element\n", 16);
				free_all_maps(win);
			}
			j++;
		}
		i++;
	}
}
