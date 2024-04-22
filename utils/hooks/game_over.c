/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:43:13 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 13:43:14 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	ft_restart(int key, t_solong *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == SPACE)
	{
		free_all(game);
		map_init(game, game->g_level.l[game->g_level.current]);
		game_init(game);
	}
	return (0);
}

void	game_over(t_solong *game)
{
	ft_printf("GAME OVER\nYou can do better, COME ON !\n \
		Press SPACE to restart or ESC to close\n", game->count_moves);
	game->game_over = 1;
	mlx_key_hook(game->win, ft_restart, game);
}
