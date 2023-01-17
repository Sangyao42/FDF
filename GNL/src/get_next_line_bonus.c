/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:33:11 by sawang            #+#    #+#             */
/*   Updated: 2022/11/23 21:29:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_accumulate(int fd, char *offset_str)
{
	char	*buffer;
	int		red;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(offset_str, '\n') == 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(offset_str);
			return (free (buffer), NULL);
		}
		if (red == 0)
			break ;
		buffer[red] = '\0';
		offset_str = ft_strjoin(offset_str, buffer);
		if (!offset_str)
			return (free (buffer), NULL);
	}
	free (buffer);
	return (offset_str);
}

static char	*get_first_line(char *offset_str)
{
	char	*line;
	size_t	len;

	if (!offset_str)
		return (NULL);
	len = ft_strchr(offset_str, '\n');
	if (len)
		line = ft_substr(offset_str, 0, len);
	else
		line = ft_strdup(offset_str);
	return (line);
}

static char	*get_offset_str(char *offset_str)
{
	size_t	len;
	char	*ptr;

	if (!offset_str)
		return (NULL);
	len = ft_strchr(offset_str, '\n');
	if (len)
	{
		ptr = offset_str;
		offset_str = ft_strdup(offset_str + len);
		free(ptr);
	}
	else
	{
		free(offset_str);
		return (NULL);
	}
	return (offset_str);
}

/**
 * Macro: int FD_SETSIZE
	The value of this macro is the maximum number of file descriptors
	that a fd_set object can hold information about.
	On systems with a fixed maximum number, FD_SETSIZE is at least that number.
	On some systems, including GNU, there is no absolute limit
	on the number of descriptors open,
	but this macro still has a constant value
	which controls the number of bits in an fd_set;
	if you get a file descriptor with a value as high as FD_SETSIZE,
	you cannot put that descriptor into an fd_set.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str[FD_SETSIZE];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	offset_str[fd] = read_and_accumulate(fd, offset_str[fd]);
	line = get_first_line(offset_str[fd]);
	offset_str[fd] = get_offset_str(offset_str[fd]);
	return (line);
}
