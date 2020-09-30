/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:55:37 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/30 21:15:39 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		width_char(t_struct *s, char c)
{
	if (s->minus == 1)
		ft_putchar(c);
	while (s->width > 0)
	{
		write(1, " ", 1);
		s->width--;
		s->printed++;
	}
	if (s->minus == 0)
		ft_putchar(c);
}

void			char_conv(t_struct *s, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (s->width == 0)
		ft_putchar(c);
	else if (s->width != 0)
	{
		s->width -= 1;
		width_char(s, c);
	}
	s->printed++;
}