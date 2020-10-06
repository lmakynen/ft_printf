/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_int_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:23:35 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/06 15:03:15 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../includes/ft_printf.h"

void		print_space(t_struct *s, int n)
{
	int		i;
	
	i = s->width - ft_intcount(n);
	if (s->minus == 1)
		putnbr(n);
	while (i > 0)
	{
		s->printed += write(1, " ", 1);
		i--;
	}
	if (s->minus == 0)
		putnbr(n);
	s->printed += ft_intcount(n);
}

void		print_zero(t_struct *s, int n)
{
	int	i;

	i = s->width - ft_intcount(n);
	if (s->minus == 1)
		print_space(s, n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (s->plus == 1 && n >= 0)
	{
		s->printed += write(1, "+", 1);
		i--;
	}
	while (i > 0)
	{
		s->printed += write(1, "0", 1);
		i--;
	}
	s->printed += ft_intcount(n);
}

void		print_precision(t_struct *s, int n)
{
	s->precision -= ft_intcount(n);
	if (n < 0)
	{
		
	}	
}


void		int_conv(t_struct *s, va_list ap)
{
	int	n;
	int	i;

	n = va_arg(ap, int);
	//i = ft_intcount(n);
	//ft_putnbr(n);
	//s->printed += ft_intcount(n);
	if ((s->width - ft_intcount(n)) > 0)
	{
		if (s->zero == 0 && s->minus == 0)
			print_space(s, n);
		/*if (s->zero == 1 && s->minus == 0)
		{
			print_zeros(s, n, i);
		}*/
	}
}*/
