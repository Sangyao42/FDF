/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:06:28 by sawang            #+#    #+#             */
/*   Updated: 2023/02/10 16:43:56 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	get_mid_z(t_map map)
{
	t_coord	z_mid;
	int		i;
	int		j;

	z_mid = map.coords[0][0];
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (fabs(map.coords[j][i].point.q) < fabs(z_mid.point.q))
				z_mid = map.coords[j][i];
			i++;
		}
		j++;
	}
	return (z_mid);
}

t_coord	get_max_z(t_map map)
{
	t_coord	z_max;
	int		i;
	int		j;

	z_max = get_mid_z(map);
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if ((map.coords[j][i].point.q) > z_max.point.q)
				z_max = map.coords[j][i];
			i++;
		}
		j++;
	}
	z_max.color = 0xFFFF00FF;
	return (z_max);
}

t_coord	get_min_z(t_map map)
{
	t_coord	z_min;
	int		i;
	int		j;

	z_min = get_mid_z(map);
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if ((map.coords[j][i].point.q) < z_min.point.q)
				z_min = map.coords[j][i];
			i++;
		}
		j++;
	}
	z_min.color = 0x00FFFFFF;
	return (z_min);
}

t_coord	set_base_color(t_map *map)
{
	int		i;
	int		j;
	int		j_z;
	int		i_z;
	t_coord	z_mid;

	z_mid = get_mid_z(*map);
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if ((map->coords)[j][i].point.q == z_mid.point.q)
			{
				(map->coords)[j][i].color = 0xFFFFFFFF;
				j_z = j;
				i_z = i;
			}
			i++;
		}
		j++;
	}
	return (map->coords[j_z][i_z]);
}
