/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:40:29 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/23 19:04:34 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			int_conv(t_struct *s, va_list ap)
{
	intmax_t	n;
	intmax_t	i;

	i = get_length(s, ap);
	if (i < 0 && s->precision >= ft_intcount(i))
		s->precision++;
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
	}
	check_width(s, ft_intcount(i), i);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	n = check_sign(s, i);
	print_zeroes(s, ft_intcount(i));
	if (s->empty == 0)
	{
		ft_putnbr_intmax(n);
		s->printed += ft_intcount(n);
	}
	if (s->width > 0)
		print_space(s, 2);
}
