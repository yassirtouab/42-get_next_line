/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:31:29 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/27 00:30:52 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_line(char *s)
{

	return (NULL);
}

char	*ft_left_line(char *s)
{

	return (NULL);
}

char	*ft_read(int fd)
{
	int		rd;
	char	*buff;
	char	*save;

	rd = 1;
	save = (char *)malloc(1);
	save[0] = 0;
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
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read(fd);
	if (!buff)
		return (NULL);
	return (buff);
}
