/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:10 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:29:40 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_nbr(long long n, int fd)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n == 0)
		return ;
	ft_write_nbr(n / 10, fd);
	c = 48 + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;

	lln = (long long)n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_write_nbr(lln, fd);
}
