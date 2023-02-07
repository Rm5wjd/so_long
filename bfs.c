#include "main.h"

static	int	**found_arr_init(int width, int height)
{
	int	**found;
	int	i;

	i = 0;
	found = (int **)malloc(sizeof(int *) * height);
	if (!found)
		return (0);
	while (i < height)
	{
		found[i] = (int *)malloc(sizeof(int) * width);
		if (!found[i])
			return (0);
		i++;
	}
	ft_bzero(found, sizeof(found));
	return (found);
}

static int	delta_y(int now_y, int i)
{
	int delta_y[4];

	delta_y[0] = -1;
	delta_y[1] = 0;
	delta_y[2] = 1;
	delta_y[3] = 0;
	return (now_y + delta_y[i]);
}

static int	delta_x(int now_x, int i)
{
	int delta_x[4];

	delta_x[0] = 0;
	delta_x[1] = -1;
	delta_x[2] = 0;
	delta_x[3] = 1;
	return (now_x + delta_x[i]);
}

static	void	bfs_search(int now_y, int now_x, t_queue *q, t_all *all)
{
	int	next_y;
	int	next_x;
	int	i;

	i = 0;
	ft_printf("bfs_serach start\n");
	while (i < 4)
	{
		next_y = delta_y(now_y, i);
		next_x = delta_x(now_x, i);
		if (next_x < 0 || next_x >= all->map_width || \
		next_y < 0 || next_y >= all->map_height)
		{
			i++;
			continue ;
		}
		if (all->map[next_y][next_x] == '1')
		{
			i++;
			continue ;
		}
		if (all->found[next_y][next_x] == 1)
		{
			i++;
			continue ;
		}
		enqueue(q, next_x, next_y);
		all->found[next_y][next_x] = 1;
		i++;
	}
}

int	bfs(t_all *all)
{
	t_queue	q;
	t_pos	pos;
	int		colletible_cnt;

	all->found = found_arr_init(all->map_width, all->map_height);
	//ft_printf("found init pass\n");
	init_queue(&q);
	//ft_printf("init q pass\n");
	//ft_printf("%d\n", q.count);
	enqueue(&q, all->player.pos.x, all->player.pos.y);
	//ft_printf("enqueue pass\n");
	all->found[all->player.pos.y][all->player.pos.x] = 1;
	colletible_cnt = 0;
	while (q.count > 0)
	{
		pos = dequeue(&q);
		if (all->map[pos.y][pos.x] == 'C')
			colletible_cnt++;
		if (all->map[pos.y][pos.x] == 'E' && \
		colletible_cnt == all->collectible_cnt)
			return (1);
		bfs_search(pos.y, pos.x, &q, all);
		ft_printf("bfs_serach pass\n");
	}
	// found free
	return (0);
}