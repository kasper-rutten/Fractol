/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:54:37 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 16:37:56 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		output[i] = (*f)(s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
