/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:14:01 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 17:24:47 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_input	*init_data(t_input *data)
{
	data->z_inc = 1;
	data->scaler = 1;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->u_inc = WIDTH / 2;
	data->v_inc = HEIGHT / 2;
	return (data);
}

int	start_fdf(t_fdf *frame)
{
	(*frame).data = *init_data(&(*frame).data);
	(*frame).mlx = mlx_init(WIDTH, HEIGHT, "FDF_Sangyao", true);
	if (!(*frame).mlx)
		return (err_msg(5), EXIT_FAILURE);
	(*frame).g_img = mlx_new_image((*frame).mlx, WIDTH, HEIGHT);
	if (!(*frame).g_img)
		return (err_msg(6), mlx_terminate(frame->mlx), EXIT_FAILURE);
	mlx_image_to_window((*frame).mlx, (*frame).g_img, 0, 0);
	init_map(frame);
	draw(frame->g_img, &frame->map, &frame->data, 0);
	mlx_scroll_hook(frame->mlx, (mlx_scrollfunc) scroll_hook, frame);
	mlx_key_hook(frame->mlx, (mlx_keyfunc) key_hook, frame);
	mlx_loop_hook((*frame).mlx, (void (*)(void *))hook, frame);
	mlx_loop((*frame).mlx);
	quit(frame);
	return (EXIT_SUCCESS);
}
