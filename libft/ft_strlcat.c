/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:53:31 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:14:47 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		lend;
	size_t		lens;
	size_t		i;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || lend >= dstsize)
		return (dstsize + lens);
	while (lend + i < dstsize - 1 && src[i] != '\0')
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
