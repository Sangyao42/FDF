/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 17:49:47 by sawang           ###   ########.fr       */
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

# ifndef PI
#  define PI 3.1415
# endif

# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include "MLX42.h"
# include "get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <unistd.h>

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

typedef struct s_map
{
	t_coord	**coords;
	int		width;
	int		height;
}				t_map;

typedef struct s_input
{
	int	z_inc;
	int	x_angle;
	int	y_angle;
	int	z_angle;
	int	u_inc;
	int	v_inc;
	int	scaler;
}				t_input;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_map		map;
	t_input		data;
}				t_fdf;

//Call the mlx functions
// int		start_fdf(t_coord	***map, int *width, int *height);
int		start_fdf(t_fdf *frame);
//Manipulate the map using hook
void	hook(void *param);
//Getting the whole map from fdf file
// check if file is valid
bool	file_is_valid(char *str);
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
//2. Rotation: update the 3d coordinates
t_coord	**rotate_map(t_coord **map, int *width, int *height);
//3. Isometric Projection
// uint32_t	u_axis(int32_t x, int32_t y);
// uint32_t	v_ordinate(int32_t x, int32_t y, int32_t z);
// t_pixel	iso_proj(int32_t x, int32_t y, int32_t z);
t_pixel	iso_proj(t_mid_pixel p_cart);
t_coord	**proj_map(t_coord **map, int *width, int *height);
// 4. scaling the map to draw inside the window, get the scale rate
// after the projection, which updates the 2d coordinates value,
// but apply the rate to update the 3d coordinates for a new projection
// before the final draw.
t_coord	**scale_map(t_coord **map, int *width, int *height);
// 5. draw whole map
//Plotting line
void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2);
//Link all the points using draw_line
void	draw_map(mlx_image_t *g_img, t_coord **map, int *width, int *height);
//Draw function
// void	draw(mlx_image_t *g_img, t_coord ***map, int *width, int *height);
void	draw(mlx_image_t *g_img, t_coord ***map, int *width, int *height, t_input data);
//update map using data
t_coord	**update_coord(t_coord **map, int *width, int *height, t_input data);
//error controlling
void	err_msg(int i);

#endif
