/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:21:21 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 18:00:57 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countint(intmax_t n)
{
	long		count;

	count = 0;
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

char			*ft_imaxtoa(intmax_t nb)
{
	char			*str;
	intmax_t		i;

	i = ft_countint(nb);
	if (i == 0)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}
