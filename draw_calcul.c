/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:47:20 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/03 13:47:48 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"


 t_vect     get_normal(t_vect vect, t_object *object,t_rt *rt) 
 {
  t_vect v2;
  t_vect temp;

   if(object->type == 1)
    return (normale(soustraction(vect, object->position)));
  if (object->type == 2)
  {
    if (dot(rt->cam.cam_ray.d, object->direction) <= 1e-5)
      return (object->direction);
    return (multiplication(object->direction, -1.0));
  }
   v2 = soustraction(rt->cam.cam_ray.o, object->position);
  if (object->type == 3)
      return (normale(soustraction(soustraction(vect, object->position), multiplication(object->direction, dot(rt->cam.cam_ray.d, object->direction) * rt->t + dot(v2, object->direction)))));
  temp = multiplication(object->direction, dot(rt->cam.cam_ray.d, object->direction) * rt->t + dot(v2, object->direction));
  temp = multiplication(temp, 1 + tan(object->r) * tan(object->r));
  return (normale(soustraction(soustraction(vect, object->position), temp))); 
 }

t_vect    get_refracted(t_vect vect, t_vect v, t_object *object,t_rt *rt)
{
  t_vect n;
  t_vect r;

  n = get_normal(vect, object, rt);
  r = soustraction(v, multiplication(n, 2.0 * dot(v, n)));
  return (normale(r)); 
}
int     inter(t_rt *rt, t_object *object_temp, double *dist)
{
  if (object_temp->type == 1)
    return (sphere_intersection(rt,object_temp, dist));
  else{
  if(object_temp->type == 2)
    return (plane_intersection(rt,object_temp, dist));
    else
    {
      if(object_temp->type == 3)
       return (cylinder_intersection(rt,object_temp, dist));
       else
       {
         return (cone_intersection(rt,object_temp, dist));
       }
       
    }
    
  }
}

void light_inter(t_rt *rt, double dist)
{
  t_light *temp;
  t_vect  p;

  p = addition(rt->cam.cam_ray.o, multiplication(rt->cam.cam_ray.d, dist));
  temp = rt->light;
  while(temp)
  {
    if ((temp->position.x == p.x) && (temp->position.y == p.y) && (temp->position.z == p.z))
    {
        temp->enable = 0;
    }
    temp = temp->next;
  }
}

t_object   *intersection(t_rt *rt, double max)
{
  t_object *temp;
  double   dist;
  t_object *obj_affich;

  rt->t = max;
  temp = rt->object;
  obj_affich = NULL;
  while (temp)
  {
    if (inter(rt,temp, &dist))
    {
        if (rt->t > dist)
        {
          rt->t = dist;
          obj_affich = temp;
        }
    
    }
    temp = temp->next;
 
  }

    return (obj_affich);
}
# define VEC(x, y, z) (t_vect){x, y, z}
double   diffuse(t_rt *rt,t_object *sphere, t_light *temp, int choix)
{
  
    double facing_ratio;
    t_vect p;
    t_vect ligth_d_norm;

    p = addition(rt->cam.cam_ray.o, multiplication(rt->cam.cam_ray.d, rt->t));
    ligth_d_norm = normale(soustraction(temp->position, p));
    if(temp->enable == 0)
        return (0.0);
    if(choix == 1)
      facing_ratio = dot(get_normal(p, sphere, rt), ligth_d_norm);
    else
      facing_ratio = dot(get_refracted(p, ligth_d_norm, sphere, rt), rt->cam.cam_ray.d);
    if (facing_ratio < 0.0)
      facing_ratio = 0.0;
    if(choix == 1)
      return (facing_ratio);
    return(pow(facing_ratio, 44.0));
}
double clamp(double v)
{
  if (v < 0.0)
    v = 0.0;
  else if (v > 1.0)
    v = 1.0;
  return (v);
}
int  Shading(t_rt *rt, t_object* sphere)
{

  t_vect amb;
  t_vect color;
  t_vect  temp_o;
  t_vect  temp_d;
  t_light *temp;
  t_object *x;
  double dt;
  double sp;
  double max;
  double t3;

  dt = 0.0;
  sp = 0.0;
  color = multiplication(constrector(sphere->red, sphere->green, sphere->blue), 1.0 / 255.99);
   amb =  multiplication(color, 0.15);
  temp = rt->light;
  while(temp)
  {
        temp_o = constrector(rt->cam.cam_ray.o.x, rt->cam.cam_ray.o.y, rt->cam.cam_ray.o.z);
        temp_d = constrector(rt->cam.cam_ray.d.x, rt->cam.cam_ray.d.y, rt->cam.cam_ray.d.z);
        t3 =  rt->t;
        rt->cam.cam_ray.o = addition(rt->cam.cam_ray.o, multiplication(rt->cam.cam_ray.d , rt->t)); 
       rt->cam.cam_ray.d = normale(soustraction(temp->position, rt->cam.cam_ray.o));
       max = module(soustraction(temp->position, rt->cam.cam_ray.o));
          x = intersection(rt, max);
         rt->cam.cam_ray.o =  constrector(temp_o.x, temp_o.y, temp_o.z);
          rt->cam.cam_ray.d = constrector(temp_d.x, temp_d.y, temp_d.z);
          if(!x)
          {
               rt->t = t3;
              dt += diffuse(rt, sphere,temp, 1);
             sp += diffuse(rt,sphere,temp, 2);
          }
   temp = temp->next;     
  }
  
  color =  addition(addition(amb,multiplication(color,dt * 0.5)), multiplication(VEC(1, 1, 1),sp));
  color = multiplication((t_vect){clamp(color.x), clamp(color.y), clamp(color.z)}, 255.99);
	return (((int)color.x << 16) | ((int)color.y << 8) | (int)color.z );
}

void    ray_calcul(t_rt *rt, t_vect pixel_vect)
{
  t_object *obj_affich;
  rt->cam.cam_ray.d = normale(soustraction(pixel_vect, rt->cam.cam_ray.o));
  obj_affich = intersection(rt, 800000.0);
  if (obj_affich && rt->t > 0.0)
  {
      put_pixel(rt, rt->x,rt->y, Shading(rt, obj_affich));
  }
}

 void  draw(t_rt *rt)
 {
     t_vect pixel_vect;

    ft_bzero((void *)rt->data, WIDHT * HEIGHT * 4);
    mlx_clear_window(rt->mlx_ptr,rt->win_ptr);

     rt->x = 0;
     while (rt->x <= WIDHT)
     {
         rt->y = 0;
         while (rt->y <= HEIGHT)
         {
            pixel_vect =  addition(addition(rt->cam.center_corner, multiplication(rt->cam.u, rt->x * 2 * rt->cam.h / WIDHT)), multiplication(rt->cam.v, rt->y * 2 * rt->cam.h / WIDHT));
            ray_calcul(rt, pixel_vect);
            rt->y++;
         }
         rt->x++;
     }
     mlx_put_image_to_window(rt->mlx_ptr,rt->win_ptr,rt->img_ptr,0,0);
    
 }
