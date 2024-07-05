/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:26:31 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/05 20:29:16 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **map_tab)
{
	int	x;
	int	y;

	find_player(map_tab, &x, &y);
	ft_printf("x : %d\ny : %d\n", x, y);
	
	int i = 0;
	while (map_tab[i])
	{
		ft_printf("%s", map_tab[i]);
		i++;
	}
	ft_printf("\n%s\n", map_tab[i]);
	
	flood_fill(map_tab, x , y);

	
	return (0);
}

int	flood_fill(char **map_tab, int x, int y)
{
	if (map_tab[y][x] == '1' || map_tab[y][x] == 'F')
		return (0);
	
	map_tab[y][x] = 'F';
	// ft_printf("allo\n");
	if (flood_fill(map_tab, x - 1, y) || flood_fill(map_tab, x, y - 1) || flood_fill(map_tab, x + 1, y) || flood_fill(map_tab, x, y + 1))
	{
		return (1);
	}
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
