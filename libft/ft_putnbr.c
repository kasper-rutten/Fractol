/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:42:16 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 14:42:26 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putnbr_div(int n)
{
	int		div;

	div = 1;
	while (n / div >= 10 || n / div <= -10)
		div *= 10;
	return (div);
}

void		ft_putnbr(int n)
{
	long	local;
	int		divider;

	divider = putnbr_div(n);
	local = n;
	if (n < 0)
	{
		ft_putchar('-');
		local *= -1;
	}
	while (divider > 0)
	{
		ft_putchar((local / divider) + 48);
		local = local % divider;
		divider = divider / 10;
	}
}
