/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:15:07 by apierret          #+#    #+#             */
/*   Updated: 2025/11/03 21:16:53 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "map.h"

t_cell_type	get_cell_type(t_map *map, int x, int y)
{
	if (map == NULL || x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (OUTSIDE);
	return (map->grid[y * map->width + x]);
}
