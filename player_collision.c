/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:49 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 15:48:08 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	box_collider_update(t_all *all)
{
	all->player.rect.left_top.x = all->player.pos.x + 17;
	all->player.rect.left_top.y = all->player.pos.y + 14;
	all->player.rect.left_bot.x = all->player.rect.left_top.x;
	all->player.rect.left_bot.y = all->player.rect.left_top.y + PLAYER_HEIGHT;
	all->player.rect.right_top.x = all->player.rect.left_top.x + PLAYER_WIDTH;
	all->player.rect.right_top.y = all->player.rect.left_top.y;
	all->player.rect.right_bot.x = all->player.rect.left_top.x + PLAYER_WIDTH;
	all->player.rect.right_bot.y = all->player.rect.left_top.y + PLAYER_HEIGHT;
}

static int	vertex_detect(t_pos from, t_pos to, t_all *all)
{
	if (from.x == to.x)
		return (vertex_y_from_to(all, from, to));
	else
		return (vertex_x_from_to(all, from, to));
}

static int	collided_object(t_box_collider box)
{
	if (box.top == WALL || box.bot == WALL || \
	box.left == WALL || box.right == WALL)
		return (WALL);
	else if (box.top == COLLECTIBLE || box.bot == COLLECTIBLE || \
	box.left == COLLECTIBLE || box.right == COLLECTIBLE)
		return (COLLECTIBLE);
	else if (box.top == EXIT || box.bot == EXIT || \
	box.left == EXIT || box.right == EXIT)
		return (EXIT);
	else if (box.top == ENEMY || box.bot == ENEMY || \
	box.left == ENEMY || box.right == ENEMY)
		return (ENEMY);
	else
		return (EMPTY);
}

int	collision_detect(t_all *all)
{
	t_box_collider	box;

	box.top = vertex_detect(all->player.rect.left_top, \
	all->player.rect.right_top, all);
	box.left = vertex_detect(all->player.rect.left_top, \
	all->player.rect.left_bot, all);
	box.right = vertex_detect(all->player.rect.right_top, \
	all->player.rect.right_bot, all);
	box.bot = vertex_detect(all->player.rect.left_bot, \
	all->player.rect.right_bot, all);
	return (collided_object(box));
}
