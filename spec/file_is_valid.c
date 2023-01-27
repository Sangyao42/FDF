/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:34:40 by sawang            #+#    #+#             */
/*   Updated: 2023/01/27 20:56:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	file_is_valid(char *str)
{
	int		i;
	char	*file_name;

	file_name = ".fdf";
	i = 0;
	while (*(str + i))
		i++;
	if (*(str + i - 4) == *file_name)
		return (true);
	return (false);
}
