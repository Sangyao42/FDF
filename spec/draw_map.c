/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/01/31 17:21:45 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_coord	**translate_map(t_coord **map, int *width, int *height, t_input *data)
// {
// 	int		i;
// 	int		j;

// 	j = 0;
// 	printf("\nPrev: map00: %d, %d\n", (map[0][0].pixel.u, map[0][0].pixel.v));
// 	printf("map00: %d, %d\n\n",  data->u_inc,  data->v_inc);
// 	while (j < *height)
// 	{
// 		i = 0;
// 		while (i < *width)
// 		{
// 			map[j][i].mid_pixel.o += data->u_inc;
// 			map[j][i].mid_pixel.p += data->v_inc;
// 			// map[j][i].pixel.u += data->u_inc;
// 			// map[j][i].pixel.v += data->v_inc;
// 			i++;
// 		}
// 		j++;
// 	}
// 	printf("\nmap00: %d, %d\n", map[0][0].pixel.u, map[0][0].pixel.v);
// 	printf("map00: %d, %d\n",  data->u_inc,  data->v_inc);
// 	return (map);
// }

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

t_coord	**draw(mlx_image_t *g_img, t_coord **map, int *width, int *height, t_input *data, keys_t key)
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
	// 		printf("%d,%.2d ", map[i][j].pixel.u, map[i][j].pixel.v);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	map =  update_coord(map, width, height, data, key);
	// *map = center_map(*map, width, height);
	// *map = rotate_map(*map, width, height);
	// *map = scale_map(*map, width, height);
	// *map = proj_map(*map, width, height);
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
	draw_map(g_img, map, width, height);
	return(map);
}

t_coord	**update_coord(t_coord **map, int *width, int *height, t_input *data, keys_t key)
{
	int		i;
	int		j;

	update_data(data, key);
	// printf("tst_u: %d\n", data->u_inc);
	// printf("tst_v: %d\n", data->v_inc);
	// j = 0;
	// while (j < *height)
	// {
	// 	i = 0;
	// 	while (i < *width)
	// 	{
	// 		map[j][i].mid_pixel.o = map[j][i].mid_pixel.o * data->scaler;
	// 		map[j][i].mid_pixel.p = map[j][i].mid_pixel.p * data->scaler;
	// 		map[j][i].mid_pixel.q = (map[j][i].mid_pixel.q + data->z_inc) * data->scaler;
	// 		i++;
	// 	}
	// 	j++;
	// }
	// map = rotate_map(map, width, height, *data);
	// map = proj_map(map, width, height);
	map = translate_map(map, width, height, data);
	return (map);
}

t_input	*update_data(t_input *data, keys_t key)
{
	if (key == MLX_KEY_Z)
		data->z_inc = 20;
	if (key == MLX_KEY_X)
		data->z_inc = -20;
	if (key == MLX_KEY_KP_ADD)
		data->scaler = 2;
	if (key == MLX_KEY_KP_SUBTRACT)
		data->scaler = 0.5;
	if (key == MLX_KEY_Q)
		data->x_angle = 5;
	if (key == MLX_KEY_E)
		data->x_angle = -5;
	if (key == MLX_KEY_A)
		data->y_angle = 5;
	if (key == MLX_KEY_D)
		data->y_angle = -5;
	if (key == MLX_KEY_W)
		data->z_angle = 5;
	if (key == MLX_KEY_S)
		data->z_angle = -5;
	if (key == MLX_KEY_RIGHT)
		data->u_inc = 10;
	if (key == MLX_KEY_LEFT)
		data->u_inc = -15;
	if (key == MLX_KEY_DOWN)
		data->v_inc = 10;
	if (key == MLX_KEY_UP)
		data->v_inc = -15;
	return (data);
}
