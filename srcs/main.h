/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:27 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 19:29:48 by junglee          ###   ########.fr       */
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

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
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

// file_extension_check
int		file_extension_check(char **argv);

// map_pharsing
int		map_parsing(t_all *all, char **argv);
void	print_map(t_all *all);

// enemy_spawn
void	enemy_spawn(t_all *all_data);

// map_valid_check
int		map_valid_check(t_all *all);
int		screen_size_check(t_all *all);

// queue
void	init_queue(t_queue *queue);
int		is_empty(t_queue *queue);
void	enqueue(t_queue *queue, int x, int y);
t_pos	dequeue(t_queue *queue);
void	free_queue(t_queue *queue);

// bfs
int		bfs(t_all *all);
//bfs_utils.c
int		continue_case_check(int next_x, int next_y, int *i, t_all *all);

// so_long_utils
void	map_zero(t_all *all);
void	map_free(t_all *all);
void	found_zero(int **all, int width, int height);
void	enemy_collision_check(t_all *all, t_pos prev);
void	exit_error(void);
// so_long_utils2
void	render_move(t_all *all, t_player player, int move_frame);
void	render_idle(t_all *all, t_player player, int idle_frame);
void	render_move_enemy(t_all *all, t_enemy enemy, int move_frame);
int		haveone_final_check(t_all *all);
// so_long_utils3
int		vertex_y_from_to(t_all *all, t_pos from, t_pos to);
int		vertex_x_from_to(t_all *all, t_pos from, t_pos to);
void	exit_so_long(t_all *all);

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