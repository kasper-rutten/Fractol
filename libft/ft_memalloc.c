/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:44:34 by krutten           #+#    #+#             */
/*   Updated: 2018/10/08 17:35:17 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*output;
	size_t	i;

	if (!(output = (void *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		output[i++] = 0;
	return ((void *)output);
}
