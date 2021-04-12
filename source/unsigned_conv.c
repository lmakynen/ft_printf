/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:53:26 by lmakynen          #+#    #+#             */
/*   Updated: 2021/02/23 19:23:31 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Unsigned decimal integer conversion.
** Every sub-specifier is taken into account
** except for hash. I do the conversion
** according to those sub-specifiers and write
** the output.
*/

void	unsigned_conv(t_struct *s, va_list ap)
{
	uintmax_t	i;

	i = get_length_u(s, ap);
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
	}
	check_width(s, ft_intcount_u(i), -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_zeroes(s, ft_intcount_u(i));
	if (s->empty == 0)
	{
		ft_putnbr_uintmax(i);
		s->printed += ft_intcount_u(i);
	}
	if (s->width > 0)
		print_space(s, 2);
}
