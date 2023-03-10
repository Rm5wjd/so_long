/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_sprite_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:22 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 21:14:28 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	die_left_sprite(t_player *player, void *mlx_ptr)
{
	player->die_left_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/hurt_left_001.xpm", \
	&(player->die_left_sprite[0].img_width), \
	&(player->die_left_sprite[0].img_height));
	\
	player->die_left_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/hurt_left_002.xpm", \
	&(player->die_left_sprite[1].img_width), \
	&(player->die_left_sprite[1].img_height));
	\
	player->die_left_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/hurt_left_003.xpm", \
	&(player->die_left_sprite[2].img_width), \
	&(player->die_left_sprite[2].img_height));
	\
	player->die_left_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/hurt_left_004.xpm", \
	&(player->die_left_sprite[3].img_width), \
	&(player->die_left_sprite[3].img_height));
}

static void	collect_left_sprtie(t_player *player, void *mlx_ptr)
{
	player->collect_left_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/collect_left_001.xpm", \
	&(player->collect_left_sprite[0].img_width), \
	&(player->collect_left_sprite[0].img_height));
	\
	player->collect_left_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/collect_left_002.xpm", \
	&(player->collect_left_sprite[1].img_width), \
	&(player->collect_left_sprite[1].img_height));
	\
	player->collect_left_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/collect_left_003.xpm", \
	&(player->collect_left_sprite[2].img_width), \
	&(player->collect_left_sprite[2].img_height));
}

static void	move_left_sprite(t_player *player, void *mlx_ptr)
{
	player->move_left_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/move_left_001.xpm", \
	&(player->move_left_sprite[0].img_width), \
	&(player->move_left_sprite[0].img_height));
	\
	player->move_left_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/move_left_002.xpm", \
	&(player->move_left_sprite[1].img_width), \
	&(player->move_left_sprite[1].img_height));
	\
	player->move_left_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/move_left_003.xpm", \
	&(player->move_left_sprite[2].img_width), \
	&(player->move_left_sprite[2].img_height));
	\
	player->move_left_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/move_left_004.xpm", \
	&(player->move_left_sprite[3].img_width), \
	&(player->move_left_sprite[3].img_height));
}

static void	idle_left_sprite(t_player *player, void *mlx_ptr)
{
	player->idle_left_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_000.xpm", \
	&(player->idle_left_sprite[0].img_width), \
	&(player->idle_left_sprite[0].img_height));
	player->idle_left_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_001.xpm", \
	&(player->idle_left_sprite[1].img_width), \
	&(player->idle_left_sprite[1].img_height));
	player->idle_left_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_002.xpm", \
	&(player->idle_left_sprite[2].img_width), \
	&(player->idle_left_sprite[2].img_height));
	player->idle_left_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_003.xpm", \
	&(player->idle_left_sprite[3].img_width), \
	&(player->idle_left_sprite[3].img_height));
	player->idle_left_sprite[4].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_004.xpm", \
	&(player->idle_left_sprite[4].img_width), \
	&(player->idle_left_sprite[4].img_height));
	player->idle_left_sprite[5].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/player/left/idle_left_005.xpm", \
	&(player->idle_left_sprite[5].img_width), \
	&(player->idle_left_sprite[5].img_height));
}

void	player_left_sprite_init(t_all *all_data)
{
	idle_left_sprite(&all_data->player, all_data->mlx_ptr);
	move_left_sprite(&all_data->player, all_data->mlx_ptr);
	die_left_sprite(&all_data->player, all_data->mlx_ptr);
	collect_left_sprtie(&all_data->player, all_data->mlx_ptr);
}
