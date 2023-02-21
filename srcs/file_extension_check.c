/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:40:17 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 19:05:52 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	sl_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == 0)
		return (0);
	else
		return (1);
}

static int	ft_last_idx_set(char const *s1, char c)
{
	int		i;
	size_t	s1_len;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	i = s1_len - 1;
	while (i >= 0)
	{
		if (s1[i] == c)
			return (i);
		i--;
	}
	return (0);
}

int	file_extension_check(char **argv)
{
	int	dot_idx;

	dot_idx = ft_last_idx_set(argv[1], '.');
	if (sl_strncmp((argv[1] + dot_idx), ".ber", 4) != 0)
		return (1);
	else
		return (0);
}
