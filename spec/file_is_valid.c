/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:34:40 by sawang            #+#    #+#             */
/*   Updated: 2023/01/28 13:20:17 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	file_is_valid(char *str)
{
	int		i;
	int		j;
	char	*file_name;

	file_name = ".fdf";
	i = 0;
	while (*(str + i))
		i++;
	j = 0;
	while (*(file_name + j))
	{
		if (*(str + i - 4 + j) != *(file_name + j))
			return (false);
		j++;
	}
	return (true);
}
