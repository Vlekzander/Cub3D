/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:37:35 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 15:49:00 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "color.h"
#include "image.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	int	base_color;

	if (image == NULL || x < 0 || y < 0
		|| x >= image->width || y >= image->height)
		return ;
	base_color = image->pixels[y * image->width + x];
	image->pixels[y * image->width + x] = blend_colors(base_color, color);
}
