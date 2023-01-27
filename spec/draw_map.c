/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/01/27 17:55:59 by sawang           ###   ########.fr       */
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

void	draw(mlx_image_t *g_img, t_coord ***map, int *width, int *height)
{
	*map = center_map(*map, width, height);
	*map = rotate_map(*map, width, height);
	*map = scale_map(*map, width, height);
	*map = proj_map(*map, width, height);
	draw_map(g_img, *map, width, height);
}
