/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:38 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/06 16:29:25 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEFAULT -2
# define NON_PRECISION -1
# define ZERO_PRECISION 0

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	op_minus;
	int	op_plus;
	int	op_space;
	int	op_zero;
	int	op_hash;
}	t_flags;

typedef struct s_contents
{
	t_flags	flags;
	int		width;
	int		precision;
	int		type;
}	t_contents;

typedef struct s_box
{
	int			sign;
	char		sign_value;
	int			prefix;
	long long	value;
	int			value_len;
	int			right_margin;
	int			left_margin;
	char		base[20];
	int			base_len;
	int			zero;
}	t_box;

int		ft_printf(const char *format, ...);
int		ft_pharsing(const char **format, va_list *ap, t_contents *contents);

//utils1
int		right_format(char c);
int		flags_check_in(char c);
int		type_check_in(const char c);
void	*printf_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

//utils2
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	get_u_len(unsigned long long n);
int		ft_isdigit(int c);
void	check_sign(t_contents *contents, t_box *box);

//boxing
void	ft_boxing(t_contents *contents, t_box *box, va_list *ap);

//combination
int		ft_combination(t_contents *contents);

int		printf_atoi(const char **str);

int		put_all(t_contents *contents, t_box *box, long long *len);
int		ft_putnbr_base(unsigned int nb, char *base);

// put_utils1
int		print_left_margin(t_box *box, long long *len);
int		print_sign(t_box *box, long long *len);
int		print_prefix(t_contents *contents, t_box *box, long long *len);
int		print_zero(t_box *box, long long *len);
int		print_right_margin(t_box *box, long long *len);

// put_utils2
int		put_str(char *value, int value_len);
int		put_memory(void *ptr, int len);
int		ft_max(int x, int y);
int		get_number_len(unsigned long value, int base);

#endif
