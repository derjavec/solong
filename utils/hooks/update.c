/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:33:56 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/18 14:33:57 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static void	anim_player_r(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->player_r_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.player = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.player = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.player = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.player = temp->next->next->next->content;
	return ;
}

static void	anim_player_l(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->player_l_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.player = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.player = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.player = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.player = temp->next->next->next->content;
	return ;
}

static void	anim_enemy(t_solong *game)
{	
	t_list_img	*temp;

	temp = *game->enemy_animation;
	if (game->frames == 1 || game->frames == 500)
		game->img.enemy = temp->content;
	if (game->frames == 125 || game->frames == 625)
		game->img.enemy = temp->next->content;
	if (game->frames == 250 || game->frames == 750)
		game->img.enemy = temp->next->next->content;
	if (game->frames == 375 || game->frames == 875)
		game->img.enemy = temp->next->next->next->content;
	return ;
}

int	update(t_solong *game)
{
	game->frames++;
	if (game->frames > 1000)
		game->frames = 0;
	if (game->next_level == 0 && game->game_over == 0 && game->winner == 0)
	{
		animation(game);
		anim_enemy(game);
		if (game->direction == 0)
			anim_player_r(game);
		if (game->direction == 1)
			anim_player_l(game);
		if (game->frames == 200)
			move_enemy(game);
		render(game, game->map);
	}	
	if (game->next_level == 1)
		print_img(game, game->img.next_level, 0, 0);
	if (game->game_over == 1)
		print_img(game, game->img.game_over, 0, 0);
	if (game->winner == 1)
		print_img(game, game->img.winner, 0, 0);
	return (0);
}
