/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:25:17 by lmakynen          #+#    #+#             */
/*   Updated: 2021/05/10 19:20:51 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** I pass the input through different functions which check
** the flags, width, precision and modifiers. If the input
** has some sub-specifiers (like the minus flag), it's put
** to my struct for later use.
*/

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
	while ((format[s->pos] >= '0' && format[s->pos] <= '9')
		|| format[s->pos] == '*')
	{
		if (format[s->pos] >= '0' && format[s->pos] <= '9')
		{
			s->width = ft_atoi(&format[s->pos]);
			s->pos += ft_intcount(s->width);
		}
		else if (format[s->pos] == '*')
		{
			s->width = va_arg(ap, int);
			if (s->width < 0)
			{
				s->width *= -1;
				s->minus = 1;
			}
			s->pos++;
		}
	}
}

void	precision(t_struct *s, const char *format, va_list ap)
{
	if (format[s->pos] == '.')
	{
		while (format[s->pos] == '.')
		{
			s->precision = 0;
			s->pos++;
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
			}
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

void	modifier(t_struct *s, const char *format, va_list ap)
{
	flags(s, format);
	width(s, format, ap);
	precision(s, format, ap);
	length(s, format);
}
