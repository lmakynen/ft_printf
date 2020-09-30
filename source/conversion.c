/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:50:17 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/30 19:32:39 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		conversion(t_struct *s, const char *format, va_list ap)
{
	if (format[s->pos] == 'c')
		char_conv(s, ap);
	//else if (format[s->pos] == 's')
	//	conv_string(s, format, ap);
	//conv_int(s, format);
	//conv_pointer(s, format);
	//add more conversions here
	//we need to pass the struct to use the modifiers
}
