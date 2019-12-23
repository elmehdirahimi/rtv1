/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:07:20 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/16 19:46:18 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int   parser(t_rt *rt)
{
	rt->light = NULL;
    char *buff;

	int k;
	int h;
	int j;
	int o;
	h = 10;
	j = 16;
	o = 22;
	k = 6;
	buff = NULL;
		
    buff =  get_buffer(rt);
    if(!buff)
       return (-1);

	k = 0;
    rt->image = ft_strsplit(buff, '\n');
   if((rt->nb_line < k + 6 ) || init_camera(rt, 10) == -1)
   	 return (-1);

	k = 6;
	while(k < rt->nb_line)
	{
	
	if ((rt->nb_line >= k + 6) && (ft_strcmp(rt->image[k], "light") == 0))
	{
		if(add_light(rt, &k, 6) == -1)
		{
			return (-1);
		}
	}
	else{
		
		if ((rt->nb_line >= k + 7) && (ft_strcmp(rt->image[k], "sphere") == 0))
		{
		if(add_sphere(rt, &k, 6) == -1)
		{	
		
			return (-1);
		}
		}
		else{
		
	
			if ((rt->nb_line >= k + 8) && (ft_strcmp(rt->image[k], "plane") == 0))
			{
				
			if(add_plane(rt, &k, 6) == -1)
			{
			
		     	return (-1);
			}
			
			}else{
					if ((rt->nb_line >= k + 9) && (ft_strcmp(rt->image[k], "cylinder") == 0))
					{
					if(add_cylinder(rt, &k, 6) == -1)
					{
					return (-1);
					}
					
					}
					else{	
				
					return(-1);
	}
	}
	}
	}
}
    return (1);
}