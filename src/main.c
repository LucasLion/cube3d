/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:37:53 by llion             #+#    #+#             */
/*   Updated: 2023/05/07 03:36:42 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("maps/map1.cub", O_RDONLY);
	printf("fd: %d\n", fd);		

	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}
