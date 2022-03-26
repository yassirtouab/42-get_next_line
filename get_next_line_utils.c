/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:31:21 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/27 00:14:23 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == 0)
		return ((char *)str);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	x;
	size_t	l;

	i = start;
	x = 0;
	if (!s)
		return (0);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (i < l && x < len)
		ret[x++] = s[i++];
	ret[x] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a[4];

	a[0] = 0;
	a[1] = 0;
	if (!s1 || !s2)
		return (0);
	a[2] = ft_strlen(s1);
	a[3] = ft_strlen(s2);
	ret = (char *)malloc((a[2] + a[3] + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (a[0] < a[2])
	{
		ret[a[0]] = s1[a[0]];
		a[0]++;
	}
	while (a[1] < a[3])
		ret[a[0]++] = s2[a[1]++];
	ret[a[0]] = 0;
	free(s1);
	return (ret);
}
