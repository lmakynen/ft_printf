/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:24:45 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/28 18:28:36 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Unsigned hexadecimal integer conversion.
** Every sub-specifier is present. I do
** the conversion according to the sub-specifiers
** and write the value.
*/

static void	print_all(t_struct *s, char *str, int len, uintmax_t i)
{
	print_value(s, str, i, 1);
	print_zeroes(s, len);
	print_value(s, str, i, 2);
	if (s->width > 0)
		print_space(s, 2);
	s->printed += len;
}

void		hexa_conv(t_struct *s, va_list ap)
{
	uintmax_t	i;
	char		*str;
	int			len;

	i = get_length_u(s, ap);
	if (CURR_POS == 'x')
		str = ft_itoa_base_low_u(i, 16);
	else
		str = ft_itoa_base_u(i, 16);
	len = ft_strlen(str);
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
		s->printed--;
	}
	if (i != 0)
		check_width(s, len, -1);
	else
		check_width(s, len, 0);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_all(s, str, len, i);
}
