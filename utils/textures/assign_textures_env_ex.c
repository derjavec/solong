/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures_env_ex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:25:17 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 14:25:19 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	assign_exit(t_solong *game)
{
	t_list_img	**exit_list;

	exit_list = NULL;
	game->img.exit_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit/house_1.xpm", &game->img.width, &game->img.height);
	game->img.exit_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit/house_2.xpm", &game->img.width, &game->img.height);
	game->img.exit_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit/house_3.xpm", &game->img.width, &game->img.height);
	game->img.exit_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit/house_4.xpm", &game->img.width, &game->img.height);
	exit_list = create_list(game->img.exit_frame, game);
	game->img.exit = (*exit_list)->content;
	game->exit_animation = exit_list;
}

static void	assign_floor(t_solong *game)
{
	t_list_img	**floor_list;

	floor_list = NULL;
	game->img.floor_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/fond/grass_1.xpm", &game->img.width, &game->img.height);
	game->img.floor_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/fond/grass_2.xpm", &game->img.width, &game->img.height);
	game->img.floor_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/fond/grass_3.xpm", &game->img.width, &game->img.height);
	game->img.floor_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/fond/grass_4.xpm", &game->img.width, &game->img.height);
	floor_list = create_list(game->img.floor_frame, game);
	game->img.floor = (*floor_list)->content;
	game->floor_animation = floor_list;
}

static void	assign_wall(t_solong *game)
{
	t_list_img	**wall_list;

	wall_list = NULL;
	game->img.wall_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/wall/wall_1.xpm", &game->img.width, &game->img.height);
	game->img.wall_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/wall/wall_2.xpm", &game->img.width, &game->img.height);
	game->img.wall_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/wall/wall_3.xpm", &game->img.width, &game->img.height);
	game->img.wall_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/wall/wall_4.xpm", &game->img.width, &game->img.height);
	wall_list = create_list(game->img.wall_frame, game);
	game->img.wall = (*wall_list)->content;
	game->wall_animation = wall_list;
}

void	assign_textures_env_ex(t_solong *game)
{
	assign_wall(game);
	assign_floor(game);
	assign_exit(game);
}
