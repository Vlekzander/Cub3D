/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_channel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:57:45 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:59:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	get_color_channel(int color, t_channel channel)
{
	if (channel == ALPHA)
		return ((color >> 24) & 0xFF);
	if (channel == RED)
		return ((color >> 16) & 0xFF);
	if (channel == GREEN)
		return ((color >> 8) & 0xFF);
	if (channel == BLUE)
		return (color & 0xFF);
	return (0);
}
