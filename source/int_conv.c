/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:36:05 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/06 19:03:30 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_space(t_struct *s, int state)
{
	if (state == 1)
	{
		if (s->zero == 1)
			return ;
		while (s->width > 0)
		{
			write(1, " ", 1);
			s->width--;
			s->printed++;
		}
	}
	else if (state == 2)
	{
		while (s->width > 0)
		{
			write(1, " ", 1);
			s->width--;
			s->printed++;
		}
	}
}

static long	check_sign(t_struct *s, int i, int state)
{
	long	n;

	n = i;
	if (state == 1)
	{
		if (s->plus == 1 && i >= 0)
			return (1);
	}
	else if (state == 2)
	{
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
	return (0);
}

static void	print_zeroes(t_struct *s, int state, int i, long c, int p)
{
	if (state == 1)
	{
		while (s->precision > 0)
		{
			write(1, "0", 1);
			s->precision--;
			s->printed++;
		}
	}
	else if (state == 2)
	{
		//s->width -= (ft_intcount(i) + c);
		if (s->width > (p + ft_intcount(i) + c))
		{
			while (s->width > 0)
			{
				write(1, "0", 1);
				s->width--;
				s->printed++;
			}
		}
	}
}

static void	print_int(t_struct *s, long n, int p)
{
	if (n == 2147483648)
	{
		ft_putnbr(214748364);
		ft_putnbr(8);
	}
	else
		ft_putnbr(n);
	if (s->width > p)
	{
		s->width -= p;
		print_space(s, 2);
	}
}

void		int_conv(t_struct *s, va_list ap)
{
	int		i;
	int		p;
	long	n;
	long	c;

	i = va_arg(ap, int);
	p = 0;
	c = check_sign(s, i, 1);
	if (s->precision == -1 && i == 0)
		return ;
	if (s->precision > ft_intcount(i))
	{
		if (i < 0)
			s->precision++;
		s->precision -= ft_intcount(i);
		p = s->precision;
	}
	if ((s->width > (p + ft_intcount(i) + c) && s->minus == 0))
		{
			s->width -= (p + ft_intcount(i) + c);
			print_space(s, 1);
		}
	n = check_sign(s, i, 2);
	if (p > 0)
		print_zeroes(s, 1, i, c, p);
	if ((p == 0 && (s->zero == 1 && s->minus == 0)) || (p == 0 && s->zero == 1))
		print_zeroes(s, 2, i, c, p);
	p += ft_intcount(i) + c;
	print_int(s, n, p);
}

// 	if ((s->minus == 0 && s->zero == 0) || (s->precision && s->zero == 1) ||(s->precision && s->minus == 0) || (s->precision && s->zero == 1 && s->minus == 1))