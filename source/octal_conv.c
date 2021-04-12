/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:57 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 21:25:09 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Unsigned octal conversion.
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
	if (i == 0 && s->hash == 1 && s->precision == -1)
	{
		write(1, "0", 1);
		s->printed++;
	}
	s->printed += len;
}

void		octal_conv(t_struct *s, va_list ap)
{
	uintmax_t	i;
	char		*str;
	int			len;

	i = get_length_u(s, ap);
	str = ft_itoa_base_u(i, 8);
	len = ft_strlen(str);
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
		s->printed--;
	}
	if (s->hash == 1)
		s->precision--;
	if (i != 0)
		check_width(s, len, -1);
	else
		check_width(s, len, 0);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_all(s, str, len, i);
}
