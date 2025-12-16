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

static int	collide(t_map *map, t_vec2f pos)
{
	if (map == NULL)
		return (0);
	if (get_cell_type(map, pos.x + COLIDE, pos.y + COLIDE) == WALL)
		return (1);
	if (get_cell_type(map, pos.x - COLIDE, pos.y - COLIDE) == WALL)
		return (1);
	if (get_cell_type(map, pos.x + COLIDE, pos.y - COLIDE) == WALL)
		return (1);
	if (get_cell_type(map, pos.x - COLIDE, pos.y + COLIDE) == WALL)
		return (1);
	return (0);
}

static void	logic_collisions(t_game *game, t_vec2f before)
{
	if (game == NULL)
		return ;
	if (collide(game->map, game->player_pos))
	{
		if (!collide(game->map, (t_vec2f){before.x, game->player_pos.y}))
			game->player_pos.x = before.x;
		else if (!collide(game->map, (t_vec2f){game->player_pos.x, before.y}))
			game->player_pos.y = before.y;
		else
			game->player_pos = before;
	}
}

static void	logic_movements(t_game *game, float delta)
{
	t_vec2f	before;

	if (game == NULL)
		return ;
	before = game->player_pos;
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
	logic_collisions(game, before);
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
