/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:05:48 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/06 09:05:49 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

static size_t	ft_strlen( const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_print_s(char *s)
{
	int		len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr(s);
	len = ft_strlen (s);
	return (len);
}
