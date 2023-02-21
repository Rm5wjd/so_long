/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:28:43 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 19:32:22 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	enemy_pos_set(int i, int j, t_all *all_data)
{
	const int	delta_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	const int	delta_y[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int			idx;

	idx = 0;
	while (idx < 8)
	{
		if (i + delta_y[idx] < 0 || i + delta_y[idx] >= all_data->map_height - 1
			|| j + delta_x[idx] < 0 || \
			j + delta_x[idx] >= all_data->map_width - 1)
		{
			idx++;
			continue ;
		}
		if (all_data->map[i + delta_y[idx]][j + delta_x[idx]] != '1')
		{
			all_data->enemy.pos.x = (j + delta_x[idx]) * TILE_BIT;
			all_data->enemy.pos.y = (i + delta_y[idx]) * TILE_BIT;
		}
		idx++;
	}
}

void	enemy_spawn(t_all *all_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < all_data->map_height)
	{
		j = 0;
		while (j < all_data->map_width)
		{
			if (all_data->map[i][j] == 'E')
			{
				enemy_pos_set(i, j, all_data);
				return ;
			}
			j++;
		}
		i++;
	}
}
