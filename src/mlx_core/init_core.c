/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:12:38 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 14:48:04 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "mlx_core.h"

t_mlx_core	*init_core(char *title)
{
	t_mlx_core	*core;

	if (title == NULL)
		return (NULL);
	core = ft_calloc(1, sizeof(t_mlx_core));
	if (core == NULL)
		return (NULL);
	core->width = WIDTH;
	core->height = HEIGHT;
	core->mlx = mlx_init();
	if (core->mlx == NULL)
		return (free_core(core), NULL);
	core->window = mlx_new_window(core->mlx, WIDTH, HEIGHT, title);
	if (core->window == NULL)
		return (free_core(core), NULL);
	mlx_hook(core->window, 17, 0L, mlx_loop_end, core->mlx);
	mlx_key_hook(core->window, key_handler, core);
	mlx_loop_hook(core->mlx, update, core);
	return (core);
}
