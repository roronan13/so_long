/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:27:13 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 19:19:05 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_image(t_game *game_info, mlx_image_t **to_change, char *png_name)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png_name);
	if (!texture)
		return (-1);
	*to_change = mlx_texture_to_image(game_info->mlx, texture);
	if (!*to_change)
		return (-1);
	mlx_delete_texture(texture);
	return (0);
}

int	start_mlx(char **map, char **argv)
{
	t_game	game_info;

	if (!map || !*map)
		return (-1);
	game_info.map = map;
	game_info.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "so_long", false);
	if (!game_info.mlx)
		return (-1);
	game_info.slot_width = WIN_WIDTH / (ft_strlen(map[0]) - 1);
	game_info.slot_height = WIN_HEIGHT / number_of_line(argv);
	create_image(&game_info, &game_info.player, "./src/assets/player.png");
	create_image(&game_info, &game_info.wall, "./src/assets/wall.png");
	create_image(&game_info, &game_info.floor, "./src/assets/floor.png");
	create_image(&game_info, &game_info.collectible, "./src/assets/collectible.png");
	create_image(&game_info, &game_info.exit, "./src/assets/exit.png");
	mlx_loop(game_info.mlx);
	mlx_terminate(game_info.mlx);
	return (0);
}
