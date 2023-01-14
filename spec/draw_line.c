/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:30:46 by sawang            #+#    #+#             */
/*   Updated: 2023/01/14 22:02:24 by sawang           ###   ########.fr       */
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

// 	dy = y2 - y1;
// 	dx = x2 - x1;
// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	p = (2 * dy) - dx;
// 	while (x1 <= x2)
// 	{
// 		mlx_put_pixel(g_img, x1, y1, 0x00FF00FF);
// 		x1++;
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else
// 		{
// 			p = p + 2 * dy - 2 * dx;
// 			y1 = y1 + yi;
// 		}
// 	}
// }

static void	drawlinelow(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
{
	int			dx;
	int			dy;
	int			yi;
	int			p;

	dy = p2.v - p1.v;
	dx = p2.u - p1.u;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = (2 * dy) - dx;
	while (p1.u <= p2.u)
	{
		mlx_put_pixel(g_img, p1.u, p1.v, 0x00FF00FF);
		p1.u++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			p1.v = p1.v + yi;
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

// 	dy = y2 - y1;
// 	dx = x2 - x1;
// 	xi = 1;
// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	p = (2 * dx) - dy;
// 	while (y1 <= y2)
// 	{
// 		mlx_put_pixel(g_img, x1, y1, 0x00FF00FF);
// 		y1++;
// 		if (p < 0)
// 			p = p + 2 * dx;
// 		else
// 		{
// 			p = p + 2 * dx - 2 * dy;
// 			x1 = x1 + xi;
// 		}
// 	}
// }

static void	drawlinehigh(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
{
	int			dx;
	int			dy;
	int			xi;
	int			p;

	dy = p2.v - p1.v;
	dx = p2.u - p1.u;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = (2 * dx) - dy;
	while (p1.v <= p2.v)
	{
		mlx_put_pixel(g_img, p1.u, p1.v, 0x00FF00FF);
		p1.v++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			p1.u = p1.u + xi;
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

void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
{
	if (abs(p2.v - p1.v) < abs(p2.u - p1.u))
	{
		if (p1.u > p2.u)
			drawlinelow(g_img, p2, p1);
		else
			drawlinelow(g_img, p1, p2);
	}
	else
	{
		if (p1.v > p2.v)
			drawlinehigh(g_img, p2, p1);
		else
			drawlinehigh(g_img, p1, p2);
	}
}

// uint32_t	get_diff(uint32_t a, uint32_t b)
// {
// 	if (a >= b)
// 		return (a - b);
// 	else
// 		return (b - a);
// }
