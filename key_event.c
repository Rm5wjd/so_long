/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:17 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 20:43:12 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void key_flag_set(int keycode, t_all *all)
{
	if (keycode == W)
		all->player.w_flag = 1;
	else if (keycode == A)
		all->player.a_flag = 1;
	else if (keycode == S)
		all->player.s_flag = 1;
	else if (keycode == D)
		all->player.d_flag = 1;
}
void	key_input(t_all *all)
{
	t_pos		prev;
	int			collision;
	static int	cnt_frame;

	prev.x = all->player.pos.x;
	prev.y = all->player.pos.y;
	wasd_pos_set(all);
	box_collider_update(all);
	collision = collision_detect(all);
	if (collision == WALL)
	{
		all->player.pos = prev;
		return ;
	}
	else if (collision == EXIT)
	{
		if (all->collectible_cnt == 0)
			exit (0);
		all->player.pos = prev;
	}
	if (++cnt_frame % 2 == 0)
		all->walk_cnt++;
}

int	key_down(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keycode == ESC)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(0);
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 40, \
		create_trgb(0, 255, 0, 0), "key_down");
	key_flag_set(keycode, all);
	key_input(all);
	return (keycode);
}

int mouse_down(int button, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_printf("%d, x: %d y: %d", button, x, y);
	return (button);
}

int redcross_close(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_printf("exit");
	exit(0);
}