/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cntl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:47:54 by sawang            #+#    #+#             */
/*   Updated: 2023/01/27 21:57:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_msg(int i)
{
	if (i == 1)
		write(3, "Wrong map length", 17);
	if (i == 2)
		write(3, "No file selected", 17);
	if (i == 3)
		write(3, "Wrong file name", 16);
	if (i == 4)
		write(3, "cannot get the map", 19);
	return ;
}
