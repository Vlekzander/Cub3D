/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:15 by apierret          #+#    #+#             */
/*   Updated: 2025/10/21 10:15:48 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "image.h"
#include "map.h"

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	free_image(map->north);
	free_image(map->south);
	free_image(map->east);
	free_image(map->west);
	free(map->grid);
	free(map);
}
