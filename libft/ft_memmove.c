/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:40:44 by krutten           #+#    #+#             */
/*   Updated: 2018/10/05 14:30:41 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*srcbyte;
	unsigned char		*dstbyte;
	size_t				i;

	srcbyte = src;
	dstbyte = dst;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dstbyte[i] = srcbyte[i];
		}
	}
	else if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dstbyte[i] = srcbyte[i];
			i++;
		}
	}
	return (dst);
}
