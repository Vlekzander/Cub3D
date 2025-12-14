/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:28:33 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 16:07:24 by apierret         ###   ########.fr       */
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
	return (*game = new_game, ERR_NONE);
}
