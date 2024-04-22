/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:14:26 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 15:14:28 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strnstr(const char *str, const char *c, size_t len)
{
	size_t	i;
	size_t	j;

	if (c[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == c[j] && (i + j) < len)
		{
			if (c[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}				
		i++;
	}
	return (NULL);
}
