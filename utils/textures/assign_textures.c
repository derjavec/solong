/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:13:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/19 13:21:23 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	assign_numbers(t_solong *game)
{
	game->img.number[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/0.xpm", &game->img.width, &game->img.height);
	game->img.number[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/1.xpm", &game->img.width, &game->img.height);
	game->img.number[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/2.xpm", &game->img.width, &game->img.height);
	game->img.number[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/3.xpm", &game->img.width, &game->img.height);
	game->img.number[4] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/4.xpm", &game->img.width, &game->img.height);
	game->img.number[5] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/5.xpm", &game->img.width, &game->img.height);
	game->img.number[6] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/6.xpm", &game->img.width, &game->img.height);
	game->img.number[7] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/7.xpm", &game->img.width, &game->img.height);
	game->img.number[8] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/8.xpm", &game->img.width, &game->img.height);
	game->img.number[9] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/9.xpm", &game->img.width, &game->img.height);
}

static void	assign_text_images(t_solong *game)
{
	game->img.game_over = mlx_xpm_file_to_image(game->mlx, \
		"./img/text/game_over.xpm", &game->img.width, &game->img.height);
	game->img.next_level = mlx_xpm_file_to_image(game->mlx, \
		"./img/text/next_level.xpm", &game->img.width, &game->img.height);
	game->img.winner = mlx_xpm_file_to_image(game->mlx, \
		"./img/text/winner.xpm", &game->img.width, &game->img.height);
}

void	assign_textures(t_solong *game)
{
	game->images_created = 1;
	game->lists_created = 1;
	assign_textures_pl_e_c(game);
	assign_textures_env_ex(game);
	game->lists_created = 1;
	assign_numbers(game);
	assign_text_images(game);
	return ;
}
