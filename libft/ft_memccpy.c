/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:25:32 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:10:52 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		if (source[i] != (unsigned char)c)
			dest[i] = source[i];
		if (source[i] == (unsigned char)c)
		{
			dest[i] = (unsigned char)c;
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
