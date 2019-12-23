/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:42:54 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/08 11:42:55 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDHT 1000
# define HEIGHT 1000

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>



typedef struct s_vect
{
	double x;
	double y;
	double z;
}			t_vect;

typedef struct  s_ray
{
	t_vect o;
	t_vect d;
	t_vect translation;
} 				t_ray;

typedef struct  s_cam
{
	t_ray cam_ray;
	t_vect look_at;
	t_vect  u;
	t_vect  v;
	double w;
	double h;
	t_vect center_corner;
} 				t_cam;

typedef struct  s_light
{
	t_vect position;
	t_vect color;
	int enable;
	t_vect translation;
	struct  s_light *next;
} 				t_light;

typedef struct  s_object
{
	int 			type;
	int				 red;
	int 			blue;
	int 			green;
    t_vect 			position;
	t_vect     direction;
	t_vect     rotation;
	t_vect  translation;
	double r;
	struct  s_object *next;
} 				t_object;



typedef struct	s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;
	t_object 	*object;
	t_cam		cam;
	t_light     *light;
	double     t;
	int x;
    int y;
	int fd;
	int nb_line_min;
	int nb_line;
	char **image;
}				t_rt;



void  print_vect(t_vect vect); ////////// suppppppppppppremer
void	initialize(t_rt *rt, char *argv);
t_vect addition(t_vect vect1, t_vect vect2);
t_vect soustraction(t_vect vect1, t_vect vect2);
t_vect multiplication(t_vect vect1, double x);
double  dot(t_vect vect1, t_vect vect2);
double  module(t_vect vect);
t_vect normale(t_vect vect);
t_vect  constrector(double x, double y, double z);
void	put_pixel(t_rt *rt, int x, int y,int color);
void  draw(t_rt *rt);
void  print_vect(t_vect vect);
t_vect  cross(t_vect vect1, t_vect vect2);
t_vect division(t_vect vect1, t_vect vect2);
int  plane_intersection(t_rt *rt, t_object *plane_temp, double *dist);
int  cylinder_intersection(t_rt *rt, t_object *plane_temp, double *dist);
int  cone_intersection(t_rt *rt, t_object *cone_temp, double *dist);
int  sphere_intersection(t_rt *rt, t_object *sphere_temp, double *dist);
int equal(t_vect vect1, t_vect vect2);
int   init_camera(t_rt *rt, int j);
int	  add_light(t_rt *rt, int *k, int j);
int			add_sphere(t_rt *rt, int *k, int i);
int			add_cylinder(t_rt *rt, int *k, int i);
int			add_plane(t_rt *rt, int *k, int i);
double		ft_atod(char *str, int *j);
char    *get_buffer(t_rt *rt);
int		ft_color_position(t_rt *rt, t_object *object, int *k);
int   initialiser(t_rt *rt, char *argv);
int   parser(t_rt *rt);
int		ft_new_atoi(char *str, int *j);
void light_inter(t_rt *rt, double dist);
void   corner(t_rt *rt);

#endif
