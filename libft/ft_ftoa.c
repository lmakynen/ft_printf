/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:23:42 by lmakynen          #+#    #+#             */
/*   Updated: 2021/04/12 18:00:46 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*first_part(intmax_t startnbr)
{
	char	*pt;

	if (startnbr < 0)
		startnbr *= -1;
	pt = ft_imaxtoa(startnbr);
	return (pt);
}

static char		*helper(char *pt1, char *pt2)
{
	char	*final;

	if (ft_strlen(pt2) == 1)
		final = ft_strdup(pt1);
	else
		final = ft_strjoin(pt1, pt2);
	free(pt1);
	free(pt2);
	return (final);
}

char			*ft_ftoa(long double nbr, int p)
{
	int			i;
	char		*pt1;
	char		*pt2;
	char		*final;
	intmax_t	startnbr;

	startnbr = (intmax_t)nbr;
	pt1 = first_part(startnbr);
	if (nbr < 0)
		nbr *= -1;
	if (startnbr < 0)
		startnbr *= -1;
	i = 0;
	pt2 = ft_strnew(p + 2);
	pt2[i++] = '.';
	while (p-- > 0)
	{
		nbr = (nbr - (long double)startnbr) * 10;
		startnbr = (intmax_t)nbr;
		pt2[i++] = startnbr + '0';
	}
	final = helper(pt1, pt2);
	return (final);
}
