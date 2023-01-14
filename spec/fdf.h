/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/14 22:02:07 by sawang           ###   ########.fr       */
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
# include <stddef.h>
# include <math.h>
# include "MLX42.h"

//Store the line read from fdf using linked list
typedef struct s_linelist
{
	int32_t			*line_array;
	struct s_line	*next;
}					t_linelist;

//Struct for pixel
typedef struct s_pixel
{
	int32_t	u;
	int32_t	v;
}				t_pixel;

//Isometric Projection
// uint32_t	u_axis(int32_t x, int32_t y);
// uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z);
t_pixel	iso_proj(int32_t x, int32_t y, int32_t z);

//Plotting line
// void	draw_line(mlx_image_t *g_img, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2);

#endif
