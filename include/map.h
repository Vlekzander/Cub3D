/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:07:55 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 15:24:52 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "error.h"
# include "image.h"

typedef enum e_cell_type
{
	OUTSIDE,
	WALL,
	SPACE
}	t_cell_type;

typedef enum e_facing
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W'
}	t_facing;

typedef struct s_map
{
	t_cell_type		*grid;
	t_image			*north;
	t_image			*south;
	t_image			*east;
	t_image			*west;
	int				color_ceil;
	int				color_floor;
	int				width;
	int				height;
	int				spawn_x;
	int				spawn_y;
	t_facing		facing;
}	t_map;

t_error		parse_map(t_map **map, const char *path);
t_error		parse_map_data(t_map *map, int fd);
t_error		parse_map_content(t_map *map, int fd);
t_error		parse_map_check(t_map *map);
void		free_map(t_map *map);
t_cell_type	get_cell_type(t_map *map, int x, int y);

#endif
