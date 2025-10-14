/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:47:11 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:33:50 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include "image.h"
#include "libft.h"

t_image	*create_image(int width, int height)
{
	t_image	*image;

	if (width < 1 || height < 1 || width > INT_MAX / height)
		return (NULL);
	image = ft_calloc(1, sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->width = width;
	image->height = height;
	image->pixels = ft_calloc(width * height, sizeof(int));
	if (image->pixels == NULL)
		return (free_image(image), NULL);
	return (image);
}
