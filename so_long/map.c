#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>


int     count_map_lines(int fd)
{
    int i;
    char *line;

    i = -1;
    line = malloc(1);
    line[0] = 1;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    return (i);
}

int get_map_lines(int fd, t_map *map)
{
    int i;

    i = 0;
    while(i < map->h)
    {
        map->map_lines[i] = get_next_line(fd);
        i++;
    }
    close(fd);
    if (!map->map_lines[0])
    {
        //freemap
        return (1);
    }
    map->w = ft_strlen(map->map_lines[0]);
    map->w--;
    return (0);
}

t_map *read_map(char *path)
{
    t_map *r;
    int fd;
    int i;

    r = ft_calloc(1, sizeof(t_map));
    fd = open(path, O_RDONLY);
    r->h = count_map_lines(fd);
    r->map_lines = malloc(sizeof(char *) * r->h + 1);
    close (fd);
    fd = open(path, O_RDONLY);
    i = get_map_lines(fd, r);
    if (i == 1)
        return (NULL);
    return (r);
}

void    put_image(char c, t_win *win, int x, int y)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img_bg, x, y);
    if (c == 'P')
    {
        win->chr->l_x = x;
        win->chr->l_y = y;
        mlx_put_image_to_window(win->mlx, win->win, win->chr->cur, x, y);
    }
    if (c == '1')
        mlx_put_image_to_window(win->mlx, win->win, win->block_bg, x, y);
    if (c == 'C')
        mlx_put_image_to_window(win->mlx, win->win, win->c_bg, x, y);
    if (c == 'E')
    {   
        win->map->gatex = x;
        win->map->gatey = y;
        mlx_put_image_to_window(win->mlx, win->win, win->end_bg, x, y);
    }

}

void    load_map(t_win *win)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(win->map->map_lines[i])
    {
        j = 0;
        x = 0;
        while (win->map->map_lines[i][j])
        {
            put_image(win->map->map_lines[i][j++], win, x, y);
            x += 64;
        }
        i++;
        y += 64;
    }
}