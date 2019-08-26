/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:05:13 by krutten           #+#    #+#             */
/*   Updated: 2019/06/13 16:44:53 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define MAX_ITERATION 50
# define WIDTH 2300
# define HEIGHT 1000
# define THREADS 8
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_specs
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_str;
	double		rangex;
	double		rangey;
	double		left;
	double		bot;
	int			palette;
	int			colours[256];
	int			shape;
	int			tnumber;
	char		*thread_str;
	char		edit;
	float		julx;
	float		july;
	int			(*ft)(double, double, float, float);
}				t_specs;
t_specs			*init_specs(void *mlx_ptr, void *win_ptr, void *img_ptr,
char *shape);
int				ft_comp_mand(double realx, double imgy, float julx, float july);
int				ft_comp_jul(double realx, double imgy, float julx, float july);
int				ft_comp_burn(double realx, double imgy, float julx, float july);
int				ft_comp_tri(double realx, double imgy, float julx, float july);
int				deal_mouse(int button, int x, int y, void *param);
int				deal_key(int key, void *param);
int				deal_move(int x, int y, void *param);
int				thread_iter(t_specs *specs);
void			colour_table0(t_specs *specs);
void			colour_table1(t_specs *specs);
void			colour_table2(t_specs *specs);
void			colour_table3(t_specs *specs);
void			colour_table4(t_specs *specs);
int				ft_gradient(int i, int *pal);
int				rgb_fluid(float ratio, int color1, int color2);
void			window_finish(t_specs *specs);
void			draw_palettes(t_specs *specs);
void			exit_protocol1(t_specs *reader);
void			exit_protocol2(pthread_t *tid,
t_specs *specs, char **threadstr);
t_specs			init_threadspecs(t_specs *specs, int i);

#endif
