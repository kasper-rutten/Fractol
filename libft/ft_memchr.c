/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:30:50 by krutten           #+#    #+#             */
/*   Updated: 2018/10/06 16:59:25 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*reader;
	unsigned char		comp;
	size_t				i;

	reader = s;
	comp = c;
	i = 0;
	while (i < n && reader[i] != comp)
		i++;
	if (i < n)
		return ((void*)reader + i);
	return (NULL);
}
