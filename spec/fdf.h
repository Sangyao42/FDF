/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/09 18:46:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# include <stdlib.h>
# include <math.h>
# include "MLX42.h"

//Isometric Projection
uint32_t	u_axis(int32_t x, int32_t y);
uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z);

//Plotting line
void	draw_line(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

#endif
