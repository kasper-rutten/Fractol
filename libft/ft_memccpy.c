/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:41:21 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 18:55:42 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			stop;
	unsigned char			*byte;
	const unsigned char		*bytesrc;

	byte = dst;
	bytesrc = src;
	stop = c;
	i = 0;
	while (i < n)
	{
		byte[i] = bytesrc[i];
		i++;
		if (bytesrc[i - 1] == stop)
			return (dst + i);
	}
	return (NULL);
}
