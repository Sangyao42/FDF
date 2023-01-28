/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 21:21:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**center_map(t_coord **map, int *width, int *height)
{
	int		i;
	int		j;
	float	center_x;
	float	center_y;

	center_x = (*width) / 2;
	center_y = (*height) / 2;
	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			map[j][i].mid_pixel.o = (float)i - center_x;
			map[j][i].mid_pixel.p = (float)j - center_y;
			map[j][i].mid_pixel.q = (float)map[j][i].z;
			i++;
		}
		j++;
	}
	return (map);
}

void	draw_map(mlx_image_t *g_img, t_coord **map, int *width, int *height)
{
	int	i;
	int	j;

	j = 0;
	while (j < ((*height) - 1))
	{
		i = 0;
		while (i < ((*width) - 1))
		{
			draw_line(g_img, map[j][i].pixel, map[j][i + 1].pixel);
			draw_line(g_img, map[j][i].pixel, map[j + 1][i].pixel);
			i++;
			draw_line(g_img, map[j + 1][i].pixel, map[j][i].pixel);
		}
		j++;
	}
	i = 0;
	while (i < (*width - 1))
	{
		draw_line(g_img, map[j][i].pixel, map[j][i + 1].pixel);
		i++;
	}
}

void	draw(mlx_image_t *g_img, t_coord ***map, int *width, int *height, t_input data)
{
	int	i;
	int	j;

	// t_coord **points = *map;
	// i = 0;
	// while (i < *height)
	// {
	// 	j = 0;
	// 	while (j < *width)
	// 	{
	// 		printf("%d,%.2d ", points[i][j].pixel.u, points[i][j].pixel.v);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	*map = update_coord(*map, width, height, data);
	// *map = center_map(*map, width, height);
	// *map = rotate_map(*map, width, height);
	// *map = scale_map(*map, width, height);
	// *map = proj_map(*map, width, height);
	draw_map(g_img, *map, width, height);
}

t_coord	**update_coord(t_coord **map, int *width, int *height, t_input data)
{
	int		i;
	int		j;

	printf("tst: %d\n", data.u_inc);
	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			map[j][i].pixel.u = map[j][i].pixel.u + data.u_inc;
			map[j][i].pixel.v = map[j][i].pixel.v + data.v_inc;
			i++;
		}
		j++;
	}

	// i = 0;
	// while (i < *height)
	// {
	// 	j = 0;
	// 	while (j < *width)
	// 	{
	// 		printf("%d,%.2d ", map[i][j].pixel.u, map[i][j].pixel.v);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	return (map);
}
