/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:30:41 by krutten           #+#    #+#             */
/*   Updated: 2019/05/02 17:50:50 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_comp_mand(double realx, double imgy, float julx, float july)
{
	int		iter;
	double	realnew;
	double	real;
	double	img;
	double	squares[2];

	julx += july;
	iter = -1;
	real = 0.0;
	img = 0.0;
	squares[0] = 0.0;
	squares[1] = 0.0;
	while (squares[0] + squares[1] < 4.0 && ++iter < MAX_ITERATION)
	{
		realnew = squares[0] - squares[1] + realx;
		img = 2.0 * real * img + imgy;
		real = realnew;
		squares[0] = real * real;
		squares[1] = img * img;
	}
	return (iter);
}

int		ft_comp_jul(double realx, double imgy, float julx, float july)
{
	int		iter;
	double	realtemp;
	double	imgtemp;

	iter = -1;
	while (++iter < MAX_ITERATION && realx * realx + imgy * imgy < 4)
	{
		realtemp = realx;
		imgtemp = imgy;
		imgy = 2.0 * realtemp * imgtemp + july;
		realx = (realtemp * realtemp) - (imgtemp * imgtemp) + julx;
		iter++;
	}
	return (iter);
}

int		ft_comp_burn(double realx, double imgy, float julx, float july)
{
	int		iter;
	double	realtemp;
	double	new[2];
	double	squares[2];

	iter = -1;
	julx -= july;
	squares[0] = realx * realx;
	squares[1] = imgy * imgy;
	new[0] = realx;
	new[1] = imgy;
	while (++iter < MAX_ITERATION && squares[0] + squares[1] < 4.0)
	{
		realtemp = squares[0] - squares[1] + realx;
		new[1] = ft_abs(2 * new[0] * new[1]) + imgy;
		new[0] = ft_abs(realtemp);
		squares[0] = new[0] * new[0];
		squares[1] = new[1] * new[1];
	}
	return (iter);
}

int		ft_comp_tri(double realx, double imgy, float julx, float july)
{
	int		iter;
	double	realnew;
	double	real;
	double	img;
	double	squares[2];

	julx += july;
	iter = -1;
	real = 0.0;
	img = 0.0;
	squares[0] = 0.0;
	squares[1] = 0.0;
	while (squares[0] + squares[1] < 4.0 && ++iter < MAX_ITERATION)
	{
		realnew = squares[0] - squares[1] + realx;
		img = -2.0 * real * img + imgy;
		real = realnew;
		squares[0] = real * real;
		squares[1] = img * img;
	}
	return (iter);
}
