/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:25:24 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/12/17 22:25:29 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int     init_camera(t_rt *rt, int j)
{
	if ((ft_strcmp(rt->image[0], "[camera")) || (ft_strcmp(rt->image[1], "<")) || (ft_strncmp(rt->image[4], "translation(", 11)) ||\
 		(ft_strcmp(rt->image[5], ">")) || (ft_strncmp(rt->image[2], "look_from(", 9)) || (ft_strncmp(rt->image[3], "look_at(", 7)))
		return (-1);
	
	rt->cam.cam_ray.o.x =  ft_atod(rt->image[2], &j);
	rt->cam.cam_ray.o.y =  ft_atod(rt->image[2], &j);
	rt->cam.cam_ray.o.z =  ft_atod(rt->image[2], &j);
	if (rt->image[2][j] != ')')
		return (-1);
	j = 8;
    rt->cam.look_at.x =  ft_atod(rt->image[3], &j);
	rt->cam.look_at.y =  ft_atod(rt->image[3], &j);
	rt->cam.look_at.z =  ft_atod(rt->image[3], &j);
	if (rt->image[3][j] != ')')
		return (-1);
	j = 12;
     rt->cam.cam_ray.translation.x	= ft_atod(rt->image[4], &j);
	 rt->cam.cam_ray.translation.y  = ft_atod(rt->image[4], &j);
	 rt->cam.cam_ray.translation.z  = ft_atod(rt->image[4], &j);;
	if (rt->image[4][j] != ')')
		return (-1);
	return (1);
}


int			add_light(t_rt *rt, int *k, int j)
{
	t_light *l;
	t_light *tmp;
	if (!(l = (t_light *)malloc(sizeof(t_light))))
		return (-1);

	tmp = rt->light;
	
	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 5], ">") || (ft_strncmp(rt->image[*k + 4], "translation(", 11)) ||\
	   ft_strncmp(rt->image[*k + 2], "color(", 5) || \
	  ft_strncmp(rt->image[*k + 3], "position(", 8) )
	  {
		return (-1);
	  }
	l->color.x	= ft_atod(rt->image[*k + 2], &j);
	l->color.y  = ft_atod(rt->image[*k + 2], &j);
	l->color.z  = ft_atod(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')')
		return (-1);	
	j = 9;

	l->position.x	= ft_atod(rt->image[*k + 3], &j);
	l->position.y  = ft_atod(rt->image[*k + 3], &j);
	l->position.z  = ft_atod(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')')
		return (-1);
			j = 12;
   l->translation.x	= ft_atod(rt->image[*k + 4], &j);
	l->translation.y  = ft_atod(rt->image[*k + 4], &j);
	l->translation.z  = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')')
		return (-1);
	l->enable = 1;
	l->next = tmp;
	rt->light = l;
	*k += 6;
	return (1);
}

int			add_sphere(t_rt *rt, int *k, int j)
{
	
	t_object	*object;
    t_object *tmp;
     tmp = rt->object;
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (-1);
	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 6], ">") || (ft_strncmp(rt->image[*k + 5], "translation(", 11)) ||\
	   ft_strncmp(rt->image[*k + 2], "color(", 5) || ft_strncmp(rt->image[*k + 3], "position(", 8) || ft_strncmp(rt->image[*k + 4], "r(", 1))
	  {
	
		return (-1);
	  }
	object->red	= ft_new_atoi(rt->image[*k + 2], &j);
	object->green  = ft_new_atoi(rt->image[*k + 2], &j);
	object->blue  = ft_new_atoi(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')')
		return (-1);
	j = 9;
	object->position.x	= ft_atod(rt->image[*k + 3], &j);
	object->position.y  = ft_atod(rt->image[*k + 3], &j);
	object->position.z  = ft_atod(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')')
		return (-1);
	j = 2;
	object->r = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')')
		return (-1);
		j = 12;
   object->translation.x	= ft_atod(rt->image[*k + 5], &j);
	object->translation.y  = ft_atod(rt->image[*k + 5], &j);
	object->translation.z  = ft_atod(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')')
		return (-1);
	object->type = 1;
	object->next = tmp;
	rt->object = object;
	*k += 7;
