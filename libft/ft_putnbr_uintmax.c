/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uintmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:28:48 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/25 16:30:57 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uintmax(uintmax_t nbr)
{
	if ((nbr / 10) > 0)
		ft_putnbr_uintmax(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
