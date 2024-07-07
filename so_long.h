/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:19:00 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 21:48:03 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	char			**map;
	unsigned int	slot_width;
	unsigned int	slot_height;
	int				count_move;
}	t_game;

void	check_errors(int argc, char **argv);
int		check_args(int argc);
int		check_extension(char *name, char *ext);

char	**check_and_create_tab(char **argv);
char	**create_tab(char **argv, int line_nbr);

void	check_rectangle(char **argv);
void	check_wrong_caracters(char **map_tab);
void	check_walls(char **map_tab, int line_nbr);

void	check_caracters(char **map_tab);
int		check_player(char **map_tab);
int		check_collectible(char **map_tab);
int		check_exit(char **map_tab);

int		check_path(char **map_tab, int line_nbr);
char	**copy_map(char **map_tab, int line_nbr);
int		check_final_map(char **map_cpy);
void	find_player(char **map_tab, int *x, int *y);
int		flood_fill(char **map_tab, int x, int y);

char	**ft_free_double(char **ptr);
int		number_of_line(char **argv);

int		start_mlx(char **map, char **argv);

#endif