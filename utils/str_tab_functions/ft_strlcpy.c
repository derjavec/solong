/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:22:29 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 09:22:30 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
		i++;
	if (n > 0)
	{
		j = 0;
		while (s[j] && j < n - 1)
		{
			d[j] = s[j];
			j++;
		}
		d[j] = '\0';
	}
	return (i);
}
