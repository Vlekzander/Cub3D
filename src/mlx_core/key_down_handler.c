/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:53:14 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 21:31:10 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_core.h"

int	key_down_handler(int keycode, t_mlx_core *core)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(core->mlx);
	else if (keycode == 'w')
		core->game->forward = 1;
	else if (keycode == 's')
		core->game->backward = 1;
	else if (keycode == 'a')
		core->game->left = 1;
	else if (keycode == 'd')
		core->game->right = 1;
	else if (keycode == KEY_LEFT)
		core->game->view_left = 1;
	else if (keycode == KEY_RIGHT)
		core->game->view_right = 1;
	else if (keycode == 'm')
		core->game->minimap = !core->game->minimap;
	return (0);
}
