/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:50:17 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/25 16:58:56 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		conversion(t_struct *s, const char *format, va_list ap)
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
	//add more conversions here
}
