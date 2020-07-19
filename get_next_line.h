/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:55:37 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/19 20:28:52 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*str_join(char *str1, char *str2);
size_t	find_pointer_to_n(char *str);
int		fill_line(char **str, char **line);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
