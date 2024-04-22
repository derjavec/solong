/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:18:30 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/15 14:18:32 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	free_lists_utils(t_list_img **lst)
{
	ft_lstclear_solong(lst);
	free(lst);
}

static void	free_lists(t_solong *game)
{
	if (game->player_r_animation)
		free_lists_utils(game->player_r_animation);
	if (game->player_l_animation)
		free_lists_utils(game->player_l_animation);
	if (game->enemy_animation)
		free_lists_utils(game->enemy_animation);
	if (game->collectible_animation)
		free_lists_utils(game->collectible_animation);
	if (game->exit_animation)
		free_lists_utils(game->exit_animation);
	if (game->floor_animation)
		free_lists_utils(game->floor_animation);
	if (game->wall_animation)
		free_lists_utils(game->wall_animation);
}

void	destroy_images(t_solong *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->img.game_over);
	mlx_destroy_image(game->mlx, game->img.next_level);
	mlx_destroy_image(game->mlx, game->img.winner);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->img.player_r_frame[i]);
		mlx_destroy_image(game->mlx, game->img.player_l_frame[i]);
		mlx_destroy_image(game->mlx, game->img.enemy_frame[i]);
		mlx_destroy_image(game->mlx, game->img.collectible_frame[i]);
		mlx_destroy_image(game->mlx, game->img.exit_frame[i]);
		mlx_destroy_image(game->mlx, game->img.floor_frame[i]);
		mlx_destroy_image(game->mlx, game->img.wall_frame[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(game->mlx, game->img.number[i]);
		i++;
	}
}

void	free_all(t_solong *game)
{
	if (game->map)
		ft_freemap(game->map);
	if (game->lists_created == 1)
		free_lists(game);
	if (game->images_created == 1)
		destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
