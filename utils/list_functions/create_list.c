/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:22:29 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 14:22:30 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

t_list_img	**create_list(void *img[], t_solong *game)
{
	t_list_img	**animation_list;
	t_list_img	*animation_node;
	int			i;

	animation_list = malloc(4 * sizeof(t_list_img *));
	if (animation_list == NULL)
		ft_error(game, "Malloc error creating an animation list\n");
	i = 0;
	while (i < 4)
		animation_list[i++] = NULL;
	i = 0;
	while (i < 4)
	{
		animation_node = ft_lstnew(img[i]);
		if (animation_node == NULL)
			ft_error(game, "Malloc error creating an animation list\n");
		ft_lstadd_back(animation_list, animation_node);
		i++;
	}
	return (animation_list);
}
