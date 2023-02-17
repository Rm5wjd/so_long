/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:56 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 20:59:20 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	render_background(t_all *all)
{
	if (all->collectible_cnt == 0)
	{
		free(all->exit.img);
		all->exit.img = mlx_xpm_file_to_image(all->mlx_ptr, \
		"./Sprites/tileset/exit_open.xpm", \
		&(all->exit.img_width), &(all->exit.img_height));
	}
	tiling(all);
}

static void	render_player(t_all *all)
{
	t_player	player;
	static int	move_frame;
	static int	idle_frame;

	player = all->player;
	if (player.state == IDEL)
	{
		move_frame = 0;
		if (++idle_frame == 120)
			idle_frame = 0;
		render_idle(all, player, idle_frame);
	}
	else if (player.state == MOVE)
	{
		idle_frame = 0;
		if (++move_frame == 80)
			move_frame = 0;
		render_move(all, player, move_frame);
	}
}

static void	render_info(t_all *all)
{
	char	*walk_cnt;

	walk_cnt = ft_itoa(all->walk_cnt);
	//mlx_string_put(all->mlx_ptr, all->win_ptr, 50, 50, create_trgb(0, 255, 0, 0), ft_itoa(all->player.w_flag));
	//mlx_string_put(all->mlx_ptr, all->win_ptr, 40, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.a_flag));
	//mlx_string_put(all->mlx_ptr, all->win_ptr, 50, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.s_flag));
	//mlx_string_put(all->mlx_ptr, all->win_ptr, 60, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.d_flag));
	//mlx_string_put(all->mlx_ptr, all->win_ptr, 120, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.state));
	//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->player.pos.x, all->player.pos.y, create_trgb(0, 255, 255, 0));
	//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->player.rect.left_top.x, all->player.rect.left_top.y, create_trgb(0, 255, 0, 0));
	//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->player.rect.left_bot.x, all->player.rect.left_bot.y, create_trgb(0, 255, 0, 0));
	//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->player.rect.right_bot.x, all->player.rect.right_bot.y, create_trgb(0, 255, 0, 0));
	//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->player.rect.right_top.x, all->player.rect.right_top.y, create_trgb(0, 255, 0, 0));
	mlx_string_put(all->mlx_ptr, all->win_ptr, 150, 80, create_trgb(0, 0, 255, 0), walk_cnt);
	ft_printf("%d\n", all->walk_cnt);
	free(walk_cnt);
}

static void	render_enemy(t_all *all)
{
	static int	move_frame;
	t_pos		prev;

	prev.x = all->enemy.pos.x;
	prev.y = all->enemy.pos.y;
	if (all->player.pos.x < all->enemy.pos.x)
	{
		all->enemy.look_direction = LEFT;
		all->enemy.pos.x -= 1;
	}
	else
	{
		all->enemy.look_direction = RIGHT;
		all->enemy.pos.x += 1;
	}
	enemy_collision_check(all, prev);
	prev.x = all->enemy.pos.x;
	if (all->player.pos.y < all->enemy.pos.y)
		all->enemy.pos.y -= 1;
	else
		all->enemy.pos.y += 1;
	enemy_collision_check(all, prev);
	if (++move_frame == 80)
		move_frame = 0;
	render_move_enemy(all, all->enemy, move_frame);
}

int	render_all(t_all *all)
{
	static int	a;

	if (++a % 2 == 0)
		return (1);
	if (!all->player.a_flag && !all->player.d_flag \
	&& !all->player.w_flag && !all->player.s_flag)
		all->player.state = IDEL;
	if ((all->player.a_flag || all->player.d_flag \
	|| all->player.s_flag || all->player.w_flag) && all->player.state == MOVE)
		key_input(all);
	render_background(all);
	render_info(all);
	render_player(all);
	render_enemy(all);
	return (0);
}
