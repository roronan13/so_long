/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:45:57 by rpothier          #+#    #+#             */
/*   Updated: 2024/07/08 16:50:20 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(mlx_key_data_t key, void *param)
{
	t_game	*game_info;

	game_info = param;
	if (key.key == MLX_KEY_W && key.action == 1
		&& check_collisions(game_info, UP) == 1)
		game_info->player->instances->y -= game_info->slot_height;
	if (key.key == MLX_KEY_S && key.action == 1
		&& check_collisions(game_info, DOWN) == 1)
		game_info->player->instances->y += game_info->slot_height;
	if (key.key == MLX_KEY_A && key.action == 1
		&& check_collisions(game_info, LEFT) == 1)
		game_info->player->instances->x -= game_info->slot_width;
	if (key.key == MLX_KEY_D && key.action == 1
		&& check_collisions(game_info, RIGHT) == 1)
		game_info->player->instances->x += game_info->slot_width;
	if (key.key == MLX_KEY_ESCAPE)
		exit((mlx_terminate(game_info->mlx), \
		ft_free_double(game_info->map), 1));
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_S || key.key == MLX_KEY_A
			|| key.key == MLX_KEY_D) && key.action == 1)
	{
		game_info->count_move++;
		ft_printf("moove : %d\n", game_info->count_move);
	}
	check_player_and_collectible(game_info);
}

int	check_collisions(t_game *game_info, int dir)
{
	int	pos_x;
	int	pos_y;

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
	int		pos_x;
	int		pos_y;
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
			exit(0), 0);
	return (0);
}
