/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:46:19 by lmakynen          #+#    #+#             */
/*   Updated: 2019/11/05 17:14:41 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	end = (ft_strlen(s) - 1);
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (i > end)
	{
		if (!(new = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
	}
	else if (!(new = ft_strsub(s, i, end - i + 1)))
		return (NULL);
	return (new);
}
