/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:53:55 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/07 12:53:56 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned int x, int *len)
{
	char				*hexdig;
	char				hexchar;
	unsigned long long	n;

	hexdig = "0123456789ABCDEF";
	n = x;
	if (n == 0)
	{
		write(1, "0", 1);
		(*len)++;
	}
	else
	{
		if (n > 15)
		{
			ft_putnbr_hex(n / 16, len);
		}
		hexchar = hexdig[n % 16];
		write (1, &hexchar, 1);
		(*len)++;
	}
	return ((*len));
}

int	ft_print_xx(unsigned int x)
{
	int	len;

	len = 0;
	len = ft_putnbr_hex(x, &len);
	return (len);
}
