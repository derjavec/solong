/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:49 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/18 11:08:51 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	ft_lstclear_solong(t_list_img **lst)
{
	t_list_img	*current;
	t_list_img	*next;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current ->next;
		free (current);
		current = next;
	}
	*lst = NULL;
}
