/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:38:20 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 22:18:45 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_caracters(char **map_tab)
{
	if (check_player(map_tab) != 1)
	{
		ft_free_double(map_tab);
		ft_printf("Error\nYou must have ONE player in your map !\n");
		exit(1);
	}
	if (check_collectible(map_tab) < 1)
	{
		ft_free_double(map_tab);
		ft_printf("Error\nYou must have at least one \
		collectible in your map !\n");
		exit(1);
	}
	if (check_exit(map_tab) != 1)
	{
		ft_free_double(map_tab);
		ft_printf("Error\nYou must have ONE exit in your map !\n");
		exit(1);
	}
}

int	check_player(char **map_tab)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (p);
}

int	check_collectible(char **map_tab)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	check_exit(char **map_tab)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	return (e);
}
