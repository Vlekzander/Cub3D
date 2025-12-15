/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:14 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 21:31:50 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "game.h"
#include "map.h"
#include "mlx_core.h"
#include "shapes.h"

static int	get_color(t_cell_type cell)
{
	if (cell == OUTSIDE)
		return (MAP_OUTSIDE);
	if (cell == WALL)
		return (MAP_WALL);
	if (cell == SPACE)
		return (MAP_SPACE);
	return (0);
}

void	draw_minimap(t_game *game, t_image *screen)
{
	int			i;
	int			j;
	int			color;
	int			space;

	if (game == NULL || screen == NULL || !game->minimap)
		return ;
	space = HEIGHT - (MAP_CELL * (game->map->height + 2));
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			color = get_color(get_cell_type(game->map, j, i));
			if (j == (int) game->player_pos.x && i == (int) game->player_pos.y)
				color = 0xFFFF0000;
			draw_rect(screen, (t_rect){MAP_CELL * 2 + (MAP_CELL * j),
				space + (MAP_CELL * i), MAP_CELL, MAP_CELL}, 1, color);
			j++;
		}
		i++;
	}
}
