/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:03:00 by junglee           #+#    #+#             */
/*   Updated: 2022/11/17 18:15:40 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_alloc(char **substr, unsigned int start, size_t len, size_t slen)
{
	if (start >= slen)
	{
		*substr = (char *)malloc(1);
		if (!(*substr))
			return (0);
		return (2);
	}
	if (start + len > slen)
		len = slen - start;
	*substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(*substr))
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (!ft_alloc(&substr, start, len, slen))
		return (0);
	i = 0;
	while (i < len && start < slen)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
