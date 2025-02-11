#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_char
{
    int l_x;
    int l_y;
    int point;
    void    *cur;
}   t_char;

typedef struct s_map
{
    char    **map_lines;
    int         w;
    int         h;
    int         cb;
    int         gatex;
    int         gatey;
    int         p_ct;
    int         end_ct;
    int         coin_ct;
}   t_map;

typedef struct s_win
{
    t_map *map;
    t_char *chr;
    void    *win;
    void    *mlx;
    void    *img_bg;
    void    *block_bg;
    void    *c_bg;
    void    *end_bg;
    int     hgh;
    int     wdt;
}   t_win;


void    xpm_isexist();
void    map_path_control(char *path);
void    map_file_exits(char *path);

t_map   *read_map(char *path);
void    load_map(t_win *win);






#endif