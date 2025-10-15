/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:01:55 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 12:25:39 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "color.h"
#include "image.h"
#include "stdio.h"

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
