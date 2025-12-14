/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:52:14 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/14 20:34:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "error.h"
#include "raycast.h"
#include "vec.h"

static float	absf(float val)
{
	if (val < 0)
		return (-val);
	return (val);
}

static t_error	perf_dda(t_hit_result *res, t_dda_ctx *ctx, t_map *map)
{
	while (1)
	{
		if (ctx->side.x < ctx->side.y)
		{
			ctx->side.x += ctx->delta.x;
			res->pos.x += ctx->step.x;
			res->side = ctx->step.x + 2;
		}
		else
		{
			ctx->side.y += ctx->delta.y;
			res->pos.y += ctx->step.y;
			res->side = ctx->step.y + 1;
		}
		if (res->pos.x < 0 || res->pos.x > map->width
			|| res->pos.y < 0 || res->pos.y > map->height)
			return (ERR_OOB);
		if (map->grid[res->pos.y * map->width + res->pos.x] == WALL)
		{
			res->dist.x = ctx->side.x - ctx->delta.x;
			res->dist.y = ctx->side.y - ctx->delta.y;
			return (ERR_NONE);
		}
	}
}

static void	setup_dda(
	t_vec2f dir, t_dda_ctx *ctx, t_hit_result *res, t_vec2f pos)
{
	if (dir.x > 0)
	{
		ctx->side.x = ((float)(res->pos.x) + 1 - pos.x) * ctx->delta.x;
		ctx->step.x = 1;
	}
	else
	{
		ctx->side.x = (pos.x - (float)(res->pos.x)) * ctx->delta.x;
		ctx->step.x = -1;
	}
	if (dir.y > 0)
	{
		ctx->side.y = ((float)(res->pos.y) + 1 - pos.y) * ctx->delta.y;
		ctx->step.y = 1;
	}
	else
	{
		ctx->side.y = (pos.y - (float)(res->pos.y)) * ctx->delta.y;
		ctx->step.y = -1;
	}
}

t_error	dda(t_hit_result *res, t_map *map, t_vec2f pos, t_vec2f dir)
{
	t_dda_ctx	ctx;

	res->pos.x = (int)pos.x;
	res->pos.y = (int)pos.y;
	ctx.delta.x = absf(1 / dir.x);
	ctx.delta.y = absf(1 / dir.y);
	setup_dda(dir, &ctx, res, pos);
	return (perf_dda(res, &ctx, map));
}
