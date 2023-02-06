/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:54:56 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/06 16:29:26 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	right_format(char c)
{
	const char	str[] = {"diucspxX%"};
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	flags_check_in(char c)
{
	const char	flags[] = "-+0# ";
	int			i;

	i = 0;
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	type_check_in(const char c)
{
	const char	type[] = "c%spdiuxX";
	int			i;

	i = 0;
	while (type[i])
	{
		if (c == type[i])
			return (type[i]);
		i++;
	}
	return (0);
}

void	*printf_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ucb;

	count = 0;
	ucb = (unsigned char *)b;
	while (count < len)
	{
		*ucb = (unsigned char)c;
		count++;
		ucb++;
	}
	return (b);
}
