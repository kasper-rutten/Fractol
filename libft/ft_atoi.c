/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:05:44 by krutten           #+#    #+#             */
/*   Updated: 2019/08/14 14:51:59 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	output;
	int		sign;

	sign = 1;
	output = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*(str - 1) == '-')
		sign = -1;
	while (*str >= 48 && *str <= 57)
	{
		if ((output > 922337203685477580 || (output ==
						922337203685477580 && *str - 48 > 7)) && sign == 1)
			return (-1);
		if ((output > 922337203685477580 || (output ==
						922337203685477580 && *str - 48 > 8)) && sign == -1)
			return (0);
		output *= 10;
		output += *str - 48;
		str++;
	}
	return (output * sign);
}
