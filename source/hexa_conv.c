/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:13:39 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/25 16:24:54 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hexa_conv(t_struct *s, va_list ap)
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
	check_width(s, len, -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_zeroes(s, len);
	print_value(s, str, i);
	if (s->width > 0)
		print_space(s, 2);
	s->printed += len;
}
