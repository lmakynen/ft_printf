/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:48:51 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/20 19:42:27 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*precision_str(t_struct *s, char *str)
{
	char		*tmp;
	size_t		i;

	if (s->precision == 0)
	{
		str = "\0";
		return (str);
	}
	i = (size_t)s->precision;
	tmp = ft_strndup(str, i);
	str = tmp;
	free(tmp);
	return (str);
}

static void		width_str(t_struct *s, char *str)
{
	if (s->minus == 1)
		ft_putstr(str);
	while (s->width > 0)
	{
		write(1, " ", 1);
		s->width--;
		s->printed++;
	}
	if (s->minus == 0)
		ft_putstr(str);
}

void			str_conv(t_struct *s, va_list ap)
{
	int		i;
	char	*str;
	char	*new;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	i = (int)ft_strlen(str);
	if (s->precision > -1 && i > s->precision)
	{
		new = precision_str(s, str);
		str = new;
		i = (int)ft_strlen(str);
	}
	if ((s->width - i) > 0)
	{
		s->width -= i;
		width_str(s, str);
		s->printed += i;
	}
	else
	{
		ft_putstr(str);
		s->printed += i;
	}
}
