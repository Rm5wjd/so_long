#include "main.h"

void	box_collider_update(t_all *all)
{
	all->player.rect.left_top.x = all->player.pos.x;
	all->player.rect.left_top.y = all->player.pos.y;

	all->player.rect.left_bot.x = all->player.pos.x;
	all->player.rect.left_bot.y = all->player.pos.y + PLAYER_HEIGHT;

	all->player.rect.right_top.x = all->player.pos.x + PLAYER_WIDTH;
	all->player.rect.right_top.y = all->player.pos.y;

	all->player.rect.right_bot.x = all->player.pos.x + PLAYER_WIDTH;
	all->player.rect.right_bot.y = all->player.pos.y + PLAYER_HEIGHT;
}

static int	vertex_detect(t_pos from, t_pos to, t_all *all)
{
	if (from.x == to.x)
	{
		while (from.y <= to.y)
		{
			if (all->map[from.y / 64][from.x / 64] == '1')
				return (WALL);
			else if (all->map[from.y / 64][from.x / 64] == 'C')
				return (COLLECTIBLE);
			else if (all->map[from.y / 64][from.x / 64] == 'E')
				return (EXIT);
			from.y++;
		}
	}
	else
	{
		while (from.x <= to.x)
		{
			if (all->map[from.y / 64][from.x / 64] == '1')
				return (WALL);
			else if (all->map[from.y / 64][from.x / 64] == 'C')
				return (COLLECTIBLE);
			else if (all->map[from.y / 64][from.x / 64] == 'E')
				return (EXIT);
			from.x++;
		}
	}
	return (EMPTY);
}

int	collision_detect(t_all *all)
{
	t_pos	vertex_from;
	t_pos	vertex_to;

	vertex_from = all->player.rect.left_top;
	vertex_to = all->player.rect.right_top;
	if (vertex_detect(vertex_from, vertex_to, all) == WALL)
		return (1);
	vertex_from = all->player.rect.left_top;
	vertex_to = all->player.rect.left_bot;
	if (vertex_detect(vertex_from, vertex_to, all) == WALL)
		return (1);
	vertex_from = all->player.rect.right_bot;
	vertex_to = all->player.rect.right_top;
	if (vertex_detect(vertex_from, vertex_to, all) == WALL)
		return (1);
	vertex_from = all->player.rect.right_bot;
	vertex_to = all->player.rect.left_bot;
	if (vertex_detect(vertex_from, vertex_to, all) == WALL)
		return (1);
	return (0);
}
