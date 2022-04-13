/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:24 by ktanemur          #+#    #+#             */
/*   Updated: 2022/02/23 19:06:13 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strchr(const char *s, int c, int is_before);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
char	*ft_strchr_before(const char *s, int c);
void	ft_bzero(void *buf, size_t n);

#endif
