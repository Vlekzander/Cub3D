/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:28:33 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 15:30:09 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "game.h"

t_error	init_game(t_game **game)
{
	t_game	*new_game;

	if (game == NULL)
		return (ERR_IMPLEMENTATION);
	new_game = ft_calloc(1, sizeof(t_game));
	if (new_game == NULL)
		return (ERR_ALLOCATION);
	return (*game = new_game, ERR_NONE);
}
