/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:07:57 by rkamegne          #+#    #+#             */
/*   Updated: 2018/10/09 11:27:47 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((48 <= c && c <= 57) || (65 <= c && c <= 90) ||
			(97 <= c && c <= 122))
		return (1);
	return (0);
}
