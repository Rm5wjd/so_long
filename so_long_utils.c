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