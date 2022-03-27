/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:31:29 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/27 18:31:13 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_line(char *s)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{	
		line[i] = s[i];
		i++;
	}
	if (ft_strchr(s, '\n'))
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_left_line(char *s)
{
	size_t	i;
	size_t	x;
	char	*save;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\n')
		return (NULL);
	save = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!save)
		return (NULL);
	while (s[++i])
		s[i] = save[x++];
	save[x] = 0;
	free(s);
	return (save);
}

char	*ft_read(int fd, char *save)
{
	int		rd;
	char	*buff;

	rd = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (rd && !ft_strchr(save, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = 0;
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_left_line(save);
	return (line);
}
