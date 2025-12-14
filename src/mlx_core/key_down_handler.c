/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:53:14 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 17:40:52 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_core.h"

int	key_down_handler(int keycode, t_mlx_core *core)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(core->mlx);
	else if (keycode == KEY_W)
		core->game->forward = 1;
	else if (keycode == KEY_S)
		core->game->backward = 1;
	else if (keycode == KEY_A)
		core->game->left = 1;
	else if (keycode == KEY_D)
		core->game->right = 1;
	else if (keycode == KEY_LEFT)
		core->game->view_left = 1;
	else if (keycode == KEY_RIGHT)
		core->game->view_right = 1;
	return (0);
}
