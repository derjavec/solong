/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:04:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/19 11:04:33 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	level_initializer(char *filename)
{
	int		level;
	size_t	filename_len;

	level = -1;
	filename_len = strlen(filename);
	if (filename_len >= 4 \
		&& strncmp(filename + filename_len - 4, ".ber", 4) == 0)
	{
		if (strcmp(filename, "maps/map_level_1.ber") == 0)
			level = 0;
		else if (strcmp(filename, "maps/map_level_2.ber") == 0)
			level = 1;
		else if (strcmp(filename, "maps/map_level_3.ber") == 0)
			level = 2;
	}
	return (level);
}

void	assign_level(char *filename, t_solong *game)
{
	game->g_level.current = level_initializer(filename);
	if (game->g_level.current < 0)
		ft_error(game, "Wrong name, expected : map_level_n being n 1, 2 or 3\n");
	if (game->g_level.current == 0)
	{
		game->g_level.l[0] = "maps/map_level_1.ber";
		game->g_level.l[1] = "maps/map_level_2.ber";
		game->g_level.l[2] = "maps/map_level_3.ber";
	}
	else if (game->g_level.current == 1)
	{
		game->g_level.l[1] = "maps/map_level_2.ber";
		game->g_level.l[2] = "maps/map_level_3.ber";
	}
	else if (game->g_level.current == 2)
		game->g_level.l[2] = "maps/map_level_3.ber";
	return ;
}
