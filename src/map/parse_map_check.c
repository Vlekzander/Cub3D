/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:03:50 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 16:03:10 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "error.h"
#include "libft.h"
#include "map.h"

static t_error	check_split(t_map *map, unsigned char *map_check)
{
	int			i;
	int			j;

	if (map == NULL || map_check == NULL)
		return (ERR_IMPLEMENTATION);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_check[i * map->width + j] == 0
				&& get_cell_type(map, j, i) != OUTSIDE)
				return (ERR_MAP_SPACE);
			j++;
		}
		i++;
	}
	return (ERR_NONE);
}

static t_error	flood_fill(t_map *map, unsigned char *map_check,
						int pos[2], t_cell_type from)
{
	t_cell_type	cell;

	if (map == NULL || map_check == NULL)
		return (ERR_IMPLEMENTATION);
	cell = get_cell_type(map, pos[0], pos[1]);
	if (cell == OUTSIDE)
	{
		if (from == SPACE)
			return (ERR_MAP_NOT_CLOSED);
		return (ERR_NONE);
	}
	if (map_check[pos[1] * map->width + pos[0]] == 1)
		return (ERR_NONE);
	map_check[pos[1] * map->width + pos[0]] = 1;
	if (flood_fill(map, map_check, (int []){pos[0] - 1, pos[1]}, cell)
		|| flood_fill(map, map_check, (int []){pos[0] + 1, pos[1]}, cell)
		|| flood_fill(map, map_check, (int []){pos[0], pos[1] - 1}, cell)
		|| flood_fill(map, map_check, (int []){pos[0], pos[1] + 1}, cell))
		return (ERR_MAP_NOT_CLOSED);
	return (ERR_NONE);
}

t_error	parse_map_check(t_map *map)
{
	t_error			error;
	unsigned char	*map_check;

	if (map == NULL)
		return (ERR_IMPLEMENTATION);
	if (map->spawn_x == -1)
		return (ERR_MAP_SPAWN);
	map_check = ft_calloc(map->width * map->height, sizeof(unsigned char));
	if (map_check == NULL)
		return (ERR_ALLOCATION);
	error = flood_fill(map, map_check,
			(int []){map->spawn_x, map->spawn_y}, SPACE);
	if (error != ERR_NONE)
		return (free(map_check), error);
	error = check_split(map, map_check);
	if (error != ERR_NONE)
		return (free(map_check), error);
	return (free(map_check), ERR_NONE);
}
