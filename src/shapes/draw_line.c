/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:44:40 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 16:31:54 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "shapes.h"

static int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	invert_points(t_line *line)
{
	int	temp;

	if (line == NULL)
		return ;
	temp = line->sy;
	line->sy = line->ey;
	line->ey = temp;
	temp = line->sx;
	line->sx = line->ex;
	line->ex = temp;
}

static void	draw_line_high(t_image *image, t_line line, int color, int *delta)
{
	int	step;
	int	d;

	if (image == NULL || delta == NULL)
		return ;
	step = 1;
	if (delta[0] < 0)
	{
		delta[0] = -delta[0];
		step = -1;
	}
	d = 2 * delta[0] - delta[1];
	while (line.sy <= line.ey)
	{
		put_pixel(image, line.sx, line.sy, color);
		if (d > 0)
		{
			line.sx += step;
			d += 2 * (delta[0] - delta[1]);
		}
		else
			d += 2 * delta[0];
		line.sy++;
	}
}

static void	draw_line_low(t_image *image, t_line line, int color, int *delta)
{
	int	step;
	int	d;

	if (image == NULL || delta == NULL)
		return ;
	step = 1;
	if (delta[1] < 0)
	{
		delta[1] = -delta[1];
		step = -1;
	}
	d = 2 * delta[0] - delta[1];
	while (line.sx <= line.ex)
	{
		put_pixel(image, line.sx, line.sy, color);
		if (d > 0)
		{
			line.sy += step;
			d += 2 * (delta[1] - delta[0]);
		}
		else
			d += 2 * delta[1];
		line.sx++;
	}
}

void	draw_line(t_image *image, t_line line, int color)
{
	int	delta[2];

	if (image == NULL)
		return ;
	if (abs_int(line.ey - line.sy) >= abs_int(line.ex - line.sx))
	{
		if (line.sy > line.ey)
			invert_points(&line);
		delta[0] = line.ex - line.sx;
		delta[1] = line.ey - line.sy;
		draw_line_high(image, line, color, delta);
	}
	else
	{
		if (line.sx > line.ex)
			invert_points(&line);
		delta[0] = line.ex - line.sx;
		delta[1] = line.ey - line.sy;
		draw_line_low(image, line, color, delta);
	}
}
