/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:14 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 14:37:16 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	move_enemy_r(t_solong *game, int x, int y)
{
	if (x + 1 < game->size.x && game->map[y][x + 1] == '0')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'M';
		x++;
	}
	else if (game->map[y][x + 1] == 'P')
		game_over(game);
	return (x);
}

static int	move_enemy_l(t_solong *game, int x, int y)
{
	if (x - 1 >= 0 && game->map[y][x - 1] == '0')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'M';
	}
	else if (game->map[y][x - 1] == 'P')
		game_over(game);
	return (x);
}

void	move_enemy(t_solong *game)
{
	static int	dir = 1;
	int			x;
	int			y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == 'M')
			{
				if (dir == 1)
					x = move_enemy_r(game, x, y);
				else
					x = move_enemy_l(game, x, y);
			}
			x++;
		}
		y++;
	}
	dir = -dir;
}
