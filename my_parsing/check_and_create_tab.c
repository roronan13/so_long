/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/08 14:51:42 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**check_and_create_tab(char **argv)
{
	char	**map_tab;
	int		line_nbr;

	line_nbr = number_of_line(argv);
	if (line_nbr > 30)
		exit((ft_printf("Error\nMap is too long !\n"), 1));
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
	if (check_path(map_tab, line_nbr))
	{
		ft_free_double(map_tab);
		exit(1);
	}
	return (map_tab);
}

char	**create_tab(char **argv, int line_nbr)
{
	char	**map_tab;
	int		i;
	int		fd;

	i = -1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((perror("Error\nOpening map file failed"), 1));
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));
	if (!map_tab)
		return (close(fd), NULL);
	while (++i < line_nbr)
	{
		map_tab[i] = get_next_line(fd);
		if (!map_tab[i])
		{
			ft_free_double(map_tab);
			close(fd);
			return (NULL);
		}
	}
	map_tab[i] = get_next_line(fd);
	close(fd);
	return (map_tab);
}
