/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:48:39 by apierret          #+#    #+#             */
/*   Updated: 2025/11/30 14:49:49 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "mlx_core.h"

void	free_core(t_mlx_core *core)
{
	if (core == NULL)
		return ;
	mlx_destroy_window(core->mlx, core->window);
	mlx_destroy_image(core->mlx, core->img);
	mlx_destroy_display(core->mlx);
	free(core->mlx);
	free(core->screen);
	free(core);
}
