/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:55:27 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:15:16 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	new;

	new = 0;
	index = ft_strlen(s1);
	while (s2[new] && (new < n))
	{
		s1[index + new] = s2[new];
		new++;
	}
	s1[index + new] = '\0';
	return (s1);
}
