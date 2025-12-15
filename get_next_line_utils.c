/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:56:33 by abchtaib          #+#    #+#             */
/*   Updated: 2025/12/07 15:51:12 by abchtaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	if (!str || !(*str))
		return (0);
	return (1 + ft_strlen(str + 1));
}

char	*ft_strdup(char *str, int len)
{
	char	*s;
	int		i;

	s = malloc(len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str && i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_strcat(char *s1, char *s2, int len)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		str[len + i] = s2[i];
		i++;
	}
	str[len + i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strdup(s1, ft_strlen(s1)));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strcat(s1, s2, len1 + len2);
	free(s1);
	return (str);
}
