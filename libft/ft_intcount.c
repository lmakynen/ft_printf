/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:05:11 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/23 18:50:05 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intcount(intmax_t n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
