/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:55:47 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 14:57:19 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	continue_case_check(int next_x, int next_y, int *i, t_all *all)
{
	if (next_x < 0 || next_x >= all->map_width || \
		next_y < 0 || next_y >= all->map_height)
	{
		(*i)++;
		return (1);
	}
	else if (all->map[next_y][next_x] == '1' || all->found[next_y][next_x] == 1)
	{
		(*i)++;
		return (1);
	}
	else if (all->map[next_y][next_x] == 'E')
	{
		(*i)++;
		all->exit_cnt--;
		return (1);
	}
	return (0);
}
