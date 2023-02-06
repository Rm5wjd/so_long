/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:40:54 by junglee           #+#    #+#             */
/*   Updated: 2023/02/02 16:48:22 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	contents_box_init(t_contents *contents, t_box *box, \
const char **format)
{
	printf_memset(contents, 0, sizeof(t_contents));
	contents->precision = DEFAULT;
	printf_memset(box, 0, sizeof(t_box));
	(*format)++;
}

static int	print_char(const char *format, long long *len)
{
	if (write(1, format, 1) < 0)
		return (-1);
	(*len)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_contents	contents;
	t_box		box;
	long long	len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			contents_box_init(&contents, &box, &format);
			if (ft_pharsing(&format, &ap, &contents) < 0 \
			|| ft_combination(&contents) < 0)
				return (-1);
			ft_boxing(&contents, &box, &ap);
			if (put_all(&contents, &box, &len) < 0)
				return (-1);
		}
		else
			if (print_char(format, &len) < 0)
				return (-1);
		format++;
	}
	return (len);
}
