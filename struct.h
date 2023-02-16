/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:43:07 by junglee           #+#    #+#             */
/*   Updated: 2023/02/16 16:17:23 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data	t_data;

# define TILE_BIT 64
# define VELOCITY 2
# define PLAYER_WIDTH 27
# define PLAYER_HEIGHT 36
# define ENEMY_WIDTH 33
# define ENEMY_HEIGHT 57

enum	e_keycode {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	SHIFT = 57,
	SPACEBAR = 49
};

enum	e_state {
	IDEL,
	MOVE,
	COLLECT,
	DIE
};

enum	e_direction {
	LEFT,
	RIGHT
};

enum	e_map_object {
	WALL,
	COLLECTIBLE,
	ENEMY,
	EXIT,
	EMPTY
};

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_node
{
	t_pos			pos;
	struct s_node	*next;
}				t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
	int		count;
}				t_queue;

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_rect
{
	t_pos	left_top;
	t_pos	left_bot;
	t_pos	right_top;
	t_pos	right_bot;
}				t_rect;

typedef struct s_box_collider
{
	int	left;
	int	right;
	int	top;
	int	bot;
}				t_box_collider;

typedef struct s_player
{
	t_image	idle_left_sprite[6];
	t_image	move_left_sprite[4];
	t_image	die_left_sprite[4];
	t_image	collect_left_sprite[3];
	t_image	idle_right_sprite[6];
	t_image	move_right_sprite[4];
	t_image	die_right_sprite[4];
	t_image	collect_right_sprite[3];
	t_pos	pos;
	t_rect	rect;
	int		state;
	int		look_direction;
	int		w_flag;
	int		a_flag;
	int		s_flag;
	int		d_flag;
}				t_player;

typedef struct s_enemy
{
	t_image	move_left_sprite[4];
	t_image	move_right_sprite[4];
	t_pos	pos;
	t_rect	rect;
	int		state;
	int		look_direction;
}				t_enemy;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			**found;
	int			map_width;
	int			map_height;
	int			walk_cnt;
	int			collectible_cnt;
	int			exit_cnt;
	int			startpos_cnt;
	t_player	player;
	t_enemy		enemy;
	t_image		wall;
	t_image		plane;
	t_image		collectible[4];
	t_image		exit;
}				t_all;

#	endif
