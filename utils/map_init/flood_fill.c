/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:04:20 by derjavec          #+#    #+#             */
/*   Updated: 2024/05/06 12:37:50 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	filling_utils(int x, int y, char **tempmap, t_solong *game)
{
	if (x < 0 || y < 0 || x >= game->size.x || y >= game->size.y \
		|| tempmap[y][x] == '1' || tempmap[y][x] == 'V')
		return (1);
	if (tempmap[y][x] == 'F' || tempmap[y][x] == 'M' || tempmap[y][x] == 'V')
		return (1);
	else if (tempmap[y][x] == 'C' && (tempmap[y + 1][x] == 'F' \
		|| tempmap[y + 1][x] == '0' || tempmap[y][x + 1] == 'F' \
		|| tempmap[y][x + 1] == '0' || tempmap[y - 1][x] == 'F' \
		|| tempmap[y - 1][x] == '0' || tempmap[y][x - 1] == 'F' \
		|| tempmap[y][x - 1] == '0'))
		game->map_collectibles++;
	else if (tempmap[y][x] == 'E')
	{
		game->exit++;
		tempmap[y][x] = 'V';
	}
	if (tempmap[y][x] == '0' || tempmap[y][x] == 'C')
		tempmap[y][x] = 'F';
	return (0);
}

static int	filling(int x, int y, char **tempmap, t_solong *game)
{
	if (filling_utils(x, y, tempmap, game) == 1)
		return (1);
	filling(x - 1, y, tempmap, game);
	filling(x + 1, y, tempmap, game);
	filling(x, y - 1, tempmap, game);
	filling(x, y + 1, tempmap, game);
	if (game->map_collectibles != game->map_content.collectible \
		|| game->exit != 1)
		return (1);
	return (0);
}

int	flood_fill(t_solong *game, char **tempmap)
{
	if (filling(game->player.x, game->player.y, tempmap, game) == 1)
	{
		ft_freemap(tempmap);
		return (1);
	}
	ft_freemap(tempmap);
	return (0);
}
