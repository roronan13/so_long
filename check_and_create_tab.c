/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/02 15:39:01 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_and_create_tab(char **argv)
{
	int		line_nbr;
	int		line_len;
	int		fd;
	char	**map_tab;

	line_nbr = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	line_len = ft_strlen(get_next_line(fd));
	while (get_next_line(fd))
		line_nbr++;
	map_tab = malloc(size_of());
	
	ft_printf("line_nbr : %d\n", line_nbr);
	ft_printf("line_len : %d\n", line_len);

	
	
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
