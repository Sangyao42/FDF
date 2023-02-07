/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:01:00 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 22:20:40 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
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

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	percentage = percent(start.q, end.q, current.q);
	red = get_light((start.color >> 16) & 0xFF, \
		(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, \
		(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, \
		end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue | 0xFF);
}
