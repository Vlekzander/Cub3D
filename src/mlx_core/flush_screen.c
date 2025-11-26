/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:50:48 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:35:28 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "mlx.h"
#include "mlx_core.h"

static void	put_pixel_mlx(void *image, int x, int y, int color)
{
	void	*data;
	int		bpp;
	int		size_line;
	int		endian;

	if (image == NULL)
		return ;
	data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	*(int *)(data + (y * size_line + x * (bpp / 8))) = color;
}

t_error	flush_screen(t_mlx_core *core)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < core->screen->height)
	{
		j = 0;
		while (j < core->screen->width)
		{
			color = core->screen->pixels[i * core->screen->width + j];
			put_pixel_mlx(core->img, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(core->mlx, core->window, core->img, 0, 0);
	fill_image(core->screen, 0xFF000000);
	return (ERR_NONE);
}
