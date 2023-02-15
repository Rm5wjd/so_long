#include "main.h"

static void die_right_sprite(t_player *player, void *mlx_ptr)
{
	player->die_right_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/hurt_right_001.xpm",  \
	&(player->die_right_sprite[0].img_width), &(player->die_right_sprite[0].img_height));
	player->die_right_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/hurt_right_002.xpm",  \
	&(player->die_right_sprite[1].img_width), &(player->die_right_sprite[1].img_height));
	player->die_right_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/hurt_right_003.xpm",  \
	&(player->die_right_sprite[2].img_width), &(player->die_right_sprite[2].img_height));
	player->die_right_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/hurt_right_004.xpm",  \
	&(player->die_right_sprite[3].img_width), &(player->die_right_sprite[3].img_height));
}

static void collect_right_sprite(t_player *player, void *mlx_ptr)
{
	player->collect_right_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/collect_right_001.xpm",  \
	&(player->collect_right_sprite[0].img_width), &(player->collect_right_sprite[0].img_height));
	player->collect_right_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/collect_right_002.xpm",  \
	&(player->collect_right_sprite[1].img_width), &(player->collect_right_sprite[1].img_height));
	player->collect_right_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/collect_right_003.xpm",  \
	&(player->collect_right_sprite[2].img_width), &(player->collect_right_sprite[2].img_height));
}

static void move_right_sprite(t_player *player, void *mlx_ptr)
{
	player->move_right_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/move_right_001.xpm",  \
	&(player->move_right_sprite[0].img_width), &(player->move_right_sprite[0].img_height));
	ft_printf("%p\n", player->idle_right_sprite[0].img);
	player->move_right_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/move_right_002.xpm",  \
	&(player->move_right_sprite[1].img_width), &(player->move_right_sprite[1].img_height));
	player->move_right_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/move_right_003.xpm",  \
	&(player->move_right_sprite[2].img_width), &(player->move_right_sprite[2].img_height));
	player->move_right_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/move_right_004.xpm",  \
	&(player->move_right_sprite[3].img_width), &(player->move_right_sprite[3].img_height));
}

static void	idle_right_sprite(t_player *player, void *mlx_ptr)
{
	player->idle_right_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_000.xpm",  \
	&(player->idle_right_sprite[0].img_width), &(player->idle_right_sprite[0].img_height));
	player->idle_right_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_001.xpm",  \
	&(player->idle_right_sprite[1].img_width), &(player->idle_right_sprite[1].img_height));
	player->idle_right_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_002.xpm",  \
	&(player->idle_right_sprite[2].img_width), &(player->idle_right_sprite[2].img_height));
	player->idle_right_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_003.xpm",  \
	&(player->idle_right_sprite[3].img_width), &(player->idle_right_sprite[3].img_height));
	player->idle_right_sprite[4].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_004.xpm",  \
	&(player->idle_right_sprite[4].img_width), &(player->idle_right_sprite[4].img_height));
	player->idle_right_sprite[5].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/right/idle_right_005.xpm",  \
	&(player->idle_right_sprite[5].img_width), &(player->idle_right_sprite[5].img_height));
}

void	player_right_sprite_init(t_all *all_data)
{
	idle_right_sprite(&(all_data->player), all_data->mlx_ptr);
	move_right_sprite(&(all_data->player), all_data->mlx_ptr);
	die_right_sprite(&(all_data->player), all_data->mlx_ptr);
	collect_right_sprite(&(all_data->player), all_data->mlx_ptr);
}