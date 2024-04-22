/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:59:25 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/15 08:59:26 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	anim_exit(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->exit_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.exit = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.exit = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.exit = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.exit = temp->next->next->next->content;
	return ;
}

static void	anim_wall(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->wall_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.wall = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.wall = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.wall = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.wall = temp->next->next->next->content;
	return ;
}

static void	anim_floor(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->floor_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.floor = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.floor = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.floor = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.floor = temp->next->next->next->content;
	return ;
}

static void	anim_collectible(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->collectible_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.collectible = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.collectible = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.collectible = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.collectible = temp->next->next->next->content;
	return ;
}

void	animation(t_solong *game)
{
	anim_wall(game);
	anim_floor(game);
	anim_collectible(game);
	anim_exit(game);
}
