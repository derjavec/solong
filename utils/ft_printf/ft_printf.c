/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:55:58 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/03 12:56:00 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(int f, va_list content)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_print_c(va_arg(content, int));
	else if (f == 's')
		len += ft_print_s((va_arg(content, char *)));
	else if (f == 'p')
		len += ft_print_p(va_arg(content, unsigned long long));
	else if (f == 'd' || f == 'i')
		len += ft_print_di(va_arg(content, int));
	else if (f == 'u')
		len += ft_print_u(va_arg(content, unsigned int));
	else if (f == 'x')
		len += ft_print_x(va_arg(content, unsigned int));
	else if (f == 'X')
		len += ft_print_xx(va_arg(content, unsigned int));
	else if (f == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	content;

	va_start (content, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format [i] == '%')
		{
			len += ft_format(format[i + 1], content);
			i++;
		}
		else
			len += write (1, &format[i], 1);
		i++;
	}	
	va_end(content);
	return (len);
}
