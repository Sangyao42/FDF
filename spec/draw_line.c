/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:30:46 by sawang            #+#    #+#             */
/*   Updated: 2023/02/08 22:29:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_put_pixel(mlx_image_t *img, t_pixel pixel, uint32_t color)
{
	if (pixel.u < WIDTH && pixel.u > 0 && pixel.v > 0 && pixel.v < HEIGHT)
		mlx_put_pixel(img, pixel.u, pixel.v, color);
}

// static void	drawlinelow(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
// {
// 	int			dx;
// 	int			dy;
// 	int			yi;
// 	int			p;

// 	dy = p2.v - p1.v;
// 	dx = p2.u - p1.u;
// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	p = (2 * dy) - dx;
// 	while (p1.u <= p2.u)
// 	{
// 		fdf_put_pixel(g_img, p1, p1.color);
// 		p1.u++;
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else
// 		{
// 			p = p + 2 * dy - 2 * dx;
// 			p1.v = p1.v + yi;
// 		}
// 	}
// }

// static void	drawlinehigh(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
// {
// 	int			dx;
// 	int			dy;
// 	int			xi;
// 	int			p;

// 	dy = p2.v - p1.v;
// 	dx = p2.u - p1.u;
// 	xi = 1;
// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	p = (2 * dx) - dy;
// 	while (p1.v <= p2.v)
// 	{
// 		fdf_put_pixel(g_img, p1, p1.color);
// 		p1.v++;
// 		if (p < 0)
// 			p = p + 2 * dx;
// 		else
// 		{
// 			p = p + 2 * dx - 2 * dy;
// 			p1.u = p1.u + xi;
// 		}
// 	}
// }

// void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2)
// {
// 	if (abs(p2.v - p1.v) < abs(p2.u - p1.u))
// 	{
// 		if (p1.u > p2.u)
// 			drawlinelow(g_img, p2, p1);
// 		else
// 			drawlinelow(g_img, p1, p2);
// 	}
// 	else
// 	{
// 		if (p1.v > p2.v)
// 			drawlinehigh(g_img, p2, p1);
// 		else
// 			drawlinehigh(g_img, p1, p2);
// 	}
// }

static void	drawlinelow(mlx_image_t *g_img, t_coord p1, t_coord p2, int sign)
{
	t_delta		delta;
	t_coord		start;

	start = p1;
	delta.dy = p2.pixel.v - p1.pixel.v;
	delta.dx = p2.pixel.u - p1.pixel.u;
	delta.yi = 1;
	if (delta.dy < 0)
	{
		delta.yi = -1;
		delta.dy = -delta.dy;
	}
	delta.p = (2 * delta.dy) - delta.dx;
	while (p1.pixel.u <= p2.pixel.u)
	{
		p1.color = get_color(p1, start, p2, sign);
		fdf_put_pixel(g_img, p1.pixel, p1.color);
		p1.pixel.u++;
		if (delta.p < 0)
			delta.p = delta.p + 2 * delta.dy;
		else
		{
			delta.p = delta.p + 2 * delta.dy - 2 * delta.dx;
			p1.pixel.v = p1.pixel.v + delta.yi;
		}
	}
}

static void	drawlinehigh(mlx_image_t *g_img, t_coord p1, t_coord p2, int sign)
{
	t_delta		delta;
	t_coord		start;

	start = p1;
	delta.dy = p2.pixel.v - p1.pixel.v;
	delta.dx = p2.pixel.u - p1.pixel.u;
	delta.xi = 1;
	if (delta.dx < 0)
	{
		delta.xi = -1;
		delta.dx = -delta.dx;
	}
	delta.p = (2 * delta.dx) - delta.dy;
	while (p1.pixel.v <= p2.pixel.v)
	{
		p1.color = get_color(p1, start, p2, sign);
		fdf_put_pixel(g_img, p1.pixel, p1.color);
		p1.pixel.v++;
		if (delta.p < 0)
			delta.p = delta.p + 2 * delta.dx;
		else
		{
			delta.p = delta.p + 2 * delta.dx - 2 * delta.dy;
			p1.pixel.u = p1.pixel.u + delta.xi;
		}
	}
}

void	draw_line(mlx_image_t *g_img, t_coord p1, t_coord p2)
{
	if (abs(p2.pixel.v - p1.pixel.v) < abs(p2.pixel.u - p1.pixel.u))
	{
		if (p1.pixel.u > p2.pixel.u)
			drawlinelow(g_img, p2, p1, 1);
		else
			drawlinelow(g_img, p1, p2, -1);
	}
	else
	{
		if (p1.pixel.v > p2.pixel.v)
			drawlinehigh(g_img, p2, p1, 1);
		else
			drawlinehigh(g_img, p1, p2, -1);
	}
}
