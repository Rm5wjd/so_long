/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:47:12 by junglee           #+#    #+#             */
/*   Updated: 2022/11/15 14:00:59 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*mapistr;

	i = 0;
	len = ft_strlen(s);
	mapistr = (char *)malloc(sizeof(char) * (len + 1));
	if (mapistr == 0)
		return (0);
	while (s[i])
	{
		mapistr[i] = f(i, s[i]);
		i++;
	}
	mapistr[i] = '\0';
	return (mapistr);
}
