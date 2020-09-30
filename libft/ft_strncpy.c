/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:34:26 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:15:38 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;
	size_t		remaining;

	index = 0;
	while (src[index] && index < len)
	{
		dst[index] = src[index];
		index++;
	}
	remaining = (len - index);
	if (index < len)
	{
		while (remaining)
		{
			dst[(index + remaining) - 1] = '\0';
			remaining--;
		}
	}
	return (dst);
}
