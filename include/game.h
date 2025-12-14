/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:24:19 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 15:37:31 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "error.h"
# include "map.h"

typedef struct s_game
{
	t_map	*map;
}	t_game;

t_error	init_game(t_game **game);
void	free_game(t_game *game);

#endif
