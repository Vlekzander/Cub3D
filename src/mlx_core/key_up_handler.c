/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:53:14 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 21:31:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_core.h"

int	key_up_handler(int keycode, t_mlx_core *core)
{
	if (keycode == 'w')
		core->game->forward = 0;
	else if (keycode == 's')
		core->game->backward = 0;
	else if (keycode == 'a')
		core->game->left = 0;
	else if (keycode == 'd')
		core->game->right = 0;
	else if (keycode == KEY_LEFT)
		core->game->view_left = 0;
	else if (keycode == KEY_RIGHT)
		core->game->view_right = 0;
	return (0);
}
