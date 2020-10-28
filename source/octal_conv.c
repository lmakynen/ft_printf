/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:57 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/28 20:07:40 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	octal_conv(t_struct *s, va_list ap)
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
	check_width(s, len, -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_value(s, str, i, 1);
	print_zeroes(s, len);
	print_value(s, str, i, 2);
	if (s->width > 0)
		print_space(s, 2);
	s->printed += len;
}
