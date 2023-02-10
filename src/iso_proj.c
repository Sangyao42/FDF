/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:21:30 by sawang            #+#    #+#             */
/*   Updated: 2023/02/04 21:14:13 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso_proj(t_coord **map, int j, int i)
{
	int32_t	u_o;
	int32_t	v_o;

	u_o = WIDTH / 2;
	v_o = HEIGHT / 2;
	map[j][i].pixel.u = u_o + roundf((map[j][i].point.o - map[j][i].point.p) \
		* cos(0.46365));
	map[j][i].pixel.v = v_o + roundf((map[j][i].point.o + map[j][i].point.p) \
		* sin(0.46365) - map[j][i].point.q);
}

void	proj_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			iso_proj(map->coords, j, i);
			i++;
		}
		j++;
	}
}
