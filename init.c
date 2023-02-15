/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:14 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 21:10:53 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	tileset_init(t_all *all_data)
{
	all_data->wall.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/Brick_Wall.xpm", \
	&(all_data->wall.img_width), &(all_data->wall.img_height));
	all_data->plane.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/Metal_Floor.xpm", \
	&(all_data->plane.img_width), &(all_data->plane.img_height));
	all_data->exit.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/exit.xpm", \
	&(all_data->exit.img_width), &(all_data->exit.img_height));
	all_data->collectible.img = mlx_xpm_file_to_image(all_data->mlx_ptr, \
	"./Sprites/tileset/coin.xpm", \
	&(all_data->collectible.img_width), &(all_data->collectible.img_height));
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
}
