/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_low_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:22:16 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/25 17:35:02 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_count(uintmax_t value, int base)
{
	int	len;

	len = 0;
	while (value > 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base_low_u(uintmax_t value, int base)
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
	new[len] = '\0';
	while (len > 0)
	{
		new[len - 1] = str[value % base];
		value /= base;
		len--;
	}
	return (new);
}
