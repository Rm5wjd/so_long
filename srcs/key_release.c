/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:19 by junglee           #+#    #+#             */
/*   Updated: 2023/02/17 19:49:45 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	key_up(int keycode, t_all *all)
{
	mlx_string_put(all->mlx_ptr, all->win_ptr, 200, 40, \
		create_trgb(0, 255, 50, 40), "key_release");
	if (keycode == W)
		all->player.w_flag = 0;
	else if (keycode == A)
		all->player.a_flag = 0;
	else if (keycode == S)
		all->player.s_flag = 0;
	else if (keycode == D)
		all->player.d_flag = 0;
	return (keycode);
}
