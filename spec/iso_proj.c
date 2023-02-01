/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:21:30 by sawang            #+#    #+#             */
/*   Updated: 2023/02/01 16:46:21 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// uint32_t	u_axis(int32_t x, int32_t y)
// {
// 	uint32_t	u;
// 	int32_t		u_org;

// 	u_org = WIDTH / 2;
// 	u = u_org + (x - y) * cos(0.46365);
// 	return (u);
// }

// uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z)
// {
// 	uint32_t	v;
// 	int32_t		v_org;

// 	v_org = HEIGHT / 2;
// 	v = v_org + ((x + y) * sin(0.46365) - z);
// 	return (v);
// }

// t_pixel	iso_proj(int32_t x, int32_t y, int32_t z)
// {
// 	t_pixel	pixel;
// 	int32_t	u_org;
// 	int32_t	v_org;

// 	u_org = WIDTH / 2;
// 	v_org = HEIGHT / 2;
// 	pixel.u = u_org + (x - y) * cos(0.46365);
// 	pixel.v = v_org + ((x + y) * sin(0.46365) - z);
// 	return (pixel);
// }

void	iso_proj(t_coord **map, int j, int i)
{
	int32_t	u_o;
	int32_t	v_o;

	u_o = WIDTH / 2;
	v_o = HEIGHT / 2;
	map[j][i].pixel.u = u_o + roundf((map[j][i].mid_pixel.o - map[j][i].mid_pixel.p) * cos(0.46365));
	map[j][i].pixel.v = v_o + roundf((map[j][i].mid_pixel.o + map[j][i].mid_pixel.p) * sin(0.46365) - map[j][i].mid_pixel.q);
}

t_coord	**proj_map(t_coord **map, int *width, int *height)
{
	int	i;
	int	j;

	j = 0;
	while (j < *height)
	{
		i = 0;
		while (i < *width)
		{
			iso_proj(map, j, i);
			i++;
		}
		j++;
	}
	return (map);
}
