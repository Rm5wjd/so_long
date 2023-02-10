#include "main.h"

static void key_flag_set(int keycode, t_all *all)
{
	if (keycode == W)
		all->player.w_flag = 1;
	else if (keycode == A)
		all->player.a_flag = 1;
	else if (keycode == S)
		all->player.s_flag = 1;
	else if (keycode == D)
		all->player.d_flag = 1;
}
static void	key_input(int keycode, t_all *all)
{
	t_pos	prev;

	prev.x = all->player.pos.x;
	prev.y = all->player.pos.y;
	if (all->player.w_flag)
	{
		all->player.pos.y -= VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "up move");
		if (all->player.d_flag)
		{
			all->player.pos.x += VELOCITY;
			all->player.look_direction = RIGHT;
		}
		else if (all->player.a_flag)
		{
			all->player.pos.x -= VELOCITY;
			all->player.look_direction = LEFT;
		}
	}
	else if (all->player.a_flag)
	{
		all->player.pos.x -= VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "left move");
		all->player.look_direction = LEFT;
		if (all->player.w_flag)
			all->player.pos.y -= VELOCITY;
		else if (all->player.s_flag)
			all->player.pos.y += VELOCITY;
	}
	else if (all->player.s_flag)
	{
		all->player.pos.y += VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "down move");
		if (all->player.d_flag)
		{
			all->player.pos.x += VELOCITY;
			all->player.look_direction = RIGHT;
		}
		else if (all->player.a_flag)
		{
			all->player.pos.x -= VELOCITY;
			all->player.look_direction = LEFT;
		}
	}
	else if (all->player.d_flag)
	{
		all->player.pos.x += VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "right move");
		all->player.look_direction = RIGHT;
		if (all->player.w_flag)
			all->player.pos.y -= VELOCITY;
		else if (all->player.s_flag)
			all->player.pos.y += VELOCITY;
	}
	box_collider_update(all);
	if (collision_detect(all))
		all->player.pos = prev;
}

int	key_down(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keycode == ESC)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(0);
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 40, \
		create_trgb(0, 255, 0, 0), "key_down");
	key_flag_set(keycode, all);
	key_input(keycode, all);
	return (keycode);
}

void	key_check(t_all *all)
{
	t_pos	prev;

	prev.x = all->player.pos.x;
	prev.y = all->player.pos.y;
	mlx_string_put(all->mlx_ptr, all->win_ptr, 300, 40, \
		create_trgb(0, 255, 50, 0), "key_check");
	if (all->player.w_flag)
	{
		all->player.pos.y -= VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "up move");
		if (all->player.d_flag)
		{
			all->player.pos.x += VELOCITY;
			all->player.look_direction = RIGHT;
		}
		else if (all->player.a_flag)
		{
			all->player.pos.x -= VELOCITY;
			all->player.look_direction = LEFT;
		}
	}
	else if (all->player.a_flag)
	{
		all->player.pos.x -= VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "left move");
		all->player.look_direction = LEFT;
		if (all->player.w_flag)
			all->player.pos.y -= VELOCITY;
		else if (all->player.s_flag)
			all->player.pos.y += VELOCITY;
	}
	else if (all->player.s_flag)
	{
		all->player.pos.y += VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "down move");
		if (all->player.d_flag)
		{
			all->player.pos.x += VELOCITY;
			all->player.look_direction = RIGHT;
		}
		else if (all->player.a_flag)
		{
			all->player.pos.x -= VELOCITY;
			all->player.look_direction = LEFT;
		}
	}
	else if (all->player.d_flag)
	{
		all->player.pos.x += VELOCITY;
		all->player.state = MOVE;
		mlx_string_put(all->mlx_ptr, all->win_ptr, 140, 60, \
		create_trgb(0, 255, 0, 0), "right move");
		all->player.look_direction = RIGHT;
		if (all->player.w_flag)
			all->player.pos.y -= VELOCITY;
		else if (all->player.s_flag)
			all->player.pos.y += VELOCITY;
	}
	box_collider_update(all);
	if (collision_detect(all))
		all->player.pos = prev;
}

int mouse_down(int button, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_printf("%d, x: %d y: %d", button, x, y);
	return (button);
}

int redcross_close(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_printf("exit");
	exit(0);
}