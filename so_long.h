/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:19:00 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/27 23:39:37 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	check_errors(int argc, char **argv);
int	check_args(int argc);
int	check_extension(char *name, char *ext);

int line_number(char **argv);

#endif