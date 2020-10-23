/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_intmax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:59:51 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/23 19:58:46 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_intmax(intmax_t nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if ((nbr / 10) > 0)
		ft_putnbr_intmax(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
