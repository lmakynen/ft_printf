/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:50:17 by lmakynen          #+#    #+#             */
/*   Updated: 2021/03/26 20:17:05 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** I loop through the input trying to find a conversion.
** If a conversion is found, I send it to the right
** conversion function. Otherwise I set the position
** back into what it was before the looping.
*/

static void	conv_help(t_struct *s, va_list ap)
{
	if (CURR_POS == 'c')
		char_conv(s, ap);
	else if (CURR_POS == 's')
		str_conv(s, ap);
	else if (CURR_POS == 'd' || CURR_POS == 'i')
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
	else if (CURR_POS == 'f')
		float_conv(s, ap);
}

void		conversion(t_struct *s, const char *format, va_list ap)
{
	int	i;

	i = s->pos;
	while (format[s->pos] != '\0')
	{
		if (ft_strchr(CONV, format[s->pos]))
		{
			conv_help(s, ap);
			return ;
		}
		s->pos++;
	}
	s->pos = i;
}
