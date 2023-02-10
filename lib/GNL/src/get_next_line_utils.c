/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:38 by sawang            #+#    #+#             */
/*   Updated: 2023/01/18 19:59:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

/**
 * @brief Join the previous offset_str with newly red buffer.
 * Return the new joined offset_str.
 * Before returning, free the previous offset_str.
 * @details At first, the static char *offset_str points to NULL
 * as default.
 * So if the new offset_str = ft_strdup(offset_str + len) == '\0',
 * it must be set as NULL to prepare for the next call of
 * get_next_line() in ft_strdup().
*/
char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	char	*str_join;
	size_t	s1_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	str_join = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!str_join)
		return (free(s1), NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str_join[s1_len + i] = s2[i];
		i++;
	}
	str_join[s1_len + i] = '\0';
	return (free(s1), str_join);
}

/**
 * @brief Find the if there is '\n' in offset_str.
 * @return the index of the first character after char c.
 * If no char *s, return 0.
 * If no int c found, return 0 as well.
*/
size_t	ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	s_len = ft_strlen(str);
	if ((char) c == 0)
		return (s_len + 1);
	i = 1;
	while (str[i - 1] != '\0')
	{
		if (str[i - 1] == (char) c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		substr = (char *)malloc(1);
	else if (len > s_len)
		substr = (char *)malloc(s_len - (size_t)start + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && (size_t)start < s_len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

/**
 * @details if (!*s1) statement is linked to
 * offset_str = ft_strdup(offset_str + len) in get_offset_str() function.
 * If (offset_str + len) points to end of string, which is '\0',
 * that happens when before '\0' there is a '\n'.
 * The new offset_str must be set as NULL, to prepare
 * the next call get_next_line().
 * Once the next read returns 0, the offset_str will remain as NULL.
 * Thus, the gext_first_line will return NULL as well.
*/
char	*ft_strdup(char const *s1)
{
	int		i;
	char	*dup;

	if (!*s1)
		return (NULL);
	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
