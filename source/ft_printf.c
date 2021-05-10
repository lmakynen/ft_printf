/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:06:14 by lmakynen          #+#    #+#             */
/*   Updated: 2021/05/10 19:18:52 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** The program starts here. First I allocate memory for my struct.
** After that I initialize a variable argument list and set some
** variables to my struct. I don't want to reset these variables, so
** I set them seperately at the start. Then I check that the input is
** correct. If everything is fine, I start looping the input.
** If the input doesn't need the conversion process, I just print it.
** Otherwise I start the process by setting default values to my struct.
** Then I check all the specifiers and finally the conversion.
** When I have looped through the whole input, I end the variable
** argument list and free my struct. Then I return the number of printed
** characters. :)
*/

void		set_struct(t_struct *s)
{
	s->minus = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
	s->width = 0;
	s->precision = -1;
	s->length = 0;
	s->empty = 0;
	s->neg = 0;
}

void		check_all(t_struct *s, const char *format, va_list ap)
{
	s->pos++;
	set_struct(s);
	modifier(s, format, ap);
	conversion(s, format, ap);
}

void		check_format(t_struct *s, const char *format, va_list ap)
{
	while (CURR_POS != '\0')
	{
		if (CURR_POS == '%' && NEXT_POS == '%')
		{
			write(1, &CURR_POS, 1);
			s->pos += 2;
			s->printed++;
		}
		else if (CURR_POS == '%')
		{
			check_all(s, format, ap);
			s->pos++;
		}
		else
		{
			write(1, &CURR_POS, 1);
			s->printed++;
			s->pos++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*s;
	int			len;

	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	va_start(ap, format);
	s->input = (char*)format;
	s->pos = 0;
	s->printed = 0;
	len = ft_strlen(format);
	if (len == 0 || (len == 1 && format[0] == '%'))
	{
		free(s);
		return (0);
	}
	check_format(s, format, ap);
	va_end(ap);
	free(s);
	return (s->printed);
}
