/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:34:54 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/08 14:46:53 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangle(char **map_tab)
{
	int	line_len;
	int	i;

	i = 0;
	line_len = ft_strlen(map_tab[i]);
	if (line_len > 30)
		exit((ft_free_double(map_tab), \
		ft_printf("Error\nMap is too large !\n"), 1));
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

void	check_wrong_caracters(char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] != '0' && map_tab[i][j] != '1'
			&& map_tab[i][j] != 'C' && map_tab[i][j] != 'P'
			&& map_tab[i][j] != 'E' && map_tab[i][j] != '\n')
			{
				ft_free_double(map_tab);
				ft_printf("Error\nYou have wrong caracters in your map !\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(char **map_tab, int line_nbr)
{
	int	i;
	int	j;

	i = -1;
	while (map_tab[++i])
	{
		if (i == 0 || i == line_nbr - 1)
		{
			j = 0;
			while (map_tab[i][j] && map_tab[i][j] != '\n')
			{
				if (map_tab[i][j] != '1')
					exit((ft_printf("Error\nNot surrounded by walls !\n"), \
					ft_free_double(map_tab), 1));
				j++;
			}
		}
		else
		{
			if (map_tab[i][0] != '1'
				|| map_tab[i][ft_strlen(map_tab[i]) - 2] != '1')
				exit((ft_printf("Error\nNot surrounded by walls !\n"), \
				ft_free_double(map_tab), 1));
		}
	}
}
