#include "main.h"

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
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->wall.img, j * TILE_BIT, i * TILE_BIT);
			else if (all->map[i][j] == '0' || all->map[i][j] == 'P' || all->map[i][j] == 'C')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->plane.img, j * TILE_BIT, i * TILE_BIT);
			else if (all->map[i][j] == 'E')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->exit.img, j * TILE_BIT, i * TILE_BIT);
			j++;
		}
		i++;
	}
}