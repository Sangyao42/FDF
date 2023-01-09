/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:30:46 by sawang            #+#    #+#             */
/*   Updated: 2023/01/09 20:37:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//draw line when 0 < |slope| < 1
// static void	drawlinelow(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
// {
// 	int			dx;
// 	int			dy;
// 	int			yi;
// 	int			p;
// 	uint32_t	x;
// 	uint32_t	y;

// 	x = x1;
// 	y = y1;
// 	dy = y2 - y1;
// 	dx = x2 - x1;
// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	p = (2 * dy) - dx;
// 	while (x <= x2)
// 	{
// 		mlx_put_pixel(g_img, x, y, 0x00FF00FF);
// 		x++;
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else
// 		{
// 			p = p + 2 * dy - 2 * dx;
// 			y = y + yi;
// 		}
// 	}
// }

static void	drawlinelow(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	int			dx;
	int			dy;
	int			yi;
	int			p;

	dy = y2 - y1;
	dx = x2 - x1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = (2 * dy) - dx;
	while (x1 <= x2)
	{
		mlx_put_pixel(g_img, x1, y1, 0x00FF00FF);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y1 = y1 + yi;
		}
	}
}

//draw line when |slope| > 1
// static void	drawlinehigh(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
// {
// 	int			dx;
// 	int			dy;
// 	int			xi;
// 	int			p;
// 	uint32_t	x;
// 	uint32_t	y;

// 	x = x1;
// 	y = y1;
// 	dy = y2 - y1;
// 	dx = x2 - x1;
// 	xi = 1;
// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	p = (2 * dx) - dy;
// 	while (y <= y2)
// 	{
// 		mlx_put_pixel(g_img, x, y, 0x00FF00FF);
// 		y++;
// 		if (p < 0)
// 			p = p + 2 * dx;
// 		else
// 		{
// 			p = p + 2 * dx - 2 * dy;
// 			x = x + xi;
// 		}
// 	}
// }

static void	drawlinehigh(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	int			dx;
	int			dy;
	int			xi;
	int			p;

	dy = y2 - y1;
	dx = x2 - x1;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = (2 * dx) - dy;
	while (y1 <= y2)
	{
		mlx_put_pixel(g_img, x1, y1, 0x00FF00FF);
		y1++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			x1 = x1 + xi;
		}
	}
}

//check the draw direction
// void	draw_line(mlx_image_t *g_img, int32_t x1, int32_t y1, int32_t x2, int32_t y2)
// {
// 	if (abs(y2 - y1) < abs(x2 - x1))
// 	{
// 		if (x1 > x2)
// 			drawlinelow(g_img, x2, y2, x1, y1);
// 		else
// 			drawlinelow(g_img, x1, y1, x2, y2);
// 	}
// 	else
// 	{
// 		if (y1 > y2)
// 			drawlinehigh(g_img, x2, y2, x1, y1);
// 		else
// 			drawlinehigh(g_img, x1, y1, x2, y2);
// 	}
// }

void	draw_line(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	if ((y2 - y1) < (x2 - x1))
	{
		if (x1 > x2)
			drawlinelow(g_img, x2, y2, x1, y1);
		else
			drawlinelow(g_img, x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2)
			drawlinehigh(g_img, x2, y2, x1, y1);
		else
			drawlinehigh(g_img, x1, y1, x2, y2);
	}
}
