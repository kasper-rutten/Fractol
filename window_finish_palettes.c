/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_finish_palettes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:47:31 by krutten           #+#    #+#             */
/*   Updated: 2019/05/13 23:47:34 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		draw_palettes5(t_specs *specs)
{
	int		i;
	int		j;

	i = HEIGHT - 375;
	while (++i < HEIGHT - 300)
	{
		j = WIDTH - 300;
		while (++j < WIDTH - 240)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xcb0c59);
		while (++j < WIDTH - 180)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x7b1346);
		while (++j < WIDTH - 120)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x00ff9f);
		while (++j < WIDTH - 60)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x22a0b6);
		while (++j < WIDTH)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x0c4383);
	}
}

void		draw_palettes4(t_specs *specs)
{
	int		i;
	int		j;

	i = HEIGHT - 300;
	while (++i < HEIGHT - 225)
	{
		j = WIDTH - 300;
		while (++j < WIDTH - 240)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xd99efb);
		while (++j < WIDTH - 180)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x90e1f9);
		while (++j < WIDTH - 120)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xa5f69d);
		while (++j < WIDTH - 60)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xe7f695);
		while (++j < WIDTH)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xfd8c8c);
	}
	draw_palettes5(specs);
}

void		draw_palettes3(t_specs *specs)
{
	int		i;
	int		j;

	i = HEIGHT - 225;
	while (++i < HEIGHT - 150)
	{
		j = WIDTH - 300;
		while (++j < WIDTH - 240)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x98b9ff);
		while (++j < WIDTH - 180)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x84b1ff);
		while (++j < WIDTH - 120)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x7a9eff);
		while (++j < WIDTH - 60)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x8991ff);
		while (++j < WIDTH)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x937bff);
	}
	draw_palettes4(specs);
}

void		draw_palettes2(t_specs *specs)
{
	int		i;
	int		j;

	i = HEIGHT - 150;
	while (++i < HEIGHT - 75)
	{
		j = WIDTH - 300;
		while (++j < WIDTH - 240)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xf6f6f6);
		while (++j < WIDTH - 180)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xbcb5e5);
		while (++j < WIDTH - 120)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xf02424);
		while (++j < WIDTH - 60)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x383331);
		while (++j < WIDTH)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0x201e1e);
	}
	draw_palettes3(specs);
}

void		draw_palettes(t_specs *specs)
{
	int		i;
	int		j;

	i = HEIGHT - 75;
	while (++i < HEIGHT)
	{
		j = WIDTH - 300;
		while (++j < WIDTH - 240)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xfff68f);
		while (++j < WIDTH - 180)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xf9e29a);
		while (++j < WIDTH - 120)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xf2cea0);
		while (++j < WIDTH - 60)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xeebaa7);
		while (++j < WIDTH)
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i, 0xe5a7af);
	}
	draw_palettes2(specs);
}
