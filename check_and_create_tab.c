/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:21:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/03 01:43:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_line(char **argv)
{
	int	line_nbr;
	int	fd;

	line_nbr = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	while (get_next_line(fd))
		line_nbr++;
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
	line_nbr = number_of_line(argv);
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

char	**create_tab(char **argv, int line_nbr, int fd)
{
	int		line_len;
	char	**map_tab;
	char	*line;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	line_len = size_of_first_line(argv, fd);
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));
	if (!map_tab)
	{
		// close(fd); deja close dans l'autre dans if (!map_tab)
		// perror
		return (NULL);
	}
	line = get_next_line(fd);
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
	return (map_tab);
}

char	**check_and_create_tab(char **argv)
{
	int		line_nbr;
	int		fd;
	char	**map_tab;

	line_nbr = number_of_line(argv);
	if (line_nbr <= 2)
		exit((ft_printf("Error\nMap is too small !\n"), 1));
		
	if (check_rectangle(argv))
		exit((ft_printf("Error\nThis map is not a rectangle !\n"), 1));
		
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	map_tab = create_tab(argv, line_nbr, fd);
	if (!map_tab)
	{
		close(fd);
		exit(errno);
	}
	close(fd);
	
	if (check_walls(argv))
	{
		// ft_free_tab map_tab
		exit((ft_printf("Error\nMap is not surrounded by walls !\n"), 1));
	}

	
	
	return (map_tab);
}

	/* fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nOpening map file failed !\n"), 1));
	line_len = size_of_first_line(argv);
	
	map_tab = malloc(sizeof(char *) * (line_nbr + 1));

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
	map_tab[i] = NULL; */
	
	/* ft_printf("line_nbr : %d\n", line_nbr);
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
	} */