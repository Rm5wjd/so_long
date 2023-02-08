#include "main.h"

static void	render_background(t_all *all)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(all->mlx_ptr, "./Sprites/background/bitmap.xpm", &width, &height);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, img, 0, 0);
}

static void	render_player(t_all *all)
{
	t_player player;

	player = all->player;
	if (player.state == IDEL)
	{
		if (player.look_direction == LEFT)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.idle_left_sprite[0].img, player.pos.x, player.pos.y);
		}
		else
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.idle_right_sprite[0].img, player.pos.x, player.pos.y);
		}
	}
	else if (player.state == MOVE)
	{
		if (player.look_direction == LEFT)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.move_left_sprite[0].img, player.pos.x, player.pos.y);
		}
		else
		{
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, player.move_right_sprite[0].img, player.pos.x, player.pos.y);
		}
	}
}

int	render_all(t_all * all)
{
	if (!all->player.a_flag && !all->player.d_flag \
	&& !all->player.w_flag && !all->player.s_flag)
		all->player.state = IDEL;
	//render_background(all);
	render_player(all);
	return (0);
}