/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:15 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/19 14:20:32 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "utils/ft_printf/ft_printf.h"
# include "utils/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define KEYPRESS 2
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define A_KEY 'a'
# define W_KEY 'w'
# define S_KEY 's'
# define D_KEY 'd'
# define ESC 65307
# define SPACE 32

typedef struct s_list_img
{
	void				*content;
	struct s_list_img	*next;
}	t_list_img;

typedef struct s_pos
{
	int	x;
	int	y;
	int	dir;
}	t_pos;

typedef struct s_solong_img
{
	void	*player;
	void	*enemy;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*player_d[2];
	void	*player_r_frame[4];
	void	*player_l_frame[4];	
	void	*enemy_frame[4];	
	void	*collectible_frame[4];
	void	*exit_frame[4];
	void	*wall_frame[4];
	void	*floor_frame[4];
	void	*number[10];
	void	*game_over;
	void	*next_level;
	void	*winner;
	int		height;
	int		width;
}	t_solong_img;

typedef struct s_map
{
	int		player;
	int		collectible;
	int		enemy;
	int		exit;
	t_pos	exit_pos;
}	t_map;

typedef struct s_level
{
	char	*l[3];
	int		current;
}	t_level;

typedef struct s_solong
{
	char			**map;
	void			*mlx;
	void			*win;
	t_map			map_content;
	t_pos			size;
	t_pos			player;
	t_solong_img	img;
	t_list_img		**player_r_animation;
	t_list_img		**player_l_animation;
	t_list_img		**enemy_animation;
	t_list_img		**collectible_animation;
	t_list_img		**exit_animation;
	t_list_img		**floor_animation;
	t_list_img		**wall_animation;
	int				exit;
	int				e;
	int				count_moves;
	int				map_collectibles;
	int				direction;
	t_level			g_level;
	int				game_over;
	int				next_level;
	int				winner;
	int				images_created;
	int				lists_created;
	int				frames;
}	t_solong;

size_t			ft_strlen( const char *c);
char			*ft_strnstr(const char *str, const char *c, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
size_t			ft_strlcpy(char *d, const char *s, size_t n);
char			*ft_strdup( const char *src);
int				ft_strncmp(const char *first, const char *second, \
					size_t length);
void			ft_error(t_solong *game, char *msg);
void			ft_freemap(char **map);
int				ft_filelen(const char *filename);
int				ft_printf(const char *format, ...);
void			map_init(t_solong *game, char *filename);
int				flood_fill(t_solong *game, char **tempmap);
void			initialize(t_solong *game);
char			**ft_mapdup(char **map, t_solong *game);
void			check_borders(char **map, t_solong *game);
void			check_content(char **map, t_solong *game);
void			assign_level(char *filename, t_solong *game);
void			game_init(t_solong *game);
void			assign_textures(t_solong *game);
void			assign_textures_pl_e_c(t_solong *game);
void			assign_textures_env_ex(t_solong *game);
t_list_img		**create_list(void *img[], t_solong *game);
void			move_player(t_solong *game, int x, int y);
void			move_enemy(t_solong *game);
void			animation(t_solong *game);
int				update(t_solong *game);
void			you_win(t_solong *game);
int				close_game(t_solong *game);
int				esc_to_close_game(int key, t_solong *game);
int				key(int key, t_solong *game);
void			render(t_solong *game, char **map);
void			print_img(t_solong *game, void *img, int x, int y);
int				update(t_solong *game);
int				next_level(int key, t_solong *game);
void			game_over(t_solong *game);
t_list_img		*ft_lstnew(void *content);
void			ft_lstadd_back(t_list_img **lst, t_list_img *new);
void			ft_lstclear_solong(t_list_img **lst);
void			free_all(t_solong *game);

#endif
