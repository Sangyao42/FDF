/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/26 14:43:01 by sawang           ###   ########.fr       */
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
# include <fcntl.h>
# include "MLX42.h"
# include "get_next_line.h"
# include <stdio.h>

//Struct for pixel
typedef struct s_pixel
{
	int32_t	u;
	int32_t	v;
}				t_pixel;

//struct for coordinates after calculate, eg: rotation
typedef struct s_mid_pixel
{
	float	o;
	float	p;
	float	q;
}				t_mid_pixel;

//struct for three differnt coordinates: orgianl, after rotation, 2d coordinates
typedef struct s_coord
{
	int				z;
	t_mid_pixel		mid_pixel;
	t_pixel			pixel;
}				t_coord;

typedef struct s_pixel_max
{
	int		u_max;
	int		v_max;
}				t_pixel_max;

//Getting the whole map from fdf file
// void	free_map(int **map, unsigned int height);
void	free_map(t_coord **map, int height);
// int	**get_map(int fd, unsigned int *width, unsigned int *height);
t_coord	**get_map(int fd, int *width, int *height);
// int				get_map(int fd, int ***map);
// t_linelist	**get_map(int fd);

//Parser for every line in the fdf line
int		get_width(char *str);
// int				*get_int_array(char *str, unsigned int width);
t_coord	*get_int_array(char *str, int width);
// t_linelist		*get_int_array(char *str, unsigned int width);

//Transfered the map into 2d array, steps would be:
//1. Centering the map
t_coord	**center_map(t_coord **map, int *width, int *height);
//2. Rotation

//3. Isometric Projection
// uint32_t	u_axis(int32_t x, int32_t y);
// uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z);
// t_pixel	iso_proj(int32_t x, int32_t y, int32_t z);
t_pixel	iso_proj(t_mid_pixel p_cart);
t_coord	**proj_map(t_coord **map, int *width, int *height);
// 4. scaling the map to draw inside the window

// 5. draw whole map
//Plotting line
void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2);
//Link all the points using draw_line
void	draw_map(mlx_image_t *g_img, t_coord **map, int *width, int *height);
//Draw function
void	draw(mlx_image_t *g_img, t_coord ***map, int *width, int *height);

#endif
