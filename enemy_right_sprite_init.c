/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_right_sprite_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:10:14 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 15:10:40 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	right_run_sprite_init(t_enemy *enemy, void *mlx_ptr)
{
	enemy->move_right_sprite[0].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/right/run_right_000.xpm", \
	&(enemy->move_right_sprite[0].img_width), \
	&(enemy->move_right_sprite[0].img_height));
	enemy->move_right_sprite[1].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/right/run_right_001.xpm", \
	&(enemy->move_right_sprite[1].img_width), \
	&(enemy->move_right_sprite[1].img_height));
	enemy->move_right_sprite[2].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/right/run_right_002.xpm", \
	&(enemy->move_right_sprite[2].img_width), \
	&(enemy->move_right_sprite[2].img_height));
	enemy->move_right_sprite[3].img = mlx_xpm_file_to_image(mlx_ptr, \
	"./Sprites/enemy/right/run_right_003.xpm", \
	&(enemy->move_right_sprite[3].img_width), \
	&(enemy->move_right_sprite[3].img_height));
}

void	enemy_right_sprite_init(t_all *all)
{
	right_run_sprite_init(&all->enemy, all->mlx_ptr);
}
