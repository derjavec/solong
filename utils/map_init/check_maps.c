/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:31:09 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 09:31:10 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	check_case(char c, int x, int y, t_solong *game)
{
	if (c == 'P' && game->map_content.player == 0)
	{
		game->player.x = x;
		game->player.y = y;
		game->map_content.player++;
	}
	else if (c == 'P' && game->map_content.player != 0)
		return (1);
	else if (c == 'C')
		game->map_content.collectible++;
	else if (c == 'M')
		return (0);
	else if (c == 'E')
	{
		game->map_content.exit++;
		game->map_content.exit_pos.x = x;
		game->map_content.exit_pos.y = y;
	}
	else if (c != '1' && c != '0')
		return (1);
	return (0);
}

void	check_content(char **map, t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_case(map[i][j], j, i, game) == 1)
				ft_error(game, "Invalid character found in the map\n");
			j++;
		}
		i++;
	}
	if (game->map_content.collectible == 0 || game->map_content.exit != 1 \
		|| game->map_content.player != 1)
		ft_error(game, "Either not collectibles,\
		wrong amount of exit or wrong amount of players\n");
	if (flood_fill(game, ft_mapdup(map, game)) == 1)
		ft_error(game, "Map is not fully accessible\n");
	return ;
}

void	check_borders(char **map, t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->size.x)
	{
		if (map[0][i] != '1' || map[game->size.y - 1][i] != '1')
			ft_error(game, "Map must be surrounded by '1'\n");
		i++;
	}
	i = 0;
	while (i < game->size.y)
	{
		if (map[i][0] != '1' || map[i][game->size.x - 1] != '1')
			ft_error(game, "Map must be surrounded by '1'\n");
		i++;
	}
}
