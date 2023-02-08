/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:19:53 by sawang            #+#    #+#             */
/*   Updated: 2023/02/08 21:47:45 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_points(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].point.o = (float)i - (map->width) / 2;
			(map->coords)[j][i].point.p = (float)j - (map->height) / 2;
			(map->coords)[j][i].point.q = (float)(map->coords)[j][i].z;
			i++;
		}
		j++;
	}
}

static void	init_color(t_map *map)
{
	int		i;
	int		j;
	t_coord	start;
	t_coord	end_pos;
	t_coord	end_neg;

	start = set_base_color(map);
	end_pos = get_max_z(*map);
	end_neg = get_min_z(*map);
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if ((map->coords)[j][i].point.q > start.point.q)
				(map->coords)[j][i].color = \
					set_color((map->coords)[j][i], start, end_pos);
			else if ((map->coords)[j][i].point.q < start.point.q)
				(map->coords)[j][i].color = \
					set_color((map->coords)[j][i], end_neg, start);
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
	return (max);
}

static float	get_scale_rate(t_map *map)
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

void	init_map(t_fdf *frame)
{
	init_points(&frame->map);
	printf("map _ color : %0x", frame->map.coords[0][0].color);
	init_color(&frame->map);
	proj_map(&frame->map);
	frame->data.scaler = get_scale_rate(&frame->map);
	// int	i;
	// int	j;

	// j = 0;
	// while (j < frame->map.height)
	// {
	// 	i = 0;
	// 	while (i < frame->map.width)
	// 	{
	// 		printf("initial color[%d][%d]: %0x\n", j, i, frame->map.coords[j][i].color);
	// 		i++;
	// 	}
	// 	j++;
	// }
}
