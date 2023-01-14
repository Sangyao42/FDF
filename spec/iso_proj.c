/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:21:30 by sawang            #+#    #+#             */
/*   Updated: 2023/01/14 21:40:54 by sawang           ###   ########.fr       */
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

t_pixel	iso_proj(int32_t x, int32_t y, int32_t z)
{
	t_pixel	pixel;
	int32_t	u_org;
	int32_t	v_org;

	u_org = WIDTH / 2;
	v_org = HEIGHT / 2;
	pixel.u = u_org + (x - y) * cos(0.46365);
	pixel.v = v_org + ((x + y) * sin(0.46365) - z);
	return (pixel);
}
