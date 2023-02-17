/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:43:04 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 21:21:03 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	collectible_tiling(t_all *all, int i, int j)
{
	static int	frame;

	if (++frame == 80)
		frame = 0;
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
	all->collectible[frame / 20].img, j * TILE_BIT, i * TILE_BIT);
}

void	tiling(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map_height)
	{
		j = 0;
		while (j < all->map_width)
		{
			if (all->map[i][j] == '1')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
				all->wall.img, j * TILE_BIT, i * TILE_BIT);
			if (!(all->map[i][j] == '1'))
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
				all->plane.img, j * TILE_BIT, i * TILE_BIT);
			if (all->map[i][j] == 'E')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
				all->exit.img, j * TILE_BIT, i * TILE_BIT);
			if (all->map[i][j] == 'C')
				collectible_tiling(all, i, j);
			j++;
		}
		i++;
	}
}
