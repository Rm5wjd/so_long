/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boxing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:34:40 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/02 16:48:40 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	boxing_d_i_u_data(va_list *ap, t_contents *contents, t_box *box);
static void	boxing_s_data(va_list *ap, t_contents *contents, t_box *box);
static void	boxing_c_percent_data(va_list *ap, t_contents *contents, \
t_box *box);
static void	boxing_else_data(va_list *ap, t_contents *contents, t_box *box);

void	ft_boxing(t_contents *contents, t_box *box, va_list *ap)
{
	int	content_len;

	content_len = 0;
	printf_memset(box, 0, sizeof(t_box));
	if (contents->type == 'd' || contents->type == 'i' || contents->type == 'u')
		boxing_d_i_u_data(ap, contents, box);
	else if (contents->type == 's')
		boxing_s_data(ap, contents, box);
	else if (contents->type == 'c' || contents->type == '%')
		boxing_c_percent_data(ap, contents, box);
	else
		boxing_else_data(ap, contents, box);
	content_len = box->sign + ft_max(box->zero, 0) + box->prefix + \
	box->value_len;
	if (contents->flags.op_minus)
		box->right_margin = ft_max((contents->width - content_len), 0);
	else if (contents->flags.op_minus == 0)
		box->left_margin = ft_max((contents->width - content_len), 0);
}

static void	boxing_d_i_u_data(va_list *ap, t_contents *contents, t_box *box)
{
	box->value = (long long)va_arg(*ap, int);
	check_sign(contents, box);
	if (box->value == 0 \
	&& (contents->precision == NON_PRECISION \
	|| contents->precision == ZERO_PRECISION))
			box->value_len = 0;
	else
		box->value_len = get_number_len((unsigned int)box->value, 10);
	ft_strlcpy(box->base, "0123456789", 11);
	box->base_len = 10;
	if (contents->precision != DEFAULT)
		box->zero = contents->precision - box->value_len;
	else if (contents->precision == DEFAULT && contents->flags.op_zero)
		box->zero = contents->width - box->value_len - box->sign;
}

static void	boxing_s_data(va_list *ap, t_contents *contents, t_box *box)
{
	box->value = (long long)va_arg(*ap, char *);
	if (box->value == 0)
		box->value_len = 6;
	else
		box->value_len = ft_strlen((const char *)box->value);
	if (contents->precision == NON_PRECISION \
	|| contents->precision == ZERO_PRECISION)
		box->value_len = 0;
	else if (contents->precision != DEFAULT)
	{
		if (contents->precision < box->value_len)
			box->value_len = contents->precision;
	}
}

static void	boxing_c_percent_data(va_list *ap, t_contents *contents, t_box *box)
{
	if (contents->type == 'c')
		box->value = (long long)va_arg(*ap, int);
	else
		box->value = '%';
	box->value_len = 1;
	if (contents->flags.op_zero)
		box->zero = contents->width - box->value_len;
}

static void	boxing_else_data(va_list *ap, t_contents *contents, t_box *box)
{
	if (contents->type == 'p')
		box->value = (long long)va_arg(*ap, void *);
	else
		box->value = (unsigned int)va_arg(*ap, unsigned int);
	if (contents->type == 'p' || (contents->flags.op_hash && box->value != 0))
		box->prefix = 2;
	if (contents->type == 'p')
		box->value_len = get_u_len((unsigned long long)((void *)box->value));
	else if ((contents->precision == NON_PRECISION \
	|| contents->precision == ZERO_PRECISION) \
	&& box->value == 0)
		box->value_len = 0;
	else
		box->value_len = get_number_len((unsigned int)(box->value), 16);
	if (contents->type == 'X')
		ft_strlcpy(box->base, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(box->base, "0123456789abcdef", 17);
	box->base_len = 16;
	if (contents->precision != DEFAULT)
		box->zero = contents->precision - box->value_len;
	else if (contents->precision == DEFAULT && contents->flags.op_zero)
		box->zero = contents->width - box->value_len - box->sign - box->prefix;
}
