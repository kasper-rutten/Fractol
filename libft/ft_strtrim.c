/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:23:23 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 16:40:55 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trimfill(char *output, char const *s, int size)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = 0;
	while (j < size)
		output[j++] = s[i++];
	output[j] = '\0';
	return (output);
}

char		*ft_strtrim(char const *s)
{
	int		wspacecount;
	int		i;
	size_t	size;
	char	*output;

	if (s == 0)
		return (NULL);
	wspacecount = 0;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		wspacecount++;
	if (!(s[i]))
	{
		output = (char *)malloc(1);
		output[0] = '\0';
		return (output);
	}
	while (s[i])
		i++;
	size = i;
	while (s[--i] == ' ' || s[i] == '\t' || s[i] == '\n')
		wspacecount++;
	if (!(output = (char *)malloc(size - wspacecount + 1)))
		return (NULL);
	return (trimfill(output, s, size - wspacecount));
}
