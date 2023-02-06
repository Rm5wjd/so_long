/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:36:45 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:28:14 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*reptr;
	unsigned char	*ucs;
	size_t			i;

	reptr = 0;
	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ucs == (unsigned char)c)
		{
			reptr = (void *)ucs;
			return (reptr);
		}
		ucs++;
		i++;
	}
	return (reptr);
}
