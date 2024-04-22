/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:13:27 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/06 14:13:29 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbru(unsigned int n)
{
	char	nbr;

	if (n > 9)
	{
		ft_putnbru(n / 10);
	}
	nbr = n % 10 + 48;
	write (1, &nbr, 1);
}

int	ft_print_u(unsigned int u)
{
	int				len;

	ft_putnbru(u);
	len = 0;
	if (u == 0)
		len = 1;
	while (u != 0)
	{
		u = u / 10;
		len++;
	}
	return (len);
}
