/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/02/01 21:43:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**scale_map(t_coord **map, int *width, int *height, t_input *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			map[j][i].mid_pixel_modified.o = map[j][i].mid_pixel.o * data->scaler;
			map[j][i].mid_pixel_modified.p = map[j][i].mid_pixel.p * data->scaler;
			map[j][i].mid_pixel_modified.q = map[j][i].mid_pixel.q * data->scaler;
			i++;
		}
		j++;
	}
	return (map);
}

// t_coord	**translate_map(t_coord **map, int *width, int *height, t_input *data)
// {
// 	int		i;
// 	int		j;

// 	j = 0;
// 	while (j < *height)
// 	{
// 		i = 0;
// 		while (i < *width)
// 		{
// 			map[j][i].pixel.u += data->u_inc;
// 			map[j][i].pixel.v += data->v_inc;
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (map);
// }

t_pixel	update_pixel(t_mid_pixel point, t_input data)
{
	t_pixel	pixel;
	int32_t	u_o;
	int32_t	v_o;

	u_o = WIDTH / 2;
	v_o = HEIGHT / 2;
	pixel.u = u_o + roundf((point.o - point.p) * cos(0.46365));
	pixel.v = v_o + roundf((point.o + point.p) * sin(0.46365) - point.q);
	pixel.u += data.u_inc;
	pixel.v += data.v_inc;
	return (pixel);
}

void	draw_map(mlx_image_t *g_img, t_coord **map, int *width, int *height, t_input data)
{
	int	i;
	int	j;

	j = 0;
	while (j < ((*height) - 1))
	{
		i = 0;
		while (i < ((*width) - 1))
		{
			draw_line(g_img, update_pixel(map[j][i].mid_pixel_modified, data), update_pixel(map[j][i + 1].mid_pixel_modified, data));
			// draw_line(g_img, map[j][i].pixel, map[j + 1][i].pixel);
			draw_line(g_img, update_pixel(map[j][i].mid_pixel_modified, data), update_pixel(map[j + 1][i].mid_pixel_modified, data));
			i++;
			// draw_line(g_img, map[j + 1][i].pixel, map[j][i].pixel);
			draw_line(g_img, update_pixel(map[j + 1][i].mid_pixel_modified, data), update_pixel(map[j][i].mid_pixel_modified, data));
		}
		j++;
	}
	i = 0;
	while (i < (*width - 1))
	{
		// draw_line(g_img, map[j][i].pixel, map[j][i + 1].pixel);
		draw_line(g_img, update_pixel(map[j][i].mid_pixel_modified, data), update_pixel(map[j][i + 1].mid_pixel_modified, data));
		i++;
	}
	// int	i;
	// int	j;

	// j = 0;
	// while (j < ((*height) - 1))
	// {
	// 	i = 0;
	// 	while (i < ((*width) - 1))
	// 	{
	// 		draw_line(g_img, map[j][i].pixel, map[j][i + 1].pixel);
	// 		draw_line(g_img, map[j][i].pixel, map[j + 1][i].pixel);
	// 		i++;
	// 		draw_line(g_img, map[j + 1][i].pixel, map[j][i].pixel);
	// 	}
	// 	j++;
	// }
	// i = 0;
	// while (i < (*width - 1))
	// {
	// 	draw_line(g_img, map[j][i].pixel, map[j][i + 1].pixel);
	// 	i++;
	// }
}

t_coord	**draw(mlx_image_t *g_img, t_coord **map, int *width, int *height, t_input *data)
{
	// int	i;
	// int	j;


	// t_coord **points = *map;
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
	memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	map =  update_coord(map, width, height, data);
	// *map = center_map(*map, width, height);
	// *map = rotate_map(*map, width, height);
	// *map = scale_map(*map, width, height);
	// map = proj_map(map, width, height);

	// map = translate_map(map, width, height, data);
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
	// copy(map, *width, *height);
	draw_map(g_img, map, width, height, *data);
	return(map);
}

t_coord	**update_coord(t_coord **map, int *width, int *height, t_input *data)
{
	// int		i;
	// int		j;

	// update_key_data(data, key);
	// update_scroll_data(data, ydelta);
	map = scale_map(map, width, height, data);
	map = rotate_map(map, width, height, data);
	// j = 0;
	// while (j < *height)
	// {
	// 	i = 0;
	// 	while (i < *width)
	// 	{
	// 		// map[j][i].mid_ pixel.o = map[j][i].mid_pixel.o * data->scaler;
	// 		// map[j][i].mid_pixel.p = map[j][i].mid_pixel.p * data->scaler;
	// 		// map[j][i].mid_pixel.q = (map[j][i].mid_pixel.q + data->z_inc) * data->scaler;
	// 		i++;
	// 	}
	// 	j++;
	// }
	return (map);
}

// t_input	*update_key_data(t_input *data, keys_t key)
// {
// 	if (key == MLX_KEY_Z)
// 		data->z_inc += 10;
// 	if (key == MLX_KEY_X)
// 		data->z_inc -= 10;
// 	if (key == MLX_KEY_Q)
// 		data->x_angle += 5;
// 	if (key == MLX_KEY_E)
// 		data->x_angle += -5;
// 	if (key == MLX_KEY_A)
// 		data->y_angle += 5;
// 	if (key == MLX_KEY_D)
// 		data->y_angle += -5;
// 	if (key == MLX_KEY_W)
// 		data->z_angle += 5;
// 	if (key == MLX_KEY_S)
// 		data->z_angle += -5;
// 	if (key == MLX_KEY_RIGHT)
// 		data->u_inc += 10;
// 	if (key == MLX_KEY_LEFT)
// 		data->u_inc -= 10;
// 	if (key == MLX_KEY_DOWN)
// 		data->v_inc += 10;
// 	if (key == MLX_KEY_UP)
// 		data->v_inc -= 10;
// 	return (data);
// }
