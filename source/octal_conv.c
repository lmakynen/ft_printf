/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:57 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/20 18:55:12 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	octal_conv(t_struct *s, va_list ap)
{
	intmax_t	i;
	char		*str;
	int			len;

	i = va_arg(ap, long long);
	str = ft_itoa_base(i, 8);
	len = ft_strlen(str);
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
		s->printed--;
	}
	check_width(s, len, -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_zeroes(s, len);
	print_value(s, str, i);
	if (s->width > 0)
		print_space(s, 2);
	s->printed += len;
}
