/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:43:01 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 19:27:54 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	map_free(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map_height)
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
}

void	found_zero(int **found, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			found[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	map_zero(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map_height)
	{
		j = 0;
		while (j < all->map_width)
		{
			all->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	enemy_collision_check(t_all *all, t_pos prev)
{
	enemy_box_collider_update(all);
	if (enemy_player_collision(all))
		exit_so_long(all);
	if (enemy_object_collision(all))
		all->enemy.pos = prev;
}

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
