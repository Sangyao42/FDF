/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:59:53 by sawang            #+#    #+#             */
/*   Updated: 2023/01/25 17:41:30 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../MLX42/include/MLX42/MLX42.h"
// #include <stdlib.h>
#include <stdio.h>
// #include <unistd.h>
// #include <memory.h>
#include "fdf.h"

// static void draw_rectangle(mlx_image_t	*g_img, int32_t x, int32_t y, int32_t z, uint32_t *u, uint32_t *v)
// {
// 	*u = u_axis(x, y);
// 	*v = v_ordinate(x, y, z);
// 	mlx_put_pixel(g_img, *u, *v, 0x0000FFFF);
// 	return ;
// }

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, g_img, 0, 0);

// 	/*** Testing Isometric Projection ***/
// 	int32_t x = 0;
// 	int32_t y = 1000;
// 	int32_t z = 0;
// 	// uint32_t u = u_axis(x, y);
// 	// uint16_t v = v_ordinate(x, y, z);
// 	t_pixel p = iso_proj(x, y, z);
// 	mlx_put_pixel(g_img, p.u, p.v, 0x00FF00FF);
// 	mlx_put_pixel(g_img, WIDTH / 2, HEIGHT / 2, 0xFF0000FF);
// 	/************************/

// 	/*** Testing draw line function ***/
// 	// uint32_t u_1 = u_axis(0,0);
// 	// uint32_t v_1= v_ordinate(0,0,0);
// 	// uint32_t u_2= u_axis(100,0);
// 	// uint32_t v_2= v_ordinate(100,0,0);
// 	// uint32_t u_3= u_axis(0,50);
// 	// uint32_t v_3= v_ordinate(0,50,0);
// 	// uint32_t u_4= u_axis(100,50);
// 	// uint32_t v_4= v_ordinate(100,50,0);
// 	// uint32_t u_5= u_axis(0,0);
// 	// uint32_t v_5= v_ordinate(0,0,30);
// 	// uint32_t u_6= u_axis(100,0);
// 	// uint32_t v_6= v_ordinate(100,0,30);
// 	// uint32_t u_7= u_axis(0,50);
// 	// uint32_t v_7= v_ordinate(0,50,30);
// 	// uint32_t u_8= u_axis(100,50);
// 	// uint32_t v_8= v_ordinate(100,50,30);
// 	t_pixel p1 = iso_proj(0,0,0);
// 	t_pixel p2 = iso_proj(100,0,0);
// 	t_pixel p3 = iso_proj(0,50,0);
// 	t_pixel p4 = iso_proj(100,50,0);
// 	t_pixel p5 = iso_proj(0,0,30);
// 	t_pixel p6 = iso_proj(100,0,30);
// 	t_pixel p7 = iso_proj(0,50,30);
// 	t_pixel p8 = iso_proj(100,50,30);
// 	// draw_rectangle(g_img, 0, 0, 0, u_1, v_1);
// 	// draw_rectangle(g_img, 10, 0, 0, u_2, v_2);
// 	// draw_rectangle(g_img, 0, 5, 0, u_3, v_3);
// 	// draw_rectangle(g_img, 10, 5, 0, u_4, v_4);
// 	// draw_rectangle(g_img, 0, 0, 1, u_5, v_5);
// 	// draw_rectangle(g_img, 10, 0, 1, u_6, v_6);
// 	// draw_rectangle(g_img, 0, 5, 1, u_7, v_7);
// 	// draw_rectangle(g_img, 10, 5, 1, u_8, v_8);
// 	draw_line(g_img, p1, p2);
// 	draw_line(g_img, p1, p3);
// 	draw_line(g_img, p2, p4);
// 	draw_line(g_img, p3, p4);
// 	draw_line(g_img, p5, p6);
// 	draw_line(g_img, p5, p7);
// 	draw_line(g_img, p6, p8);
// 	draw_line(g_img, p7, p8);
// 	draw_line(g_img, p1, p5);
// 	draw_line(g_img, p2, p6);
// 	draw_line(g_img, p3, p7);
// 	draw_line(g_img, p8, p4);
// 	/************************/

	/*** Testing draw map function ***/
	int		fd;
	int		height;
	int		width;
	t_coord	**map;

	width = 0;
	height = 0;
	fd = open("../test_maps/42.fdf", O_RDONLY);
	printf("fd: %d\n", fd);
	map = get_map(fd, &width, &height);
	// printf("hallo: height: %d\n", height);
	// printf("hallo: width: %d\n", width);
	close(fd);
	draw(g_img, &map, &width, &height);
	/************************/
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// /*** Testing Isometric Projection ***/
// int	main(void)
// {
// 	int				fd;
// 	int	j;
// 	int	i;
// 	int	height;
// 	int	width;
// 	t_coord			**map;

// 	width = 0;
// 	height = 0;
// 	fd = open("../test_maps/pyramide.fdf", O_RDONLY);
// 	printf("fd: %d\n", fd);
// 	map = get_map(fd, &width, &height);
// 	close(fd);
// 	printf("hallo: height: %d\n", height);
// 	printf("hallo: width: %d\n", width);
// 	// map =
// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			printf("%d,", map[i][j].z);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	// draw_map(map, &width, &height);
// 	free_map(map, height);
// 	system("leaks ./fdf_test.o");
// }
// 	/************************/
