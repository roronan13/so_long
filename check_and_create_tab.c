/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 16:24:55 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_and_create_tab(char **argv)
{
	char	**map_tab;
	int		line_nbr;
	
	line_nbr = number_of_line(argv, -1);
	map_tab = create_tab(argv, line_nbr);
	if (!map_tab)
	{
		perror("Error\nMalloc failed");
		exit(errno);
	}
	check_rectangle(map_tab);
	check_wrong_caracters(map_tab);
	check_walls(map_tab, line_nbr);
	check_caracters(map_tab);
	if (check_path(map_tab))
	{
		ft_free_double(map_tab);
		exit(1);
	}
		
	return (map_tab);
}

char	**create_tab(char **argv, int line_nbr)
{
	char	**map_tab;
	// int		line_nbr;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((perror("Error\nOpening map file failed"), 1));
	// line_nbr = number_of_line(argv, fd);
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));
	if (!map_tab)
	{
		close(fd);
		return (NULL);
	}
	while (i < line_nbr)
	{
		map_tab[i] = get_next_line(fd);
		if (!map_tab[i])
		{
			ft_free_double(map_tab);
			close(fd);
			return (NULL);
		}
		i++;
	}
	map_tab[i] = get_next_line(fd);
	close(fd);
	return (map_tab);
}
