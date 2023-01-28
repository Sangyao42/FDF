/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:14:01 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 21:00:09 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_fdf(t_fdf *frame)
{
	t_input *data;
	data = calloc(1, sizeof(t_input));
	(*frame).data = *data;
	printf("test: %d", data->u_inc);
	(*frame).mlx = mlx_init(WIDTH, HEIGHT, "FDF_Sangyao", true);
	if (!(*frame).mlx)
	{
		err_msg(5);
		exit(EXIT_FAILURE);
	}
	(*frame).g_img = mlx_new_image((*frame).mlx, WIDTH, HEIGHT);
	mlx_image_to_window((*frame).mlx, (*frame).g_img, 0, 0);
	frame->map.coords = center_map((*frame).map.coords, &(*frame).map.width, &(*frame).map.height);
	frame->map.coords = scale_map((*frame).map.coords, &(*frame).map.width, &(*frame).map.height);
	frame->map.coords = proj_map((*frame).map.coords, &(*frame).map.width, &(*frame).map.height);
	draw((*frame).g_img, &(*frame).map.coords, &(*frame).map.width, &(*frame).map.height, frame->data);
	mlx_loop_hook((*frame).mlx, &hook, &frame);
	mlx_loop((*frame).mlx);
	free_map((*frame).map.coords, (*frame).map.height);
	mlx_delete_image((*frame).mlx, (*frame).g_img);
	mlx_terminate((*frame).mlx);
	return (EXIT_SUCCESS);
}
