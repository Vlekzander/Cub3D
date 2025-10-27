/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:42:34 by apierret          #+#    #+#             */
/*   Updated: 2025/10/15 12:33:16 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "shapes.h"

void	fill_image(t_image *image, int color)
{
	if (image == NULL)
		return ;
	draw_rect(image, (t_rect){0, 0, image->width, image->height}, 1, color);
}
