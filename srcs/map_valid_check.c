/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:43 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 17:32:42 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	must_have_one(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map_height)
	{
		j = 0;
		while (j < all->map_width)
		{
			if (all->map[i][j] == 'C')
				all->collectible_cnt++;
			else if (all->map[i][j] == 'E')
				all->exit_cnt++;
			else if (all->map[i][j] == 'P')
			{
				all->player.pos.x = j * 64;
				all->player.pos.y = i * 64;
				all->startpos_cnt++;
			}
			j++;
		}
		i++;
	}
	return (haveone_final_check(all));
}

static int	wall_check(t_all *all)
{
	int	i;
	int	width_end;
	int	height_end;

	i = 0;
	width_end = all->map_width - 1;
	height_end = all->map_height - 1;
	while (i < all->map_width)
	{
		if (all->map[0][i] != '1' || all->map[height_end][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < all->map_height)
	{
		if (all->map[i][0] != '1' || all->map[i][width_end] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	screen_size_check(t_all *all)
{
	int	map_width;
	int	map_height;
	int	screen_width;
	int	screen_height;

	map_width = all->map_width * TILE_BIT;
	map_height = all->map_height * TILE_BIT;
	screen_height = 0;
	screen_height = 0;
	mlx_get_screen_size(all->mlx_ptr, &screen_width, &screen_height);
	if (screen_height < map_height || screen_width < map_width)
		return (1);
	return (0);
}

int	map_valid_check(t_all *all)
{
	if (!must_have_one(all))
	{
		ft_printf("must_have_one\n");
		return (1);
	}
	if (!wall_check(all))
	{
		ft_printf("wall_check catch\n");
		return (1);
	}
	if (!bfs(all))
	{
		ft_printf("bfs catch\n");
		return (1);
	}
	ft_printf("map check end\n");
	return (0);
}
