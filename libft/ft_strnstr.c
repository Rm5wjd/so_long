/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:27:01 by junglee           #+#    #+#             */
/*   Updated: 2022/11/16 19:34:17 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_find(const char *haystack, const char *needle
		, size_t find_loc, size_t len)
{
	size_t	j;

	j = 0;
	while (needle[j] && haystack[find_loc] == needle[j] && find_loc < len)
	{
		find_loc++;
		j++;
	}
	if (needle[j] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if ((haystack == 0 || needle == 0) && len == 0)
		return (0);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check_find(haystack, needle, i, len))
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (0);
}
