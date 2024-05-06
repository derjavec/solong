/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:04:33 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/19 14:11:29 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	check_path(t_solong *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

static void	key_l(t_solong *game, t_pos pl)
{
	game->img.player = game->img.player_d[1];
	game->direction = 1;
	move_player(game, pl.x - 1, pl.y);
}

static void	key_r(t_solong *game, t_pos pl)
{
	game->img.player = game->img.player_d[0];
	game->direction = 0;
	move_player(game, pl.x + 1, pl.y);
}

int	key(int key, t_solong *game)
{
	t_pos	pl;

	pl = game->player;
	if (key == ESC)
		close_game(game);
	else if ((key == LEFT_KEY || key == A_KEY) \
		&& check_path(game, pl.x - 1, pl.y) == 0)
		key_l(game, pl);
	else if ((key == RIGHT_KEY || key == D_KEY) \
		&& check_path(game, pl.x + 1, pl.y) == 0)
		key_r(game, pl);
	else if ((key == UP_KEY || key == W_KEY) \
		&& check_path(game, pl.x, pl.y - 1) == 0)
		move_player(game, pl.x, pl.y - 1);
	else if ((key == DOWN_KEY || key == S_KEY) \
		&& check_path(game, pl.x, pl.y + 1) == 0)
		move_player(game, pl.x, pl.y + 1);
	return (0);
}
