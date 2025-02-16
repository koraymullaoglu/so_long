/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:50:36 by femullao          #+#    #+#             */
/*   Updated: 2025/02/16 19:24:02 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void free_map(t_map *map)
{
    int i;

    i = 0;
    if (!map)
        return;
    while (map->map_lines[i])
    {
        free(map->map_lines[i]);
        i++;
    }
    free(map->map_lines);
    free(map);
}