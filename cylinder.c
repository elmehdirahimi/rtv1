/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:53:11 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/05 20:53:13 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int  cylinder_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
    t_vect vect;
    double a;
    double b;
    double c;
    double delta;
    double t1;
    double t2;

    vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
    a = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - dot(rt->cam.cam_ray.d, plane_temp->direction) * dot(rt->cam.cam_ray.d, plane_temp->direction);
    b = 2.0 * (dot(rt->cam.cam_ray.d, vect) - dot(rt->cam.cam_ray.d, plane_temp->direction) * dot(vect, plane_temp->direction));
    c = dot(vect , vect) - dot(vect, plane_temp->direction) * dot(vect, plane_temp->direction) - plane_temp->r * plane_temp->r;
    delta = b * b - 4.0 * a * c;
      if (delta >= 0.0)
     {
    t1 = (- b - sqrt(delta)) / (2.0 * a);
    t2 = (- b + sqrt(delta)) / (2.0 * a);
    light_inter(rt, t1);
      light_inter(rt, t2);
  if (t2 > t1 && t1 >= 1e-4)
      *dist = t1;
    else
      *dist = t2;
    if(*dist >= 1e-4)
     return (1);
     }
     return (0);
}
