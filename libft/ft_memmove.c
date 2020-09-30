/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:30:22 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:11:50 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (!(len) || dst == src)
		return (dst);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
	return (dst);
}
