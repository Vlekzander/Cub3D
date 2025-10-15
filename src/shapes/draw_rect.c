/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:34:25 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 12:33:09 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "shapes.h"

static void	prepare_rect(t_rect *rect)
{
	if (rect == NULL)
		return ;
	if (rect->width < 0)
	{
		rect->width = -rect->width;
		rect->x -= rect->width;
	}
	if (rect->height < 0)
	{
		rect->height = -rect->height;
		rect->y -= rect->height;
	}
	if (rect->x < 0)
	{
		rect->width += rect->x;
		rect->x = 0;
	}
	if (rect->y < 0)
	{
		rect->height += rect->y;
		rect->y = 0;
	}
}

void	draw_rect(t_image *image, t_rect rect, int fill, int color)
{
	int	i;
	int	j;

	if (image == NULL || rect.width == 0 || rect.height == 0)
		return ;
	prepare_rect(&rect);
	if (rect.width <= 0 || rect.height <= 0)
		return ;
	i = rect.y;
	while (i < rect.y + rect.height && i < image->height)
	{
		j = rect.x;
		while (j < rect.x + rect.width && j < image->width)
		{
			if (fill || (i == rect.y || j == rect.x
					|| i == rect.y + rect.height -1
					|| j == rect.x + rect.width -1))
				put_pixel(image, j, i, color);
			j++;
		}
		i++;
	}
}
