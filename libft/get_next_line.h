/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:14:37 by junglee           #+#    #+#             */
/*   Updated: 2023/01/06 16:01:12 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*backup;
	int				fd;
	int				read_size;
	int				find;
	struct s_list	*next;
}	t_list;

t_list	*find_or_add(t_list **head, int fd);
void	delete_node(t_list **head, int fd);
char	*ft_strjoin(const char *s1, const char *s2, int *malb);
size_t	gnl_strlen(const char *s);
char	*check_backup(t_list *lp, int *crack_malloc);

char	*get_next_line(int fd);
int		find_nl(t_list *cur_node, char *back_line);
char	*final_check(t_list **head, int fd, int *malb, char *line);
char	*sep_line(t_list *cur_node, int *malb);
char	*gnl_strlcpy(const char *src, size_t dstsize, int *malb);

#endif