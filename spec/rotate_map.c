/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:53:28 by sawang            #+#    #+#             */
/*   Updated: 2023/02/04 21:42:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mid_pixel	rotate_x(t_mid_pixel m_pixel, float gamma)
{
	float	prev_p;
	float	prev_q;

	prev_p = m_pixel.p;
	prev_q = m_pixel.q;
	m_pixel.p = prev_p * cos(gamma) + prev_q * sin(gamma);
	m_pixel.q = -prev_p * sin(gamma) + prev_q * cos(gamma);
	return (m_pixel);
}

t_mid_pixel	rotate_y(t_mid_pixel m_pixel, float beta)
{
	float	prev_o;
	float	prev_q;

	prev_o = m_pixel.o;
	prev_q = m_pixel.q;
	m_pixel.o = prev_o * cos(beta) - prev_q * sin(beta);
	m_pixel.q = prev_o * sin(beta) + prev_q * cos(beta);
	return (m_pixel);
}

t_mid_pixel	rotate_z(t_mid_pixel m_pixel, float alpha)
{
	float	prev_o;
	float	prev_p;

	prev_o = m_pixel.o;
	prev_p = m_pixel.p;
	m_pixel.o = prev_o * cos(alpha) + prev_p * sin(alpha);
	m_pixel.p = -prev_o * sin(alpha) + prev_p * cos(alpha);
	return (m_pixel);
}

void	rotate_map(t_map *map, t_input *data)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			(map->coords)[j][i].point_modified = rotate_x(\
				(map->coords)[j][i].point_modified, data->x_angle * PI / 180);
			(map->coords)[j][i].point_modified = rotate_y(\
				(map->coords)[j][i].point_modified, data->y_angle * PI / 180);
			(map->coords)[j][i].point_modified = rotate_z(\
				(map->coords)[j][i].point_modified, data->z_angle * PI / 180);
			i++;
		}
		j++;
	}
}
