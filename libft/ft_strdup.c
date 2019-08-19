/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:31:01 by krutten           #+#    #+#             */
/*   Updated: 2018/10/05 13:32:13 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(output = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	while (j < i && (output != NULL))
	{
		output[j] = s1[j];
		j++;
	}
	output[j] = '\0';
	return (output);
}
