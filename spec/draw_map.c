/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/02/06 19:49:59 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(t_map *map, t_input *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].point_modified.o = \
				(map->coords)[j][i].point.o * data->scaler;
			(map->coords)[j][i].point_modified.p = \
				(map->coords)[j][i].point.p * data->scaler;
			(map->coords)[j][i].point_modified.q = \
				((map->coords)[j][i].point.q * data->z_inc / 10) * data->scaler;
			i++;
		}
		j++;
	}
}

void	update_coord(t_map *map, t_input *data)
{
	scale_map(map, data);
	rotate_map(map, data);
}

void	update_pixel(t_map *map, t_input *data)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].pixel.u = roundf(\
				((map->coords)[j][i].point_modified.o - \
				(map->coords)[j][i].point_modified.p) * cos(0.46365));
			(map->coords)[j][i].pixel.v = roundf(\
				((map->coords)[j][i].point_modified.o + \
				(map->coords)[j][i].point_modified.p) * \
				sin(0.46365) - (map->coords)[j][i].point_modified.q);
			(map->coords)[j][i].pixel.u += data->u_inc;
			(map->coords)[j][i].pixel.v += data->v_inc;
			i++;
		}
		j++;
	}
}

void	draw_map(mlx_image_t *g_img, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < (map->height - 1))
	{
		i = 0;
		while (i < (map->width - 1))
		{
			draw_line(g_img, (map->coords)[j][i].pixel, \
				(map->coords)[j][i + 1].pixel);
			draw_line(g_img, (map->coords)[j][i].pixel, \
				(map->coords)[j + 1][i].pixel);
			i++;
			draw_line2(g_img, (map->coords)[j + 1][i].pixel, \
				(map->coords)[j][i].pixel);
		}
		j++;
	}
	i = 0;
	while (i++ < (map->width - 1))
	{
		draw_line2(g_img, (map->coords)[j][i - 1].pixel, \
			(map->coords)[j][i].pixel);
	}
}

void	updata_data(t_input *data, keys_t key)
{
	if (key == MLX_KEY_UP)
		data->v_inc -= 10;
	if (key == MLX_KEY_DOWN)
		data->v_inc += 10;
	if (key == MLX_KEY_LEFT)
		data->u_inc -= 10;
	if (key == MLX_KEY_RIGHT)
		data->u_inc += 10;
	if (key == MLX_KEY_Q)
		data->x_angle += 1;
	if (key == MLX_KEY_W)
		data->x_angle -= 1;
	if (key == MLX_KEY_A)
		data->y_angle += 1;
	if (key == MLX_KEY_S)
		data->y_angle -= 1;
	if (key == MLX_KEY_Z)
		data->z_angle += 1;
	if (key == MLX_KEY_X)
		data->z_angle -= 1;
}

void	draw(mlx_image_t *g_img, t_map *map, t_input *data, keys_t key)
{
	updata_data(data, key);
	memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	update_coord(map, data);
	update_pixel(map, data);
	draw_map(g_img, map);
}

