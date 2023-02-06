/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:24:37 by sindong-yeo       #+#    #+#             */
/*   Updated: 2022/12/07 15:26:02 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	size;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize - 1)
		size = srclen;
	else
		size = dstsize - 1;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

size_t	get_u_len(unsigned long long n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

void	check_sign(t_contents *contents, t_box *box)
{
	if (contents->flags.op_space && box->value >= 0)
	{
		box->sign_value = ' ';
		box->sign = 1;
	}
	if (contents->flags.op_plus && box->value >= 0)
	{
		box->sign_value = '+';
		box->sign = 1;
	}
	if (contents->type != 'u' && (int)box->value < 0)
	{
		box->sign_value = '-';
		box->sign = 1;
		box->value *= -1;
	}	
}
