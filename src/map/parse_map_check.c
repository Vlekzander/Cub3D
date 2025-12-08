/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:03:50 by apierret          #+#    #+#             */
/*   Updated: 2025/12/08 12:19:52 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "error.h"
#include "libft.h"
#include "map.h"

static int	next_space(t_map *map, unsigned char *map_check, int *x, int *y)
{
	int	i;
	int	j;

	if (map == NULL || map_check == NULL)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_check[i * map->width + j] == 0
				&& get_cell_type(map, j, i) == SPACE)
				return (*x = j, *y = i, 1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_error	flood_fill(t_map *map, unsigned char *map_check, int x, int y)
{
	if (map == NULL || map_check == NULL)
		return (ERR_IMPLEMENTATION);
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (ERR_FILE_FORMAT);
	if (get_cell_type(map, x, y) == OUTSIDE)
		return (ERR_FILE_FORMAT);
	if (get_cell_type(map, x, y) == WALL || map_check[y * map->width + x] == 1)
		return (ERR_NONE);
	map_check[y * map->width + x] = 1;
	if (flood_fill(map, map_check, x -1, y) == ERR_FILE_FORMAT)
		return (ERR_FILE_FORMAT);
	if (flood_fill(map, map_check, x +1, y) == ERR_FILE_FORMAT)
		return (ERR_FILE_FORMAT);
	if (flood_fill(map, map_check, x, y -1) == ERR_FILE_FORMAT)
		return (ERR_FILE_FORMAT);
	if (flood_fill(map, map_check, x, y +1) == ERR_FILE_FORMAT)
		return (ERR_FILE_FORMAT);
	return (ERR_NONE);
}

t_error	parse_map_check(t_map *map)
{
	t_error			error;
	unsigned char	*map_check;
	int				x;
	int				y;

	if (map == NULL)
		return (ERR_IMPLEMENTATION);
	map_check = ft_calloc(map->width * map->height, sizeof(unsigned char));
	if (map_check == NULL)
		return (ERR_ALLOCATION);
	while (next_space(map, map_check, &x, &y))
	{
		error = flood_fill(map, map_check, x, y);
		if (error != ERR_NONE)
			return (free(map_check), error);
	}
	return (free(map_check), ERR_NONE);
}
