/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:53:06 by sawang            #+#    #+#             */
/*   Updated: 2023/01/17 18:31:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

static void	line_add_back(t_linelist **lst, t_linelist *new)
{
	t_linelist	*current;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
	}
}

// // void	line_add_next(t_linelist *lst, t_linelist *new)
// // {
// // 	// t_linelist	*current;

// // 	if (!new)
// // 		return ;
// // 	if (!lst)
// // 	{
// // 		lst = new;
// // 		return ;
// // 	}
// // 	lst->next = new;
// // 	return ;
// // }

void	free_map(t_linelist *map)
{
	t_linelist	*current;

	if (!map)
		return ;
	current = map;
	while (current)
	{
		current = current->next;
		free((map)->line_array);
		free(map);
		map = current;
	}
	map = NULL;
	// map = NULL;
	return ;
}

t_linelist	*get_map(int fd)
{
	char			*str;
	unsigned int	width;
	t_linelist		*line;
	t_linelist		*map;
	// t_linelist		*current;

	map = NULL;
	str = get_next_line(fd);
	if (str)
		width = get_width(str);
	while (str)
	{
		if (get_width(str) != width)
			return (free(str), free_map(map), NULL);
		line = get_int_array(str, width);
		if (!line)
			return (free(str), free_map(map), NULL);
		// // printf("correct value:%d,\n", line->line_array[1]);
		// current = line;
		// // printf("and current value:%d.\n", current->line_array[1]);
		// current = current->next;
		line_add_back(&map, line);
		free(str);
		str = get_next_line(fd);
	}
	// printf("map value: %p,\n", map);
	return (map);
}
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*current;

// 	if (!new || !lst)
// 		return ;
// 	if (!*lst)
// 		*lst = new;
// 	else
// 	{
// 		current = *lst;
// 		while (current->next)
// 		{
// 			current = current->next;
// 		}
// 		current->next = new;
// 	}
// }

// t_linelist	*create_a_node(char *str, unsigned int last_width)
// {
// 	if (last_width != get_width(str))
// 		return (NULL);
// 	return (get_int_array(str, last_width));
// }

// t_linelist	*get_map(int fd)
// {
// 	char			*str;
// 	unsigned int	width;
// 	t_linelist		*map;
// 	t_linelist		*current;

// 	str = get_next_line(fd);
// 	if (!str)
// 		return (NULL);
// 	width = get_width(str);
// 	map = create_a_node(str, width);
// 	current = map;
// 	if (!current)
// 		return (NULL);
// 	while (str)
// 	{
// 		current->next = create_a_node(str, width);
// 		current = current->next;
// 		if (!current)
// 			return (free_map(map), NULL);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	return (map);
// }
