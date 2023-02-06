/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:20:43 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:26:25 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*alptr;

	alptr = (unsigned char *)malloc(size * count);
	if (alptr == 0)
		return (0);
	ft_bzero(alptr, size * count);
	return (alptr);
}
