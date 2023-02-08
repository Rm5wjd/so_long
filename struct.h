# ifndef __STRUCT_H__
# define __STRUCT_H__

typedef struct s_data t_data;

#define MAP_WIDTH 10
#define MAP_HEIGHT 8
#define VELOCITY 5

enum keycode {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	SHIFT = 57,
	SPACEBAR = 49
};

enum state {
	IDEL,
	MOVE,
	DIE
};

enum direction {
	LEFT,
	RIGHT
};

typedef	struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_node
{
	t_pos	pos;
	struct	s_node	*next;
}				t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
	int		count;
}				t_queue;


typedef struct	s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct	s_player
{
	t_image	idle_left_sprite[6];
	t_image	move_left_sprite[4];
	t_image	die_left_sprite[4];
	t_image	idle_right_sprite[6];
	t_image	move_right_sprite[4];
	t_image	die_right_sprite[4];
	t_pos	pos;
	int		state;
	int		look_direction;
	int		w_flag;
	int		a_flag;
	int		s_flag;
	int		d_flag;
}				t_player;

typedef struct	s_data
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
	int			collectible_cnt;
	int			exit_cnt;
	int			startpos_cnt;
	t_player	player;
}				t_all;

# endif
