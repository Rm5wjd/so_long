/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:14 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 16:40:11 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	collectible_sprite(t_all *all_data)
{
	all_data->collectible[0].img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/collectible/ball000.xpm", \
	&(all_data->collectible[0].img_width), \
	&(all_data->collectible[0].img_height));
	all_data->collectible[1].img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/collectible/ball001.xpm", \
	&(all_data->collectible[1].img_width), \
	&(all_data->collectible[1].img_height));
	all_data->collectible[2].img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/collectible/ball002.xpm", \
	&(all_data->collectible[2].img_width), \
	&(all_data->collectible[2].img_height));
	all_data->collectible[3].img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/collectible/ball003.xpm", \
	&(all_data->collectible[3].img_width), \
	&(all_data->collectible[3].img_height));
}

static void	tileset_init(t_all *all_data)
{
	all_data->wall.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/metal_wall.xpm", \
	&(all_data->wall.img_width), &(all_data->wall.img_height));
	all_data->plane.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/Metal_Floor.xpm", \
	&(all_data->plane.img_width), &(all_data->plane.img_height));
	all_data->exit.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/exit.xpm", \
	&(all_data->exit.img_width), &(all_data->exit.img_height));
	collectible_sprite(all_data);
}

void	data_init(t_all	*all_data, int map_width, int map_height)
{
	all_data->mlx_ptr = mlx_init();
	all_data->win_ptr = mlx_new_window(all_data->mlx_ptr, map_width \
	* TILE_BIT, map_height * TILE_BIT, "junglee");
	all_data->map_width = map_width;
	all_data->map_height = map_height;
	all_data->player.state = IDEL;
	all_data->player.look_direction = RIGHT;
	tileset_init(all_data);
	player_left_sprite_init(all_data);
	player_right_sprite_init(all_data);
	enemy_left_sprite_init(all_data);
	enemy_right_sprite_init(all_data);
	all_data->enemy.pos.x = 4 * TILE_BIT;
	all_data->enemy.pos.y = 4 * TILE_BIT;
}
