/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:28:52 by lmakynen          #+#    #+#             */
/*   Updated: 2019/11/05 15:47:37 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *end)
{
	t_list		*move;

	if (end)
	{
		if (!(*alst))
		{
			(*alst) = end;
			return ;
		}
		move = (*alst);
		while (move->next)
			move = move->next;
		move->next = end;
	}
}
