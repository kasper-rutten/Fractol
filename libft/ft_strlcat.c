/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:59:05 by krutten           #+#    #+#             */
/*   Updated: 2018/10/06 16:56:23 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j])
		j++;
	if (i == size)
		return (i + j);
	j = 0;
	while (i + j + 1 < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (src[j])
	{
		while (src[j])
			j++;
	}
	return (i + j);
}
