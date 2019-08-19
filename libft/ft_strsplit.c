/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:49:49 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 22:50:35 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**alloc_array(char const *s, char c)
{
	int		i;
	int		wcount;
	int		lcount;
	char	**array;

	i = -1;
	wcount = -1;
	lcount = 0;
	while (s[++i])
	{
		if (s[i] == c)
			lcount = 0;
		else
		{
			if (lcount == 0)
				wcount++;
			lcount++;
		}
	}
	if (!(array = (char **)malloc(sizeof(char*) * (wcount + 2))))
		return (NULL);
	array[wcount + 1] = NULL;
	return (array);
}

static char		**alloc_words(char const *s, char c, char **array)
{
	int		i;
	int		wcount;
	int		lcount;

	i = -1;
	wcount = -1;
	lcount = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (lcount != 0)
				if (!(array[wcount] = (char *)malloc(lcount + 1)))
					return (NULL);
			lcount = 0;
		}
		else if (lcount++ == 0)
			wcount++;
	}
	if (!(array[wcount] = (char *)malloc(lcount + 1)))
		return (NULL);
	return (array);
}

static char		**fill_array(char const *s, char c, char **array)
{
	int		i;
	int		wcount;
	int		lcount;

	i = -1;
	wcount = -1;
	lcount = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (lcount != 0)
				array[wcount][lcount] = '\0';
			lcount = 0;
		}
		else
		{
			if (lcount == 0)
				wcount++;
			array[wcount][lcount] = s[i];
			lcount++;
		}
	}
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (s == NULL)
	{
		array = (char **)malloc(sizeof(char *) * 2);
		array[0] = NULL;
		array[1] = NULL;
		return (array);
	}
	array = alloc_array(s, c);
	if (array == NULL)
		return (NULL);
	array = alloc_words(s, c, array);
	array = fill_array(s, c, array);
	return (array);
}
