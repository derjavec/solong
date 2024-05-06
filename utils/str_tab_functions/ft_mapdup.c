/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:54:28 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 09:54:29 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	mapheight(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

char	**ft_mapdup(char **map, t_solong *game)
{
	char	**result;
	int		i;
	int		height;

	i = 0;
	height = mapheight(map);
	result = malloc((height + 1) * sizeof(char *));
	if (result == NULL)
		ft_error(game, "Malloc error in map");
	while (map && map[i])
	{
		result[i] = ft_strdup(map[i]);
		if (!result[i])
		{
			ft_freemap(result);
			ft_error(game, "Malloc error in map");
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
