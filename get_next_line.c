/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:09:37 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/19 20:30:53 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join(char *str1, char *str2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(res = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	ft_strlcpy(res, str1, len1 + 1);
	ft_strlcpy((res + len1), str2, len2 + 1);
	free(str1);
	return (res);
}

size_t	find_pointer_to_n(char *str)
{
	char *s;

	if (str)
	{
		s = str;
		while (*s)
		{
			if (*s == '\n')
				return (s - str + 1);
			s++;
		}
	}
	return (0);
}

int		fill_line(char **str, char **line)
{
	size_t	n;
	char	*temp;

	n = find_pointer_to_n(str[1]);
	if (n && (*line = ft_substr(str[1], 0, n - 1)))
	{
		temp = ft_strdup(str[1] + n);
		free(str[1]);
		str[1] = temp;
		return (1);
	}
	else if (!n && (*line = ft_strdup(str[1])))
	{
		if (str[1])
		{
			free(str[1]);
			str[1] = NULL;
		}
		return (0);
	}
	free(str[1]);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str[2];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((!find_pointer_to_n(str[1]) && (n = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[n] = '\0';
		str[1] = str_join(str[1], buf);
		if (!str[1])
			return (-1);
	}
	if (n < 0)
		return (-1);
	if (str[1] == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	return (fill_line(str, line));
}
