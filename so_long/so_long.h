/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:14:45 by femullao          #+#    #+#             */
/*   Updated: 2025/02/21 16:24:50 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_char
{
	int		l_x;
	int		l_y;
	int		point;
	void	*cr;
}	t_char;

typedef struct s_map
{
	char		**map_lines;
	int			w;
	int			h;
	int			coin_ct;
	int			gatex;
	int			gatey;
	int			p_ct;
	int			end_ct;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct s_win
{
	t_map	*map;
	t_map	*map_copy;
	t_char	*chr;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*block_bg;
	void	*c_bg;
	void	*end_bg;
	int		hgh;
	int		wdt;
}			t_win;

void	xpm_isexist(void);
void	map_path_control(char *path);
void	map_file_exits(char *path);

int		ft_strlen_sl(char *str);

t_map	*read_map(char *path);
void	load_map(t_win *win);

int		stop_mlx(t_win *win);

void	check_player(t_win *win);
void	check_map_size(t_win *win);
void	check_wall(t_win *win);
void	check_exit(t_win *win);
void	check_coin(t_win *win);
void	check_elements(t_win *win);

int		catch_key(int keycode, void *param);
void	start_ff(t_win *win);
void	free_map(t_map *map);
void	free_all_maps(t_win *win);

#endif