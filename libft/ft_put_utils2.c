/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:29:52 by sindong-yeo       #+#    #+#             */
/*   Updated: 2022/12/07 15:34:54 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *value, int value_len)
{
	int	i;

	i = 0;
	while (i < value_len)
	{
		if (write(1, &(value[i]), 1) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	put_memory(void *ptr, int len)
{
	unsigned long long	val;
	char				*address;
	int					i;

	i = 0;
	val = (unsigned long long)ptr;
	address = (char *)malloc(sizeof(char) * (len + 1));
	if (address == 0)
		return (-1);
	while (i < len)
	{
		address[i] = "0123456789abcdef"[val % 16];
		val /= 16;
		i++;
	}
	address[i] = 0;
	while (--len >= 0)
	{
		if (write(1, address + len, 1) == -1)
			return (-1);
	}
	free(address);
	address = 0;
	return (1);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	get_number_len(unsigned long value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		len++;
	}
	return (len);
}
