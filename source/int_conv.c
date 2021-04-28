/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:25:02 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/28 18:25:04 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Signed decimal integer conversion.
** Every sub-specifier is taken into account
** except for hash. I do the conversion
** according to those sub-specifiers and write
** the output.
*/

static void		check_space(t_struct *s, intmax_t i)
{
	if (i >= 0 && s->plus == 0 && s->space == 1)
	{
		s->width--;
		write(1, " ", 1);
		s->printed++;
	}
}

static void		helper_int(t_struct *s, intmax_t i)
{
	intmax_t	n;

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

static void		print_min(t_struct *s, intmax_t i)
{
	if (s->precision >= 20)
		s->precision++;
	check_width(s, 20, i);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	write(1, "-", 1);
	print_zeroes(s, 20);
	write(1, "9223372036854775808", 19);
	s->printed += 20;
	if (s->width > 0)
		print_space(s, 2);
}

void			int_conv(t_struct *s, va_list ap)
{
	intmax_t	i;

	i = get_length(s, ap);
	check_space(s, i);
	if (i != LONG_MIN)
	{
		if (i < 0 && s->precision >= ft_intcount(i))
			s->precision++;
		if (i == 0 && s->precision == 0)
		{
			s->empty = 1;
			s->width++;
		}
		check_width(s, ft_intcount(i), i);
		helper_int(s, i);
	}
	else
		print_min(s, i);
}
