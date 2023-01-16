/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:53:06 by sawang            #+#    #+#             */
/*   Updated: 2023/01/16 22:01:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	add_back_line(t_linelist **lst, t_linelist *new)
// {
// 	t_linelist	*current;

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

void	line_add_next(t_linelist *lst, t_linelist *new)
{
	// t_linelist	*current;

	if (!new)
		return ;
	if (!lst)
		lst = new;
	lst->next = new;
}

static void	free_map(t_linelist **map)
{
	t_linelist	*current;

	if (!map)
		return ;
	current = *map;
	while (current)
	{
		current = current->next;
		free((*map)->line_array);
		free(*map);
		*map = current;
	}
	map = NULL;
	return ;
}

t_linelist	*get_map(int fd)
{
	char			*str;
	unsigned int	width;
	t_linelist		*line;
	t_linelist		*map;
	t_linelist		*current;

	current = NULL;
	map = current;
	str = get_next_line(fd);
	if (str)
		width = check_width(str);
	while (str)
	{
		if (check_width(str) != width)
			return (free(str), free_map(map), NULL);
		line = get_int_array(str, width);
		if (!line)
			return (free(str), free_map(map), NULL);
		// current = line;
		add_back_line(current, line);
		current = current->next;
		free(str);
		str = get_next_line(fd);
	}
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

