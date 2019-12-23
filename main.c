/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:37:32 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/10 16:43:02 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	put_pixel(t_rt *rt, int x, int y,int color)
{

	if (x < WIDHT && x >= 0 && y >= 0 && y < HEIGHT)
	{
		rt->data[x + y * WIDHT] = color;
	}
}

static int		key_press(int key, t_rt *rt)
{
		if (key == 53)
	{
		free(rt);
		exit(0);
	}

	if(key == 124)
	{
	   rt->cam.cam_ray.o.x+=0.1;
     ///rt->light->position.x-=10;
	}

	if(key == 123)
	{
			rt->cam.cam_ray.o.x-=0.1;
		//	rt->light->position.x+=10;
	}

	if(key == 126)
	{
	  rt->cam.cam_ray.o.y+=0.1;
////rt->light->position.y+=10;

	}

	if(key == 125)
	{
			rt->cam.cam_ray.o.y-=0.1;
//	rt->light->position.y-=10;
	}
	if(key == 69)
	{
	   rt->cam.cam_ray.o.z+=1;

	}

	if(key == 78)
	{
			rt->cam.cam_ray.o.z-=0.1;

		//	 rt->light->position.z-=10;
	}

	

	if(key == 86)
	{
	  rt->light->position.x+=10;

	}

	if(key == 88)
	{
		
			rt->light->position.x-=10;
	}

	if(key == 91)
	{
	   rt->light->position.y+=10;

	}

	if(key == 84)
	{
			rt->light->position.y-=10;
	}
	if(key == 83)
	{
	   rt->light->position.z+=10;

	}

	if(key == 85)
	{

			rt->light->position.z-=10;
	}
	//print_vect(rt->cam.cam_ray.o);
	draw(rt);
	return (0);
}


int main(int argc,char **argv)
{
	t_rt *rt;
	int i;

	i = 0;
	if(argc == 2)
	{
	rt = (t_rt *)malloc(sizeof(t_rt));
	initialize(rt, argv[1]);
	if(initialiser(rt, argv[1]) == 1)
	{
		if (parser(rt) == 1)
		{
				corner(rt);
		draw(rt);
			mlx_hook(rt->win_ptr, 2, 0, key_press, rt);
			mlx_loop(rt->mlx_ptr);
		}
		else
		{
			printf("erreur\n");
		}
		
	}

	}
	return (0);
}
