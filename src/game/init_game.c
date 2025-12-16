/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:28:33 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 16:00:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "game.h"
#include "map.h"

static void	set_player_direction(t_game *game)
{
	if (game == NULL)
		return ;
	game->direction = (t_vec2f){0, -1};
	game->camera_plane = (t_vec2f){0.88888888f, 0};
	if (game->map->facing == SOUTH)
	{
		game->direction = (t_vec2f){0, 1};
		game->camera_plane = (t_vec2f){-0.88888888f, 0};
	}
	else if (game->map->facing == EAST)
	{
		game->direction = (t_vec2f){1, 0};
		game->camera_plane = (t_vec2f){0, 0.88888888f};
	}
	else if (game->map->facing == WEST)
	{
		game->direction = (t_vec2f){-1, 0};
		game->camera_plane = (t_vec2f){0, -0.88888888f};
	}
}

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
	new_game->player_pos.x = new_game->map->spawn_x + 0.5f;
	new_game->player_pos.y = new_game->map->spawn_y + 0.5f;
	set_player_direction(new_game);
	return (*game = new_game, ERR_NONE);
}
