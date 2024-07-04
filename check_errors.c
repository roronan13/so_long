/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:20:51 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/04 17:31:48 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(int argc, char **argv)
{
	if (check_args(argc))
	{
		ft_printf("Error\nOnly map file is needed as argument !\n");
		exit(1);
	}
	if (check_extension(argv[1], ".ber"))
	{
		ft_printf("Error\nMap file extension MUST be .ber !\n");
		exit (1);
	}
}

int	check_args(int argc)
{
	if (argc != 2)
		return (1);
	else
		return (0);
}

int	check_extension(char *name, char *ext)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(ext);
	if (ft_strncmp(&name[name_len - ext_len], ext, ext_len))
		return (1);
	else
		return (0);
}

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
