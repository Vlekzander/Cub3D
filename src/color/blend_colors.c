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
	unsigned char	alpha;
	unsigned char	alpha_inv;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	alpha = get_color_channel(color, ALPHA);
	if (alpha == 255)
		return (color);
	alpha_inv = 255 - alpha;
	r = ((get_color_channel(color, RED) * alpha)
			+ (get_color_channel(base_color, RED) * (alpha_inv))) >> 8;
	g = ((get_color_channel(color, GREEN) * alpha)
			+ (get_color_channel(base_color, GREEN) * (alpha_inv))) >> 8;
	b = ((get_color_channel(color, BLUE) * alpha)
			+ (get_color_channel(base_color, BLUE) * (alpha_inv))) >> 8;
	return (rgb(r, g, b));
}
