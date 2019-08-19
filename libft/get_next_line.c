/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:52:28 by krutten           #+#    #+#             */
/*   Updated: 2019/06/28 19:53:39 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		re_line(char **stock, char **line, int fd)
{
	int				len;
	char			*tmp;

	len = 0;
	while (stock[fd][len] != '\n' && stock[fd][len] != '\0')
		len++;
	if (stock[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(stock[fd], 0, len)) ||
		(!(tmp = ft_strdup(stock[fd] + len + 1))))
			return (-1);
		free(stock[fd]);
		stock[fd] = tmp;
	}
	else if (stock[fd][len] == '\0')
	{
		if (!(*line = ft_strdup(stock[fd])))
			return (-1);
		ft_strdel(&stock[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stock[OPEN_MAX];
	char			buffer[BUFF_SIZE + 1];
	char			*cpy;
	int				bound;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	while ((bound = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bound] = '\0';
		if (stock[fd] == NULL)
			if (!(stock[fd] = ft_strnew(0)))
				return (-1);
		if (!(cpy = ft_strjoin(stock[fd], buffer)))
			return (-1);
		free(stock[fd]);
		stock[fd] = cpy;
		if (ft_strchr(stock[fd], '\n'))
			break ;
	}
	if (bound < 0)
		return (-1);
	if (bound == 0 && (stock[fd] == NULL || stock[fd][0] == '\0'))
		return (0);
	return (re_line(stock, line, fd));
}
