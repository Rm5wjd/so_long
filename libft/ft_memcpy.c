/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:53:59 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:28:41 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;
	size_t			size;

	if (dst == 0 && src == 0)
		return (0);
	size = 0;
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	while (size < n)
	{
		*ucdst = *ucsrc;
		ucdst++;
		ucsrc++;
		size++;
	}
	return (dst);
}
