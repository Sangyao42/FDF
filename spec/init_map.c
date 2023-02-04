/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:19:53 by sawang            #+#    #+#             */
/*   Updated: 2023/02/04 21:20:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_map *map)
{
	int		i;
	int		j;
	float	center_x;
	float	center_y;

	center_x = (map->width) / 2;
	center_y = (map->height) / 2;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].point.o = (float)i - center_x;
			(map->coords)[j][i].point.p = (float)j - center_y;
			(map->coords)[j][i].point.q = (float)(map->coords)[j][i].z;
			i++;
		}
		j++;
	}
}

static t_pixel_max	get_max(t_map map)
{
	t_pixel_max	max;
	int			i;
	int			j;

	max.u_max = 0;
	max.v_max = 0;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (abs((map.coords)[j][i].pixel.u - WIDTH / 2) > max.u_max)
				max.u_max = (float)abs((map.coords)[j][i].pixel.u - WIDTH / 2);
			if (abs((map.coords)[j][i].pixel.v - HEIGHT / 2) > max.v_max)
				max.v_max = (float)abs((map.coords)[j][i].pixel.v - HEIGHT / 2);
			i++;
		}
		j++;
	}
	printf("u_max: %d\n", max.u_max);
	printf("v_max: %d\n", max.v_max);
	return (max);
}

float	get_scale_rate(t_map *map)
{
	float		u_rate;
	float		v_rate;
	t_pixel_max	max;

	max = get_max(*map);
	u_rate = ((WIDTH / 2) - (WIDTH / 10)) / max.u_max;
	v_rate = ((HEIGHT / 2) - (HEIGHT / 10)) / max.v_max;
	if (u_rate < v_rate)
		return (u_rate);
	return (v_rate);
}
