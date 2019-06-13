/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:57:25 by krutten           #+#    #+#             */
/*   Updated: 2019/05/13 23:57:27 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	colour_table1(t_specs *specs)
{
	int	i;
	int	pal[5];

	pal[0] = 0xfff68f;
	pal[1] = 0xf9e29a;
	pal[2] = 0xf2cea0;
	pal[3] = 0xeebaa7;
	pal[4] = 0xe5a7af;
	i = 0;
	while (i < 256)
	{
		specs->colours[i] = ft_gradient(i, pal);
		i++;
	}
}

void	colour_table2(t_specs *specs)
{
	int	i;
	int	pal[5];

	pal[0] = 0x98b9ff;
	pal[1] = 0x84b1ff;
	pal[2] = 0x7a9eff;
	pal[3] = 0x8991ff;
	pal[4] = 0x937bff;
	i = 0;
	while (i < 256)
	{
		specs->colours[i] = ft_gradient(i, pal);
		i++;
	}
}

void	colour_table3(t_specs *specs)
{
	int	i;
	int	pal[5];

	pal[0] = 0xd99efb;
	pal[1] = 0x90e1f9;
	pal[2] = 0xa5f69d;
	pal[3] = 0xe7f695;
	pal[4] = 0xfd8c8c;
	i = 0;
	while (i < 256)
	{
		specs->colours[i] = ft_gradient(i, pal);
		i++;
	}
}

void	colour_table4(t_specs *specs)
{
	int	i;
	int	pal[5];

	pal[0] = 0xcb0c59;
	pal[1] = 0x7b1346;
	pal[2] = 0x00ff9f;
	pal[3] = 0x22a0b6;
	pal[4] = 0x0c4383;
	i = 0;
	while (i < 256)
	{
		specs->colours[i] = ft_gradient(i, pal);
		i++;
	}
}
