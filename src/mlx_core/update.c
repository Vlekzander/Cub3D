/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:56:20 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 20:51:27 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "game.h"
#include "image.h"
#include "map.h"
#include "mlx.h"
#include "mlx_core.h"
#include "raycast.h"
#include "shapes.h"
#include "utils.h"
#include "vec.h"

static void	clear_screen(t_image *image)
{
	int	i;
	int	size;

	if (image == NULL)
		return ;
	size = image->width * image->height;
	i = 0;
	while (i < size)
	{
		image->pixels[i] = 0;
		i++;
	}
}

void	logic_movements(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->forward)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(game->direction, GAME_SPEED));
	if (game->backward)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(180)), GAME_SPEED));
	if (game->left)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(270)), GAME_SPEED));
	if (game->right)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(90)), GAME_SPEED));
}

void	logic(t_game *game)
{
	long long	time;
	long long	delta;

	time = get_time();
	delta = time - game->last_time;
	if (game == NULL || delta < 20)
		return ;
	game->last_time = time;
	logic_movements(game);
	if (game->view_left)
	{
		game->direction = vec2f_rot(game->direction,
				rad(-ROT_SPEED) / GAME_SPEED);
		game->camera_plane = vec2f_rot(game->camera_plane,
				rad(-ROT_SPEED / GAME_SPEED));
	}
	if (game->view_right)
	{
		game->direction = vec2f_rot(game->direction,
				rad(ROT_SPEED) / GAME_SPEED);
		game->camera_plane = vec2f_rot(game->camera_plane,
				rad(ROT_SPEED / GAME_SPEED));
	}
}

int	update(t_mlx_core *core)
{
	if (core == NULL)
		return (0);
	logic(core->game);
	clear_screen(core->screen);
	draw_rect(core->screen, (t_rect){0, 0, WIDTH, HEIGHT / 2}, 1,
		core->game->map->color_ceil);
	draw_rect(core->screen, (t_rect){0, HEIGHT / 2, WIDTH, HEIGHT}, 1,
		core->game->map->color_floor);
	raycast(core, core->game->map);
	mlx_put_image_to_window(core->mlx, core->window, core->img, 0, 0);
	return (0);
}
