/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:35 by junglee           #+#    #+#             */
/*   Updated: 2023/02/21 15:35:42 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	line_to_map(char **map, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\n')
	{
		map[i][j] = line[j];
		j++;
	}
}

static int	nl_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && s[len] != '\n')
	{
		len++;
	}
	return (len);
}

static void	read_map(t_all *all, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < all->map_height)
	{
		all->map[i] = get_next_line(fd);
		i++;
	}
}

int	map_parsing(t_all *all, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error();
	line = 0;
	line = get_next_line(fd);
	all->map_width = nl_strlen(line);
	all->map_height = 0;
	while (line != 0)
	{
		if (all->map_width == 0 || nl_strlen(line) != all->map_width)
			return (1);
		all->map_height++;
		free(line);
		line = 0;
		line = get_next_line(fd);
	}
	all->map = (char **)malloc(sizeof(char *) * all->map_height);
	if (!all->map || all->map_width == 0)
		return (1);
	close(fd);
	read_map(all, argv);
	return (0);
}

void	print_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("%d %d\n", all->map_height, all->map_width);
	while (i < all->map_height)
	{
		j = 0;
		while (j < all->map_width)
		{
			ft_printf("%c ", all->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("print_map end\n");
}
