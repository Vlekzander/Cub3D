/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:01:55 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 13:06:37 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "color.h"
#include "image.h"
#include "stdio.h"

static int	blend_colors(int base_color, int color)
{
	float			alpha;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	alpha = (float) get_color_channel(color, ALPHA) / 255;
	if (alpha == 1.0f)
		return (color);
	r = get_color_channel(color, RED);
	g = get_color_channel(color, GREEN);
	b = get_color_channel(color, BLUE);
	r = (unsigned char)(r * alpha + get_color_channel(base_color, RED)
			* (1.0f - alpha) + 0.5f);
	g = (unsigned char)(g * alpha + get_color_channel(base_color, GREEN)
			* (1.0f - alpha) + 0.5f);
	b = (unsigned char)(b * alpha + get_color_channel(base_color, BLUE)
			* (1.0f - alpha) + 0.5f);
	return (rgb(r, g, b));
}

void	draw_image(t_image *dst, t_image *src, int x, int y)
{
	int	i;
	int	j;
	int	s_col;
	int	d_col;

	if (dst == NULL || src == NULL)
		return ;
	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			if (x + i >= 0 && x + i < dst->width
				&& y + j >= 0 && y + j < dst->height)
			{
				s_col = src->pixels[j * src->width + i];
				d_col = dst->pixels[(y + j) * dst->width + (x + i)];
				if (get_color_channel(s_col, ALPHA) != 0)
					put_pixel(dst, x + i, y + j, blend_colors(d_col, s_col));
			}
			j++;
		}
		i++;
	}
}
