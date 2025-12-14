/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:56:20 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 16:08:57 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "mlx.h"
#include "mlx_core.h"
#include "shapes.h"

static void	clear_screen(t_image *image)
{
	int	i;
	int	size;

	if (image == NULL)
		return ;
	size = image->width * image->height;
	i = 0;
	while (i < size)
	{
		image->pixels[i] = 0;
		i++;
	}
}

int	update(t_mlx_core *core)
{
	clear_screen(core->screen);
	draw_rect(core->screen, (t_rect){0, 0, WIDTH, HEIGHT/2}, 1, core->game->map->color_ceil);
	draw_rect(core->screen, (t_rect){0, HEIGHT/2, WIDTH, HEIGHT}, 1, core->game->map->color_floor);
	mlx_put_image_to_window(core->mlx, core->window, core->img, 0, 0);
	return (0);
}
