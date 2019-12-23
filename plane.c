/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:36:12 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/04 21:36:16 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int  plane_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
    t_vect vect;
    double a;
    double b;
  
    vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
    a = -dot(vect, plane_temp->direction);
    b = dot(rt->cam.cam_ray.d, plane_temp->direction);
    *dist =a / b;
    light_inter(rt, *dist);
    if(*dist >= 1e-4)
     return (1);
   return (0);
}
