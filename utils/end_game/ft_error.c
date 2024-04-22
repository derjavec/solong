/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:47:21 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 08:47:22 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../so_long.h"

void	ft_error(t_solong *game, char *msg)
{
	size_t	i;

	i = 0;
	free_all(game);
	write(2, "Error:", 6);
	while (i < ft_strlen(msg))
		write(2, &msg[i++], 1);
	exit(EXIT_FAILURE);
}
