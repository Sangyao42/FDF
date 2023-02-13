/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:01:00 by sawang            #+#    #+#             */
/*   Updated: 2023/02/13 10:56:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(float start, float end, float current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

static int	get_light(int start_color, int end_color, double percentage)
{
	return ((int)((1 - percentage) * start_color + percentage * end_color));
}

int	set_color(t_coord current, t_coord start, t_coord end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	percentage = percent(start.point.q, end.point.q, current.point.q);
	red = get_light((start.color >> 24) & 0xFF, \
		(end.color >> 24) & 0xFF, percentage);
	green = get_light((start.color >> 16) & 0xFF, \
		(end.color >> 16) & 0xFF, percentage);
	blue = get_light(start.color >> 8 & 0xFF, \
		(end.color >> 8) & 0xFF, percentage);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}

int	get_color(t_coord current, t_coord start, t_coord end, t_delta delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.dx > delta.dy)
		percentage = percent(start.pixel.u, end.pixel.u, current.pixel.u);
	else
		percentage = percent(start.pixel.v, end.pixel.v, current.pixel.v);
	red = get_light((start.color >> 24) & 0xFF, \
		(end.color >> 24) & 0xFF, percentage);
	green = get_light((start.color >> 16) & 0xFF, \
		(end.color >> 16) & 0xFF, percentage);
	blue = get_light((start.color >> 8) & 0xFF, \
		(end.color >> 8) & 0xFF, percentage);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}
