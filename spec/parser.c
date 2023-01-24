/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:43:07 by sawang            #+#    #+#             */
/*   Updated: 2023/01/24 16:44:54 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>

// typedef struct s_linelist
// {
// 	int32_t				*line_array;
// 	struct s_linelist	*next;
// }					t_linelist;

// char	*get_int(char *str, int32_t *n);
// char	*remove_color_info(char *str);

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

// t_linelist	*get_int_array(char *str, unsigned int width)
// {
// 	t_linelist		*line;
// 	unsigned int	i;

// 	i = 0;
// 	line = malloc(sizeof(t_linelist));
// 	if (!line)
// 		return (NULL);
// 	line->next = NULL;
// 	line->line_array = malloc(width * sizeof(int32_t));
// 	if (!line->line_array)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	while (*str && i < width)
// 	{
// 		line->line_array[i] = 0;
// 		while (*str == ' ')
// 			str++;
// 		str = get_int(str, &line->line_array[i]);
// 		if (*str == ',')
// 			str = remove_color_info(str);
// 		i++;
// 	}
// 	return (line);
// }

// int	*get_int_array(char *str, unsigned int width)
// {
// 	int				*line;
// 	unsigned int	i;

// 	i = 0;
// 	line = malloc(width * sizeof(int32_t));
// 	if (!line)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	while (*str && i < width)
// 	{
// 		line[i] = 0;
// 		while (*str == ' ')
// 			str++;
// 		str = get_int(str, &line[i]);
// 		if (*str == ',')
// 			str = remove_color_info(str);
// 		i++;
// 	}
// 	return (line);
// }

t_coord	*get_int_array(char *str, int width)
{
	t_coord				*line;
	unsigned int	i;

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

// int	*get_int_array(char *str, unsigned int width)
// {
// 	int				line[width];
// 	unsigned int	i;

// 	i = 0;
// 	while (*str && i < width)
// 	{
// 		line[i] = 0;
// 		while (*str == ' ')
// 			str++;
// 		str = get_int(str, &line[i]);
// 		if (*str == ',')
// 			str = remove_color_info(str);
// 		i++;
// 	}
// 	return (line);
// }
// int	main(void)
// {
// 	char	*str1 = " 0,0xff 0,0xff 1,0xff 0,0xff 5,0xff00 3,0xff 5,0xff00    ";
// 	int		width1 = check_width(str1);
// 	printf("%d\n", width1);

// 	t_linelist	*line1;
// 	line1 = get_int_array(str1, width1);
// 	while (width1)
// 	{
// 		printf("test1: %d,\n", line1->line_array[7 - width1]);
// 		width1--;
// 	}
// 	free(line1);

// 	char	*str2 = " -100 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1    ";
// 	int		width2 = check_width(str2);
// 	printf("%d\n", width2);
// 	t_linelist	*line2;
// 	line2 = get_int_array(str2, width2);
// 	while (width2)
// 	{
// 		printf("test2: %d,\n", line2->line_array[12 - width2]);
// 		width2--;
// 	}
// 	free(line2);

// 	char	*str3 = "300 2 2 -1000 0 0 1 -2 -3 -1 3   0";
// 	int		width3 = check_width(str3);
// 	printf("%d\n", width3);
// 	t_linelist	*line3;
// 	line3 = get_int_array(str3, width3);
// 	while (width3)
// 	{
// 		printf("test3: %d,\n", line3->line_array[12 - width3]);
// 		width3--;
// 	}
// 	free(line3);

// 	return (0);
// }
