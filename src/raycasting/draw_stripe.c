/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:33:34 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/14 22:47:10 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "mlx_core.h"
#include "raycast.h"
#include "image.h"
#include "vec.h"

static t_stripe	make_stripe(float dist, int stripe_x)
{
	t_stripe	stripe;

	stripe.height = (int)(HEIGHT / dist);
	stripe.start = HEIGHT / 2 - stripe.height / 2;
	stripe.end = HEIGHT / 2 + stripe.height / 2;
	if (stripe.end >= HEIGHT)
		stripe.end = HEIGHT - 1;
	stripe.x = stripe_x;
	return (stripe);
}

static void	draw_stripe_to_screen(
		t_mlx_core *core, t_image *image, int image_x, t_stripe stripe)
{
	int		i;
	float	image_y_ratio;
	int		y;

	if (core == NULL || image == NULL)
		return ;
	image_y_ratio = (float)image->height / (float)stripe.height;
	i = stripe.start;
	while (i < stripe.end)
	{
		y = (int)((i - stripe.start) * image_y_ratio);
		put_pixel(core->screen, stripe.x, i,
			image->pixels[y * image->width + image_x]);
		i++;
	}
}

static int	find_image_x(t_image *image, float wallX, int side)
{
	int	image_x;

	if (image == NULL)
		return (0);
	image_x = wallX * (float)image->width;
	if (side % 2)
		image_x = image->width - image_x - 1;
	return (image_x);
}

void	draw_stripe(t_mlx_core *core, t_hit_result *hit, t_vec2f dir,
			int stripe_x)
{
	float		wall_x;
	t_stripe	stripe;
	t_image		*image;

	if (core == NULL || hit == NULL)
		return ;
	if (hit->side % 2)
	{
		wall_x = core->game->player_pos.y + hit->dist.x * dir.y;
		stripe = make_stripe(hit->dist.x, stripe_x);
		image = core->game->map->east;
		if (hit->side == 1)
			image = core->game->map->west;
	}
	else
	{
		wall_x = core->game->player_pos.x + hit->dist.y * dir.x;
		stripe = make_stripe(hit->dist.y, stripe_x);
		image = core->game->map->south;
		if (hit->side == 0)
			image = core->game->map->north;
	}
	wall_x -= floorf(wall_x);
	draw_stripe_to_screen(core, image,
		find_image_x(image, wall_x, hit->side), stripe);
}
