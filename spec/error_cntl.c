/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cntl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:47:54 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 14:29:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_msg(int i)
{
	if (i == 1)
		write(STDERR_FILENO, "Wrong map length", 17);
	if (i == 2)
		write(STDERR_FILENO, "No file selected", 17);
	if (i == 3)
		write(STDERR_FILENO, "Wrong file name", 16);
	if (i == 4)
		write(STDERR_FILENO, "cannot get the map", 19);
	if (i == 5)
		write(STDERR_FILENO, "Failed to initialize mlx", 25);
	return ;
}
