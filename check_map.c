/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpothier <ronanpothier@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:46:06 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/25 23:14:14 by ronanpothie      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>


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
