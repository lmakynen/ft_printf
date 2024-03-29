/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:15:25 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 17:59:06 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Length modifier. I type cast the value
** into the desired length. Then I type cast
** it back to intmax_t or uintmax_t depending
** if it's unsigned or not. This way I make
** the conversion process easier without
** changing the value.
*/

intmax_t	get_length(t_struct *s, va_list ap)
{
	intmax_t	n;

	if (s->length == 1)
		n = (short int)va_arg(ap, int);
	else if (s->length == 2)
		n = (signed char)va_arg(ap, int);
	else if (s->length == 3)
		n = (long int)va_arg(ap, long int);
	else if (s->length == 4)
		n = (long long int)va_arg(ap, long long int);
	else
		n = (int)va_arg(ap, int);
	return ((intmax_t)n);
}

uintmax_t	get_length_u(t_struct *s, va_list ap)
{
	uintmax_t	n;

	if (s->length == 1)
		n = (unsigned short int)va_arg(ap, unsigned int);
	else if (s->length == 2)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (s->length == 3)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	else if (s->length == 4)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	else
		n = (unsigned int)va_arg(ap, unsigned int);
	return ((uintmax_t)n);
}
