/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:14:55 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/14 18:50:29 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "error.h"
# include "mlx_core.h"
# include "map.h"
# include "vec.h"

typedef struct s_hit_result
{
	t_vec2i	pos;
	t_vec2f	dist;
	int		side;
}	t_hit_result;

typedef struct s_dda_ctx
{
	t_vec2f	delta;
	t_vec2f	side;
	t_vec2i	step;
}	t_dda_ctx;

typedef struct s_stripe
{
	int		height;
	int		start;
	int		end;
	int		x;
	float	image_x;
}	t_stripe;

void	draw_stripe(
			t_mlx_core *core, t_hit_result *hit, t_vec2f dir, int stripe_x);
t_error	dda(t_hit_result *res, t_map *map, t_vec2f pos, t_vec2f dir);
t_error	raycast(t_mlx_core *core);

#endif
