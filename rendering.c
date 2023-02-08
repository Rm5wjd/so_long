#include "main.h"

static void	render_background(t_all *all)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->background.img, 0, 0);
}

static void	render_player(t_all *all)
{
	t_player	player;
	static int	move_frame;
	static int	idle_frame;

	player = all->player;
	if (player.state == IDEL)
	{
		move_frame = 0;
		if (++idle_frame == 120)
			idle_frame = 0;
		if (player.look_direction == LEFT)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.idle_left_sprite[idle_frame / 20].img, player.pos.x, player.pos.y);
		}
		else
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.idle_right_sprite[idle_frame / 20].img, player.pos.x, player.pos.y);
		}
	}
	else if (player.state == MOVE)
	{
		idle_frame = 0;
		if (++move_frame == 80)
			move_frame = 0;
		if (player.look_direction == LEFT)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.move_left_sprite[move_frame / 20].img, player.pos.x, player.pos.y);
		}
		else
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.move_right_sprite[move_frame / 20].img, player.pos.x, player.pos.y);
		}
	}
}

static void	render_info(t_all *all)
{
	mlx_string_put(all->mlx_ptr, all->win_ptr, 50, 50, create_trgb(0, 255, 0, 0), ft_itoa(all->player.w_flag));
	mlx_string_put(all->mlx_ptr, all->win_ptr, 40, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.a_flag));
	mlx_string_put(all->mlx_ptr, all->win_ptr, 50, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.s_flag));
	mlx_string_put(all->mlx_ptr, all->win_ptr, 60, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.d_flag));
	mlx_string_put(all->mlx_ptr, all->win_ptr, 120, 60, create_trgb(0, 255, 0, 0), ft_itoa(all->player.state));
}

int	render_all(t_all * all)
{
	static int	a;

	if (++a % 2 == 0)
		return (1);
	if (!all->player.a_flag && !all->player.d_flag \
	&& !all->player.w_flag && !all->player.s_flag)
		all->player.state = IDEL;
	render_background(all);
	render_info(all);
	render_player(all);
	return (0);
}