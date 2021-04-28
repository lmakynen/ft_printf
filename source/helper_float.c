/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:03:32 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 17:58:41 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** These helper functions needed different
** rules for float conversion. The idea is
** still same.
*/

void			print_space_f(t_struct *s, int state)
{
	if (state == 1)
	{
		if (s->zero == 0)
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

void			print_zeroes_f(t_struct *s)
{
	if (s->zero == 1 && s->minus == 0 && s->width > 0)
	{
		while (s->width > 0)
		{
			write(1, "0", 1);
			s->printed++;
			s->width--;
		}
	}
}
