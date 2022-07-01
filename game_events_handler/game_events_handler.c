/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:24:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:43:54 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_map_boundaries(t_data *mlx, int desired_move, char x_or_y)
{
	int y_boundaries;
	int	x_boundaries;
 
	x_boundaries = (mlx->map_dimensions.columns * DEFAULT_PIXEL_SIZE) - DEFAULT_PIXEL_SIZE;
	y_boundaries = (mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE) - DEFAULT_PIXEL_SIZE;
	if (x_or_y == 'x' && (mlx->img_player.x + desired_move < DEFAULT_PIXEL_SIZE || mlx->img_player.x + desired_move >= x_boundaries))
		desired_move = 0;
	else if (x_or_y == 'y' && (mlx->img_player.y + desired_move < DEFAULT_PIXEL_SIZE || mlx->img_player.y + desired_move >= y_boundaries))
		desired_move = 0;
	return (desired_move);
}

void	floor_replace_player(t_data *mlx)
{
	mlx->img_floor.y = mlx->img_player.y;
	mlx->img_floor.x = mlx->img_player.x;
	image_put(mlx, &mlx->img_floor);
}

void	player_move(t_data *mlx, char x_or_y, int positive_negative)
{
	int desired_move;

	desired_move = DEFAULT_PIXEL_SIZE * positive_negative;
	if (!is_in_map_boundaries(mlx, desired_move,x_or_y))
		return ;
	floor_replace_player(mlx);
	if (x_or_y == 'x')
		mlx->img_player.x += desired_move;
	else
		mlx->img_player.y += desired_move;
	image_put(mlx, &mlx->img_player);
}

int	deal_key_press(int key, t_data *mlx)
{
    if (key == KEY_SCAPE)
		game_exit(mlx);
	else if (key == KEY_W)
		player_move(mlx, 'y', -1);
	else if (key == KEY_A)
		player_move(mlx, 'x', -1);
	else if (key == KEY_S)
		player_move(mlx, 'y', 1);
	else if (key == KEY_D)
		player_move(mlx, 'x', 1);
    return (0);
}

void	handle_events(t_data *mlx)
{
	mlx_hook(mlx->win_ptr, KEY_PRESS_EVENT, (1L<<0), &deal_key_press, mlx);
	mlx_hook(mlx->win_ptr, DESTROY_NOTIFY_EVENT, (1L<<17), &game_exit, mlx);
}