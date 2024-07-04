/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:32:19 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/04 20:35:15 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free_double(char **ptr)
{
	long unsigned int	i;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

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
