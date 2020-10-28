/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:50:17 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/28 20:46:04 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		conversion(t_struct *s, const char *format, va_list ap)
{
	int	i;

	i = s->pos;
	while (format[s->pos] != '\0')
	{
		if (ft_strchr(CONV, format[s->pos]))
		{
			if (format[s->pos] == 'c')
				char_conv(s, ap);
			else if (format[s->pos] == 's')
				str_conv(s, ap);
			else if (format[s->pos] == 'd' || CURR_POS == 'i')
				int_conv(s, ap);
			else if (CURR_POS == 'X' || CURR_POS == 'x')
				hexa_conv(s, ap);
			else if (CURR_POS == 'o')
				octal_conv(s, ap);
			else if (CURR_POS == 'p')
				pointer_conv(s, ap);
			else if (CURR_POS == 'u')
				unsigned_conv(s, ap);
			else if (CURR_POS == '%')
				percent_conv(s);
			return ;
		}
		s->pos++; //if the modifiers are in wrong places, do i still need to use them or can i just skip
	}
	s->pos = i;
}
