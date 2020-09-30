/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:23:17 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/04 19:33:19 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrdcount(char const *s, char c)
{
	int		i;
	int		word;

	word = 0;
	i = 0;
	if (s[i] != '\0' && s[i] != c)
	{
		word++;
		i++;
	}
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
				word++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

static int		ft_wrdlen(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void		ft_fillwrd(char const *s, char *array, int len, int i)
{
	int		letter;

	letter = 0;
	while (len > 0)
	{
		array[letter] = s[i];
		len--;
		i++;
		letter++;
	}
	array[letter] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		len;
	int		j;
	int		wrd;

	wrd = ft_wrdcount(s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (wrd + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < wrd)
	{
		while (s[i] == c)
			i++;
		len = ft_wrdlen(s, c, i);
		if (!(array[j] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_fillwrd(s, array[j], len, i);
		j++;
		i = i + len;
	}
	array[j] = 0;
	return (array);
}
