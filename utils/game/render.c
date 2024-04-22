/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:42:40 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/05 09:42:41 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	print_img(t_solong *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
	return ;
}

static void	print_elements(t_solong *game, int x, int y)
{
	if (game->map[y][x] == '1')
		print_img(game, game->img.wall, x, y);
	else if (game->map[y][x] == '0')
		print_img(game, game->img.floor, x, y);
	else if (game->map[y][x] == 'C')
		print_img(game, game->img.collectible, x, y);
	else if (game->map[y][x] == 'E')
		print_img(game, game->img.exit, x, y);
	else if (game->map[y][x] == 'P')
		print_img(game, game->img.player, x, y);
	else if (game->map[y][x] == 'M')
		print_img(game, game->img.enemy, x, y);
	return ;
}

static void	print_moves_count(int number, t_solong *game)
{
	int	i;
	int	pos_digit;
	int	digit[4];

	i = 0;
	while (i < 4)
		digit[i++] = 0;
	i = 3;
	while (number > 0 && i >= 0)
	{
		digit[i] = number % 10;
		number /= 10;
		i--;
	}
	i = 0;
	pos_digit = 450;
	while (i < 4)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.number[digit[i]], pos_digit, 525);
		pos_digit += 64;
		i++;
	}
	return ;
}

void	render(t_solong *game, char **map)
{
	t_pos	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
			print_elements(game, pos.x++, pos.y);
		pos.y++;
	}
	print_moves_count(game->count_moves, game);
	return ;
}
