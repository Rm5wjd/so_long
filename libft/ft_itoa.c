/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:17:25 by junglee           #+#    #+#             */
/*   Updated: 2022/11/17 16:37:12 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_len(long long n, int *len)
{
	if (n < 0)
	{
		n *= -1;
		(*len)++;
	}
	if (n == 0)
		return ;
	ft_set_len(n / 10, len);
	(*len)++;
}

static void	ft_fill_str(long long n, char *str, int *index)
{
	if (n < 0)
	{
		str[*index] = '-';
		(*index)++;
		n *= -1;
	}
	if (n == 0)
		return ;
	ft_fill_str(n / 10, str, index);
	str[*index] = 48 + (n % 10);
	(*index)++;
}

char	*ft_itoa(int n)
{
	int			len;
	int			index;
	long long	lln;
	char		*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (0);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	lln = (long long)n;
	len = 0;
	index = 0;
	ft_set_len(lln, &len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ft_fill_str(lln, str, &index);
	str[index] = '\0';
	return (str);
}
