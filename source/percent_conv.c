/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:45:56 by lmakynen          #+#    #+#             */
/*   Updated: 2020/12/23 17:06:34 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Percent sign conversion.
** Only width and minus are taken
** into account.
*/

void		percent_conv(t_struct *s)
{
	s->precision = -1;
	check_width(s, 1, -1);
	if (s->minus == 0 && s->width > 0)
		print_space(s, 1);
	print_zeroes(s, 1);
	write(1, "%%", 1);
	s->printed++;
	if (s->width > 0)
		print_space(s, 2);
}
