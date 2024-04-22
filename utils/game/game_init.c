/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:41:34 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/04 17:41:35 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	setup_event_hooks(t_solong *game)
{
	mlx_loop_hook(game->mlx, update, game);
	mlx_key_hook(game->win, key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}

void	game_init(t_solong *game)
{
	if (game->mlx == NULL)
	{
		game->mlx = mlx_init();
		if (game->mlx == NULL)
			ft_error(game, "Failed to initialize mlx\n");
	}
	if (game->win == NULL)
	{
		game->win = mlx_new_window(game->mlx \
		, 64 * game->size.x, 64 * game->size.y, "so_long");
		if (game->win == NULL)
			ft_error(game, "Failed to create window\n");
	}
	assign_textures(game);
	game->map_collectibles = 0;
	game->exit = 0;
	game->count_moves = 0;
	game->direction = 0;
	game->game_over = 0;
	game->next_level = 0;
	game->winner = 0;
	setup_event_hooks(game);
	render(game, game->map);
	mlx_loop(game->mlx);
	return ;
}
