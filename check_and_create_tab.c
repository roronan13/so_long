/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/04 17:17:47 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_line(char **argv, int fd_2)
{
	int		line_nbr;
	int		fd;
	char	*line;

	line_nbr = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		if (fd_2 != -1)
			close(fd_2);
		exit((perror("Error\nOpening map file failed\n"), 1));
	}
	line = get_next_line(fd);
	while (line)
	{
		line_nbr++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_nbr);
}

void	check_rectangle(char **map_tab)
{
	int	line_len;
	int	i;

	i = 0;
	line_len = ft_strlen(map_tab[i]);
	while (map_tab[i + 1])
	{
		if ((int)ft_strlen(map_tab[i]) != line_len)
		{
			ft_free_double(map_tab);
			ft_printf("Error\nThis map is not a rectangle !\n");
			exit (1);
		}
		i++;
	}
	if ((int)ft_strlen(map_tab[i]) != line_len - 1)
	{
		ft_free_double(map_tab);
		ft_printf("Error\nThis map is not a rectangle !\n");
		exit (1);
	}
}

void	check_walls(char **map_tab, int line_nbr)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i])
	{
		if (i == 0 || i == line_nbr - 1)
		{
			j = 0;
			while (map_tab[i][j] && map_tab[i][j] != '\n')
			{
				if (map_tab[i][j] != '1')
				{
					ft_free_double(map_tab);
					ft_printf("Error\nThis map is not surrounded by walls !\n");
					exit(1);
				}
				j++;
			}
		}
		else
		{
			if (map_tab[i][0] != '1' || map_tab[i][ft_strlen(map_tab[i]) - 2] != '1')
			{
				ft_free_double(map_tab);
				ft_printf("Error\nThis map is not surrounded by walls !\n");
				exit(1);
			}
		}
		i++;
	}
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
	check_walls(map_tab, line_nbr);
	

	return (map_tab);
}
