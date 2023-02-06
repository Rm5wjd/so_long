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

static size_t	nl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
	{
		len++;
	}
	return (len);
}

void	map_pharsing(t_all *all, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	all->map_width = ft_atoi(get_next_line(fd));
	all->map_height = ft_atoi(get_next_line(fd));
	all->map = (char **)malloc(sizeof(char *) * all->map_height);
	while (i < all->map_height)
		all->map[i++] = (char *)malloc(sizeof(char) * all->map_width);
	i = 0;
	while (i < all->map_height)
	{
		line = get_next_line(fd);
		if (nl_strlen(line) != all->map_width)
			return ;
		line_to_map(all->map, line, i);
		i++;		
	}
}

void	print_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
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
}