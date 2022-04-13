/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:38:42 by ktanemur          #+#    #+#             */
/*   Updated: 2022/03/22 09:46:41 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char *s2)
{
	size_t	i;
	char	*nstr;
	size_t	s1_len;
	size_t	length;

	i = 0;
	length = ft_strlen(s2);
	if (s1)
	{
		s1_len = ft_strlen(s1);
		length += s1_len;
	}
	nstr = (char *)ft_calloc(length + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	if (s1 != NULL)
		while (i < s1_len && *s1)
			nstr[i++] = *s1++;
	if (s2 == NULL)
		return (nstr);
	while (*s2 && length != i)
		nstr[i++] = *s2++;
	return (nstr);
}

void	ft_bzero(void *buf, size_t n)
{
	size_t	a;

	a = 0;
	while (n != a)
	{
		((char *)buf)[a] = 0;
		a++;
	}
}

void	has_saved(char **result_from_save, char **save, int fd, char **line)
{
	char	*tmp;
	char	*s_tmp;

	tmp = NULL;
	tmp = ft_strdup(ft_strchr(*save, '\n', 0));
	*result_from_save = ft_strchr(*save, '\n', 1);
	free(*save);
	*save = NULL;
	if (tmp && *tmp != '\0')
		*save = ft_strdup(tmp);
	free(tmp);
	if (*save)
	{
		if (read(fd, *line, (size_t)BUFFER_SIZE) > 0)
		{
			s_tmp = ft_strdup(*save);
			free(*save);
			*save = ft_strjoin(s_tmp, *line);
			free(s_tmp);
		}
	}
}

char	*gnl_while(char **result_f_save, char **result, char *line, char **save)
{
	char	*result_before_save;
	char	*print_tmp;
	char	*tmp;

	print_tmp = ft_strchr(line, '\n', 1);
	result_before_save = ft_strjoin(*result_f_save, *result);
	if (*result)
		free(*result);
	*result = ft_strjoin(result_before_save, print_tmp);
	free(print_tmp);
	tmp = ft_strchr(line, '\n', 0);
	if (*result_f_save)
	{
		free(*result_f_save);
		*result_f_save = NULL;
	}
	if (result_before_save)
		free(result_before_save);
	if (tmp)
		*save = ft_strdup(tmp);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save[256];
	char		*line;
	char		*tmp;
	char		*result;
	char		*result_from_save;

	result = NULL;
	result_from_save = NULL;
	if (fd < 0 || fd > 255)
		return (NULL);
	line = (char *)ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (save[fd] != NULL)
		has_saved(&result_from_save, &save[fd], fd, &line);
	while (save[fd] == NULL && read(fd, line, (size_t)BUFFER_SIZE) > 0)
	{
		tmp = gnl_while(&result_from_save, &result, line, &save[fd]);
		if (tmp || result[ft_strlen(result) - 1] == '\n')
			break ;
		ft_bzero(line, ft_strlen(line));
	}
	free(line);
	if (result_from_save)
		return (result_from_save);
	return (result);
}
