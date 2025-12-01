/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:56:20 by apierret          #+#    #+#             */
/*   Updated: 2025/11/30 14:50:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "image.h"
#include "mlx_core.h"

static void	clear_screen(t_image *image)
{
	int	i;
	int	size;

	if (image == NULL)
		return ;
	size = image->width * image->height;
	i = 0;
	while (i < size)
	{
		image->pixels[i] = 0;
		i++;
	}
}

int	update(t_mlx_core *core)
{
	clear_screen(core->screen);
	return (0);
}
