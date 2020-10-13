/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:40:29 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/13 16:59:45 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	check_width(t_struct *s, int i, int nb)
{
	if (s->precision > i)
		s->width -= (s->precision - i);
	if (s->plus == 1 && nb >= 0)
		s->width--;
	s->width -= i;
}

static void	print_space(t_struct *s, int state)
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

static long	check_sign(t_struct *s, int i)
{
	long n;

	n = i;
	if (s->plus == 1 && i >= 0)
	{
		write(1, "+", 1);
		s->printed++;
	}
	else if (i < 0)
	{
		write(1, "-", 1);
		n *= -1;
		s->printed++;
	}
	return (n);
}

static void	print_zeroes(t_struct *s, int i)
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

static void	print_number(t_struct *s, long n)
{
	if (n == 2147483648)
	{
		ft_putnbr(214748364);
		ft_putnbr(8);
	}
	else
		ft_putnbr(n);
	s->printed += ft_intcount(n);
}

void	int_conv(t_struct *s, va_list ap)
{
	int	i;
	long n;

	i = va_arg(ap, int);
	if (i < 0 && s->precision >= ft_intcount(i))
		s->precision++;
	if (i == 0 && s->precision == 0)
	{
		s->empty = 1;
		s->width++;
	}
	check_width(s, ft_intcount(i), i);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	n = check_sign(s, i);
	print_zeroes(s, ft_intcount(i));
	if (s->empty == 0)
		print_number(s, n);
	if (s->width > 0)
		print_space(s, 2);
}
