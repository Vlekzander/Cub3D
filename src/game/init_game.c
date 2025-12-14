/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:28:33 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 19:02:52 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "game.h"
#include "map.h"

t_error	init_game(t_game **game, char *map_path)
{
	t_error	error;
	t_game	*new_game;

	if (game == NULL)
		return (ERR_IMPLEMENTATION);
	new_game = ft_calloc(1, sizeof(t_game));
	if (new_game == NULL)
		return (ERR_ALLOCATION);
	error = parse_map(&new_game->map, map_path);
	if (error != ERR_NONE)
		return (free_game(new_game), error);
	new_game->player_pos.x = new_game->map->spawn_x;
	new_game->player_pos.y = new_game->map->spawn_y;
	new_game->direction.x = 0;
	new_game->direction.y = -1;
	new_game->camera_plane.x = 0.88888888;
	new_game->camera_plane.y = 0;
	return (*game = new_game, ERR_NONE);
}
