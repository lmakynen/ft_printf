/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:26:24 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:11:29 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	*dt;

	i = 0;
	sc = (unsigned char*)src;
	dt = (unsigned char*)dst;
	if (!(n) || dst == src)
		return (dst);
	while (i < n)
	{
		dt[i] = sc[i];
		i++;
	}
	return (dst);
}
