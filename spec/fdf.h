/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/17 17:35:15 by sawang           ###   ########.fr       */
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
#include <fcntl.h>
# include "MLX42.h"
# include "get_next_line.h"

//Store the line read from fdf using linked list
typedef struct s_linelist
{
	int32_t				*line_array;
	struct s_linelist	*next;
}					t_linelist;

//Struct for pixel
typedef struct s_pixel
{
	int32_t	u;
	int32_t	v;
}				t_pixel;

//Getting the whole map from fdf file
t_linelist		*get_map(int fd);
// t_linelist	**get_map(int fd);

//Parser for every line in the fdf line
unsigned int	get_width(char *str);
t_linelist		*get_int_array(char *str, unsigned int width);

//Isometric Projection
// uint32_t	u_axis(int32_t x, int32_t y);
// uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z);
t_pixel			iso_proj(int32_t x, int32_t y, int32_t z);

//Plotting line
void			draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2);

#endif
