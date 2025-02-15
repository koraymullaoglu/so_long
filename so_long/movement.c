#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>

void    move_player(t_win *win, int x, int y)
{
    if (win->map->cb == 0 && win->map->map_lines[y / 64][x / 64] == 'E')
    {
        win->chr->point++;
        printf("Win\n"); //ft
        stop_mlx(win);
    }
    if (!(win->map->map_lines[y / 64][x / 64] == '1' || win->map->map_lines[y / 64][x / 64] == 'E'))
    {
        win->chr->point++;
        if (win->map->map_lines[y / 64][x / 64] == 'C')
            win->map->cb--;
        win->map->map_lines[win->chr->l_y / 64][win->chr->l_x / 64] = '0';
        win->map->map_lines[win->map->gatey / 64][win->map->gatex / 64] = 'E';
        win->map->map_lines[y / 64][x / 64] = 'P'; 
    }
}

int catch_key(int keycode, void *param)
{
    t_win *win;
    win = param;
    mlx_clear_window(win->mlx, win->win);
    if (keycode == 2)
    move_player(win,  win->chr->l_x + 64, win->chr->l_y);
    if (keycode == 0)
        move_player(win,  win->chr->l_x - 64, win->chr->l_y);
    if (keycode == 13)
        move_player(win,  win->chr->l_x, win->chr->l_y - 64);
    if (keycode == 1)
        move_player(win, win->chr->l_x, win->chr->l_y + 64);
    if (keycode == 53)
        stop_mlx(win);
    load_map(win);
    return (keycode);
}