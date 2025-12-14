/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:22:35 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/14 20:34:10 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "raycast.h"
#include "error.h"

t_error	raycast(t_mlx_core *core)
{
	t_vec2f			dir;
	float			camera_x;
	t_hit_result	hit;
	int				x;
	t_error			e;

	if (core == NULL)
		return (ERR_IMPLEMENTATION);
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		dir.x = core->game->direction.x
			+ core->game->camera_plane.x * camera_x;
		dir.y = core->game->direction.y
			+ core->game->camera_plane.y * camera_x;
		e = dda(&hit, core->game->map,
				(t_vec2f){core->game->player_pos.x,
				core->game->player_pos.y}, dir);
		if (e)
			return (e);
		draw_stripe(core, &hit, dir, x);
		x++;
	}
	return (ERR_NONE);
}
