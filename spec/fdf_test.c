/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:59:53 by sawang            #+#    #+#             */
/*   Updated: 2023/01/07 19:00:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../MLX42/include/MLX42/MLX42.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <memory.h>
#include "fdf.h"


int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, g_img, 0, 0);

	/*** Testing Isometric Projection ***/
	int32_t x = 0;
	int32_t y = 0;
	int32_t z = 0;
	uint32_t u = u_axis(x, y, z);
	uint16_t v = v_ordinate(x, y, z);
	mlx_put_pixel(g_img, u, v, 0x00FF00FF);
	// mlx_put_pixel(g_img, WIDTH / 2, HEIGHT / 2, 0xFF0000FF);
	/************************/
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
