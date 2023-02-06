/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:12:07 by dongyshi          #+#    #+#             */
/*   Updated: 2022/12/07 15:21:46 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_combination(t_contents *contents)
{
	if (!(contents->type == 'd') && (!(contents->type == 'i') \
	&& !(contents->type == '%')) && !(contents->type == 's') \
	&& (contents->flags.op_space || contents->flags.op_plus))
		return (-1);
	if ((!(contents->type == 'x') && !(contents->type == 'X') \
	&& !(contents->type == '%')) && contents->flags.op_hash)
		return (-1);
	if ((contents->type == 'c' || contents->type == 's' \
	|| contents->type == 'p') && contents->flags.op_zero)
		return (-1);
	if ((contents->type == 'c' || contents->type == 'p') \
	&& (contents->precision == ZERO_PRECISION || contents->precision > 0))
		return (-1);
	if (contents->type == '%' && contents->precision > 0)
		contents->precision = 0;
	if (contents->flags.op_zero && contents->precision > 0)
		contents->flags.op_zero = 0;
	return (1);
}