return(1);
}

int			add_cylinder(t_rt *rt, int *k, int j)
{
	t_object	*object;
	t_object    *tmp;

    tmp = rt->object;	printf("Ok");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (-1);
	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 8], ">") || (ft_strncmp(rt->image[*k + 7], "translation(", 11)) ||\
	  ft_strncmp(rt->image[*k + 6], "rotation(", 9) || ft_strncmp(rt->image[*k + 3], "position(", 8)\
      || ft_strncmp(rt->image[*k + 5], "direction(", 9) || ft_strncmp(rt->image[*k + 4], "r(", 2))
		return (-1);
		
	object->red	= ft_new_atoi(rt->image[*k + 2], &j);
	object->green  = ft_new_atoi(rt->image[*k + 2], &j);
	object->blue  = ft_new_atoi(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')')
		return (-1);
	j = 9;
	object->position.x	= ft_atod(rt->image[*k + 3], &j);
	object->position.y  = ft_atod(rt->image[*k + 3], &j);
	object->position.z  = ft_atod(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')')
		return (-1);
	j = 2;
	object->r = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')')
		return (-1);
	j = 10;
	object->direction.x	= ft_atod(rt->image[*k + 5], &j);
	object->direction.y  = ft_atod(rt->image[*k + 5], &j);
	object->direction.z  = ft_atod(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')')
		return (-1);
			j = 9;
	object->rotation.x	= ft_atod(rt->image[*k + 6], &j);
	object->rotation.y  = ft_atod(rt->image[*k + 6], &j);
	object->rotation.z  = ft_atod(rt->image[*k + 6], &j);
	if (rt->image[*k + 6][j] != ')')
		return (-1);
	if((ft_strcmp(rt->image[*k], "cone") == 0))
			object->type = 4;
		j = 12;
   object->translation.x	= ft_atod(rt->image[*k + 7], &j);
	object->translation.y  = ft_atod(rt->image[*k + 7], &j);
	object->translation.z  = ft_atod(rt->image[*k + 7], &j);
	if (rt->image[*k + 7][j] != ')')
		return (-1);
	object->type = 3;
	object->next = tmp;
	rt->object = object;
	*k += 10;

return(1);
}

int			add_plane(t_rt *rt, int *k, int j)
{
	t_object	*object;
    t_object     *tmp;
     tmp = rt->object;
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (-1);
	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 7], ">") || (ft_strncmp(rt->image[*k + 6], "translation(", 11)) ||\
	   ft_strncmp(rt->image[*k + 5], "rotation(", 9)\
	   || ft_strncmp(rt->image[*k + 2], "color(", 5) || ft_strncmp(rt->image[*k + 4], "direction(", 9)\
	   || ft_strncmp(rt->image[*k + 3], "position(", 8))
	      return (-1);
		 
	object->red	= ft_new_atoi(rt->image[*k + 2], &j);
	object->green  = ft_new_atoi(rt->image[*k + 2], &j);
	object->blue  = ft_new_atoi(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')')
		return (-1);
			
	j = 9;
	object->position.x	= ft_atod(rt->image[*k + 3], &j);
	object->position.y  = ft_atod(rt->image[*k + 3], &j);
	object->position.z  = ft_atod(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')')
		return (-1);

	j = 10;
	object->direction.x	= ft_atod(rt->image[*k + 4], &j);
	object->direction.y  = ft_atod(rt->image[*k + 4], &j);
	object->direction.z  = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')')
		return (-1);
	
			j = 9;
	object->rotation.x	= ft_atod(rt->image[*k + 5], &j);
	object->rotation.y  = ft_atod(rt->image[*k + 5], &j);
	object->rotation.z  = ft_atod(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')')
		return (-1);
		j = 12;
   object->translation.x	= ft_atod(rt->image[*k + 6], &j);
	object->translation.y  = ft_atod(rt->image[*k + 6], &j);
	object->translation.z  = ft_atod(rt->image[*k + 6], &j);
	if (rt->image[*k + 6][j] != ')')
		return (-1);
	object->type = 2;
	object->next = tmp;
	rt->object = object;
	*k += 8;
	
return(1);
	return (0);
}