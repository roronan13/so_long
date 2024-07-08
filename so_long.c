/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:56:46 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/08 16:14:41 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map_tab;

	check_errors(argc, argv);
	map_tab = check_and_create_tab(argv);
	if (start_mlx(map_tab, argv) == -1)
	{
		ft_free_double(map_tab);
		return (1);
	}
	ft_free_double(map_tab);
	return (0);
}
