/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:06:14 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/30 21:20:26 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_struct(t_struct *s)
{
	s->minus = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
	s->width = 0;
	s->precision = 0;
	s->length = 0;
	s->printed = 0;
}

void		check_all(t_struct *s, const char *format, va_list ap)
{
	s->pos++;
	modifier(s, format, ap);
	conversion(s, format, ap);
}

void		check_format(t_struct *s, const char *format, va_list ap)
{
	while (CURR != '\0')
	{
		if (CURR == '%' && NEXT == '%')
		{
			write(1, &CURR, 1);
			s->pos += 2;
			s->printed++;
		}
		else if (CURR == '%')
		{
			check_all(s, format, ap);
			s->pos++;
		}
		else
		{
			write(1, &CURR, 1);
			s->printed++;
			s->pos++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*s;
	int			len;

	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	va_start(ap, format);
	s->input = (char*)format;
	set_struct(s);
	s->pos = 0;
	len = ft_strlen(format);
	if (len == 0 || (len == 1 && format[0] == '%'))
		return (0);
	check_format(s, format, ap);
	va_end(ap);
	free(s);
	return (s->printed);
	//ft_itoa_base needs to be modified
}