/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:15:14 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/06 09:15:17 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned long long p, int *len)
{
	char				*hexdig;
	char				hexchar;
	unsigned long long	n;

	hexdig = "0123456789abcdef";
	n = p;
	if (n > 15)
		ft_putnbr_hex(n / 16, len);
	hexchar = hexdig[n % 16];
	(*len)++;
	write (1, &hexchar, 1);
	return ((*len));
}

int	ft_print_p(unsigned long long p)
{
	int					len;

	write(1, "0x", 2);
	len = 2;
	len = ft_putnbr_hex(p, &len);
	return (len);
}
