/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:22:02 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:12:09 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*chr;
	size_t			i;

	i = 0;
	chr = (unsigned char*)b;
	while (i < len)
	{
		*chr++ = (unsigned char)c;
		i++;
	}
	return (b);
}
