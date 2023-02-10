/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:21:31 by sawang            #+#    #+#             */
/*   Updated: 2023/02/10 15:14:06 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	frame;

	fd = check_file(argc, argv);
	frame.map.width = 0;
	frame.map.height = 0;
	frame.map.coords = get_map(fd, &(frame.map.width), &(frame.map.height));
	if (!frame.map.coords)
		return (err_msg(4), EXIT_FAILURE);
	if (close(fd))
		return (err_msg(7), \
			free_map(frame.map.coords, frame.map.height), EXIT_FAILURE);
	if (start_fdf(&frame))
		return (free_map(frame.map.coords, frame.map.height), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
