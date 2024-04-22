/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:26 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 11:29:29 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	initialize(t_solong *game)
{
	game->map_content.player = 0;
	game->map_content.enemy = 0;
	game->map_content.collectible = 0;
	game->map_content.exit = 0;
	game->map_content.exit_pos.x = 0;
	game->map_content.exit_pos.y = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->frames = 0;
	game->images_created = 0;
	game->lists_created = 0;
	game->map_collectibles = 0;
	game->exit = 0;
	game->map = NULL;
}

int	main(int argc, char	*argv[])
{
	t_solong	game;

	initialize(&game);
	if (argc != 2)
		ft_error(&game, "Wrong amount of arguments\n");
	map_init(&game, argv[1]);
	game_init(&game);
	return (0);
}
