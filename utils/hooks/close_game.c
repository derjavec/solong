/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:56:16 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/05 11:56:17 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

int	close_game(t_solong *game)
{
	free_all(game);
	exit(0);
}

int	esc_to_close_game(int key, t_solong *game)
{
	if (key == ESC)
		close_game(game);
	return (0);
}
