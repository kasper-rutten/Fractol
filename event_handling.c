/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:23:42 by krutten           #+#    #+#             */
/*   Updated: 2019/05/23 21:22:11 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		deal_mouse2(int button, int x, int y, t_specs *reader)
{
	if (button == 1)
	{
		if (x > WIDTH - 300 && y > HEIGHT - 375)
		{
			if (y < HEIGHT - 300)
				colour_table4(reader);
			else if (y < HEIGHT - 225)
				colour_table3(reader);
			else if (y < HEIGHT - 150)
				colour_table2(reader);
			else if (y < HEIGHT - 75)
				colour_table0(reader);
			else
				colour_table1(reader);
			window_finish(reader);
			thread_iter(reader);
		}
	}
	return (0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	t_specs		*reader;

	reader = param;
	if (button == 5)
	{
		reader->left -= (reader->rangex / 10.0) * ((float)x / (WIDTH - 300));
		reader->bot -= (reader->rangey / 10.0) * ((float)y / HEIGHT);
		reader->rangex *= 1.1;
		reader->rangey *= 1.1;
		thread_iter(reader);
	}
	else if (button == 4)
	{
		reader->rangex /= 1.1;
		reader->rangey /= 1.1;
		reader->left += (reader->rangex / 10.0) * ((float)x / (WIDTH - 300));
		reader->bot += (reader->rangey / 10.0) * ((float)y / HEIGHT);
		thread_iter(reader);
	}
	else
		deal_mouse2(button, x, y, reader);
	return (0);
}

int		deal_key2(int key, t_specs *reader)
{
	int	(*ft[4])(double, double, float, float);

	ft[0] = ft_comp_mand;
	ft[1] = ft_comp_jul;
	ft[2] = ft_comp_burn;
	ft[3] = ft_comp_tri;
	if (key == 124)
	{
		reader->ft = ft[(reader->shape + 1) % 4];
		reader->shape = (reader->shape + 1) % 4;
	}
	else if (key == 123)
	{
		reader->ft = ft[(reader->shape + 3) % 4];
		reader->shape = (reader->shape + 3) % 4;
	}
	else if (key == 0 || key == 2)
		reader->left += (key - 1) * (reader->rangex / 20);
	else if (key == 1 || key == 13)
		reader->bot -= ((key - 7) / 6) * reader->rangey / 20;
	else
		return (0);
	thread_iter(reader);
	return (0);
}

int		deal_key(int key, void *param)
{
	t_specs *reader;

	reader = param;
	if (key == 53)
		exit_protocol1(reader);
	else if (key == 14)
		reader->edit *= -1;
	else if (key == 15)
	{
		reader->rangex = 4.0;
		reader->rangey = 2.0;
		reader->left = -2.0;
		reader->bot = -1.0;
		reader->edit = -1;
		reader->julx = 0.0;
		reader->july = 0.0;
		colour_table0(reader);
		thread_iter(reader);
	}
	else
		deal_key2(key, reader);
	return (0);
}

int		deal_move(int x, int y, void *param)
{
	t_specs	*reader;

	reader = param;
	if (reader->edit == 1 && reader->shape == 1)
	{
		reader->julx = ((float)x * 2.0 / (WIDTH - 300)) - 1.0;
		reader->july = ((float)y * 2.0 / HEIGHT) - 1.0;
		thread_iter(reader);
	}
	return (0);
}
