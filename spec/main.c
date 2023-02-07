/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:21:31 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 18:37:09 by sawang           ###   ########.fr       */
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
		return (err_msg(4), system("leaks main"), EXIT_FAILURE);
	if (close(fd))
		return (err_msg(7), \
			free_map(frame.map.coords, frame.map.height), EXIT_FAILURE);
	if (start_fdf(&frame))
		return (free_map(frame.map.coords, frame.map.height), EXIT_FAILURE);
	system("leaks main");
	return (EXIT_SUCCESS);
}
