/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:12:25 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/28 19:18:18 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pointer_conv(t_struct *s, va_list ap)
{
	intmax_t	i;
	char		*str;
	int			len;

	i = va_arg(ap, long long);
	str = ft_low_itoa_base(i, 16);
	len = ft_strlen(str);
	s->width -= 2;
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
		s->printed--;
	}
	check_width(s, len, -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	write(1, "0x", 2);
	print_zeroes(s, len);
	print_value(s, str, i, 2);
	if (s->width > 0)
		print_space(s, 2);
	s->printed += (len + 2);
}
