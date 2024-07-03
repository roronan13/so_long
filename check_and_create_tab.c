/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/04 01:01:25 by rpothier         ###   ########.fr       */
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

int	size_of_first_line(char **argv, int fd)
{
	int	fd_2;
	int	size;
	
	fd_2 = open(argv[1], O_RDONLY);
	if (fd_2 == -1)
	{
		close(fd);
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	}
	size = ft_strlen(get_next_line(fd_2));
	close(fd_2);
	return (size);
}

int	check_rectangle(char **argv)
{
	int		line_nbr;
	int		line_len;
	int		line_len_comp;
	int		fd;

	line_nbr = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	line_nbr = number_of_line(argv, -1);
	line_len = ft_strlen(get_next_line(fd));
	while (line_nbr - 2)
	{
		line_len_comp = ft_strlen(get_next_line(fd));
		if (line_len_comp != line_len)
		{
			close(fd);
			return (1);
		}
		line_nbr--;
	}
	if (line_len != (int)ft_strlen(get_next_line(fd)) + 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

char	**create_tab(char **argv)
{
	char	**map_tab;
	int		line_nbr;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((perror("Error\nOpening map file failed"), 1));
	line_nbr = number_of_line(argv, fd);
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));
	if (!map_tab)
	{
		close(fd);
		perror("Error\nMalloc failed");
		exit(errno);
	}
	while (i < line_nbr)
	{
		map_tab[i] = get_next_line(fd);
		if (!map_tab[i])
		{
			ft_free_double(map_tab);
			close(fd);
			perror("%i - Error\nMalloc failed");
			exit(errno);
		}
		i++;
	}
	//map_tab[i] = NULL;
	close(fd);
	return (map_tab);
	

	
	/* line = get_next_line(fd);
	while (line)
	{
		map_tab[i] = malloc(sizeof(char) * line_len);
		if (!map_tab[i])
		{
			// ft_free_tab map_tab
			free(line);
			// perror
			return (NULL);
		}
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
	map_tab[i] = NULL;
	return (map_tab); */
}

char	**check_and_create_tab(char **argv)
{
	char	**map_tab;
	
	map_tab = create_tab(argv);
	if (!map_tab)
	{
		perror("Error\nMalloc failed");
		exit(errno);
	}

	return (map_tab);
}
