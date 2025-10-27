/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:53:14 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 14:56:11 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_core.h"

int	key_handler(int keycode, t_mlx_core *core)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(core->mlx);
	return (0);
}
