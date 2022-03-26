/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:27:14 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/27 00:27:14 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int 	i = 0;
	int	    fd;
	char 	*str;
		
	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (i == 10)
			break;
		printf("Line %d: |%s|\n", i + 1, str);
		free(str);
		i++;
	}
	if (str)
		free(str);	
	return (1);

}