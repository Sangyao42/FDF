/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:53:28 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 18:59:25 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *m_point, float gamma)
{
	float	prev_p;
	float	prev_q;

	prev_p = m_point->p;
	prev_q = m_point->q;
	m_point->p = prev_p * cos(gamma) + prev_q * sin(gamma);
	m_point->q = -prev_p * sin(gamma) + prev_q * cos(gamma);
}

static void	rotate_y(t_point *m_point, float beta)
{
	float	prev_o;
	float	prev_q;

	prev_o = m_point->o;
	prev_q = m_point->q;
	m_point->o = prev_o * cos(beta) - prev_q * sin(beta);
	m_point->q = prev_o * sin(beta) + prev_q * cos(beta);
}

static void	rotate_z(t_point *m_point, float alpha)
{
	float	prev_o;
	float	prev_p;

	prev_o = m_point->o;
	prev_p = m_point->p;
	m_point->o = prev_o * cos(alpha) + prev_p * sin(alpha);
	m_point->p = -prev_o * sin(alpha) + prev_p * cos(alpha);
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
			rotate_x(&(map->coords)[j][i].point_modified, \
				data->x_angle * PI / 180);
			rotate_y(&(map->coords)[j][i].point_modified, \
				data->y_angle * PI / 180);
			rotate_z(&(map->coords)[j][i].point_modified, \
				data->z_angle * PI / 180);
			i++;
		}
		j++;
	}
}
