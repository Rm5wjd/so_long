#include "mlx.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "struct.h"

//color.c
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int create_trgb(int t, int r, int g, int b);

//key_event
int	key_down(int keycode, void *param);

// init
void	data_init(t_all	*all_data);

// map_pharsing
void	map_pharsing(t_all *all, char **argv);
void	print_map(t_all *all);

// map_valid_check
int	map_valid_check(t_all *all);

// queue
void init_queue(t_queue *queue);
int is_empty(t_queue *queue);
void enqueue(t_queue *queue, int x, int y);
t_pos dequeue(t_queue *queue);

// bfs
int	bfs(t_all *all);