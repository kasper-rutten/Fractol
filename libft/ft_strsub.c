/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:12:17 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 16:39:57 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	if (s == 0)
		return (NULL);
	if (!(output = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
