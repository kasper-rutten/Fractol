/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:27:28 by krutten           #+#    #+#             */
/*   Updated: 2018/10/08 17:34:41 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*output;
	size_t	i;

	if (!(output = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		output[i++] = '\0';
	return (output);
}
