/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:51:14 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 13:51:15 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

int	next_level(int key, t_solong *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == SPACE)
	{	
		game->g_level.current++;
		if (game->g_level.current <= 3 \
			&& game->g_level.l[game->g_level.current] != NULL)
		{		
			free_all(game);
			map_init(game, game->g_level.l[game->g_level.current]);
			game_init(game);
		}
		else
			return (1);
	}
	return (0);
}
