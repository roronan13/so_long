/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:26:31 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 22:19:34 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **map_tab, int line_nbr)
{
	int		x;
	int		y;
	char	**map_cpy;

	map_cpy = copy_map(map_tab, line_nbr);
	if (!map_cpy)
	{
		perror("Error\nMalloc failed");
		return (1);
	}
	find_player(map_tab, &x, &y);
	flood_fill(map_cpy, x, y);
	if (check_final_map(map_cpy))
	{
		ft_free_double(map_cpy);
		ft_printf("Error\nThere is no valid path !\n");
		return (1);
	}
	ft_free_double(map_cpy);
	return (0);
}

char	**copy_map(char **map_tab, int line_nbr)
{
	char	**map_cpy;
	int		i;
	int		j;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (line_nbr + 1));
	if (!map_cpy)
		return (NULL);
	while (map_tab[i])
	{
		j = 0;
		map_cpy[i] = malloc(sizeof(char) * (ft_strlen(map_tab[i]) + 1));
		if (!map_cpy[i])
			return (ft_free_double(map_cpy), NULL);
		while (map_tab[i][j])
		{
			map_cpy[i][j] = map_tab[i][j];
			j++;
		}
		map_cpy[i][j] = '\0';
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	check_final_map(char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'C' || map_cpy[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(char **map_cpy, int x, int y)
{
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'F')
		return (0);
	map_cpy[y][x] = 'F';
	if (flood_fill(map_cpy, x - 1, y) || flood_fill(map_cpy, x, y - 1)
		|| flood_fill(map_cpy, x + 1, y) || flood_fill(map_cpy, x, y + 1))
		return (1);
	return (0);
}

void	find_player(char **map_tab, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j] && map_tab[i][j] != 'P')
			j++;
		if (map_tab[i][j] == 'P')
		{
			*y = i;
			*x = j;
			return ;
		}
		i++;
	}
}
