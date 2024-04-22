/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:01:43 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 09:01:44 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../so_long.h"

int	ft_filelen(const char *filename)
{
	char	*temp;
	int		fd;
	int		len;

	fd = open(filename, O_RDONLY);
	len = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		len++;
		free (temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (len);
}
