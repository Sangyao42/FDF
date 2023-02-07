/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:06:28 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 22:23:04 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	get_max_z(t_map map)
{
	int	z_max;
	int	i;
	int	j;
	int	i_z;
	int	j_z;

	z_max = 0;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.coords[j][i].point.q > z_max)
			{
				z_max = map.coords[j][i].point.q;
				j_z = j;
				i_z = i;
			}
			i++;
		}
		j++;
	}
	map.coords[j_z][i_z].point.color = 0x00FF00FF;
	return (map.coords[j_z][i_z].point);
}

t_point	get_min_z(t_map map)
{
	int	z_min;
	int	i;
	int	j;
	int	i_z;
	int	j_z;

	z_min = 0;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.coords[j][i].point.q < z_min)
			{
				z_min = map.coords[j][i].point.q;
				j_z = j;
				i_z = i;
			}
			i++;
		}
		j++;
	}
	map.coords[j_z][i_z].point.color = 0xFF0000FF;
	return (map.coords[j_z][i_z].point);
}

t_point	set_base_color(t_map *map)
{
	int		i;
	int		j;
	int		i_z;
	int		j_z;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if ((map->coords)[j][i].point.q == 0)
			{
				(map->coords)[j][i].point.color = 0xFFFFFFFF;
				j_z = j;
				i_z = i;
			}
			i++;
		}
		j++;
	}
	return (map->coords[j_z][i_z].point);
}
