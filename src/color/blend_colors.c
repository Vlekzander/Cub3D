/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:25:00 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 12:25:27 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	blend_colors(int base_color, int color)
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
