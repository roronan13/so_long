/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:46:06 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/07/02 14:59:54 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **argv)
{
	int	line_nbr;
	int	line_len;
	int	fd;

	line_nbr = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	while (get_next_line(fd))
		line_nbr++;
	
	ft_printf("line_nbr : %d\n", line_nbr);
	
	
	
	close(fd);
	
}
/* int line_number(char **argv)
{
    int line_nbr;
    char *line;
    int fd;

    line_nbr = 0;
    	fd = open(argv[1], O_RDONLY);

    printf("fd : %d\n", fd);
    line = get_next_line(fd);
        // line = get_next_line(fd);
        
        

    printf("line : %s\n", line);
    while (line)
    {
        // free(line);
        line_nbr++;
        line = get_next_line(fd);
    }
    close(fd);
    return (line_nbr);
} */
