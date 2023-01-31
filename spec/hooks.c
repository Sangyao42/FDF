/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:47:29 by sawang            #+#    #+#             */
/*   Updated: 2023/01/31 13:25:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit(mlx_t *mlx, t_coord **map)
{
	free(map);
	mlx_close_window(mlx);
	exit(EXIT_SUCCESS);
}

void	hook(t_fdf *frame)
{
	// int i;
	// int j;

	// i = 0;
	// printf("before:\n");
	// while (i < frame->map.height)
	// {
	// 	j = 0;
	// 	while (j < frame->map.width)
	// 	{
	// 		printf(" %d,%.2d ", (frame->map.coords)[i][j].pixel.u, (frame->map.coords)[i][j].pixel.v);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	if (mlx_is_key_down(frame->mlx, MLX_KEY_ESCAPE))
		quit(frame->mlx, frame->map.coords);
	// frame->data = *(init_data(&(frame->data)));
	if (mlx_is_key_down(frame->mlx, MLX_KEY_UP))
		draw(frame->g_img, (frame->map.coords), &(frame->map.width), &(frame->map.height), &frame->data, MLX_KEY_UP);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_DOWN))
		draw(frame->g_img, (frame->map.coords), &(frame->map.width), &(frame->map.height), &frame->data, MLX_KEY_DOWN);

	if (mlx_is_key_down(frame->mlx, MLX_KEY_LEFT))
		draw(frame->g_img, (frame->map.coords), &(frame->map.width), &(frame->map.height), &frame->data, MLX_KEY_LEFT);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_RIGHT))
		draw(frame->g_img, (frame->map.coords), &(frame->map.width), &(frame->map.height), &frame->data, MLX_KEY_RIGHT);
	// memset(frame->g_img->pixels, 0 , frame->g_img->width * frame->g_img->height * sizeof(int));
	// i = 0;
	// printf("after: \n");
	// while (i < frame->map.height)
	// {
	// 	j = 0;
	// 	while (j < frame->map.width)
	// 	{
	// 		printf("%d,%.2d ", (frame->map.coords)[i][j].pixel.u, (frame->map.coords)[i][j].pixel.v);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}
