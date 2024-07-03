/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:19:00 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/03 23:39:51 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

void	check_errors(int argc, char **argv);
int	check_args(int argc);
int	check_extension(char *name, char *ext);
char	**ft_free_double(char **ptr);

char	**check_and_create_tab(char **argv);
int	check_rectangle(char **argv);

int	number_of_line(char **argv, int fd_2);

#endif