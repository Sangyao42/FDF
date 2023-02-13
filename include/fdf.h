/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/02/13 10:59:06 by sawang           ###   ########.fr       */
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
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//Struct for pixel
typedef struct s_pixel
{
	int32_t		u;
	int32_t		v;
}				t_pixel;

//struct for coordinates after calculate, eg: rotation
typedef struct s_point
{
	float		o;
	float		p;
	float		q;
}				t_point;

//struct for three differnt coordinates: orgianl, after rotation, 2d coordinates
typedef struct s_coord
{
	int			z;
	t_point		point;
	t_point		point_modified;
	t_pixel		pixel;
	uint32_t	color;
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
	float	x_angle;
	float	y_angle;
	float	z_angle;
	int		parallel_flag;
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

typedef struct s_delta
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	p;
	// int	sign;
}				t_delta;
//Call the mlx functions
int		start_fdf(t_fdf *frame);
//Manipulate the data for updating the 3d-/2d-/ coordinates
t_input	*init_data(t_input *data);
//Manipulate the map using hook
// void	check_rotation(t_input *data, keys_t key);
void	hook(t_fdf *frame);
void	scroll_hook(double xdelta, double ydelta, t_fdf *frame);
void	key_hook(mlx_key_data_t keydata, t_fdf *frame);

// check if file is valid
int		check_file(int argc, char **argv);

//Parser for every line in the fdf line
int		get_width(char *str);
t_coord	*get_int_array(char *str, int width);
//Getting the whole map from fdf file
t_coord	**get_map(int fd, int *width, int *height);
void	free_map(t_coord **map, int height);

//Transfered the map into 3d and later 2d arrays, steps would be:
//1. For the first draw:
// 1.0 Get the initial map for first draw
void	init_map(t_fdf *frame);
//1.1 Centering the map
// static void	init_points(t_map *map);
//1.2 Isometric Projection -- project the map for the first time
void	proj_map(t_map *map);
// 1.3. scaling the map to draw inside the window, get the scale rate
// after the projection, which updates the 2d coordinates value,
// but apply the rate to update the 3d coordinates for a new projection
// before the final draw.
// static float	get_scale_rate(t_map *map);
//2. For the rendering:
void	updata_data(t_input *data, keys_t key);
//2.2 Update the 3d coordinates:
void	update_coord(t_map *map, t_input *data);
//2.2.1 Scale the map
void	scale_map(t_map *map, t_input *data);
//2.2.2 Rotation: update the 3d coordinates
void	rotate_map(t_map *map, t_input *data);
// 2.3 Update the 2d coordinates:
void	update_pixel(t_map *map, t_input *data);
// 3. draw whole map
// 3.1 Write my own put pixel function to avoid segfault
//void	fdf_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
//3.2 Plotting line
// void	draw_line(mlx_image_t *g_img, t_coord p1, t_coord p2);
void	draw_line(mlx_image_t *g_img, t_coord p1, t_coord p2, t_delta delta);
//3.3 Link all the points using draw_line
void	draw_map(mlx_image_t *g_img, t_map *map);
//3.4 draw based on the data updated by hooks
// 3.4.1 draw for isometric projection
void	draw(mlx_image_t *g_img, t_map *map, t_input *data, keys_t key);
// 3.4.2 draw for parallel projection
void	draw_parallel(\
		mlx_image_t *g_img, t_map *map, t_input *data, keys_t key);
//coloring
t_coord	get_max_z(t_map map);
t_coord	get_min_z(t_map map);
t_coord	set_base_color(t_map *map);
int		set_color(t_coord current, t_coord start, t_coord end);
// int		get_color(t_coord current, t_coord start, t_coord end, int sign);
int		get_color(t_coord current, t_coord start, t_coord end, t_delta delta);

//error controlling
void	err_msg(int i);
//quit successfully
void	quit(t_fdf *frame);
//memset
void	*fdf_memset(void *b, int c, size_t len);

#endif
