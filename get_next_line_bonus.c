/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:47:06 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/08 10:30:02 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[1024];
	char		*s1;
	int			r;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	s1 = malloc (BUFFER_SIZE + 1);
	if (!s1)
		return (NULL);
	r = 1;
	while (r > 0 && !ft_strchr(str[fd], '\n'))
	{
		r = read(fd, s1, BUFFER_SIZE);
		if (r < 0)
			return (free(s1), free(str[fd]), str[fd] = NULL, NULL);
		if (!r)
			break ;
		s1[r] = '\0';
		str[fd] = ft_strjoin(str[fd], s1);
	}
	if (!r && !str[fd])
		return (free(s1), NULL);
	return (free(s1), ft_subline(&str[fd]));
}
