/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:53:11 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/28 21:37:18 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int  cylinder_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
	t_vect vect;
	double all[6];

	vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
	all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) -
	 dot(rt->cam.cam_ray.d, plane_temp->direction) * dot(rt->cam.cam_ray.d, plane_temp->direction);
	all[1] = 2.0 * (dot(rt->cam.cam_ray.d, vect) -
	 dot(rt->cam.cam_ray.d, plane_temp->direction) * dot(vect, plane_temp->direction));
	all[2] = dot(vect , vect) - dot(vect, plane_temp->direction)
	 * dot(vect, plane_temp->direction) - plane_temp->r * plane_temp->r;
	all[3] = all[1] * all[1] - 4.0 * all[0] * all[2];
	if (all[3] >= 0.0)
	{
		all[4] = (- all[1] - sqrt(all[3])) / (2.0 * all[0]);
		all[5] = (- all[1] + sqrt(all[3])) / (2.0 * all[0]);
		if (all[5] > all[4] && all[4] >= 1e-4)
			*dist = all[4];
		else
			*dist = all[5];
		if(*dist >= 1e-4)
			return (1);
	}
	return (0);
}
