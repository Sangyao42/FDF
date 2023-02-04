/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/02/04 21:39:58 by sawang           ###   ########.fr       */
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
	t_mid_pixel		point;
	t_mid_pixel		point_modified;
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
	int		z_inc;
	float	scaler;
	int		x_angle;
	int		y_angle;
	int		z_angle;
	int		u_inc;
	int		v_inc;
}				t_input;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_map		map;
	t_input		data;
}				t_fdf;

//Call the mlx functions
int		start_fdf(t_fdf *frame);
//Manipulate the data for updating the 3d-/2d-/ coordinates
t_input	*init_data(t_input *data);
//Manipulate the map using hook
void	hook(t_fdf *frame);
void	scroll_hook(double xdelta, double ydelta, t_fdf *frame);
void	key_hook(mlx_key_data_t keydata, t_fdf *frame);

// check if file is valid
bool	file_is_valid(char *str);

//Parser for every line in the fdf line
int		get_width(char *str);
t_coord	*get_int_array(char *str, int width);
//Getting the whole map from fdf file
t_coord	**get_map(int fd, int *width, int *height);
void	free_map(t_coord **map, int height);

//Transfered the map into 3d and later 2d arrays, steps would be:
//1. For the first draw:
//1.1 Centering the map
void	center_map(t_map *map);
//1.2 Isometric Projection -- project the map for the first time
void	proj_map(t_map *map);
// 1.3. scaling the map to draw inside the window, get the scale rate
// after the projection, which updates the 2d coordinates value,
// but apply the rate to update the 3d coordinates for a new projection
// before the final draw.
// float	get_scale_rate(t_coord **map, int *width, int *height);
float	get_scale_rate(t_map *map);
//2. For the rendering:
//2.1 Update the 3d coordinates:
// t_coord	**update_coord(t_coord **map, int *width, int *height, t_input *data);
// t_coord	**update_coord(t_map *map, t_input *data);
void	update_coord(t_map *map, t_input *data);
//2.1.1 Scale the map
// t_coord	**scale_map(t_coord **map, int *width, int *height, t_input *data);
//2.1.2 Rotation: update the 3d coordinates
// t_coord	**rotate_map(t_coord **map, int *width, int *height, t_input *data);
void	rotate_map(t_map *map, t_input *data);
// 2.2 Update the 2d coordinates:
// void	update_pixel(t_coord **map, int *width, int	*height, t_input *data);

// 3. draw whole map
// 3.1 Write my own put pixel function to avoid segfault
//void	fdf_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
//3.2 Plotting line
void	draw_line(mlx_image_t *g_img, t_pixel p1, t_pixel p2);
void	draw_line2(mlx_image_t *g_img, t_pixel p1, t_pixel p2);
//3.3 Link all the points using draw_line
//void	draw_map(mlx_image_t *g_img, t_coord **map, int *width, int *height);
//3.4 draw based on the data updated by hooks
// t_coord	**draw(mlx_image_t *g_img, t_coord **map, int *width, int *height, t_input *data);
void	draw(mlx_image_t *g_img, t_map *map, t_input *data);

//error controlling
void	err_msg(int i);

#endif
