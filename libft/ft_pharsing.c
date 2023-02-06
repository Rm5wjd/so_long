/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:43:53 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/06 15:14:53 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(const char **format, t_contents *contents)
{
	while (flags_check_in((**format)))
	{
		if (**format == '-' && contents->flags.op_minus == 0)
			contents->flags.op_minus = 1;
		else if (**format == '+' && contents->flags.op_plus == 0)
			contents->flags.op_plus = 1;
		else if (**format == ' ' && contents->flags.op_space == 0)
			contents->flags.op_space = 1;
		else if (**format == '0' && contents->flags.op_zero == 0)
			contents->flags.op_zero = 1;
		else if (**format == '#' && contents->flags.op_hash == 0)
			contents->flags.op_hash = 1;
		(*format)++;
	}
	if (contents->flags.op_space && contents->flags.op_plus)
		contents->flags.op_space = 0;
	if (contents->flags.op_zero && contents->flags.op_minus)
		contents->flags.op_zero = 0;
}

static int	check_width(const char **format, va_list *ap, t_contents *contents)
{
	int	asterisk;

	asterisk = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*' && asterisk == 0)
		{
			contents->width = va_arg(*ap, int);
			asterisk = 1;
			(*format)++;
		}
		else if ((**format == '*' && asterisk == 1) \
		|| (asterisk == 1 && ft_isdigit(**format)))
			return (-1);
		else
			contents->width = printf_atoi(format);
	}
	return (1);
}

static int	check_precision(const char **format, t_contents *contents, \
va_list *ap)
{
	int	asterisk;

	asterisk = 0;
	if (**format == '.')
	{
		contents->precision = NON_PRECISION;
		(*format)++;
		while (ft_isdigit(**format) || (**format) == '*')
		{
			if (**format == '*' && asterisk == 0)
			{
				contents->precision = va_arg(*ap, int);
				asterisk = 1;
				(*format)++;
			}
			else if ((**format == '*' && asterisk == 1) \
			|| (ft_isdigit(**format) && asterisk == 1))
				return (-1);
			else
				contents->precision = printf_atoi(format);
			if (contents->precision < 0)
				return (-1);
		}
	}
	return (1);
}

static int	check_type(const char **format, t_contents *contents)
{
	if (right_format(**format))
		contents->type = **format;
	else
		return (-1);
	return (1);
}

int	ft_pharsing(const char **format, va_list *ap, t_contents *contents)
{
	check_flags(format, contents);
	if ((check_width(format, ap, contents) == -1) \
	|| (check_precision(format, contents, ap) == -1) \
	|| (check_type(format, contents) == -1))
		return (-1);
	return (1);
}
