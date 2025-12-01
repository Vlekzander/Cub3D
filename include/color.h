/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:49:42 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 12:24:45 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef enum e_channel
{
	BLUE,
	GREEN,
	RED,
	ALPHA
}	t_channel;

int	get_color_channel(int color, t_channel channel);
int	rgb(unsigned char r, unsigned char g, unsigned char b);
int	rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int	blend_colors(int base_color, int color);

#endif
