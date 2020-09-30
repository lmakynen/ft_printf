/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:03:21 by lmakynen          #+#    #+#             */
/*   Updated: 2019/10/30 21:42:03 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		new[j] = s[i + start];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
