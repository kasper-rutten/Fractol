/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:00:30 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 16:38:33 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*output;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i])
		i++;
	if (!(output = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
