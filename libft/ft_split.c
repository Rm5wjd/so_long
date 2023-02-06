/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:51:17 by junglee           #+#    #+#             */
/*   Updated: 2022/11/17 18:08:39 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_malloc(char const *s, char c, char **split_str)
{
	int	i;
	int	j;
	int	word_size;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_size = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && !(s[i] == c))
		{
			while (s[i] && !(s[i] == c))
			{
				word_size++;
				i++;
			}
			split_str[j] = (char *)malloc(sizeof(char) * (word_size + 1));
			if (!split_str[j])
				return (0);
			j++;
		}
	}
	return (1);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && !(s[i] == c))
		{
			count++;
			while (s[i] && !(s[i] == c))
				i++;
		}
	}
	return (count);
}

static void	ft_word_split(char const *s, char c, char **split_str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && !(s[i] == c))
		{
			k = 0;
			while (s[i] && !(s[i] == c))
			{
				split_str[j][k] = s[i];
				k++;
				i++;
			}
			split_str[j][k] = '\0';
			j++;
		}
	}
}

static void	free_split_str(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	int		word_count;

	word_count = ft_word_count(s, c);
	split_str = (char **)ft_calloc(sizeof(char *), (word_count + 1));
	if (!split_str)
		return (0);
	if (!ft_word_malloc(s, c, split_str))
	{
		free_split_str(split_str);
		return (0);
	}
	ft_word_split(s, c, split_str);
	return (split_str);
}
