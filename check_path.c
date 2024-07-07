/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:26:31 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 16:26:00 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **map_tab)
{
	int		x;
	int		y;
	char	**map_cpy;

	find_player(map_tab, &x, &y);
	ft_printf("x : %d\ny : %d\n", x, y);
	
	int i = 0;
	while (map_tab[i])
	{
		ft_printf("%s", map_tab[i]);
		i++;
	}
	ft_printf("\n%s\n", map_tab[i]);
	
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
	if (flood_fill(map_cpy, x - 1, y) || flood_fill(map_cpy, x, y - 1) || flood_fill(map_cpy, x + 1, y) || flood_fill(map_cpy, x, y + 1))
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
		{
			j++;
		}
		if (map_tab[i][j] == 'P')
		{
			*y = i;
			*x = j;
			return ;
		}
		i++;
	}
}
