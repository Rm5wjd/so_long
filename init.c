#include "main.h"

void	data_init(t_all	*all_data)
{
	ft_bzero(all_data, sizeof(all_data));
	all_data->mlx_ptr = mlx_init();
	all_data->win_ptr = mlx_new_window(all_data->mlx_ptr, 576, 384, "Hello world!");
	all_data->player.state = IDEL;
	all_data->player.look_direction = RIGHT;
	all_data->player.w_flag = 0;
	all_data->player.a_flag = 0;
	all_data->player.s_flag = 0;
	all_data->player.d_flag = 0;
	all_data->background.img = mlx_xpm_file_to_image(all_data->mlx_ptr, "./Sprites/background/bitmap.xpm", \
	&(all_data->background.img_width), &(all_data->background.img_height));
	player_left_sprite_init(all_data);
	player_right_sprite_init(all_data);
}