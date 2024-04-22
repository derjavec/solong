/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:14:26 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 15:14:28 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	map_format(char **map, t_solong *game)
{
	char	*temp;
	size_t	i;

	i = 0;
	game->size.x = ft_strlen(map[i]) - 1;
	if (game->size.x != 17)
		ft_error(game, "Wrong map size, 9 lines expected");
	while (map && map[i])
	{
		temp = ft_strtrim(map[i], "\n");
		free(map[i]);
		map[i] = temp;
		if ((int)ft_strlen(map[i]) != game->size.x)
			ft_error(game, "Format error\n");
		i++;
	}
	check_borders(map, game);
	check_content(map, game);
}

static void	map_set(t_solong *game, char *filename)
{
	char	*temp;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Fail to open file\n");
	temp = get_next_line(fd);
	while (temp)
	{
		game->map[i++] = temp;
		temp = get_next_line(fd);
	}
	close(fd);
	game->map[i] = NULL;
	if (game->map[0] == NULL)
		ft_error(game, "Empty map");
}

void	map_init(t_solong *game, char *filename)
{
	if (ft_strnstr(filename, ".ber", ft_strlen(filename)) == NULL)
		ft_error(game, "Invalid file extention\n");
	initialize(game);
	assign_level(filename, game);
	game->size.y = ft_filelen(filename);
	if (game->size.y != 9)
		ft_error(game, "Wrong map size, 9 lines expected");
	game->map = malloc((game->size.y + 1) * sizeof(char *));
	if (game->map == NULL)
		ft_error(game, "malloc error for map\n");
	map_set(game, filename);
	map_format(game->map, game);
}
