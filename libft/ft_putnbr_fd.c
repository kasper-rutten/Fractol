/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:59:30 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 15:00:38 by krutten          ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	long	local;
	int		divider;

	divider = putnbr_div(n);
	local = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		local *= -1;
	}
	while (divider > 0)
	{
		ft_putchar_fd((local / divider) + 48, fd);
		local = local % divider;
		divider = divider / 10;
	}
}
