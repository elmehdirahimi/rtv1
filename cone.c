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
    double all[7];

    all[6] = tan(cone_temp->r);
    vect = soustraction(rt->cam.cam_ray.o, cone_temp->position);
    all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - 
      (1.0 + pow(all[6], 2)) * pow(dot(rt->cam.cam_ray.d, cone_temp->direction), 2);
    all[1] = 2.0 * (dot(rt->cam.cam_ray.d, vect) - (1.0 + pow(all[5], 2)) 
    *  dot(rt->cam.cam_ray.d, cone_temp->direction) * dot(vect, cone_temp->direction));
    all[2] = dot(vect, vect) - (1.0 + pow(all[6], 2)) 
    * pow(dot(vect, cone_temp->direction), 2);
    all[3] = pow(all[1] ,2) - 4.0 * all[0] * all[2];
    if (all[3] >= 0.0)
     {
     all[4] = (- all[1] - sqrt( all[3])) / (2.0 * all[0]);
    all[5] = (- all[1] + sqrt( all[3])) / (2.0 * all[0]);
  if (all[5] > all[4] && all[4] > 1e-4)
      *dist = all[4];
    else
      *dist = all[5];
    if(*dist >= 1e-4)
     return (1);
     }
     return (0);
}