/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:00:42 by dongyshi          #+#    #+#             */
/*   Updated: 2022/12/07 15:33:01 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	putnbr_base(unsigned int nb, char *base)
{
	long long	ll_nb;
	int			c;
	int			base_len;

	base_len = ft_str_len(base);
	if (nb == 0)
	{
		return (0);
	}
	if (nb < 0)
	{
		ll_nb = (long long)nb;
		ll_nb *= -1;
	}
	else
	{
		ll_nb = (long long)nb;
	}
	if (putnbr_base(ll_nb / base_len, base) < 0)
		return (-1);
	c = ll_nb % base_len;
	if (write(1, &base[c], 1) < 0)
		return (-1);
	return (0);
}

static void	array_init(int *ascii)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		ascii[i] = 0;
		i++;
	}
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int	len;
	int	i;
	int	ascii[127];

	len = 0;
	i = 0;
	array_init(ascii);
	while (base[i])
	{
		len++;
		i++;
	}
	if (nb == 0)
	{
		if (write(1, &base[0], 1) < 0)
			return (-1);
		return (0);
	}
	if (putnbr_base(nb, base) < 0)
		return (-1);
	return (0);
}
