/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:19:53 by sawang            #+#    #+#             */
/*   Updated: 2023/01/31 22:02:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel_max	get_max(t_coord **map, int *width, int *height)
{
	t_pixel_max	max;
	int			i;
	int			j;

	max.u_max = 0;
	max.v_max = 0;
	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			if (abs(map[j][i].pixel.u - WIDTH / 2) > max.u_max)
				max.u_max = (float)abs(map[j][i].pixel.u - WIDTH / 2);
			if (abs(map[j][i].pixel.v - HEIGHT / 2) > max.v_max)
				max.v_max = (float)abs(map[j][i].pixel.v - HEIGHT / 2);
			i++;
		}
		j++;
	}
	printf("u_max: %d\n", max.u_max);
	printf("v_max: %d\n", max.v_max);
	return (max);
}

static float	get_scale_rate(t_coord **map, int *width, int *height)
{
	float		u_rate;
	float		v_rate;
	t_pixel_max	max;

	max = get_max(map, width, height);
	printf("test margin:%d\n", (WIDTH / 2) - (WIDTH / 10));
	u_rate = ((WIDTH / 2) - (WIDTH / 10)) / max.u_max;
	v_rate = ((HEIGHT / 2) - (HEIGHT / 10)) / max.v_max;
	if (u_rate < v_rate)
		return (u_rate);
	return (v_rate);
}

// void	iso_proj2(t_coord **map, int j, int i)
// {
// 	t_pixel	pixel;
// 	int32_t	u_o;
// 	int32_t	v_o;

// 	u_o = WIDTH / 2;
// 	v_o = HEIGHT / 2;
// 	map[j][i].pixel.u = u_o + roundf((map[j][i].mid_pixel.o - map[j][i].mid_pixel.p) * cos(0.46365));
// 	map[j][i].pixel.v = v_o + roundf((map[j][i].mid_pixel.o + map[j][i].mid_pixel.p) * sin(0.46365) - map[j][i].mid_pixel.q);
// }

// t_coord	**proj_map2(t_coord **map, int *width, int *height)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < *height)
// 	{
// 		i = 0;
// 		while (i < *width)
// 		{
// 			iso_proj2(map, j, i);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (map);
// }

// t_coord	**scale_map(t_coord **map, int *width, int *height)
// {
// 	int		rate;
// 	int		i;
// 	int		j;

// 	map = proj_map(map, width, height);
// 	rate = roundf(get_scale_rate(map, width, height));
// 	printf("rate: %d\n", rate);
// 	j = 0;
// 	while (j < *height)
// 	{
// 		i = 0;
// 		while (i < *width)
// 		{
// 			map[j][i].mid_pixel.o = map[j][i].mid_pixel.o * rate;
// 			map[j][i].mid_pixel.p = map[j][i].mid_pixel.p * rate;
// 			map[j][i].mid_pixel.q = map[j][i].mid_pixel.q * rate;
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (map);
// }

t_coord	**scale_map(t_coord **map, int *width, int *height)
{
	int		rate;
	int		i;
	int		j;

	map = proj_map(map, width, height);
	rate = roundf(get_scale_rate(map, width, height));
	printf("rate: %d\n", rate);
	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			map[j][i].mid_pixel_modified.o = map[j][i].mid_pixel.o * rate;
			map[j][i].mid_pixel_modified.p = map[j][i].mid_pixel.p * rate;
			map[j][i].mid_pixel_modified.q = map[j][i].mid_pixel.q * rate;
			i++;
		}
		j++;
	}
	return (map);
}
