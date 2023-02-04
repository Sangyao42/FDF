/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:47:29 by sawang            #+#    #+#             */
/*   Updated: 2023/02/04 21:41:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit(mlx_t *mlx, t_coord **map, int *height)
{
	free_map(map, *height);
	mlx_close_window(mlx);
	exit(EXIT_SUCCESS);
}

void	hook(t_fdf *frame)
{
	if (mlx_is_key_down(frame->mlx, MLX_KEY_ESCAPE))
		quit(frame->mlx, frame->map.coords, &frame->map.height);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_UP))
		frame->data.v_inc -= 10;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_DOWN))
		frame->data.v_inc += 10;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_LEFT))
		frame->data.u_inc -= 10;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_RIGHT))
		frame->data.u_inc += 10;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_Q))
		frame->data.x_angle += 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_W))
		frame->data.x_angle -= 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_A))
		frame->data.y_angle += 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_S))
		frame->data.y_angle -= 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_Z))
		frame->data.z_angle += 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_X))
		frame->data.z_angle -= 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_P))
		frame->data.z_inc += 1;
	if (mlx_is_key_down(frame->mlx, MLX_KEY_O))
		frame->data.z_inc -= 1;
	printf("x_angle: %d\n", frame->data.x_angle);
	printf("y_angle: %d\n", frame->data.y_angle);
	printf("z_angle: %d\n", frame->data.z_angle);
	draw(frame->g_img, &frame->map, &frame->data);
}

void	scroll_hook(double xdelta, double ydelta, t_fdf *frame)
{
	if (ydelta > 0)
	{
		frame->data.scaler += 1;
		printf("scaler:%f\n", frame->data.scaler);
	}
	if (ydelta < 0)
	{
		frame->data.scaler -= 1;
		printf("scaler:%f\n", frame->data.scaler);
		if (frame->data.scaler < 1)
			frame->data.scaler = 1;
	}
	if (xdelta > 0)
		frame->data.scaler += 1;
	if (xdelta < 0)
	{
		frame->data.scaler -= 1;
		if (frame->data.scaler < 1)
			frame->data.scaler = 1;
	}
	draw(frame->g_img, &frame->map, &frame->data);
}

void	key_hook(mlx_key_data_t keydata, t_fdf *frame)
{
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == 2)
	{
		frame->data.x_angle += 5;
		frame->data.y_angle += 5;
		frame->data.z_angle += 5;
	}
	draw(frame->g_img, &frame->map, &frame->data);
}
