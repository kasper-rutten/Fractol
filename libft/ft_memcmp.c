/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:45:26 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 17:10:39 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1byte;
	const unsigned char *s2byte;
	size_t				i;

	s1byte = s1;
	s2byte = s2;
	i = 0;
	while (i < n)
	{
		if (s1byte[i] != s2byte[i])
			return (s1byte[i] - s2byte[i]);
		i++;
	}
	return (0);
}
