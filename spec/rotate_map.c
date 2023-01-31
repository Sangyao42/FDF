
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:53:28 by sawang            #+#    #+#             */
/*   Updated: 2023/01/30 18:14:29 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_mid_pixel *m_pixel, float gamma)
{
	float	prev_p;
	float	prev_q;

	prev_p = m_pixel->p;
	prev_q = m_pixel->q;
	m_pixel->p = prev_p * cos(gamma) + prev_q * sin(gamma);
	m_pixel->q = -prev_p * sin(gamma) + prev_q * cos(gamma);
}

static void	rotate_y(t_mid_pixel *m_pixel, float beta)
{
	float	prev_o;
	float	prev_q;

	prev_o = m_pixel->o;
	prev_q = m_pixel->q;
	m_pixel->o = prev_o * cos(beta) - prev_q * sin(beta);
	m_pixel->q = prev_o * sin(beta) + prev_q * cos(beta);
}

static void	rotate_z(t_mid_pixel *m_pixel, float alpha)
{
	float	prev_o;
	float	prev_p;

	prev_o = m_pixel->o;
	prev_p = m_pixel->p;
	m_pixel->o = prev_o * cos(alpha) + prev_p * sin(alpha);
	m_pixel->p = -prev_o * sin(alpha) + prev_p * cos(alpha);
}

t_coord	**rotate_map(t_coord **map, int *width, int *height, t_input data)
{
	int		i;
	int		j;
	int		x_angle;
	int		y_angle;
	int		z_angle;

	// x_angle = 0;
	// y_angle = 0;
	// z_angle = 0;
	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			rotate_x(&(map[j][i].mid_pixel), data.x_angle * PI / 180);
			rotate_y(&(map[j][i].mid_pixel), data.y_angle * PI / 180);
			rotate_z(&(map[j][i].mid_pixel), data.z_angle * PI / 180);
			i++;
		}
		j++;
	}
	return (map);
}
