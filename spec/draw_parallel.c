/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:05:09 by sawang            #+#    #+#             */
/*   Updated: 2023/02/10 15:45:56 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_parallel_x(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].pixel.u = \
				(map->coords)[j][i].point_modified.p + WIDTH / 2;
			(map->coords)[j][i].pixel.v = \
				-(map->coords)[j][i].point_modified.q + HEIGHT / 2;
			i++;
		}
		j++;
	}
}

static void	pixel_parallel_y(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].pixel.u = \
				(map->coords)[j][i].point_modified.o + WIDTH / 2;
			(map->coords)[j][i].pixel.v = \
				-(map->coords)[j][i].point_modified.q + HEIGHT / 2;
			i++;
		}
		j++;
	}
}

static void	pixel_parallel_z(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].pixel.u = \
				(map->coords)[j][i].point_modified.o + WIDTH / 2;
			(map->coords)[j][i].pixel.v = \
				(map->coords)[j][i].point_modified.p + HEIGHT / 2;
			i++;
		}
		j++;
	}
}

static void	update_pixel_parallel(t_map *map, keys_t key)
{
	if (key == MLX_KEY_I)
		pixel_parallel_x(map);
	if (key == MLX_KEY_O)
		pixel_parallel_y(map);
	if (key == MLX_KEY_P)
		pixel_parallel_z(map);
}

void	draw_parallel(mlx_image_t *g_img, t_map *map, t_input *data, keys_t key)
{
	fdf_memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	scale_map(map, data);
	update_pixel_parallel(map, key);
	draw_map(g_img, map);
}
