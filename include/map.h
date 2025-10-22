/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:07:55 by apierret          #+#    #+#             */
/*   Updated: 2025/10/21 10:24:00 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "error.h"
# include "image.h"

typedef enum e_facing
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W'
}	t_facing;

typedef struct s_map
{
	unsigned char	*grid;
	t_image			*north;
	t_image			*south;
	t_image			*east;
	t_image			*west;
	int				color_ceil;
	int				color_floor;
	int				width;
	int				height;
	t_facing		facing;
}	t_map;

t_error	parse_map(t_map **map, const char *path);
t_error	parse_map_data(t_map *map, int fd);
t_error	parse_map_content(t_map *map, int fd);
void	free_map(t_map *map);

#endif
