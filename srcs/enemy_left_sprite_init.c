/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_left_sprite_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:05:33 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 15:09:52 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	left_run_sprite_init(t_enemy *enemy, void *mlx_ptr)
{
	enemy->move_left_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/left/run_left_000.xpm", \
	&(enemy->move_left_sprite[0].img_width), \
	&(enemy->move_left_sprite[0].img_height));
	enemy->move_left_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/left/run_left_001.xpm", \
	&(enemy->move_left_sprite[1].img_width), \
	&(enemy->move_left_sprite[1].img_height));
	enemy->move_left_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/left/run_left_002.xpm", \
	&(enemy->move_left_sprite[2].img_width), \
	&(enemy->move_left_sprite[2].img_height));
	enemy->move_left_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/left/run_left_003.xpm", \
	&(enemy->move_left_sprite[3].img_width), \
	&(enemy->move_left_sprite[3].img_height));
}

void	enemy_left_sprite_init(t_all *all)
{
	left_run_sprite_init(&all->enemy, all->mlx_ptr);
}
