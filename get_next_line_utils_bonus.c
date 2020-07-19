/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:40:37 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/19 20:40:43 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;

	if (!src)
		return (0);
	if (!dst || size <= 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
