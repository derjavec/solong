/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:22 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/06 13:49:24 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	nbr = n % 10 + 48;
	write (1, &nbr, 1);
}

int	ft_print_di(int d)
{
	int	len;

	ft_putnbr(d);
	len = 0;
	if (d <= 0)
		len = 1;
	while (d != 0)
	{
		d = d / 10;
		len++;
	}
	return (len);
}
