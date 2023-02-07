/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:49:59 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 18:37:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit(t_fdf *frame)
{
	free_map(frame->map.coords, frame->map.height);
	mlx_delete_image((*frame).mlx, (*frame).g_img);
	mlx_terminate((*frame).mlx);
	system("leaks main");
	exit(EXIT_SUCCESS);
}

void	*fdf_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bc;

	bc = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		bc[i] = (unsigned char) c;
		i++;
	}
	return (bc);
}

void	err_msg(int i)
{
	if (i == 1)
		write(STDERR_FILENO, "Wrong map length\n", 18);
	if (i == 2)
		write(STDERR_FILENO, "No file selected\n", 18);
	if (i == 3)
		write(STDERR_FILENO, "Wrong file name\n", 17);
	if (i == 4)
		write(STDERR_FILENO, "cannot get the map\n", 20);
	if (i == 5)
		write(STDERR_FILENO, "Failed to initialize mlx\n", 26);
	if (i == 6)
		write(STDERR_FILENO, "Failed to create new image\n", 28);
	if (i == 7)
		write(STDERR_FILENO, "close() failed\n", 16);
	return ;
}
