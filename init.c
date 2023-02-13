#include "main.h"

void	data_init(t_all	*all_data)
{
	ft_bzero(all_data, sizeof(all_data));
	all_data->mlx_ptr = mlx_init();
	all_data->win_ptr = mlx_new_window(all_data->mlx_ptr, MAP_WIDTH * TILE_BIT, MAP_HEIGHT * TILE_BIT, "Hello world!");
	all_data->player.state = IDEL;
	all_data->player.look_direction = RIGHT;
	all_data->player.w_flag = 0;
	all_data->player.a_flag = 0;
	all_data->player.s_flag = 0;
	all_data->player.d_flag = 0;
	all_data->background.img = mlx_xpm_file_to_image(all_data->mlx_ptr, "./Sprites/background/bitmap.xpm", \
	&(all_data->background.img_width), &(all_data->background.img_height));
	all_data->wall.img = mlx_xpm_file_to_image(all_data->mlx_ptr, "./Sprites/tileset/Brick_Wall.xpm", \
	&(all_data->wall.img_width), &(all_data->wall.img_height));
	all_data->plane.img = mlx_xpm_file_to_image(all_data->mlx_ptr, "./Sprites/tileset/Metal_Floor.xpm", \
	&(all_data->plane.img_width), &(all_data->plane.img_height));
	all_data->exit.img = mlx_xpm_file_to_image(all_data->mlx_ptr, "./Sprites/tileset/exit.xpm", \
	&(all_data->exit.img_width), &(all_data->exit.img_height));
	player_left_sprite_init(all_data);
	player_right_sprite_init(all_data);
}