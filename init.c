#include "main.h"

void	data_init(t_all	*all_data)
{
	all_data->mlx_ptr = mlx_init();
	all_data->win_ptr = mlx_new_window(all_data->mlx_ptr, 576, 384, "Hello world!");
}