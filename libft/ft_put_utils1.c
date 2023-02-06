/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:33:31 by sindong-yeo       #+#    #+#             */
/*   Updated: 2022/12/07 15:33:50 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_left_margin(t_box *box, long long *len)
{
	int	i;

	i = 0;
	while (i++ < box->left_margin)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_sign(t_box *box, long long *len)
{
	if (box->sign == 1)
	{
		if (write(1, &(box->sign_value), 1) < 0)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_prefix(t_contents *contents, t_box *box, long long *len)
{
	if (box->prefix == 2)
	{
		if (contents->type == 'X' && box->value != 0)
		{
			if (write(1, "0X", 2) < 0)
				return (-1);
			(*len) += 2;
		}
		else if (contents->type == 'p' \
		|| ((contents->type == 'x') && box->value != 0))
		{
			if (write(1, "0x", 2) < 0)
				return (-1);
			(*len) += 2;
		}
	}
	return (0);
}

int	print_zero(t_box *box, long long *len)
{
	int	i;

	i = 0;
	while (i++ < box->zero)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_right_margin(t_box *box, long long *len)
{
	int	i;

	i = 0;
	while (i++ < box->right_margin)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		(*len)++;
	}
	return (0);
}
