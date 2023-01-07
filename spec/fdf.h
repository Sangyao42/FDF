/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:27:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/07 19:50:32 by sawang           ###   ########.fr       */
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

#endif
