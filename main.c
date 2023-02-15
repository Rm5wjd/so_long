/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:24 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 21:28:54 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (map_pharsing(&all, argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	data_init(&all, all.map_width, all.map_height);
	print_map(&all);
	if (map_valid_check(&all))
	{
		ft_printf("Error\n");
		exit(1);
	}
	mlx_hook(all.win_ptr, 2, 0, key_down, &all);
	mlx_hook(all.win_ptr, 3, 0, key_up, &all);
	mlx_hook(all.win_ptr, 17, 0, redcross_close, &all);
	mlx_loop_hook(all.mlx_ptr, render_all, &all);
	mlx_loop(all.mlx_ptr);
}
