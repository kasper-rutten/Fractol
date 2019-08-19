/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:17:45 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 16:40:30 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	if (s1 == 0 | s2 == 0)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(output = (char *)malloc(i + j + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		output[i] = s1[i];
	j = -1;
	while (s2[++j])
		output[i + j] = s2[j];
	output[i + j] = '\0';
	return (output);
}
