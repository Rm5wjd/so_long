#include "main.h"

static int	rectangular_check(t_all *all)
{
	if (all->map_width == all->map_height || all->map_height <= 0 || all->map_width <= 0)
		return (0);
	else
		return (1);
}

static int	must_have_one(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->collectible_cnt = 0;
	all->exit_cnt = 0;
	all->startpos_cnt = 0;
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
				all->player.pos.x = j;
				all->player.pos.y = i;
				all->startpos_cnt++;
			}
			j++;
		}
		i++;
	}
	if (all->collectible_cnt == 0 || all->exit_cnt == 0 || all->startpos_cnt == 0 || all->startpos_cnt > 1)
		return (0);
	return (1);
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

int	map_valid_check(t_all *all)
{
	if (!rectangular_check(all))
		return (0);
	if (!must_have_one(all))
		return (0);
	if (!wall_check(all))
		return (0);
	if (!bfs(all))
		return (0);
	return (1);
}