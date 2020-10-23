/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:55:21 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/23 19:57:07 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_count(intmax_t value, int base)
{
	int	len;

	len = 0;
	if (value < 0)
	{
		if (base == 10)
			len++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char			*ft_low_itoa_base(intmax_t value, int base)
{
	char	*str;
	char	*new;
	int		len;

	str = "0123456789abcdef";
	if (value == 0)
		return ("0");
	len = number_count(value, base);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (value < 0)
	{
		if (base == 10)
			new[0] = '-';
		value *= -1;
	}
	new[len] = '\0';
	while (len > 0)
	{
		new[len - 1] = str[value % base];
		value /= base;
		len--;
	}
	return (new);
}
