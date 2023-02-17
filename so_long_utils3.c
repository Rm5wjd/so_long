/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:45:03 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 15:46:34 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	vertex_y_from_to(t_all *all, t_pos from, t_pos to)
{
	while (from.y <= to.y)
	{
		if (all->map[from.y / 64][from.x / 64] == '1')
			return (WALL);
		else if (all->map[from.y / 64][from.x / 64] == 'C')
		{
			all->map[from.y / 64][from.x / 64] = '0';
			all->collectible_cnt--;
			return (COLLECTIBLE);
		}
		else if (all->map[from.y / 64][from.x / 64] == 'E')
			return (EXIT);
		from.y++;
	}
	return (EMPTY);
}

int	vertex_x_from_to(t_all *all, t_pos from, t_pos to)
{
	while (from.x <= to.x)
	{
		if (all->map[from.y / 64][from.x / 64] == '1')
			return (WALL);
		else if (all->map[from.y / 64][from.x / 64] == 'C')
		{
			all->map[from.y / 64][from.x / 64] = '0';
			all->collectible_cnt--;
			return (COLLECTIBLE);
		}
		else if (all->map[from.y / 64][from.x / 64] == 'E')
			return (EXIT);
		from.x++;
	}
	return (EMPTY);
}
