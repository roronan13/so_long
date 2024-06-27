/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:56:46 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/27 20:20:20 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"
// #include "get_next_line/get_next_line.h"
// #include "get_next_line/get_next_line.c"
// #include "get_next_line/get_next_line_utils.c"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int line_nbr;
	int fd;
	char *line;

	(void)argc;
	line_nbr = 0;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("opening failed\n");
		return (1);
	}

	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line_nbr++;
		line = get_next_line(fd);
	}
	close (fd);
	printf("line_nbr : %d\n", line_nbr);


	
	
	// fd = open(argv[1], O_RDWR);
	// size = line_number(argv);
	// ft_printf("size : %d\n", size);
	return (0);
}
