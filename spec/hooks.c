/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:47:29 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 17:05:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(t_fdf *frame)
{
	if (mlx_is_key_down(frame->mlx, MLX_KEY_ESCAPE))
		quit(frame);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_UP))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_UP);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_DOWN))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_DOWN);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_LEFT))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_LEFT);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_RIGHT))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_RIGHT);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_Q))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_Q);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_W))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_W);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_A))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_A);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_S))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_S);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_Z))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_Z);
	if (mlx_is_key_down(frame->mlx, MLX_KEY_X))
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_X);
}

void	scroll_hook(double xdelta, double ydelta, t_fdf *frame)
{
	if (ydelta > 0)
	{
		frame->data.scaler += 1;
	}
	if (ydelta < 0)
	{
		frame->data.scaler -= 1;
		if (frame->data.scaler < 1)
			frame->data.scaler = 1;
	}
	if (xdelta > 0)
		frame->data.scaler += 7;
	if (xdelta < 0)
	{
		frame->data.scaler -= 7;
		if (frame->data.scaler < 1)
			frame->data.scaler = 1;
	}
	draw(frame->g_img, &frame->map, &frame->data, 0);
}

void	key_hook(mlx_key_data_t keydata, t_fdf *frame)
{
	if (keydata.key == MLX_KEY_KP_ADD)
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_KP_ADD);
	if (keydata.key == MLX_KEY_KP_SUBTRACT)
		draw(frame->g_img, &frame->map, &frame->data, MLX_KEY_KP_SUBTRACT);
	if (keydata.key == MLX_KEY_I)
		draw_parallel(frame->g_img, &frame->map, &frame->data, MLX_KEY_I);
	if (keydata.key == MLX_KEY_O)
		draw_parallel(frame->g_img, &frame->map, &frame->data, MLX_KEY_O);
	if (keydata.key == MLX_KEY_P)
		draw_parallel(frame->g_img, &frame->map, &frame->data, MLX_KEY_P);
}
