/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:15:54 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/06 19:15:58 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

int  cone_intersection(t_rt *rt, t_object *cone_temp, double *dist)
{
    t_vect vect;
    double a;
    double b;
    double c;
    double delta;
    double t1;
    double t2;
    double k;

    k = tan(cone_temp->r);
    vect = soustraction(rt->cam.cam_ray.o, cone_temp->position);
    a = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - (1.0 + k * k) * dot(rt->cam.cam_ray.d, cone_temp->direction) * dot(rt->cam.cam_ray.d, cone_temp->direction);
    b = 2.0 * (dot(rt->cam.cam_ray.d, vect) - (1.0 + k * k) *  dot(rt->cam.cam_ray.d, cone_temp->direction) * dot(vect, cone_temp->direction));
    c = dot(vect, vect) - (1.0 + k * k) * dot(vect, cone_temp->direction) * dot(vect, cone_temp->direction);
    delta = b * b - 4.0 * a * c;
      if (delta >= 0.0)
     {
    t1 = (- b - sqrt(delta)) / (2.0 * a);
    t2 = (- b + sqrt(delta)) / (2.0 * a);
    light_inter(rt, t1);
      light_inter(rt, t2);
  if (t2 > t1 && t1 > 1e-4)
      *dist = t1;
    else
      *dist = t2;
    if(*dist >= 1e-4)
     return (1);
     }
     return (0);
}