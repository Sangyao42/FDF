/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:59:53 by sawang            #+#    #+#             */
/*   Updated: 2023/01/07 17:38:32 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../MLX42/include/MLX42/MLX42.h"
#include "MLX42.h"
#include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <memory.h>
#define WIDTH 1920
#define HEIGHT 1080

static

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_put_pixel(g_img, WIDTH/2, HEIGHT/2, 0xFF000000);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}