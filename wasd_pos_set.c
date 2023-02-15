/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_pos_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:43:11 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 20:43:12 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	w_flag_pos_set(t_player *player)
{
	player->pos.y -= VELOCITY;
	player->state = MOVE;
	if (player->d_flag)
	{
		player->pos.x += VELOCITY;
		player->look_direction = RIGHT;
	}
	else if (player->a_flag)
	{
		player->pos.x -= VELOCITY;
		player->look_direction = LEFT;
	}
}

static void	a_flag_pos_set(t_player *player)
{
	player->pos.x -= VELOCITY;
	player->state = MOVE;
	player->look_direction = LEFT;
	if (player->w_flag)
		player->pos.y -= VELOCITY;
	else if (player->s_flag)
		player->pos.y += VELOCITY;
}

static void	s_flag_pos_set(t_player *player)
{
	player->pos.y += VELOCITY;
	player->state = MOVE;
	if (player->d_flag)
	{
		player->pos.x += VELOCITY;
		player->look_direction = RIGHT;
	}
	else if (player->a_flag)
	{
		player->pos.x -= VELOCITY;
		player->look_direction = LEFT;
	}
}

static void	d_flag_pos_set(t_player *player)
{
	player->pos.x += VELOCITY;
	player->state = MOVE;
	player->look_direction = RIGHT;
	if (player->w_flag)
		player->pos.y -= VELOCITY;
	else if (player->s_flag)
		player->pos.y += VELOCITY;
}

void	wasd_pos_set(t_all *all)
{
	if (all->player.w_flag)
		w_flag_pos_set(&all->player);
	else if (all->player.a_flag)
		a_flag_pos_set(&all->player);
	else if (all->player.s_flag)
		s_flag_pos_set(&all->player);
	else if (all->player.d_flag)
		d_flag_pos_set(&all->player);
}