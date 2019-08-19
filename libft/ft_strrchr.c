/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:08:42 by krutten           #+#    #+#             */
/*   Updated: 2018/10/06 17:10:06 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		find;
	size_t		i;
	char		*found;

	find = c;
	i = 0;
	found = NULL;
	while (s[i])
	{
		if (s[i] == find)
			found = (char*)(s + i);
		i++;
	}
	if (s[i] == find)
		found = (char*)(s + i);
	return (found);
}
