/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:28:26 by apierret          #+#    #+#             */
/*   Updated: 2025/11/03 20:31:45 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "error.h"
#include "image.h"

t_error	copy_image(t_image **dst, t_image *src)
{
	t_image	*image;

	if (dst == NULL || src == NULL)
		return (ERR_IMPLEMENTATION);
	image = create_image(src->width, src->height);
	if (image == NULL)
		return (ERR_ALLOCATION);
	draw_image(image, src, 0, 0);
	return (*dst = image, ERR_NONE);
}
