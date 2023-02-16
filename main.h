/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:27 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 17:04:44 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "struct.h"

//color.c
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		create_trgb(int t, int r, int g, int b);

//key_event
int		key_down(int keycode, void *param);
int		mouse_down(int button, int x, int y, void *param);
int		redcross_close(void *param);
void	key_input(t_all *all);
// key_up
int		key_up(int keycode, t_all *all);

// init
void	data_init(t_all	*all_data, int map_width, int map_height);

// sprite init
void	player_left_sprite_init(t_all *all_data);
void	player_right_sprite_init(t_all *all_data);
void	enemy_left_sprite_init(t_all *all);
void	enemy_right_sprite_init(t_all *all);

// *** render ***
int		render_all(t_all *all);

// map_pharsing
int		map_pharsing(t_all *all, char **argv);
void	print_map(t_all *all);

// map_valid_check
int		map_valid_check(t_all *all);

// queue
void	init_queue(t_queue *queue);
int		is_empty(t_queue *queue);
void	enqueue(t_queue *queue, int x, int y);
t_pos	dequeue(t_queue *queue);

// bfs
int		bfs(t_all *all);

// so_long_utils
void	map_zero(t_all *all);
void	map_free(t_all *all);
void	found_zero(int **all, int width, int height);

// ****collision****
void	box_collider_update(t_all *all);
int		collision_detect(t_all *all);

void	enemy_box_collider_update(t_all *all);
int		enemy_player_collision(t_all *all);
int		enemy_object_collision(t_all *all);

// tiling
void	tiling(t_all *all);

// wasd_flag_pos_set
void	wasd_pos_set(t_all *all);

#	endif