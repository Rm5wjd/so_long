/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:59:08 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 17:21:59 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	enemy_box_collider_update(t_all *all)
{
	all->enemy.rect.left_top.x = all->enemy.pos.x + 16;
	all->enemy.rect.left_top.y = all->enemy.pos.y + 4;
	all->enemy.rect.left_bot.x = all->enemy.rect.left_top.x;
	all->enemy.rect.left_bot.y = all->enemy.rect.left_top.y + ENEMY_HEIGHT;
	all->enemy.rect.right_top.x = all->enemy.rect.left_top.x + ENEMY_WIDTH;
	all->enemy.rect.right_top.y = all->enemy.rect.left_top.y;
	all->enemy.rect.right_bot.x = all->enemy.rect.left_top.x + ENEMY_WIDTH;
	all->enemy.rect.right_bot.y = all->enemy.rect.left_top.y + ENEMY_HEIGHT;
}

static int	player_detect(t_pos from, t_pos to, t_all *all)
{
	if (from.x == to.x)
	{
		while (from.y <= to.y)
		{
			if (from.y >= all->player.rect.left_top.y && \
				from.y <= all->player.rect.left_bot.y && \
				from.x >= all->player.rect.left_top.x && \
				from.x <= all->player.rect.right_top.x)
				return (1);
			from.y++;
		}
	}
	else
	{
		while (from.x <= to.x)
		{
			if (from.y >= all->player.rect.left_top.y && \
				from.y <= all->player.rect.left_bot.y && \
				from.x >= all->player.rect.left_top.x && \
				from.x <= all->player.rect.right_top.x)
				return (1);
			from.x++;
		}
	}
	return (0);
}

static int	object_detect(t_pos from, t_pos to, t_all *all)
{
	if (from.x == to.x)
	{
		while (from.y <= to.y)
		{
			if (all->map[from.y / 64][from.x / 64] == '1')
				return (1);
			from.y++;
		}
	}
	else
	{
		while (from.x <= to.x)
		{
			if (all->map[from.y / 64][from.x / 64] == '1')
				return (1);
			from.x++;
		}
	}
	return (0);
}

int	enemy_player_collision(t_all *all)
{
	t_box_collider	box;

	box.top = player_detect(all->enemy.rect.left_top, \
	all->enemy.rect.right_top, all);
	box.left = player_detect(all->enemy.rect.left_top, \
	all->enemy.rect.left_bot, all);
	box.right = player_detect(all->enemy.rect.right_top, \
	all->enemy.rect.right_bot, all);
	box.bot = player_detect(all->enemy.rect.left_bot, \
	all->enemy.rect.right_bot, all);
	if (box.top || box.left || box.bot || box.right)
		return (1);
	return (0);
}

int	enemy_object_collision(t_all *all)
{
	t_box_collider	box;

	box.top = object_detect(all->enemy.rect.left_top, \
	all->enemy.rect.right_top, all);
	box.left = object_detect(all->enemy.rect.left_top, \
	all->enemy.rect.left_bot, all);
	box.right = object_detect(all->enemy.rect.right_top, \
	all->enemy.rect.right_bot, all);
	box.bot = object_detect(all->enemy.rect.left_bot, \
	all->enemy.rect.right_bot, all);
	if (box.top || box.left || box.bot || box.right)
		return (1);
	return (0);
}