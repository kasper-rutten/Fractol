/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:34:39 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 18:40:44 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *c, size_t n)
{
	size_t				i;
	unsigned char		*byte;
	const unsigned char	*bytesrc;

	byte = dst;
	bytesrc = c;
	i = 0;
	while (i < n)
	{
		byte[i] = bytesrc[i];
		i++;
	}
	return (dst);
}
