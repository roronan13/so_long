/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:27:13 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/07 21:47:53 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_image(t_game *game_info, mlx_image_t **to_change, char *png_name)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png_name);
	png_name++;
	if (!texture)
		return (ft_free_double(game_info->map), mlx_terminate(game_info->mlx), exit(1));
	*to_change = mlx_texture_to_image(game_info->mlx, texture);
	if (!*to_change)
		return (mlx_delete_texture(texture), ft_free_double(game_info->map), mlx_terminate(game_info->mlx), exit(1));
	if (mlx_resize_image(*to_change, game_info->slot_width, game_info->slot_height) == false)
		return (mlx_delete_texture(texture), ft_free_double(game_info->map), mlx_terminate(game_info->mlx), exit(1));
	mlx_delete_texture(texture);
}

int check_collisions(t_game *game_info, int dir)
{
	int pos_x;
	int pos_y;

	pos_x = game_info->player->instances->x / game_info->slot_width;
	pos_y = game_info->player->instances->y / game_info->slot_height;
	if (dir == UP)
		if (game_info->map[pos_y - 1][pos_x] == '1')
			return (-1);
	if (dir == DOWN)
		if (game_info->map[pos_y + 1][pos_x] == '1')
			return (-1);
	if (dir == LEFT)
		if (game_info->map[pos_y][pos_x - 1] == '1')
			return (-1);
	if (dir == RIGHT)
		if (game_info->map[pos_y][pos_x + 1] == '1')
			return (-1);
	return (1);
}

int	check_player_and_collectible(t_game *game_info)
{
	int 	pos_x;
	int 	pos_y;
	int		i;
	int		is_collectible_visible;

	i = 0;
	is_collectible_visible = 0;
	pos_x = game_info->player->instances->x;
	pos_y = game_info->player->instances->y;
	i = -1;
	while ((size_t)++i < game_info->collectible->count)
	{
		if (game_info->collectible->instances[i].x == pos_x
			&& game_info->collectible->instances[i].y == pos_y)
			return (game_info->collectible->instances[i].enabled = false, 1);
		if (game_info->collectible->instances[i].enabled == true)
			is_collectible_visible = 1;
	}
	if (game_info->player->instances[0].x == game_info->exit->instances[0].x
		&& game_info->player->instances[0].y == game_info->exit->instances[0].y
		&& !is_collectible_visible)
		return (ft_free_double(game_info->map), mlx_terminate(game_info->mlx),
			exit(1), 0);
	return (0);
}

void	move(mlx_key_data_t key, void *param)
{
	t_game *game_info;

	game_info = param;
	if (key.key == MLX_KEY_W && key.action == 1 && check_collisions(game_info, UP) == 1)
		game_info->player->instances->y -= game_info->slot_height;
	if (key.key == MLX_KEY_S && key.action == 1 && check_collisions(game_info, DOWN) == 1)
		game_info->player->instances->y += game_info->slot_height;
	if (key.key == MLX_KEY_A && key.action == 1 && check_collisions(game_info, LEFT) == 1)
		game_info->player->instances->x -= game_info->slot_width;
	if (key.key == MLX_KEY_D && key.action == 1 && check_collisions(game_info, RIGHT) == 1)
		game_info->player->instances->x += game_info->slot_width;
	if (key.key == MLX_KEY_ESCAPE)
		exit((mlx_terminate(game_info->mlx), ft_free_double(game_info->map), 1));
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_S || key.key == MLX_KEY_A
		|| key.key == MLX_KEY_D) && key.action == 1)
	{
		game_info->count_move++;
		ft_printf("moove : %d\n", game_info->count_move);
	}
	check_player_and_collectible(game_info);
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
			if (draw_good_image(game_info, game_info->map[i][j], j * game_info->slot_width, i * game_info->slot_height) == -1)
				return (-1);
		}
	}
	find_player(game_info->map, &j, &i);
	if (mlx_image_to_window(game_info->mlx, game_info->player, j * game_info->slot_width, i * game_info->slot_height) == -1)
		return (-1);
	return (0);
}

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
	create_image(&game_info, &game_info.player, "./src/assets/player.png");
	create_image(&game_info, &game_info.wall, "./src/assets/wall.png");
	create_image(&game_info, &game_info.floor, "./src/assets/floor.png");
	create_image(&game_info, &game_info.collectible, "./src/assets/collectible.png");
	create_image(&game_info, &game_info.exit, "./src/assets/exit.png");
	if (init_image(&game_info) == -1)
		exit((ft_free_double(game_info.map), mlx_terminate(game_info.mlx), 1));
	mlx_key_hook(game_info.mlx, move, &game_info);
	mlx_loop(game_info.mlx);
	mlx_terminate(game_info.mlx);
	return (0);
}
