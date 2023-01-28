/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:47:29 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 21:58:13 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(void *param)
{
	t_fdf	**frame;

	frame = (t_fdf **)param;
	if (mlx_is_key_down((*frame)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window((*frame)->mlx);
	// (*frame)->data.u_inc = 0;
	// (*frame)->data.v_inc = 0;
	if (mlx_is_key_down((*frame)->mlx, MLX_KEY_UP))
	{
		(*frame)->data.v_inc = -10;
	}
	if (mlx_is_key_down((*frame)->mlx, MLX_KEY_DOWN))
		(*frame)->data.v_inc = 10;
	if (mlx_is_key_down((*frame)->mlx, MLX_KEY_LEFT))
	{
		(*frame)->data.u_inc -= 1000;
	}
	if (mlx_is_key_down((*frame)->mlx, MLX_KEY_RIGHT))
		(*frame)->data.u_inc = 10;
	printf("frame data: %d\n", (*frame)->data.u_inc);
	// memset((*frame)->g_img->pixels, 0 , (*frame)->g_img->width * (*frame)->g_img->height * sizeof(int));
	draw((*frame)->g_img, &((*frame)->map.coords), &((*frame)->map.width), &((*frame)->map.height), (*frame)->data);
}

// bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);
