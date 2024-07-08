/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:27:13 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/08 14:28:45 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	start_mlx(char **map, char **argv)
{
	t_game	game_info;

	if (!map || !*map)
		return (-1);
	game_info.map = map;
	game_info.count_move = 0;
	game_info.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "so_long", false);
	if (!game_info.mlx)
		return (-1);
	game_info.slot_width = WIN_WIDTH / (ft_strlen(map[0]) - 1);
	game_info.slot_height = WIN_HEIGHT / number_of_line(argv);
	create_image(&game_info, &game_info.player, "./my_mlx/assets/player.png");
	create_image(&game_info, &game_info.wall, "./my_mlx/assets/wall.png");
	create_image(&game_info, &game_info.floor, "./my_mlx/assets/floor.png");
	create_image(&game_info, &game_info.collectible, \
	"./my_mlx/assets/collectible.png");
	create_image(&game_info, &game_info.exit, "./my_mlx/assets/exit.png");
	if (init_image(&game_info) == -1)
		exit((ft_free_double(game_info.map), mlx_terminate(game_info.mlx), 1));
	mlx_key_hook(game_info.mlx, move, &game_info);
	mlx_loop(game_info.mlx);
	mlx_terminate(game_info.mlx);
	return (0);
}

void	create_image(t_game *game_info, mlx_image_t **to_change, char *png_name)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png_name);
	png_name++;
	if (!texture)
		return (ft_free_double(game_info->map), \
		mlx_terminate(game_info->mlx), exit(1));
	*to_change = mlx_texture_to_image(game_info->mlx, texture);
	if (!*to_change)
		return (mlx_delete_texture(texture), ft_free_double(game_info->map), \
		mlx_terminate(game_info->mlx), exit(1));
	if (mlx_resize_image(*to_change, game_info->slot_width, \
	game_info->slot_height) == false)
		return (mlx_delete_texture(texture), ft_free_double(game_info->map), \
		mlx_terminate(game_info->mlx), exit(1));
	mlx_delete_texture(texture);
}

int	init_image(t_game *game_info)
{
	int	i;
	int	j;

	i = -1;
	while (game_info->map[++i])
	{
		j = -1;
		while (game_info->map[i][++j] && game_info->map[i][j] != '\n')
		{
			if (draw_good_image(game_info, game_info->map[i][j], \
			j * game_info->slot_width, i * game_info->slot_height) == -1)
				return (-1);
		}
	}
	find_player(game_info->map, &j, &i);
	if (mlx_image_to_window(game_info->mlx, game_info->player, \
	j * game_info->slot_width, i * game_info->slot_height) == -1)
		return (-1);
	return (0);
}

int	draw_good_image(t_game *game_info, char slot, int x, int y)
{
	mlx_image_t	*img;

	img = NULL;
	if (slot == '1')
		img = game_info->wall;
	else if (slot == '0')
		img = game_info->floor;
	else if (slot == 'C')
	{
		if (mlx_image_to_window(game_info->mlx, game_info->floor, x, y) == -1)
			return (-1);
		img = game_info->collectible;
	}
	else if (slot == 'E')
		img = game_info->exit;
	else if (slot == 'P')
		img = game_info->floor;
	if (mlx_image_to_window(game_info->mlx, img, x, y) == -1)
		return (-1);
	return (0);
}
