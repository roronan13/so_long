/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/02 17:14:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_and_create_tab(char **argv)
{
	int		line_nbr;
	int		line_len;
	int		fd;
	char	**map_tab;
	char	*line;
	int		i;
	int		j;

	line_nbr = 1;
	i = 0;
	j = 0;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	line_len = ft_strlen(get_next_line(fd));
	while (get_next_line(fd))
		line_nbr++;
		
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));

	close(fd);
	fd = open(argv[1], O_RDONLY);
	/* if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
		// free; */
	line = get_next_line(fd);
	while (line)
	{
		map_tab[i] = malloc(sizeof(char) * line_len);
		while (j < line_len - 1)
		{
			map_tab[i][j] = line[j];
			j++;
		}
		map_tab[i][j] = '\0';
		j = 0;
		i++;
		free(line);		
		line = get_next_line(fd);
	}
	ft_printf("i : %d\n", i);
	map_tab[i] = NULL;
	
	ft_printf("line_nbr : %d\n", line_nbr);
	ft_printf("line_len : %d\n", line_len);

	i = 0;
	j = 0;
	while (map_tab[i])
	{
		while(map_tab[i][j])
		{
			ft_printf("%c", map_tab[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}

	
	
	close(fd);
	return (map_tab);
}
