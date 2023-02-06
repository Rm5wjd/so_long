/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:28 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:29:07 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	if (dst == 0 && src == 0)
		return (0);
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
	{
		ucdst += len - 1;
		ucsrc += len - 1;
		while (len > 0)
		{
			*ucdst = *ucsrc;
			ucdst--;
			ucsrc--;
			len--;
		}
		return (dst);
	}
}
