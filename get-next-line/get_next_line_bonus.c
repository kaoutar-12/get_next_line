/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:45:28 by kmouradi          #+#    #+#             */
/*   Updated: 2023/01/22 17:24:36 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	char	*txt;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	txt = (char *)malloc(sizeof(char *) * (i + 1));
	if (txt == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		txt[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		txt[i++] = '\n';
	txt[i] = '\0';
	return (txt);
}

char	*removeline(char *str)
{
	size_t	i;
	int		j;
	char	*txt;
	size_t	len;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (free (str), NULL);
	len = ft_strlen(str) - i;
	txt = (char *)malloc(sizeof(char *) * (len + 1));
	if (txt == 0)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		txt[j++] = str[i++];
	txt[j] = '\0';
	free(str);
	return (txt);
}

char	*to_read(char *txt, int fd)
{
	char	*str;
	int		len;

	len = 1;
	str = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while ((ft_strchr(txt, '\n')) == NULL && len != 0)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len == -1)
		{
			free(txt);
			free(str);
			return (NULL);
		}
		str[len] = '\0';
		txt = ft_strjoin(txt, str);
	}
	free (str);
	return (txt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(str[fd]), NULL);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	str[fd] = to_read(str[fd], fd);
	if (str[fd] == NULL)
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = removeline(str[fd]);
	return (line);
}
