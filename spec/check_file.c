/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:34:40 by sawang            #+#    #+#             */
/*   Updated: 2023/02/07 15:42:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	file_is_valid(char *str)
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

int	check_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		err_msg(2);
		exit(EXIT_FAILURE);
	}
	if (file_is_valid(*(argv + 1)) == false)
	{
		err_msg(3);
		exit(EXIT_FAILURE);
	}
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		perror(*(argv + 1));
		exit(EXIT_FAILURE);
	}
	return (fd);
}
