/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:05:13 by krutten           #+#    #+#             */
/*   Updated: 2019/05/23 21:06:14 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define MAX_ITERATION 100
# define WIDTH 2300
# define HEIGHT 1000
# define THREADS 8
# define ABS(x) ((x) < 0 ? -(x): (x))
# include <stdlib.h>
# include <stdio.h>
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
void			thread_iter(t_specs *specs);
void			colour_table0(t_specs *specs);
void			colour_table1(t_specs *specs);
void			colour_table2(t_specs *specs);
void			colour_table3(t_specs *specs);
void			colour_table4(t_specs *specs);
int				ft_gradient(int i, int *pal);
int				rgb_fluid(float ratio, int color1, int color2);
void			window_finish(t_specs *specs);
void			draw_palettes(t_specs *specs);
#endif
