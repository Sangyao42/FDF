/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:52:53 by sawang            #+#    #+#             */
/*   Updated: 2023/01/19 17:10:02 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	**get_map_array(int fd)
// {
// 	char			*str;
// 	unsigned int	width;
// 	int				*line;
// 	int				**map;
// 	unsigned int	height;

// 	map = NULL;
// 	if (str)
// 	{
// 		width = get_width(str);
// 		height = 0;
// 	}
// 	while (str)
// 	{
// 		if (get_width(str) != width)
// 			return (free(str), free_map(map, height), NULL);
// 		line = get_int_array(str, width);
// 		if (!line)
// 			return (free(str), free_map(map, height), NULL);
// 		map = new_map(map, line, height);
// 		if (!map)
// 			return (free(str), free_map(map, height), NULL);
// 		free(str);
// 		str = get_next_line(fd);
// 		height++;
// 	}
// 	return (map);
// }
void	free_map(int **map, unsigned int height)
{
	int				**current;
	unsigned int	i;

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

static int	**new_map(int **map, int *line, unsigned int height)
{
	unsigned int	j;
	int				**map_new;

	map_new = malloc((height + 1) * sizeof(int **));
	if (!map_new)
		return (free_map(map, height), NULL);
	// printf("height: %d\n", height);
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

int	**get_map(int fd, unsigned int *width, unsigned int *height)
{
	char	*str;
	int		*line;
	int		**map;

	map = NULL;
	str = get_next_line(fd);
	if (str)
		*width = get_width(str);
	while (str)
	{
		if (get_width(str) != *width)
			return (free(str), free_map(map, *height), NULL);
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

// int	get_map(int fd, int ***map)
// {
// 	char			*str;
// 	unsigned int	width;
// 	int				*line;
// 	unsigned int	height;

// 	str = get_next_line(fd);
// 	if (str)
// 	{
// 		width = get_width(str);
// 		height = 0;
// 	}
// 	while (str)
// 	{
// 		if (get_width(str) != width)
// 			return (free(str), free_map(*map, height), -1);
// 		line = get_int_array(str, width);
// 		if (!line)
// 			return (free(str), free_map(*map, height), -1);
// 		*map = new_map(*map, line, height++);
// 		if (!*map)
// 			return (free(str), -1);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	return (height);
// }

// void	free_map(t_linelist *map)
// {
// 	t_linelist	*current;

// 	if (!map)
// 		return ;
// 	current = map;
// 	while (current)
// 	{
// 		current = current->next;
// 		free((map)->line_array);
// 		free(map);
// 		map = current;
// 	}
// 	map = NULL;
// 	return ;
// }
// int	**new_map(int **map, int *line, unsigned int height)
// {
// 	int				**temp;
// 	unsigned int	j;

// 	if (!map && height == 1)
// 	{
// 		map = malloc(height * sizeof(int **));
// 		if (!map)
// 			return (free(line), NULL);
// 		*map = line;
// 	}
// 	else
// 	{
// 		temp = map;
// 		free_map(map);
// 		map = malloc(height * sizeof(int **));
// 		if (!map)
// 			return (free(line), NULL);
// 		j = 1;
// 		while (j < height)
// 		{
// 			*(map + j) = *(temp + j);
// 			j++;
// 		}
// 		*(map + j) = line;
// 	}
// 	return (map);
// }
