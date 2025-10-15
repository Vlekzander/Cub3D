/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:29:38 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 16:26:28 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include "image.h"

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_rect;

typedef struct s_line
{
	int	sx;
	int	sy;
	int	ex;
	int	ey;
}	t_line;

void	draw_rect(t_image *image, t_rect rect, int fill, int color);
void	draw_line(t_image *image, t_line line, int color);

#endif
