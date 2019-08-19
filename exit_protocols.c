/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_protocols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:01:27 by krutten           #+#    #+#             */
/*   Updated: 2019/08/19 20:01:27 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_specs		init_threadspecs(t_specs *specs, int i)
{
	t_specs new;

	new = *specs;
	new.tnumber = i;
	return (new);
}

void		exit_protocol1(t_specs *reader)
{
	mlx_destroy_image(reader->mlx_ptr, reader->img_ptr);
	mlx_destroy_window(reader->mlx_ptr, reader->win_ptr);
	free(reader);
	exit(0);
}

void		exit_protocol2(pthread_t *tid, t_specs *specs, char **threadstr)
{
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		pthread_join(tid[i], NULL);
		free(threadstr[i]);
	}
	mlx_destroy_image(specs->mlx_ptr, specs->img_ptr);
	mlx_destroy_window(specs->mlx_ptr, specs->win_ptr);
	free(specs);
	exit(0);
}
