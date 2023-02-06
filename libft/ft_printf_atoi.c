/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:27:09 by junglee           #+#    #+#             */
/*   Updated: 2023/02/06 15:13:53 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_res(const char **str, long long res, int sign)
{
	while (ft_isdigit(**str))
	{
		if (res > 922337203685477580)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		else if (res == 922337203685477580 && **str >= '7' && sign == 1)
			return (-1);
		else if (res == 922337203685477580 && **str > '7' && sign == -1)
			return (0);
		res = (res * 10) + (**str - '0');
			(*str)++;
	}
	res *= sign;
	return (res);
}

int	printf_atoi(const char **str)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	return ((int)get_res(str, res, sign));
}
