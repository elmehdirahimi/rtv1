/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:11:42 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/10 13:11:49 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void   corner(t_rt *rt)
{
	t_vect up;
	t_vect to;

	rt->cam.w = tan((60.0 * M_PI / 180.0) / 2.0) * 1.0;
	rt->cam.h = rt->cam.w;
	up = normale(constrector(0.0, 1.0, 0.0));
	to = normale(soustraction(rt->cam.cam_ray.o, rt->cam.look_at));
	if (equal(up, to) == 1)
	{
		rt->cam.u = constrector(1.0, 0.0, 0.0);
		rt->cam.v = constrector(0.0, 0.0, 1.0);
	}
	else
	{
		if(equal(up, to) == 2)
		{
			rt->cam.u = constrector(-1.0, 0.0, 0.0);
			rt->cam.v = constrector(0.0, 0.0, 1.0);
		}
		else
		{			
			rt->cam.u = cross(up, to);
			rt->cam.v = cross(rt->cam.u, to);
		}
	}
	
	
	rt->cam.center_corner = soustraction(soustraction(soustraction(rt->cam.cam_ray.o, multiplication(to, 1.0)),multiplication(rt->cam.v, rt->cam.h)), multiplication(rt->cam.u, rt->cam.w));

}


void	initialize(t_rt *rt, char * argv)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDHT, HEIGHT, argv);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, WIDHT, HEIGHT);
	rt->data = (int *)mlx_get_data_addr(rt->img_ptr, &(rt->bpp),\
			&(rt->size_line), &(rt->endian));

	 
}

