/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:57:01 by krutten           #+#    #+#             */
/*   Updated: 2018/10/09 17:37:51 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_alloc(int n)
{
	int		size;
	char	*output;

	size = 0;
	if (n == 0)
	{
		if (!(output = (char *)malloc(2)))
			return (NULL);
		return (output);
	}
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	if (!(output = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (output);
}

static int	itoa_div(int n)
{
	int		div;

	div = 1;
	while (n / div >= 10 || n / div <= -10)
		div *= 10;
	return (div);
}

char		*ft_itoa(int n)
{
	long	local;
	char	*output;
	int		divider;
	int		i;

	output = itoa_alloc(n);
	if (output == NULL)
		return (NULL);
	divider = itoa_div(n);
	local = n;
	i = 0;
	if (n < 0)
	{
		output[i++] = '-';
		local *= -1;
	}
	while (divider > 0)
	{
		output[i++] = (local / divider) + 48;
		local = local % divider;
		divider = divider / 10;
	}
	output[i] = '\0';
	return (output);
}
