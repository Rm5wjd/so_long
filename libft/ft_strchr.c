/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:44:41 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:30:41 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*det;
	int		i;

	det = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			det = (char *)(s + i);
			return (det);
		}
		i++;
	}
	if (s[i] == (char)c)
		det = (char *)(s + i);
	return (det);
}
