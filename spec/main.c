/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:21:31 by sawang            #+#    #+#             */
/*   Updated: 2023/01/27 22:21:42 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		height;
	int		width;
	t_coord	**map;

	if (argc != 2)
		return (err_msg(2), EXIT_FAILURE);
	if (file_is_valid(*(argv + 1)) == false)
		return (err_msg(3), EXIT_FAILURE);
	width = 0;
	height = 0;
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		perror(*(argv + 1));
		exit (EXIT_FAILURE);
	}
	map = get_map(fd, &width, &height);
	// if (!map)
	// 	return (err_msg(4), EXIT_FAILURE);
	// printf("hallo: height: %d\n", height);
	// printf("hallo: width: %d\n", width);
	close(fd);
	return (EXIT_SUCCESS);
}
