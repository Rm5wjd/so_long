/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:21:18 by junglee           #+#    #+#             */
/*   Updated: 2022/11/17 17:55:26 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_start_idx_set(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_check_set(set, s1[i]))
			return (i);
		i++;
	}
	return (0);
}

static int	ft_last_idx_set(char const *s1, char const *set)
{
	int		i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = s1_len - 1;
	while (i >= 0)
	{
		if (!ft_check_set(set, s1[i]))
			return (i);
		i--;
	}
	return (0);
}

static	int	ft_zero_alloc(char **str, int start_idx, int last_idx)
{
	if (start_idx == 0 && last_idx == 0)
	{
		*str = (char *)malloc(1);
		if (!(*str))
			return (0);
		return (1);
	}
	else
	{
		*str = (char *)malloc(sizeof(char) * (last_idx - start_idx + 2));
		if (!(*str))
			return (0);
		return (1);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start_idx;
	int		last_idx;
	char	*str;

	i = 0;
	start_idx = ft_start_idx_set(s1, set);
	last_idx = ft_last_idx_set(s1, set);
	if (!ft_zero_alloc(&str, start_idx, last_idx))
		return (0);
	while (start_idx <= last_idx && !(start_idx == 0 && last_idx == 0))
	{
		str[i] = s1[start_idx];
		i++;
		start_idx++;
	}
	str[i] = '\0';
	return (str);
}
