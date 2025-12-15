/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:24:19 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 21:29:41 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define ROT_SPEED 90
# define COLIDE 0.1f
# define MAP_CELL 5
# define MAP_OUTSIDE 0x80000000
# define MAP_WALL 0x80061615
# define MAP_SPACE 0x800d2d2a
# define MAP_PLAYER 0xFFFF0000
# include "error.h"
# include "map.h"
# include "vec.h"

typedef struct s_game
{
	t_map		*map;
	t_vec2f		player_pos;
	t_vec2f		direction;
	t_vec2f		camera_plane;
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			view_left;
	int			view_right;
	int			minimap;
	long long	last_time;
}	t_game;

t_error	init_game(t_game **game, char *map_path);
void	free_game(t_game *game);
void	draw_minimap(t_game *game, t_image *screen);

#endif
