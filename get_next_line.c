/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:31:29 by ytouab            #+#    #+#             */
/*   Updated: 2021/10/22 17:03:25 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_line(char **s, size_t i)
{
	char	*tmp;
	char	*ret;

	if (ft_strchr(*s, '\n'))
	{
		tmp = *s;
		ret = ft_substr(*s, 0, i);
		*s = ft_strdup(tmp + i);
		free(tmp);
		tmp = NULL;
		return (ret);
	}
	else if (*s)
	{
		tmp = ft_strdup(*s);
		ft_clear(s);
		return (tmp);
	}
	return (NULL);
}

int	ft_nl_index(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_read(char **save, int fd, int rd)
{
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	while (rd && !ft_strchr(*save, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		tmp = *save;
		*save = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (rd);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	int			rd;
	size_t		nl_index;

	rd = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	rd = ft_read(&save[fd], fd, rd);
	if (!*save[fd] && rd <= 0)
	{
		ft_clear(&save[fd]);
		return (NULL);
	}
	nl_index = ft_nl_index(save[fd]);
	return (ft_line(&save[fd], nl_index + 1));
}
