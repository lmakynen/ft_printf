/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:44:47 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 18:04:51 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Decimal floating point conversion.
** First I get the value in the right length modifier.
** After getting the value, I round it up.
** My ft_ftoa creates a string which has the float.
** The float in the string is always positive and that's
** why I need to check if the value was negative (otherwise
** printing zeroes wouldn't work). Then I handle the
** sub-specifiers and print everything out.
*/

static long double	get_val(t_struct *s, va_list ap)
{
	long double n;

	if (s->length == 5)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	return ((long double)n);
}

static long double	rounding(t_struct *s, long double n)
{
	int			count;
	long double i;

	i = 0.500;
	if (s->precision == -1)
		s->precision = 6;
	count = s->precision;
	while (count-- > 0)
		i /= 10;
	if (n < 0)
		i *= -1;
	n += i;
	return (n);
}

static void			check_print(t_struct *s, int len, intmax_t n, char *str)
{
	s->width -= len;
	if (s->plus == 1 && n == 1)
		s->width--;
	if (s->minus == 0 && s->width > 0)
		print_space_f(s, 1);
	check_sign(s, n);
	print_zeroes_f(s);
	print_value(s, str, (uintmax_t)len, 2);
	if (s->width > 0)
		print_space_f(s, 2);
}

void				float_conv(t_struct *s, va_list ap)
{
	long double n;
	char		*str;
	int			len;
	intmax_t	nbr;

	n = get_val(s, ap);
	n = rounding(s, n);
	str = ft_ftoa(n, s->precision);
	len = ft_strlen(str);
	if (n < 0)
	{
		nbr = -1;
		len++;
		s->printed--;
	}
	else
		nbr = 1;
	check_print(s, len, nbr, str);
	s->printed += len;
}
