/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:42:34 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:45:25 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"

void	fill_image(t_image *image, int color)
{
	int	i;
	int	size;

	if (image == NULL || image->pixels == NULL)
		return ;
	size = image->width * image->height;
	i = 0;
	while (i < size)
	{
		image->pixels[i] = color;
		i++;
	}
}
