/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:59:05 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/02 15:39:09 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_s_type(t_box *box, long long *len)
{
	if (box->value == 0)
	{
		if (put_str("(null)", box->value_len) < 0)
			return (-1);
	}
	else
	{
		if (put_str((char *)(box->value), box->value_len) < 0)
			return (-1);
	}
	(*len) += box->value_len;
	return (0);
}

static int	print_else_type(t_contents *contents, t_box *box, long long *len)
{
	if (contents->type == 'p')
	{
		if (put_memory((void *)box->value, box->value_len) < 0)
			return (-1);
	}
	else
	{
		if (box->value == 0 \
		&& (contents->precision == NON_PRECISION || contents->precision == 0))
			;
		else
			if (ft_putnbr_base(box->value, box->base) < 0)
				return (-1);
	}
	(*len) += box->value_len;
	return (0);
}

static int	put_type(t_contents *contents, t_box *box, long long *len)
{
	if (contents->type == 'c' || contents->type == '%')
	{
		if (write(1, &(box->value), 1) < 0)
			return (-1);
		(*len)++;
	}
	else if (contents->type == 's')
	{
		if (print_s_type(box, len) < 0)
			return (-1);
	}
	else
	{
		if (print_else_type(contents, box, len) < 0)
			return (-1);
	}
	return (0);
}

int	put_all(t_contents *contents, t_box *box, long long *len)
{
	if (print_left_margin(box, len) < 0)
		return (-1);
	if (print_sign(box, len) < 0)
		return (-1);
	if (print_prefix(contents, box, len) < 0)
		return (-1);
	if (print_zero(box, len) < 0)
		return (-1);
	if (put_type(contents, box, len) < 0)
		return (-1);
	if (print_right_margin(box, len) < 0)
		return (-1);
	return (0);
}
