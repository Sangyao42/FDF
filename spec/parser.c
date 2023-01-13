/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:43:07 by sawang            #+#    #+#             */
/*   Updated: 2023/01/13 21:30:50 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_linelist
{
	int32_t				*line_array;
	struct s_linelist	*next;
}					t_linelist;

char	*remove_color_info(char *str);

unsigned int	check_width(char *str)
{
	unsigned int	width;

	width = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str != '\0')
		{
			if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
				width++;
			str++;
		}
	}
	return (width);
}

// int	*get_int_array(char *str)
// {
// 	int	counter;
// 	int	num;

// 	num = 0;
// 	while (*str)
// 	{
// 		if (*str == ' ')
// 			str++;
// 		if (*str == '-' || (*str <= '9' && *str >= '0'))
// 		{
// 			str++;
// 		}
// 	}

// }

t_linelist	*get_int_array(char *str, unsigned int width)
{
	t_linelist		*line;
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	line = malloc(sizeof(t_linelist));
	if (!line)
		return (NULL);
	line->next = NULL;
	line->line_array = malloc(width * sizeof(int32_t));
	if (!line->line_array)
	{
		free(line);
		return (NULL);
	}
	while (*str && i < width)
	{
		line->line_array[i] = 0;
		while (*str == ' ')
			str++;
		while (*str == '-' || (*str >= '0' && *str <= '9'))
		{
			if (*str == '-')
			{
				sign = -1;
				str++;
			}
			line->line_array[i] = sign * (10 * line->line_array[i] + (*str - '0'));
			str++;
		}
		str = remove_color_info(str);
		i++;
	}
	return (line);
}

// int	is_valid_int()
char	*remove_color_info(char *str)
{
	while (*str)
	{
		if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
			return (str + 1);
		str++;
	}
	return (str);
}

int	main(void)
{
	char	*str = " 0,0xff 0,0xff 1,0xff 0,0xff 5,0xff00 3,0xff 5,0xff00    ";
	int		width = check_width(str);
	printf("%d\n", width);

	t_linelist	*line;
	line = get_int_array(str, width);
	while (width)
	{
		printf("%d,", line->line_array[7 - width]);
		width--;
	}
	free(line);
	return (0);
}
