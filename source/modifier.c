/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:46:01 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/13 17:04:44 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//still need to read what these modifiers exactly do and how they affect the result!!!!

void	flags(t_struct *s, const char *format)
{
	while (ft_strchr(FLAGS, format[s->pos]))
	{
		if (format[s->pos] == '-')
			s->minus = 1;
		if (format[s->pos] == '+')
			s->plus = 1;
		if (format[s->pos] == ' ')
			s->space = 1;
		if (format[s->pos] == '#')
			s->hash = 1;
		if (format[s->pos] == '0')
			s->zero = 1;
		s->pos++;
	}
}

void	width(t_struct *s, const char *format, va_list ap)
{
	if (format[s->pos] >= '0' && format[s->pos] <= '9')
	{
		s->width = ft_atoi(&format[s->pos]);
		s->pos += ft_intcount(s->width);
	}
	else if (format[s->pos] == '*')
	{
		s->width = va_arg(ap, int);
		s->pos += ft_intcount(s->width);
		// maybe like this? check if there's specific rules (for example 0 or < 0)
	}
}

void	precision(t_struct *s, const char *format, va_list ap)
{
	if (format[s->pos] == '.')
	{
		s->pos++;
		s->precision = 0;
		while (format[s->pos] >= '0' && format[s->pos] <= '9')
		{
				s->precision *= 10;
				s->precision += (format[s->pos] - 48);
				s->pos++;
		}
		if (format[s->pos] == '*')
		{
			s->precision = va_arg(ap, int);
			s->pos++;
			// maybe like this? check if there's specific rules (for example 0 or < 0)
		}
	}
}

void	length(t_struct *s, const char *format)
{
	if (format[s->pos] == 'h')
		s->length = (format[s->pos + 1] == 'h') ? 2 : 1;
	if (format[s->pos] == 'l')
		s->length = (format[s->pos + 1] == 'l') ? 4 : 3;
	if (format[s->pos] == 'L')
		s->length = 5;
	if (s->length == 2 || s->length == 4)
		s->pos += 2;
	else if (s->length == 1 || s->length == 3 || s->length == 5)
		s->pos += 1;
}

/*
** We will pass the struct and input through all of the
** possible modifiers and fill them into our stuct
** when they appear.
*/

void	modifier(t_struct *s, const char *format, va_list ap)
{
	flags(s, format);
	width(s, format, ap);
	precision(s, format, ap);
	length(s, format);
}
