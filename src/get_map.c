/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:52:53 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 17:06:18 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_coord **map, int height)
{
	t_coord	**current;
	int		i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		current = map + i;
		free(*current);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}

static t_coord	**new_map(t_coord **map, t_coord *line, int height)
{
	int		j;
	t_coord	**map_new;

	map_new = malloc((height + 1) * sizeof(t_coord **));
	if (!map_new)
		return (free_map(map, height), NULL);
	j = 0;
	while (j < height)
	{
		*(map_new + j) = *(map + j);
		j++;
	}
	*(map_new + j) = line;
	free(map);
	return (map_new);
}

t_coord	**get_map(int fd, int *width, int *height)
{
	char	*str;
	t_coord	*line;
	t_coord	**map;

	map = NULL;
	str = get_next_line(fd);
	if (str)
		*width = get_width(str);
	while (str)
	{
		if (get_width(str) != *width)
			return (err_msg(1), free(str), free_map(map, *height), NULL);
		line = get_int_array(str, *width);
		if (!line)
			return (free(str), free_map(map, *height), NULL);
		map = new_map(map, line, *height);
		if (!map)
			return (free(str), NULL);
		free(str);
		str = get_next_line(fd);
		(*height)++;
	}
	return (map);
}
