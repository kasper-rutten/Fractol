/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:28:19 by krutten           #+#    #+#             */
/*   Updated: 2019/05/23 21:53:12 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	colour_box(t_specs *specs)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = WIDTH - 300;
		while (++j < WIDTH)
		{
			mlx_pixel_put(specs->mlx_ptr, specs->win_ptr, j, i,
			specs->colours[0]);
		}
	}
}

void	window_finish(t_specs *specs)
{
	colour_box(specs);
	draw_palettes(specs);
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 15,
	specs->colours[255], "scroll wheel to zoom");
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 45,
	specs->colours[255], "e to edit julia parameters");
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 75,
	specs->colours[255], "r to reset to base image");
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 105,
	specs->colours[255], "click palette to recolor");
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 135,
	specs->colours[255], "arrow keys to swap fractal");
	mlx_string_put(specs->mlx_ptr, specs->win_ptr, WIDTH - 285, 165,
	specs->colours[255], "wasd to move around");
}
