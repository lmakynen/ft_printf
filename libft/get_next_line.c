/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:52:19 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/04 17:56:51 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_line(char **arr, int fd, char **line, int ret)
{
	size_t		len;
	char		*tmp;

	len = 0;
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (!(*line = ft_strndup(arr[fd], len)))
		return (-1);
	if (arr[fd][len] == '\n')
	{
		if (!(tmp = ft_strdup(arr[fd] + len + 1)))
			return (-1);
		free(arr[fd]);
		arr[fd] = tmp;
		return (1);
	}
	else if (!ft_strlen(arr[fd]) && !ret)
	{
		ft_strdel(&arr[fd]);
		return (0);
	}
	else if (arr[fd][len] == '\0')
		ft_strclr(arr[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*arr[4864];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || fd > 4864)
		return (-1);
	if (!arr[fd])
		if (!(arr[fd] = ft_strnew(1)))
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(arr[fd], buf)))
			return (-1);
		free(arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(arr[fd], '\n'))
			break ;
	}
	return (fill_line(arr, fd, line, ret));
}
