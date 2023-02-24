/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:48:09 by kmouradi          #+#    #+#             */
/*   Updated: 2022/12/28 11:28:21 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		while (s1[++i] != '\0')
		{
			str[i] = s1[i];
		}
		i = 0;
		while (s2[i] != '\0')
		{
			str[ft_strlen(s1) + i] = s2[i];
			i++;
		}
		str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
		free (s1);
		return (str);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	else
		return (0);
}

size_t	ft_strlen( const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*v;

	i = 0;
	len = ft_strlen(s1);
	v = (char *)(malloc(sizeof(char) * len + 1));
	if (v == 0)
		return (0);
	while (i < len)
	{
		v[i] = s1[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}
