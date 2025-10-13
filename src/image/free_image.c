/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:51:41 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 16:51:43 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "image.h"

void	free_image(t_image *image)
{
	if (image == NULL)
		return ;
	free(image->pixels);
	free(image);
}
