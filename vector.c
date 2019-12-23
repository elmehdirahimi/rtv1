/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:16:04 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/21 16:16:08 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect addition(t_vect vect1, t_vect vect2)
{
    t_vect vect;

    vect.x = vect1.x + vect2.x;
    vect.y = vect1.y + vect2.y;
    vect.z = vect1.z + vect2.z;
    return (vect);
}

t_vect soustraction(t_vect vect1, t_vect vect2)
{
    t_vect vect;

    vect.x = vect1.x - vect2.x;
    vect.y = vect1.y - vect2.y;
    vect.z = vect1.z - vect2.z;
    return (vect);
}

t_vect multiplication(t_vect vect1, double x)
{
    t_vect vect;

    vect.x = vect1.x * x;
    vect.y = vect1.y * x;
    vect.z = vect1.z * x;
    return (vect);
}
double  dot(t_vect vect1, t_vect vect2)
{
    double d;

    d = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
    return (d);
}

double  module(t_vect vect)
{
    return (sqrt(dot(vect, vect)));
}

t_vect normale(t_vect vect)
{
    return (multiplication(vect, 1 / module(vect)));
}

t_vect  constrector(double x, double y, double z)
{
    t_vect vect;

    vect.x = x;
    vect.y = y;
    vect.z = z;
    return (vect);
}

t_vect  cross(t_vect vect1, t_vect vect2)
{
    t_vect vect;

    vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
    vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
    vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
    return (vect);
} 
t_vect division(t_vect vect1, t_vect vect2)
{
    t_vect vect;

    vect.x = vect1.x / vect2.x;
    vect.y = vect1.y / vect2.y;
    vect.z = vect1.z / vect2.z;
    return (vect);
}

int equal(t_vect vect1, t_vect vect2)
{
    if (vect1.y == vect2.y)
        return (1);
      if (vect1.y == -vect2.y)
        return (2);
    return (0);
}
void  print_vect(t_vect vect)
{
	printf("(%f,%f,%f)\n",vect.x,vect.y,vect.z);
}