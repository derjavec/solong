/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:48:23 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/05 09:48:24 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	you_win(t_solong *game)
{
	if (game->g_level.current < 2)
	{
		ft_printf("Incredible!\nPress SPACE \
			to play next level or ESC to close\n");
		game->next_level = 1;
		mlx_key_hook(game->win, next_level, game);
	}
	else
	{
		ft_printf("You did it!\n \
			You are capable of everythig!\nPress ESC to close\n");
		game->winner = 1;
		mlx_key_hook(game->win, esc_to_close_game, game);
	}
}

static void	check_case(t_solong *game, int x, int y)
{
	t_pos		exit;

	exit = game->map_content.exit_pos;
	if (exit.x == x && exit.y == y && game->exit == 1)
		you_win(game);
	else if (game->map[y][x] == 'C')
	{
		game->map_collectibles++;
		if (game->map_collectibles == game->map_content.collectible)
		{
			game->exit = 1;
			game->map_collectibles = 0;
		}		
	}
	else if (game->map[y][x] == 'M')
	{
		game->map_collectibles = 0;
		game_over(game);
	}
}

void	move_player(t_solong *game, int x, int y)
{
	t_pos	pl;

	pl = game->player;
	check_case(game, x, y);
	game->count_moves++;
	ft_printf("Moves: %d\n", game->count_moves);
	if (game->e == 1)
	{
		game->map[pl.y][pl.x] = 'E';
		game->e = 0;
	}		
	else
		game->map[pl.y][pl.x] = '0';
	if (game->map[y][x] == 'E')
		game->e = 1;
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
