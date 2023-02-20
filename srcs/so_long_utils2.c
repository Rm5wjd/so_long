/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:32:13 by junglee           #+#    #+#             */
/*   Updated: 2023/02/20 15:04:16 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_idle(t_all *all, t_player player, int idle_frame)
{
	if (player.look_direction == LEFT)
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		player.idle_left_sprite[idle_frame / 20].img, \
		player.pos.x, player.pos.y);
	else
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		player.idle_right_sprite[idle_frame / 20].img, \
		player.pos.x, player.pos.y);
}

void	render_move(t_all *all, t_player player, int move_frame)
{
	if (player.look_direction == LEFT)
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		player.move_left_sprite[move_frame / 20].img, \
		player.pos.x, player.pos.y);
	else
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		player.move_right_sprite[move_frame / 20].img, \
		player.pos.x, player.pos.y);
}

void	render_move_enemy(t_all *all, t_enemy enemy, int move_frame)
{
	if (enemy.look_direction == LEFT)
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		enemy.move_left_sprite[move_frame / 20].img, \
		enemy.pos.x, enemy.pos.y);
	else
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		enemy.move_right_sprite[move_frame / 20].img, \
		enemy.pos.x, enemy.pos.y);
}

int	haveone_final_check(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->collectible_cnt == 0 || all->exit_cnt == 0 || \
	all->startpos_cnt == 0 || all->startpos_cnt > 1 || all->exit_cnt > 1)
		return (0);
	while (i < all->map_height)
	{
		j = 0;
		while (j < all->map_width)
		{
			if (all->map[i][j] != 'C' && all->map[i][j] != 'E' && \
				all->map[i][j] != 'P' && all->map[i][j] != '1' && \
				all->map[i][j] != '0')
			{
				ft_printf("exception character detect!\n");
				exit_error();
			}
			j++;
		}
		i++;
	}
	return (1);
}
