/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:29:19 by sawang            #+#    #+#             */
/*   Updated: 2023/02/13 11:03:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_delta(t_delta *delta)
{
	delta->dx = 0;
	delta->dy = 0;
	delta->p = 0;
	delta->xi = 1;
	delta->yi = 1;
}

void	draw_map(mlx_image_t *g_img, t_map *map)
{
	int		i;
	int		j;
	t_delta	delta;

	init_delta(&delta);
	j = 0;
	while (j < (map->height - 1))
	{
		i = 0;
		while (i < (map->width - 1))
		{
			draw_line(g_img, (map->coords)[j][i], \
				(map->coords)[j][i + 1], delta);
			draw_line(g_img, (map->coords)[j][i], \
				(map->coords)[j + 1][i], delta);
			i++;
			draw_line(g_img, (map->coords)[j + 1][i], \
				(map->coords)[j][i], delta);
		}
		j++;
	}
	i = 0;
	while (i++ < (map->width - 1))
		draw_line(g_img, (map->coords)[j][i - 1], \
			(map->coords)[j][i], delta);
}

void	draw(mlx_image_t *g_img, t_map *map, t_input *data, keys_t key)
{
	updata_data(data, key);
	fdf_memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	update_coord(map, data);
	update_pixel(map, data);
	draw_map(g_img, map);
}
