/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:40:14 by krutten           #+#    #+#             */
/*   Updated: 2019/06/28 19:40:15 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitcount(int n)
{
	int		divider;
	int		digits;

	divider = 1;
	digits = 1;
	while (n / divider > 9)
	{
		divider *= 10;
		digits++;
	}
	return (digits);
}
