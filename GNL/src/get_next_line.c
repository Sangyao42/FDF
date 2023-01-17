/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:22:07 by sawang            #+#    #+#             */
/*   Updated: 2022/11/24 17:27:58 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "stdio.h"
// #include "strings.h"

/**
 * @brief read the files into buffer and
 * join the previous offset_str with buffer, if there is no '\n' in offset_str
 * @details If read() fails, offset_str and buffer should both be freed.
 * If read() returns 0, which means no more bytes is red,
 * buffer will not be changed, then break the loop.
 * and keep offset_str as how it was before.
 * Set buffer[red] = '\0' to set the buffer red as a string
 * for using ft_strjoin().
 * Once buffer is joined to offset_str, buffer should be freed
 * and the offset_str should be freed as well,
 * which is accomplished in ft_strjoin() using free(s1).
*/
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
	}
	free (buffer);
	return (offset_str);
}

/**
 * @brief Return the first line seperated by '\n' from offset_str.
 * @details If there is no '\n' in offset_str, return the value of offset_str,
 * which means it returns the last line of the file without a newline.
*/
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

/**
 * @brief Store the string behind the '\n'
 * @details If there is '\n' in offset_str, using ft_strdup() make a copy of
 * the string starting from (offset_str + len) and free the previous offset_str
 * using a pointer (first set a ptr points to previous offset_str,
 * after ft_strdup(), free the ptr, which frees the previous offset_str).
 * If there is no '\n' in offset_str, which means we reach the last line of
 * the file, thus offset_str should be freed and
 * make offset_str points to nowhere when finishing reading.
*/
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	offset_str = read_and_accumulate(fd, offset_str);
	line = get_first_line(offset_str);
	offset_str = get_offset_str(offset_str);
	return (line);
}
