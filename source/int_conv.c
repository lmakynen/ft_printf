/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:40:29 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/20 16:10:17 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_number(t_struct *s, intmax_t n)
{
	if (n == 2147483648)
	{
		ft_putnbr(214748364);
		ft_putnbr(8);
	}
	else
		ft_putnbr(n);
	s->printed += ft_intcount(n);
}

void	int_conv(t_struct *s, va_list ap)
{
	int			i;
	intmax_t	n;

	i = va_arg(ap, int);
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
		print_number(s, n);
	if (s->width > 0)
		print_space(s, 2);
}
