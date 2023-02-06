/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:14:01 by sawang            #+#    #+#             */
/*   Updated: 2023/02/06 19:53:00 by sawang           ###   ########.fr       */
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
	printf("test: %d", frame->data.u_inc);
	(*frame).mlx = mlx_init(WIDTH, HEIGHT, "FDF_Sangyao", true);
	if (!(*frame).mlx)
	{
		err_msg(5);
		return (EXIT_FAILURE);
	}
	(*frame).g_img = mlx_new_image((*frame).mlx, WIDTH, HEIGHT);
	mlx_image_to_window((*frame).mlx, (*frame).g_img, 0, 0);
	center_map(&(frame->map));
	proj_map(&(frame->map));
	frame->data.scaler = get_scale_rate(&(frame->map));
	draw(frame->g_img, &frame->map, &frame->data, 0);
	mlx_scroll_hook(frame->mlx, (mlx_scrollfunc) scroll_hook, frame);
	mlx_key_hook(frame->mlx, (mlx_keyfunc) key_hook, frame);
	mlx_loop_hook((*frame).mlx, (void (*)(void *))hook, frame);
	mlx_loop((*frame).mlx);
	free_map((*frame).map.coords, (*frame).map.height);
	mlx_delete_image((*frame).mlx, (*frame).g_img);
	mlx_terminate((*frame).mlx);
	return (EXIT_SUCCESS);
}
