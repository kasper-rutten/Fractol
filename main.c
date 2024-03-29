/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:17:21 by krutten           #+#    #+#             */
/*   Updated: 2019/06/13 16:45:13 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		ft_colour(t_specs *specs, int escape, char *img_pixel)
{
	*img_pixel = specs->colours[escape] & 0xff;
	*(img_pixel + 1) = (specs->colours[escape] >> 8) & 0xff;
	*(img_pixel + 2) = (specs->colours[escape] >> 16) & 0xff;
}

void		*iterate(void *arg)
{
	int			coord;
	double		s[2];
	int			esc;
	t_specs		*specs;
	double		offsets[2];

	specs = (t_specs *)arg;
	offsets[1] = (1.0 / HEIGHT) * specs->rangey;
	offsets[0] = (1.0 / (WIDTH - 300) * specs->rangex);
	coord = -1 + ((WIDTH - 300) * HEIGHT / THREADS) * (specs->tnumber);
	while (++coord < ((WIDTH - 300) * HEIGHT / THREADS) * (specs->tnumber + 1))
	{
		s[0] = coord % (WIDTH - 300) * offsets[0] + specs->left;
		s[1] = coord / (WIDTH - 300) * offsets[1] + specs->bot;
		esc = specs->ft(s[0], s[1], specs->julx, specs->july);
		ft_colour(specs, esc, &specs->thread_str[coord * 4]);
	}
	pthread_exit(0);
}

int			thread_iter(t_specs *s)
{
	pthread_t		tid[THREADS];
	pthread_attr_t	attr;
	t_specs			threadspecs[THREADS];
	char			*threadstr[THREADS];
	int				i[2];

	i[0] = -1;
	pthread_attr_init(&attr);
	while (++i[0] < THREADS)
	{
		threadspecs[i[0]] = init_threadspecs(s, i[0]);
		if (!(threadstr[i[0]] = (char *)malloc(HEIGHT * (WIDTH - 300) * 4)))
			exit_protocol2(tid, s, threadstr);
		threadspecs[i[0]].thread_str = threadstr[i[0]];
		pthread_create(&tid[i[0]], &attr, iterate, &threadspecs[i[0]]);
	}
	while (--i[0] >= 0)
	{
		pthread_join(tid[i[0]], NULL);
		i[1] = ((HEIGHT * (WIDTH - 300) * 4 / THREADS) * (i[0] + 1));
		while (--i[1] > (HEIGHT * (WIDTH - 300) * 4 / THREADS) * (i[0]))
			s->img_str[i[1]] = threadspecs[i[0]].thread_str[i[1]];
		free(threadspecs[i[0]].thread_str);
	}
	return (mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0));
}

static int	ft_match_string(char *arg)
{
	return (ft_strcmp(arg, "Mandelbrot") && ft_strcmp(arg, "Julia")
	&& ft_strcmp(arg, "Burning_ship") && ft_strcmp(arg, "Tricorn"));
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	t_specs	*specs;

	if (argc != 2 || ft_match_string(argv[1]))
	{
		ft_putstr("Usage: ./fractol Mandelbrot/Julia/Burning_ship/Tricorn\n");
		return (0);
	}
	if (!(mlx = mlx_init()))
		return (0);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol");
	img = mlx_new_image(mlx, WIDTH - 300, HEIGHT);
	if (!(specs = init_specs(mlx, win, img, argv[1])) || !(thread_iter(specs)))
	{
		ft_putstr_fd("malloc error\n", 2);
		return (0);
	}
	window_finish(specs);
	mlx_key_hook(win, deal_key, specs);
	mlx_mouse_hook(win, deal_mouse, specs);
	mlx_hook(win, 6, (1L << 6), deal_move, specs);
	mlx_loop(mlx);
	return (0);
}
