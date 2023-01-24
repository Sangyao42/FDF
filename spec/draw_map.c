/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:40:33 by sawang            #+#    #+#             */
/*   Updated: 2023/01/24 19:55:47 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord **map_centering(t_coord ***map, int *width, int *height)
{
	int	j;
	int	i;
	float	center_x;
	float	center_y;

	center_x = (*width) / 2;
	center_x = (*height) / 2;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			map[i][j]->mid_pixel.o = i - center_x;
			map[i][j]->mid_pixel.p = j - center_y;
			map[i][j]->mid_pixel.q = map[i][j]->z;
			i++;
		}
		j++;
	}
	return (map);
}


t_coord **map_scaling(t_coord ***map)
{
	
}

// void draw_map(t_coord ***map, int *width, int *height)
// {

// }
