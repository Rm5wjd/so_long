/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:46:52 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:29:21 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
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
