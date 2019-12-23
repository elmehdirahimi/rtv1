/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:44:41 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/06 20:44:43 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int  sphere_intersection(t_rt *rt, t_object *sphere_temp, double *dist)
{
    t_vect vect;
    double a;
    double b;
    double c;
    double delta;
    double t1;
    double t2;

    vect = soustraction(rt->cam.cam_ray.o, sphere_temp->position);
    a = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d);
    b = 2.0 * dot(vect, rt->cam.cam_ray.d);
    c = dot(vect,vect) - sphere_temp->r * sphere_temp->r;
    delta = b * b - 4.0 * a * c;
    if (delta >= 0.0)
     {
    t1 = (- b - sqrt(delta)) / (2.0 * a);
    t2 = (- b + sqrt(delta)) / (2.0 * a);
     light_inter(rt, t1);
      light_inter(rt, t2);
    /*if ((t1 > 1e-5 && t2 < 1e-5) || (t1 < 1e-5 && t2 > 1e-5))
      return (0);
    else if (t2 > t1 && t1 > 1e-5)
      *dist = t1;
    else
      *dist = t2;*/
    if (t2 > t1 && t1 >= 1e-4)
      *dist = t1;
    else
      *dist = t2;
    if(*dist >= 1e-4)
     return (1);
     }
     return (0);
}
   