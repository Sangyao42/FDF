/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:43:07 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 17:07:04 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_int(char *str, int32_t *n)
{
	int	sign;

	sign = 1;
	if (*str == '-')
	{
			sign = -1;
			str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		*n = (10 * (*n) + (*str - '0'));
		str++;
	}
	*n = sign * (*n);
	return (str);
}

static char	*remove_color_info(char *str)
{
	while (*str)
	{
		if (*str != ' ' && \
		(*(str + 1) == ' ' || *(str + 1) == '\n' || *(str + 1) == '\0'))
		{
			if (*(str + 1) == '\n')
				return (str + 2);
			else
				return (str + 1);
		}
		str++;
	}
	return (str);
}

int	get_width(char *str)
{
	unsigned int	width;

	width = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str != '\0')
		{
			if (*str != ' ' && \
			(*(str + 1) == ' ' || *(str + 1) == '\n' || *(str + 1) == '\0'))
			{
				if (*str != '\n')
					width++;
			}
			str++;
		}
	}
	return (width);
}

t_coord	*get_int_array(char *str, int width)
{
	t_coord	*line;
	int		i;

	i = 0;
	line = malloc(width * sizeof(t_coord));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	while (*str && i < width)
	{
		line[i].z = 0;
		while (*str == ' ')
			str++;
		str = get_int(str, &line[i].z);
		if (*str == ',')
			str = remove_color_info(str);
		i++;
	}
	return (line);
}
