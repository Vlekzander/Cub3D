/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:01:55 by apierret          #+#    #+#             */
/*   Updated: 2025/11/28 00:42:13 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "color.h"
#include "image.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	draw_image(t_image *dst, t_image *src, int x, int y)
{
	int	i;
	int	j;
	int	start[2];
	int	end[2];

	if (dst == NULL || src == NULL)
		return ;
	start[0] = ft_max(-x, 0);
	start[1] = ft_max(-y, 0);
	end[0] = ft_min(src->width, dst->width - x);
	end[1] = ft_min(src->height, dst->height - y);
	if (end[0] <= start[0] || end[1] <= start[1])
		return ;
	i = start[0];
	while (i < end[0])
	{
		j = start[1];
		while (j < end[1])
		{
			put_pixel(dst, x + i, y + j, blend_colors(dst->pixels[(y + j)
					* dst->width + (x + i)], src->pixels[j * src->width + i]));
			j++;
		}
		i++;
	}
}
