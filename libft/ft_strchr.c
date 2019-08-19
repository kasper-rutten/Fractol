/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:59:47 by krutten           #+#    #+#             */
/*   Updated: 2018/10/06 17:06:31 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	size_t	i;

	find = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char*)s + i);
	return (NULL);
}
