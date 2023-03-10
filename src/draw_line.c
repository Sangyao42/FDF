/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:30:46 by sawang            #+#    #+#             */
/*   Updated: 2023/02/13 11:10:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_put_pixel(mlx_image_t *img, t_pixel pixel, uint32_t color)
{
	if (pixel.u < WIDTH && pixel.u > 0 && pixel.v > 0 && pixel.v < HEIGHT)
		mlx_put_pixel(img, pixel.u, pixel.v, color);
}

static void	drawlinelow(mlx_image_t *g_img, t_coord p1, t_coord p2, \
	t_delta delta)
{
	t_coord	start;

	start = p1;
	delta.yi = 1;
	if (delta.dy < 0)
	{
		delta.yi = -1;
		delta.dy = -delta.dy;
	}
	delta.p = (2 * delta.dy) - delta.dx;
	while (p1.pixel.u <= p2.pixel.u)
	{
		p1.color = get_color(p1, start, p2, delta);
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

static void	drawlinehigh(mlx_image_t *g_img, t_coord p1, t_coord p2, \
	t_delta delta)
{
	t_coord	start;

	start = p1;
	delta.xi = 1;
	if (delta.dx < 0)
	{
		delta.xi = -1;
		delta.dx = -delta.dx;
	}
	delta.p = (2 * delta.dx) - delta.dy;
	while (p1.pixel.v <= p2.pixel.v)
	{
		p1.color = get_color(p1, start, p2, delta);
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

void	draw_line(mlx_image_t *g_img, t_coord p1, t_coord p2, t_delta delta)
{
	delta.dx = p2.pixel.u - p1.pixel.u;
	delta.dy = p2.pixel.v - p1.pixel.v;
	if (abs(delta.dy) < abs(delta.dx))
	{
		if (p1.pixel.u > p2.pixel.u)
		{
			delta.dx *= -1;
			delta.dy *= -1;
			drawlinelow(g_img, p2, p1, delta);
		}
		else
			drawlinelow(g_img, p1, p2, delta);
	}
	else
	{
		if (p1.pixel.v > p2.pixel.v)
		{
			delta.dx *= -1;
			delta.dy *= -1;
			drawlinehigh(g_img, p2, p1, delta);
		}
		else
			drawlinehigh(g_img, p1, p2, delta);
	}
}
