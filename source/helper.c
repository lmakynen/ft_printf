/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:48:21 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/23 18:50:55 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			check_width(t_struct *s, int i, intmax_t nb)
{
	if (s->precision > i)
		s->width -= (s->precision - i);
	if (s->plus == 1 && nb >= 0)
		s->width--;
	if ((s->hash == 1 && CURR_POS == 'x') || (s->hash == 1 && CURR_POS == 'X')
			|| (s->hash == 1 && CURR_POS == 'o'))
	{
		if (CURR_POS == 'x' || CURR_POS == 'X')
			s->width--;
		s->width--;
	}
	s->width -= i;
}

void			print_space(t_struct *s, int state)
{
	if (state == 1)
	{
		if (s->zero == 0 || (s->zero == 1 && s->precision > -1))
		{
			while (s->width > 0)
			{
				write(1, " ", 1);
				s->printed++;
				s->width--;
			}
		}
	}
	else if (state == 2)
	{
		while (s->width > 0)
		{
			write(1, " ", 1);
			s->printed++;
			s->width--;
		}
	}
}

intmax_t		check_sign(t_struct *s, intmax_t i)
{
	if (s->plus == 1 && i >= 0)
	{
		write(1, "+", 1);
		s->printed++;
	}
	else if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
		s->printed++;
	}
	return (i);
}

void			print_zeroes(t_struct *s, int i)
{
	if (s->precision > i)
	{
		s->precision -= i;
		while (s->precision > 0)
		{
			write(1, "0", 1);
			s->printed++;
			s->precision--;
		}
	}
	else if (s->zero == 1 && s->minus == 0 && s->width > 0)
	{
		while (s->width > 0)
		{
			write(1, "0", 1);
			s->printed++;
			s->width--;
		}
	}
}

void			print_value(t_struct *s, char *str, intmax_t i)
{
	if (s->hash == 1 && i > 0)
	{
		if (CURR_POS == 'x')
		{
			write(1, "0x", 2);
			s->printed += 2;
		}
		else if (CURR_POS == 'X')
		{
			write(1, "0X", 2);
			s->printed += 2;
		}
		else if (CURR_POS == 'o')
		{
			write(1, "0", 1);
			s->printed++;
		}
	}
	if (s->empty == 0)
		ft_putstr(str);
	if (i > 0)
		free(str);
}
