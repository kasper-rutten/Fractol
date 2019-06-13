/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:02:51 by krutten           #+#    #+#             */
/*   Updated: 2019/05/23 21:22:12 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			rgb_fluid(float ratio, int color1, int color2)
{
	int		red;
	int		green;
	int		blue;

	red = ((color1 >> 16) & 0xff) * (1 - ratio)
		+ ((color2 >> 16) & 0xff) * ratio;
	green = ((color1 >> 8) & 0xff) * (1 - ratio)
		+ ((color2 >> 8) & 0xff) * ratio;
	blue = ((color1) & 0xff) * (1 - ratio) + ((color2) & 0xff) * ratio;
	return (red << 16 | green << 8 | blue);
}

int			ft_gradient(int i, int *pal)
{
	float	ratio;

	if (i < 4)
	{
		ratio = (i + 1) / 4.0;
		return (rgb_fluid(ratio, pal[0], pal[1]));
	}
	else if (i < 16)
	{
		ratio = (i + 1) / 16.0;
		return (rgb_fluid(ratio, pal[1], pal[2]));
	}
	else if (i < 64)
	{
		ratio = (i + 1) / 64.0;
		return (rgb_fluid(ratio, pal[2], pal[3]));
	}
	else if (i < 256)
	{
		ratio = (i + 1) / 256.0;
		return (rgb_fluid(ratio, pal[3], pal[4]));
	}
	return (0);
}

void		colour_table0(t_specs *specs)
{
	int		i;
	int		pal[5];

	pal[0] = 0xf6f6f6;
	pal[1] = 0xbcb5e5;
	pal[2] = 0xf02424;
	pal[3] = 0x383331;
	pal[4] = 0x201e1e;
	i = 0;
	while (i < 256)
	{
		specs->colours[i] = ft_gradient(i, pal);
		i++;
	}
}

t_specs		*init_specs2(t_specs *new, char *sh)
{
	new->palette = 0;
	if (ft_strcmp(sh, "Mandelbrot") == 0)
	{
		new->shape = 0;
		new->ft = ft_comp_mand;
	}
	if (ft_strcmp(sh, "Julia") == 0)
	{
		new->shape = 1;
		new->ft = ft_comp_jul;
	}
	if (ft_strcmp(sh, "Burning_ship") == 0)
	{
		new->shape = 2;
		new->ft = ft_comp_burn;
	}
	if (ft_strcmp(sh, "Tricorn") == 0)
	{
		new->shape = 3;
		new->ft = ft_comp_tri;
	}
	colour_table4(new);
	return (new);
}

t_specs		*init_specs(void *mlx_ptr, void *win_ptr, void *img_ptr, char *sh)
{
	t_specs	*new;
	char	*img_str;
	int		img_s[3];

	if (!(new = (t_specs*)malloc(sizeof(t_specs))))
		return (NULL);
	new->rangex = 4.0;
	new->rangey = 2.0;
	new->left = -2.0;
	new->bot = -1.0;
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = win_ptr;
	new->img_ptr = img_ptr;
	img_str = mlx_get_data_addr(img_ptr, &img_s[0], &img_s[1], &img_s[2]);
	new->img_str = img_str;
	new->edit = -1;
	new->julx = 0.0;
	new->july = 0.0;
	init_specs2(new, sh);
	return (new);
}
