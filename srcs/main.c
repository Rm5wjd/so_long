/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:24 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 19:38:42 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	func(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		exit_error();
	if (file_extension_check(argv))
		exit_error();
	ft_bzero(&all, sizeof(t_all));
	if (map_parsing(&all, argv))
		exit_error();
	if (screen_size_check(&all))
		exit_error();
	data_init(&all, all.map_width, all.map_height);
	print_map(&all);
	if (map_valid_check(&all))
		exit_error();
	enemy_spawn(&all);
	mlx_hook(all.win_ptr, 2, 0, key_down, &all);
	mlx_hook(all.win_ptr, 3, 0, key_up, &all);
	mlx_hook(all.win_ptr, 17, 0, redcross_close, &all);
	mlx_loop_hook(all.mlx_ptr, render_all, &all);
	mlx_loop(all.mlx_ptr);
}
