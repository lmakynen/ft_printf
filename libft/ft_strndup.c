/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:21:54 by lmakynen          #+#    #+#             */
/*   Updated: 2019/11/13 20:33:16 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*copy;
	size_t		size;

	if (!(copy = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	size = 0;
	while (s1[size] != '\0' && size < n)
	{
		copy[size] = s1[size];
		size++;
	}
	copy[size] = '\0';
	return (copy);
}
