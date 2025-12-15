/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:10:51 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/08 09:58:47 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr(char	*str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*ft_subline(char **statstr)
{
	char	*s;
	char	*p;
	int		i;

	i = ft_strchr(*statstr, '\n');
	if (!i)
	{
		s = *statstr;
		*statstr = NULL;
		return (s);
	}
	s = ft_strdup(*statstr, i);
	p = *statstr;
	*statstr = ft_strdup(*statstr + i, ft_strlen(*statstr + i));
	free(p);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s1;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s1 = malloc (BUFFER_SIZE + 1);
	if (!s1)
		return (NULL);
	r = 1;
	while (r > 0 && !ft_strchr(str, '\n'))
	{
		r = read(fd, s1, BUFFER_SIZE);
		if (r < 0)
			return (free(s1), free(str), str = NULL, NULL);
		if (!r)
			break ;
		s1[r] = '\0';
		str = ft_strjoin(str, s1);
	}
	if (!r && !str)
		return (free(s1), NULL);
	return (free(s1), ft_subline(&str));
}
