/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures_pl_e_c.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:17:27 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 14:17:30 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	assign_player_r(t_solong *game)
{
	t_list_img	**player_r_list;

	player_r_list = NULL;
	game->img.player_r_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_r_1.xpm", &game->img.width, &game->img.height);
	game->img.player_r_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_r_2.xpm", &game->img.width, &game->img.height);
	game->img.player_r_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_r_3.xpm", &game->img.width, &game->img.height);
	game->img.player_r_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_r_4.xpm", &game->img.width, &game->img.height);
	player_r_list = create_list(game->img.player_r_frame, game);
	game->img.player_d[0] = (*player_r_list)->content;
	game->img.player = game->img.player_d[0];
	game->player_r_animation = player_r_list;
}

static void	assign_player_l(t_solong *game)
{
	t_list_img	**player_l_list;

	player_l_list = NULL;
	game->img.player_l_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_l_1.xpm", &game->img.width, &game->img.height);
	game->img.player_l_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_l_2.xpm", &game->img.width, &game->img.height);
	game->img.player_l_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_l_3.xpm", &game->img.width, &game->img.height);
	game->img.player_l_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/pig_l_4.xpm", &game->img.width, &game->img.height);
	player_l_list = create_list(game->img.player_l_frame, game);
	game->img.player_d[1] = (*player_l_list)->content;
	game->player_l_animation = player_l_list;
}

static void	assign_enemy(t_solong *game)
{
	t_list_img	**enemy_list;

	enemy_list = NULL;
	game->img.enemy_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/enemy/duck_1.xpm", &game->img.width, &game->img.height);
	game->img.enemy_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/enemy/duck_2.xpm", &game->img.width, &game->img.height);
	game->img.enemy_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/enemy/duck_3.xpm", &game->img.width, &game->img.height);
	game->img.enemy_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/enemy/duck_4.xpm", &game->img.width, &game->img.height);
	enemy_list = create_list(game->img.enemy_frame, game);
	game->img.enemy = (*enemy_list)->content;
	game->enemy_animation = enemy_list;
}

static void	assign_collectible(t_solong *game)
{
	t_list_img	**collectible_list;

	collectible_list = NULL;
	game->img.collectible_frame[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectibles/chicken_1.xpm", \
		&game->img.width, &game->img.height);
	game->img.collectible_frame[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectibles/chicken_2.xpm", \
		&game->img.width, &game->img.height);
	game->img.collectible_frame[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectibles/chicken_3.xpm", \
		&game->img.width, &game->img.height);
	game->img.collectible_frame[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectibles/chicken_4.xpm", \
		&game->img.width, &game->img.height);
	collectible_list = create_list(game->img.collectible_frame, game);
	game->img.collectible = (*collectible_list)->content;
	game->collectible_animation = collectible_list;
}

void	assign_textures_pl_e_c(t_solong *game)
{
	assign_player_r(game);
	assign_player_l(game);
	assign_enemy(game);
	assign_collectible(game);
}
