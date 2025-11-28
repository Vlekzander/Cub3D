/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:25:00 by apierret          #+#    #+#             */
/*   Updated: 2025/11/28 00:41:12 by apierret         ###   ########.fr       */
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

	alpha = color >> 24;
	if (alpha == 255)
		return (color);
	if (alpha == 0)
		return (base_color);
	alpha_inv = 255 - alpha;
	r = ((((color >> 16) & 0xFF) * alpha)
			+ (((base_color >> 16) & 0xFF) * (alpha_inv))) >> 8;
	g = ((((color >> 8) & 0xFF) * alpha)
			+ (((base_color >> 8) & 0xFF) * (alpha_inv))) >> 8;
	b = (((color & 0xFF) * alpha)
			+ ((base_color & 0xFF) * (alpha_inv))) >> 8;
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
