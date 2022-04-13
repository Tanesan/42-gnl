/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:38:47 by ktanemur          #+#    #+#             */
/*   Updated: 2022/03/22 09:46:57 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;
	size_t	a;

	if (n == 0 || size == 0)
		return (NULL);
	p = (char *)malloc(size * n);
	if (!p)
		return (NULL);
	a = 0;
	while (size * n != a)
	{
		((char *)p)[a] = (unsigned char) '\0';
		a++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;
	char	*str;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && len > a)
		{
			str[a] = s[i];
			a++;
		}
		i++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c, int is_before)
{
	char	*result;
	char	*tmp;
	size_t	i;

	i = 0;
	result = NULL;
	tmp = (char *)s;
	if (c == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			result = ((char *)++s);
			break ;
		}
		s++;
		i++;
	}
	if (is_before == 1)
		return (ft_substr(tmp, 0, ++i));
	if (result && *result == '\0')
		return (NULL);
	return (result);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (ptr)
	{
		if (!str)
			return (ptr);
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
