/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:40:22 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/07 13:40:23 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

int	ft_printf(const char *s, ...);
int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_p(unsigned long long p);
int	ft_print_di(int d);
int	ft_print_u(unsigned int u);
int	ft_print_x(unsigned int x);
int	ft_print_xx(unsigned int x);
#endif
