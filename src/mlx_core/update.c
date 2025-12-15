/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:56:20 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 21:27:32 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "game.h"
#include "map.h"
#include "mlx.h"
#include "mlx_core.h"
#include "raycast.h"
#include "shapes.h"
#include "utils.h"
#include "vec.h"

int	check_colide(t_game *game)
{
	t_vec2f	pos;

	if (game == NULL)
		return (0);
	pos = game->player_pos;
	if (get_cell_type(game->map, pos.x + COLIDE, pos.y + COLIDE) == WALL)
		return (1);
	if (get_cell_type(game->map, pos.x - COLIDE, pos.y - COLIDE) == WALL)
		return (1);
	if (get_cell_type(game->map, pos.x + COLIDE, pos.y - COLIDE) == WALL)
		return (1);
	if (get_cell_type(game->map, pos.x - COLIDE, pos.y + COLIDE) == WALL)
		return (1);
	return (0);
}

void	logic_movements(t_game *game, float delta)
{
	t_vec2f	before;

	if (game == NULL)
		return ;
	before.x = game->player_pos.x;
	before.y = game->player_pos.y;
	if (game->forward)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(0)), delta));
	if (game->backward)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(180)), delta));
	if (game->left)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(270)), delta));
	if (game->right)
		game->player_pos = vec2f_add(game->player_pos,
				vec2f_div(vec2f_rot(game->direction, rad(90)), delta));
	if (check_colide(game))
	{
		game->player_pos.x = before.x;
		game->player_pos.y = before.y;
	}
}

static void	logic(t_game *game)
{
	long long	time;
	float		delta;
	float		rotation;

	time = get_time();
	delta = time - game->last_time;
	if (game == NULL || delta < 20.f)
		return ;
	game->last_time = time;
	logic_movements(game, delta);
	if (game->view_left || game->view_right)
	{
		rotation = 0;
		if (game->view_left)
			rotation += rad(-ROT_SPEED) / delta;
		if (game->view_right)
			rotation += rad(ROT_SPEED) / delta;
		game->direction = vec2f_rot(game->direction, rotation);
		game->camera_plane = vec2f_rot(game->camera_plane, rotation);
	}
}

int	update(t_mlx_core *core)
{
	if (core == NULL)
		return (0);
	logic(core->game);
	draw_rect(core->screen, (t_rect){0, 0, WIDTH, HEIGHT / 2}, 1,
		core->game->map->color_ceil);
	draw_rect(core->screen, (t_rect){0, HEIGHT / 2, WIDTH, HEIGHT}, 1,
		core->game->map->color_floor);
	raycast(core);
	draw_minimap(core->game, core->screen);
	mlx_put_image_to_window(core->mlx, core->window, core->img, 0, 0);
	return (0);
}
